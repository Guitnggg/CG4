#include "Effect.h"

#include <random>
#include <algorithm>

static std::random_device seed;
static std::mt19937 engine(seed());
static std::uniform_real_distribution<float> yScaleDist(0.5f, 5.0f);   // Y方向スケール
static std::uniform_real_distribution<float> zRotateDist(0.0f, 3.14159f * 2); // Z軸回転（0〜360度）
static std::uniform_real_distribution<float> colorDist(0.0f, 1.0f); // 色のランダム値

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 position, KamataEngine::Vector3 velocity)
{
    // NULLチェック
    assert(model);

    // 引数で受け取った値をメンバ変数に格納
    model_ = model;
    velocity_ = velocity;

    //　色の初期化
    objectColor_.Initialize();
    color_ = { 1.0f, 1.0f, 1.0f, 1.0f };    

    worldTransform_.Initialize();
    worldTransform_.translation_ = position;

    // ランダムな方向と大きさ
    worldTransform_.scale_ = {0.2f, yScaleDist(engine), 0.1f };
    worldTransform_.rotation_.z = zRotateDist(engine);
  
}

void Effect::Update()
{
    // 終了している場合は何もしない
    if (isFinished_) { return; }

    // 大きさが変わったり、回転したり、色が変わったりする
    worldTransform_.scale_.y += 0.1f;
    worldTransform_.rotation_.z += 0.05f;

    //color_.x = colorDist(engine);
    //color_.y = colorDist(engine);
    color_.z = colorDist(engine);
    objectColor_.SetColor(color_);



    // フェード処理
    counter_ += 1.0f / 60.0f;
    color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

    if (counter_ >= kDuration) {
        isFinished_ = true;
    }

    worldTransform_.UpdateMatrix();
}

void Effect::Draw(KamataEngine::Camera& camera)
{
    model_->Draw(worldTransform_, camera, &objectColor_);
}
