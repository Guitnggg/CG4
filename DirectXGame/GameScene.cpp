#include "GameScene.h"

#include <random>

std::random_device seedGenerator;
std::mt19937 random(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

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

    // 乱数の初期化
    srand((unsigned)time(NULL));
}

void GameScene::Update()
{
    // パーティクル発生場所はランダム
    Vector3 position = { distribution(random) * 30.0f, distribution(random) * 20.0f, 0 };

    // パーティクルの発生確率
    if (rand() % 30 == 0) {
        ParticleCreate(position);
    }

    // パーティクルの更新
    for (Particle* particle : particles_)
    {
        particle->Update();
    }

    // 終了フラグが立っているパーティクルを削除
    particles_.remove_if([](Particle* particle) {
        if (particle->IsFinished())
        {
            delete particle;
            return true;
        }
        return false;
        });
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

void GameScene::ParticleCreate(Vector3 position)
{
    // パーティクルの生成
    for (int i = 0; i < 150; i++)
    {
        // 生成
        Particle* particle = new Particle();
        // 位置
        Vector3 pos = position;
        // 移動量
        Vector3 velocity = { distribution(random), distribution(random), 0 };
        Normalize(velocity);
        velocity *= distribution(random);
        velocity *= 0.1f;
        // 初期化
        particle->Initialize(modelParticle_, position, velocity);
        // リストに追加
        particles_.push_back(particle);
    }
}
