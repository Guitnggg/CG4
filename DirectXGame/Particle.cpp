#include "Particle.h"

void Particle::Initialize(Model*model)
{
    // NULLチェック
    assert(model);

    // 引数で受け取ったデータをメンバ変数に格納
    model_ = model;

    // ワールド変換データの初期化
    worldTransform_.Initialize();
}

void Particle::Update()
{
    // 行列を定数バッファに転送
    worldTransform_.TransferMatrix();
}

void Particle::Draw(Camera& camera)
{
    // 3Dモデルの描画
    model_->Draw(worldTransform_, camera);
}

