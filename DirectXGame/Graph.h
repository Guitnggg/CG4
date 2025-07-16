#pragma once

#include <2d/Sprite.h>

class Graph{
public:

    /// <summary>
    /// 
    /// </summary>
    Graph();

    /// <summary>
    /// 
    /// </summary>
    ~Graph();

    /// <summary>
    /// 
    /// </summary>
    void Initialize(const KamataEngine::Vector2& positino, const KamataEngine::Vector2& size);

    /// <summary>
    /// 
    /// </summary>
    void Update(float rate);

    /// <summary>
    /// 
    /// </summary>
    void Draw();

private:
    KamataEngine::Sprite* flont_ = nullptr;
    KamataEngine::Sprite* back_ = nullptr;
    KamataEngine::Vector2  size_;
    float rate_ = 1.0f;
};

