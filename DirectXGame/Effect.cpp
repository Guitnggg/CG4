#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(KamataEngine::Model* model)
{
    // NULLチェック
    assert(model);
    // 引数で受け取ったデータをメンバ変数に格納
    model_ = model;
    // ワールド変換データの初期化
    worldTransform_.Initialize();
}

void Effect::Update()
{
    worldTransform_.TransferMatrix();
}

void Effect::Draw(KamataEngine::Camera& camera)
{
    model_->Draw(worldTransform_, camera);
}
