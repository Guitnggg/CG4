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
    KamataEngine::Sprite* scoreSprite_ = nullptr;






};

