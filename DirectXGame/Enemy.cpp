#include "Enemy.h"

#include <base/TextureManager.h>

using namespace KamataEngine;

Enemy::Enemy() {}

Enemy::~Enemy() {
    delete model_;
}

void Enemy::Initialize(Camera* camera) {
    camera_ = camera;

    model_ = Model::CreateSphere(4, 4);

    worldTransform_.Initialize();
    worldTransform_.translation_ = { 45.0f,0.0f,0.0f };
}

void Enemy::Update() {
    worldTransform_.translation_.x -= speed_;

    worldTransform_.UpdateMatrix();
}

void Enemy::Draw() {
    model_->Draw(worldTransform_, *camera_);
}

bool Enemy::IsOutOfScreen() const {
    // 一定位置よりも左に進んだら画面外と判定する
    return worldTransform_.translation_.x < -50.0f;
}