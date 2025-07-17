#include "GameScene.h"

#include "FinishScene.h"

using namespace KamataEngine;

GameScene::~GameScene(){
	delete worldTransform_;
	delete camera_;

	Model2::StaticFinalize();
	delete model_;	

	delete stage_;
	delete player_;
	delete graph_;
	delete score_;
}

void GameScene::Initialize(){
    dxCommon_ = DirectXCommon::GetInstance();

    worldTransform_ = new WorldTransform();
    worldTransform_->Initialize();

    camera_ = new Camera();
    camera_->Initialize();

	/// ステージ ///
	stage_ = new Stage();
	stage_->Initialize();

	/// Player ///
	player_ = new Player();
	player_->Initialize(camera_);

	/// 2Dグラフ ///
	graph_ = new Graph();
	graph_->Initialize();

	/// スコア ///
	score_ = new Score();
	score_->Initialize();
}

void GameScene::Update(){
	/// ステージ ///
	stage_->Update();

	/// 2Dグラフ ///
	static float timer = 1.0f;
	timer -= 0.001f;
	graph_->SetValue(timer);  // 時間で減っていくように
	graph_->Update();

	// シーン変遷
	if (timer <= 0.0f) {
		isEnd_ = true;
	}

	/// スコア ///
	score_->Update();
}

void GameScene::Draw(){
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	/// ステージ ///
	stage_->Draw();

	/// Player ///
	player_->Update();

	// スプライト描画後処理
	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(dxCommon_->GetCommandList());

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	/// Player ///
	player_->Draw();

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	/// 2Dグラフ ///
	graph_->Draw();

	/// スコア ///
	score_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

IScene* GameScene::NextScene() const{
	return new FinishScene();
}
