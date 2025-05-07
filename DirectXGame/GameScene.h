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

private:

    // カメラ
    Camera camera_;

    // パーティクルモデルデータ
    Model* modelParticle_ = nullptr;

    // パーティクル
    Particle* particle_ = nullptr;
};

