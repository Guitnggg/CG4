#pragma once

#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

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
    void ParticleCreate(Vector3 position);

private:

    // カメラ
    Camera camera_;

    // パーティクルモデルデータ
    Model* modelParticle_ = nullptr;

    // パーティクル
    std::list<Particle*> particles_;
    Particle* particle_ = nullptr;
};

