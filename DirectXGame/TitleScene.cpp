#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene(){
	delete BackgroundSprite_;
	delete TitleSprite_;
	delete StartSprite_;
}

void TitleScene::Initialize(){
	dxCommon_ = DirectXCommon::GetInstance();
    
	BackgroundTextureHandle_ = TextureManager::Load("./Resources/title/Wood.png");
	BackgroundSprite_ = Sprite::Create(BackgroundTextureHandle_, { 0.0f,0.0f });

	TitleTextureHandle_ = TextureManager::Load("./Resources/title/GameTitle.png");
	TitleSprite_ = Sprite::Create(TitleTextureHandle_, { 0.0f,0.0f });

	StartTextureHandle_ = TextureManager::Load("./Resources/title/Start.png");
	StartSprite_ = Sprite::Create(StartTextureHandle_, { 150.0f,550.0f });
}

void TitleScene::Update(){

    // 入力を受け付けるようにする
    input_ = Input::GetInstance();

    if (input_->PushKey(DIK_SPACE)) {  // シーン変遷の条件を書く
        isEnd_ = true;
    }
}

void TitleScene::Draw(){
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	BackgroundSprite_->Draw();
	TitleSprite_->Draw();
	StartSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion
}