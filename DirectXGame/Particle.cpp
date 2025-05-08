#include "Particle.h"

using namespace MathUtility;

void Particle::Initialize(Model*model)
{
    // NULLチェック
    assert(model);

    // 引数で受け取ったデータをメンバ変数に格納
    model_ = model;

    // 色の設定
    objectColor_.Initialize();
    color_ = { 1.0f, 1.0f, 0.0f, 1.0f };

    // ワールド変換データの初期化
    worldTransform_.Initialize();   
}

void Particle::Update()
{
    // 色変更オブジェクトに色の数値を設定する
    objectColor_.SetColor(color_);

    // 
    worldTransform_.translation_ += { 0.0f, 0.1f, 0.0f };

    // 行列を更新
    worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera)
{
    // 3Dモデルの描画
    model_->Draw(worldTransform_, camera, &objectColor_);
}

