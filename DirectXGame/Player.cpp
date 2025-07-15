#include "Player.h"

#include <cassert>

using namespace KamataEngine;

Player::Player() {}

Player::~Player(){

}

void Player::Initialize(uint32_t textureHandle, KamataEngine::Camera* camera){

    playerTextureHandle_ = textureHandle;
    camera_ = camera;

    model_ = Model::CreateFromOBJ("player");  // playerのモデル指定

    input_ = Input::GetInstance();  // 入力できるように

    worldTransform_ = new WorldTransform();
    worldTransform_->Initialize();
}

void Player::Update() {
    if (input_->PushKey(DIK_W)) {
        worldTransform_->translation_.y -= moveSpeed_;
    }
    if (input_->PushKey(DIK_S)) {
        worldTransform_->translation_.y += moveSpeed_;
    }

    worldTransform_->UpdateMatrix();
}

void Player::Draw() {
    model_->Draw(*worldTransform_, *camera_, playerTextureHandle_);

}