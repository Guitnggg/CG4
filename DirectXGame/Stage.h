#pragma once

#include <KamataEngine.h>

class Stage{
public:

    /// <summary>
    /// インストラクタ
    /// </summary>
    Stage();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Stage();

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private:

    uint32_t textureHandle_ = 0;
    KamataEngine::Sprite* bgSprite1_ = nullptr;
    KamataEngine::Sprite* bgSprite2_ = nullptr;

    float scrollx_ = 0.0f;
    const float kScrollSpeed = 2.0f;     // スクロール速度
    const float kScrollWidth = 1280.0f;  // 画面の幅
};

