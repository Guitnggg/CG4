#pragma once

#include <KamataEngine.h>

class Stage {
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

    uint32_t textureHandle1_ = 0;
    uint32_t textureHandle2_ = 0;

    std::array<KamataEngine::Sprite*, 4> sprites_;

    float scrollx_ = 0.0f;
    const float kScrollSpeed = 4.0f;     // スクロール速度
    const float kScrollWidth = 1280.0f;  // 画面の幅
};

