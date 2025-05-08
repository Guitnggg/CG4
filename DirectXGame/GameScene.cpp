#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene()
{   
    // メモリ解放
    delete modelParticle_;
    delete particle_;
}

void GameScene::Initialize()
{
    // カメラの初期化
    camera_.Initialize();

    // モデルの生成
    modelParticle_ = Model::CreateSphere(4, 4);

    // パーティクルの生成
    particle_ = new Particle();
    // パーティクルの初期化
    particle_->Initialize(modelParticle_);
}

void GameScene::Update()
{
    // パーティクルの更新
    particle_->Update();
}

void GameScene::Draw()
{
    // DirextXCommonインスタンスの取得
    DirectXCommon* dxCommon = DirectXCommon::GetInstance();

    // 3Dモデルの描画前処理
    Model::PreDraw(dxCommon->GetCommandList());

    // パーティクルの描画
    particle_->Draw(camera_);

    // 3Dモデルの描画後処理
    Model::PostDraw();
}
