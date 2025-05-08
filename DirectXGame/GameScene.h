#pragma once

#include "KamataEngine.h"
#include "Particle.h"

class GameScene
{
public:

    //デストラクタ
    ~GameScene();

    // 初期化
    void Initialize();

    // 更新
    void Update();

    // 描画
    void Draw();

    // パーティクル発生
    void ParticleCreate(KamataEngine::Vector3 position);

private:

    // カメラ
    KamataEngine::Camera camera_;

    // パーティクルモデルデータ
    KamataEngine::Model* modelParticle_ = nullptr;

    // パーティクル
    std::list<Particle*> particles_;
    Particle* particle_ = nullptr;
};

