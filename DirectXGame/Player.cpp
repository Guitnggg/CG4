#include "Player.h"

#include <cassert>
#include <algorithm>

using namespace KamataEngine;

Player::Player() {}

Player::~Player(){
    delete model_;
    delete worldTransform_;
}

void Player::Initialize(KamataEngine::Camera* camera){
    camera_ = camera;

    textureHandle_ = TextureManager::Load("./Resources/Player/player.png");
    model_ = Model::CreateFromOBJ("player");  // playerのモデル指定

    input_ = Input::GetInstance();  // 入力できるように

    worldTransform_ = new WorldTransform();
    worldTransform_->Initialize();
    worldTransform_->rotation_ = { 0,90.0f,0 };
    worldTransform_->scale_ = { 2,2,2 };
}

void Player::Update() {
    // 上下移動
    if (input_->PushKey(DIK_W)) {
        worldTransform_->translation_.y += moveSpeed_;
    }
    if (input_->PushKey(DIK_S)) {
        worldTransform_->translation_.y -= moveSpeed_;
    }

    // 左右移動
    if (input_->PushKey(DIK_D)) {
        worldTransform_->translation_.x += moveSpeed_;
    }
    if (input_->PushKey(DIK_A)) {
        worldTransform_->translation_.x -= moveSpeed_;
    }

    // 範囲制限（例：X:-10〜10, Y:-5〜5）
    //worldTransform_->translation_.x = std::clamp(worldTransform_->translation_.x, -10.0f, 10.0f);
    //worldTransform_->translation_.y = std::clamp(worldTransform_->translation_.y, -5.0f, 5.0f);

    worldTransform_->UpdateMatrix();
}

void Player::Draw() {
    model_->Draw(*worldTransform_, *camera_, textureHandle_);
}