#include "FinishScene.h"

#include "TitleScene.h"

using namespace KamataEngine;

FinishScene::FinishScene() {}

FinishScene::~FinishScene() {
}

void FinishScene::Initialize() {
}

void FinishScene::Update() {
    // 入力を受け付けるようにする
    input_ = Input::GetInstance();

    /// シーン変遷 ///
    if (input_->PushKey(DIK_SPACE)) {  // シーン変遷の条件を書く
        isEnd_ = true;
    }
}

void FinishScene::Draw() {
}

IScene* FinishScene::NextScene() const {
    return new TitleScene();
}
