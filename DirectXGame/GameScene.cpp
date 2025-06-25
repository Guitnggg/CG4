#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene()
{
	delete worldTransform_;
	delete camera_;

	Model2::StaticFinalize();
	delete model_;
	
}

void GameScene::Initialize()
{
    dxCommon_ = DirectXCommon::GetInstance();

    worldTransform_ = new WorldTransform();
    worldTransform_->Initialize();

    camera_ = new Camera();
    camera_->Initialize();

	Model2::StaticInitialize();
    model_ = Model2::CreateFromOBJ("Cube", true);
    textureHandle_ = TextureManager::Load("./Resources/uvChecker.png");
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model2::PreDraw(dxCommon_->GetCommandList());

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	model_->Draw(*worldTransform_, *camera_, textureHandle_);

	// 3Dオブジェクト描画後処理
	Model2::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
