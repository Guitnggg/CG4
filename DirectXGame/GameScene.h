#pragma once

#include <KamataEngine.h>

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
    KamataEngine::DirectXCommon* dxCommon_ = nullptr;
    KamataEngine::WorldTransform* worldTransform_;
    KamataEngine::Camera* camera_;

    // モデル
    KamataEngine::Model* model_ = nullptr;
    uint32_t textureHandle_;

};

