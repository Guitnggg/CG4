#pragma once

#include "KamataEngine.h"

class Particle
{
public:
    // 初期化
    void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity);

    // 更新
    void Update();

    // 描画
    void Draw(KamataEngine::Camera& camera);

    // デスフラグのgetter
    bool IsFinished() const { return isFinished_; }

private:
    // ワールド変換データ
    KamataEngine::WorldTransform worldTransform_;

    // モデル
    KamataEngine::Model* model_ = nullptr;

    // 色変更オブジェクト
    KamataEngine::ObjectColor objectColor_;

    // 色の数値
    KamataEngine::Vector4 color_;

    // 移動量
    KamataEngine::Vector3 velocity_;

    // 終了フラグ
    bool isFinished_ = false;
    // 経過時間 
    float counter_ = 0.0f;
    // 寿命
    const float kDuration = 1.0f;
};

