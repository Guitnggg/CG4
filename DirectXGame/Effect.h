#pragma once

#include "KamataEngine.h"

class Effect
{
public:
    void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity = {});
   
    void Update();
    
    void Draw(KamataEngine::Camera& camera);
    
    bool IsFinished() const { return isFinished_; }

private:
    KamataEngine::WorldTransform worldTransform_;
    KamataEngine::Model* model_ = nullptr;

    KamataEngine::Vector4 color_;
    KamataEngine::ObjectColor objectColor_;

    KamataEngine::Vector3 velocity_ = {}; // 移動ベクトル
    float counter_ = 0.0f;
    const float kDuration = 1.0f;
    bool isFinished_ = false;
};
