#pragma once

#include "KamataEngine.h"

class Particle {
public:

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw(KamataEngine::Camera& camera);

    /// <summary>
    /// デスフラグのgetter
    /// </summary>
    bool IsFinished() const { return isFinished_; }

private:

    KamataEngine::WorldTransform worldTransform_;  // ワールド変換データ    
    KamataEngine::Model* model_ = nullptr;         // モデル

    KamataEngine::ObjectColor objectColor_;  // 色変更オブジェクト    
    KamataEngine::Vector4 color_;            // 色の数値    
    KamataEngine::Vector3 velocity_;         // 移動量

    bool isFinished_ = false;      // 終了フラグ    
    float counter_ = 0.0f;         // 経過時間    
    const float kDuration = 1.0f;  // 寿命
};

