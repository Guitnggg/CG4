#include "Score.h"

using namespace KamataEngine;

Score::Score() {}

Score::~Score() {
    for (int i = 0; i < kDigitCount; i++) {
        delete sprite_[i];
    }
}

void Score::Initialize() {
    textureHandle_ = TextureManager::Load("./Resources/InGame/number.png");

    float screenWidth = static_cast<float>(KamataEngine::DirectXCommon::GetInstance()->GetBackBufferWidth());
    startX = screenWidth - (size_.x * kDigitCount) - 10.0f;
    
    for (int i = 0; i < kDigitCount; ++i) {
        sprite_[i] = Sprite::Create(textureHandle_, { startX + size_.x * i, startY });
        sprite_[i]->SetSize(size_);
    }
}

void Score::Update() {
    int32_t number = score_;
    int32_t digit = 10000;

    for (int i = 0; i < kDigitCount; ++i) {
        int nowNumber = number / digit;
        number = number % digit;
        digit /= 10;

        sprite_[i]->SetTextureRect({ size_.x * nowNumber, 0 }, size_);
    }
}

void Score::Draw() {
     for (int i = 0; i < kDigitCount; ++i) {
        sprite_[i]->Draw();
    }

}