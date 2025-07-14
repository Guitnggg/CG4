#include "Stage.h"

using namespace KamataEngine;

Stage::Stage() {}

Stage::~Stage() {
    delete bgSprite1_;
    delete bgSprite2_;
}

void Stage::Initialize() {
    textureHandle_ = TextureManager::Load();

    // 初期位置
    bgSprite1_ = Sprite::Create(textureHandle_, { 0.0f,0.0f, });
    bgSprite2_ = Sprite::Create(textureHandle_, { kScrollWidth,0.0f });
}

void Stage::Update() {
    scrollx_ -= kScrollSpeed;  // 左へスクロール

    // 左側の画像が画面分左に移動したらループ
    if (scrollx_ <= -kScrollWidth) {
        scrollx_ += kScrollWidth;
    }

    // ２枚のスプライトを更新
    bgSprite1_->SetPosition({ scrollx_,0.0f });
    bgSprite2_->SetPosition({ scrollx_ + kScrollWidth,0.0f });
}

void Stage::Draw() {
    bgSprite1_->Draw();
    bgSprite2_->Draw();
}