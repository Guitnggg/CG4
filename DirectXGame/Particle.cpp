#include "Particle.h"

#include <algorithm>
#include <random>
#include <cassert>

// グローバルな乱数エンジンを追加  
static std::random_device rd;
static std::mt19937 random(rd());

static std::uniform_real_distribution<float> rotationDist(0.0f, 3.14159f * 2); // 0〜2πラジアン（360°）

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity)
{
    // NULLチェック
    assert(model);

    // 引数で受け取ったデータをメンバ変数に格納
    model_ = model;

    // 色の設定
    objectColor_.Initialize();
    color_ = { 1.0f, 1.0f, 1.0f, 1.0f };

    // 移動量の設定
    velocity_ = velocity;

    // ワールド変換データの初期化
    worldTransform_.Initialize();
    worldTransform_.translation_ = position;
    worldTransform_.scale_ = { 0.1f, 0.1f, 0.1f };

    // 回転の値をランダムに設定
    worldTransform_.rotation_.x = rotationDist(random);
    worldTransform_.rotation_.y = rotationDist(random);

    // 青から白に変化する設定
    startColor_ = { 1.0f, 0.0f, 0.0f, 1.0f }; // 濃い青
    endColor_ = { 1.0f, 1.0f, 1.0f, 0.0f }; // 白で消える

    color_ = startColor_;

}

void Particle::Update()
{
    // 終了フラグが立っていたら何もしない
    if (isFinished_) { return; }

    // 回転
    worldTransform_.rotation_.x += 0.15f;
    worldTransform_.rotation_.y += 0.15f;

    // 大きさを徐々に大きく
    worldTransform_.scale_ += Vector3{ 0.05f,0.05f,0.05f };

    // カウンター
    counter_ += 1.0f / 30.0f;
    float t = std::clamp(counter_ / kDuration, 0.0f, 1.0f);

    // フェード処理
    color_.x = startColor_.x + (endColor_.x - startColor_.x) * t;
    color_.y = startColor_.y + (endColor_.y - startColor_.y) * t;
    color_.z = startColor_.z + (endColor_.z - startColor_.z) * t;

    // フェードだけ個別制御
    color_.w = std::clamp(1.0f - t, 0.0f, 1.0f);

    // 色を適用
    objectColor_.SetColor(color_);

    // 寿命を超えたら終了
    if (counter_ > kDuration)
    {
        counter_ = kDuration;
        isFinished_ = true;
    }

    // 行列を更新
    worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera)
{
    // 3Dモデルの描画
    model_->Draw(worldTransform_, camera, &objectColor_);
}

