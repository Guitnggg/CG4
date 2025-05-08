#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model*model, Vector3 position, Vector3 velocity)
{
    // NULLチェック
    assert(model);

    // 引数で受け取ったデータをメンバ変数に格納
    model_ = model;

    // 色の設定
    objectColor_.Initialize();
    color_ = { 1.0f, 1.0f, 0.0f, 1.0f };

    // 移動量の設定
    velocity_ = velocity;

    // ワールド変換データの初期化
    worldTransform_.Initialize();   
    worldTransform_.translation_ = position; 
    worldTransform_.scale_ = { 0.2f, 0.2f, 0.2f };
}

void Particle::Update()
{
    // 色変更オブジェクトに色の数値を設定する
    objectColor_.SetColor(color_);

    // 移動
    worldTransform_.translation_ += velocity_;

    // 行列を更新
    worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera)
{
    // 3Dモデルの描画
    model_->Draw(worldTransform_, camera, &objectColor_);
}

