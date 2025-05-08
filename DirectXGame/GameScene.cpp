#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene()
{   
    // メモリ解放
    delete modelParticle_;
    delete particle_;
    for (Particle* particle : particles_)
    {
        delete particle;
    }
    particles_.clear();
}

void GameScene::Initialize()
{
    // カメラの初期化
    camera_.Initialize();

    // モデルの生成
    modelParticle_ = Model::CreateSphere(4, 4);

    // パーティクルの生成
    for (int i = 0; i < 150; i++)
    {
        // 生成
        Particle* particle = new Particle();
        // 位置
        Vector3 position = { 0.5f*i, 0.0f, 0.0f };
        // 初期化
        particle->Initialize(modelParticle_, position);
        // リストに追加
        particles_.push_back(particle);
    }
}

void GameScene::Update()
{
    // パーティクルの更新
    for (Particle* particle : particles_)
    {
        particle->Update();
    }
}

void GameScene::Draw()
{
    // DirextXCommonインスタンスの取得
    DirectXCommon* dxCommon = DirectXCommon::GetInstance();

    // 3Dモデルの描画前処理
    Model::PreDraw(dxCommon->GetCommandList());

    // パーティクルの描画
    for (Particle* particle : particles_)
    {
        particle->Draw(camera_);
    }

    // 3Dモデルの描画後処理
    Model::PostDraw();
}
