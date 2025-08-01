#include "FinishScene.h"

#include "TitleScene.h"

using namespace KamataEngine;

FinishScene::FinishScene() {}

FinishScene::~FinishScene() {
}

void FinishScene::Initialize() {
    dxCommon_ = DirectXCommon::GetInstance();

    BackgroundTextureHandle_ = TextureManager::Load("./Resources/title/Wood.png");
    BackgroundSprite_ = Sprite::Create(BackgroundTextureHandle_, { 0.0f,0.0f });
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
    // コマンドリストの取得
    ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
    // 背景スプライト描画前処理
    Sprite::PreDraw(commandList);

    /// <summary>
    /// ここに背景スプライトの描画処理を追加できる
    /// </summary>

    BackgroundSprite_->Draw();
  
    // スプライト描画後処理
    Sprite::PostDraw();

    // 深度バッファクリア
    dxCommon_->ClearDepthBuffer();
#pragma endregion
}

IScene* FinishScene::NextScene() const {
    return new TitleScene();
}
