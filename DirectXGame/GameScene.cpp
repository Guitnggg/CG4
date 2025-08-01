#include "GameScene.h"

#include "Collision.h"
#include "FinishScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
    delete worldTransform_;
    delete camera_;

    Model2::StaticFinalize();
    delete model_;

    delete stage_;
    delete player_;   

    delete graph_;
    delete score_;
}

void GameScene::Initialize() {
    dxCommon_ = DirectXCommon::GetInstance();

    worldTransform_ = new WorldTransform();
    worldTransform_->Initialize();

    camera_ = new Camera();
    camera_->Initialize();

    /// ステージ ///
    stage_ = new Stage();
    stage_->Initialize();

    /// Player ///
    player_ = new Player();
    player_->Initialize(camera_);

    /// Enemy ///
    enemies_.clear();
    enemySpawnTimer_ = 0.0f;

    /// particle ///
    particleModel_ = Model::CreateSphere(10, 10);

    /// 2Dグラフ ///
    graph_ = new Graph();
    graph_->Initialize();
    timer_ = 1.0f;

    /// スコア ///
    score_ = new Score();
    score_->Initialize();
}

void GameScene::Update() {
    /// ステージ ///
    stage_->Update();

    /// Player ///
    player_->Update();
    KamataEngine::Vector3 playerPos = player_->GetPosition();
    float playerRadius = 1.0f;  // プレイヤーの当たり判定半径

    /// Enemy ///
    // 敵の生成タイマー更新
    enemySpawnTimer_ += 1.0f / 60.0f;
    if (enemySpawnTimer_ > 2.0f) {
        Enemy* newEnemy = new Enemy();
        newEnemy->Initialize(camera_);
        enemies_.push_back(newEnemy);
        enemySpawnTimer_ = 0.0f;
    }

    // 敵の更新
    for (auto it = enemies_.begin(); it != enemies_.end();) {
        (*it)->Update();
        if ((*it)->IsOutOfScreen()) {
            delete* it;
            it = enemies_.erase(it);
        }
        else {
            ++it;
        }
    }

    // 敵ごとの当たり判定チェック
    for (auto it = enemies_.begin(); it != enemies_.end();) {
        Enemy* enemy = *it;

        if (Collision::CheckSphereCollision(playerPos, playerRadius, enemy->GetPosition(), 1.5f)) {
            // 当たった場合、プレイヤーのHPを減らす
            player_->TakeDamage(25);

            // パーティクルを好きな数生成
            for (int i = 0; i < 30; ++i) {
                KamataEngine::Vector3 velocity = {
                    (float(rand()) / RAND_MAX - 0.5f) * 0.5f,
                    (float(rand()) / RAND_MAX - 0.5f) * 0.5f,
                    (float(rand()) / RAND_MAX - 0.5f) * 0.5f
                };

                Particle* p = new Particle();
                p->Initialize(particleModel_, playerPos, velocity);
                particles_.push_back(p);
            }

            // 敵は削除
            delete enemy;
            it = enemies_.erase(it);
        }
        else {
            ++it;
        }
    }

    /// particle ///
    for(auto it = particles_.begin(); it != particles_.end();) {
        (*it)->Update();
        if ((*it)->IsFinished()) {
            delete* it;
            it = particles_.erase(it);
        }
        else {
            ++it;
        }
    }

    /// スコア ///
    score_->Update();

    /// 2Dグラフ ///
    float hpRate = static_cast<float>(player_->GetHP()) / 100.0f;
    graph_->SetValue(hpRate);
    graph_->Update();

    /// シーン変遷 ///
    if (player_->IsDead()) {
        isEnd_ = true;
    }
}

void GameScene::Draw() {
    // コマンドリストの取得
    ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
    // 背景スプライト描画前処理
    Sprite::PreDraw(commandList);

    /// <summary>
    /// ここに背景スプライトの描画処理を追加できる
    /// </summary>

    /// ステージ ///
    stage_->Draw();

    // スプライト描画後処理
    Sprite::PostDraw();

    // 深度バッファクリア
    dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
    // 3Dオブジェクト描画前処理
    Model::PreDraw(dxCommon_->GetCommandList());

    /// <summary>
    /// ここに3Dオブジェクトの描画処理を追加できる
    /// </summary>

    /// Player ///
    player_->Draw();

    /// Enemy ///
    for (auto enemy : enemies_) {
        enemy->Draw();
    }

    /// particle ///
    for (auto& p : particles_) {
        p->Draw(*camera_);
    }

    // 3Dオブジェクト描画後処理
    Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
    // 前景スプライト描画前処理
    Sprite::PreDraw(commandList);

    /// <summary>
    /// ここに前景スプライトの描画処理を追加できる
    /// </summary>

    /// 2Dグラフ ///
    graph_->Draw();

    /// スコア ///
    score_->Draw();

    // スプライト描画後処理
    Sprite::PostDraw();

#pragma endregion
}

IScene* GameScene::NextScene() const {
    return new FinishScene();
}
