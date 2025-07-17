#pragma once

#include <2d/Sprite.h>
#include <base/TextureManager.h>

class Score{
public:

    /// <summary>
    /// 
    /// </summary>
    Score();

    /// <summary>
    /// 
    /// </summary>
    ~Score();

    /// <summary>
    /// 
    /// </summary>
    void Initialize();

    /// <summary>
    /// 
    /// </summary>
    void Update();

    /// <summary>
    /// 
    /// </summary>
    void Draw();

private:

    uint32_t textureHandle_ = 0;
    KamataEngine::Vector2 size_ = { 32.0f, 64.0f };  // 1文字サイズ
    int score_ = 0;

    static const int kDigitCount = 5;
    KamataEngine::Sprite* sprite_[kDigitCount];






};

