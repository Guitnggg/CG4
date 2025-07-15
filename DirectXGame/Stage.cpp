#include "Stage.h"

using namespace KamataEngine;

Stage::Stage() {}

Stage::~Stage() {
    for (auto sprite : sprites_) {
        delete sprite;
    }
}

void Stage::Initialize() {
    textureHandle1_ = TextureManager::Load("./Resources/InGame/mori.png");
    textureHandle2_ = TextureManager::Load("./Resources/InGame/mori2.png");

    // 初期位置
    sprites_[0] = Sprite::Create(textureHandle1_, { 0.0f, 0.0f });
    sprites_[1] = Sprite::Create(textureHandle2_, { kScrollWidth, 0.0f });
    sprites_[2] = Sprite::Create(textureHandle1_, { kScrollWidth * 2, 0.0f });
    sprites_[3] = Sprite::Create(textureHandle2_, { kScrollWidth * 3, 0.0f });
}

void Stage::Update() {
    scrollx_ -= kScrollSpeed;  // 左へスクロール

    // 左側の画像が画面分左に移動したらループ
    if (scrollx_ <= -kScrollWidth * 2) {
        scrollx_ += kScrollWidth * 2;
    }

    // 各スプライトの位置を更新（ループスクロール）
    for (int i = 0; i < 4; ++i) {
        sprites_[i]->SetPosition({ scrollx_ + i * kScrollWidth, 0.0f });
    }
}

void Stage::Draw() {
    for (auto sprite : sprites_) {
        sprite->Draw();
    }
}