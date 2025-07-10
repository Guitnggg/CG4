#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene(){

}

void TitleScene::Initialize(){
    
}

void TitleScene::Update(){

    // 入力を受け付けるようにする
    input_ = Input::GetInstance();

    if (input_->PushKey(DIK_SPACE)) {  // シーン変遷の条件を書く
        isEnd_ = true;
    }
}

void TitleScene::Draw(){

}