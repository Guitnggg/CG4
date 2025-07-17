#pragma once

#include <KamataEngine.h>

#include "Stage.h"
#include "Model2.h"
#include "Player.h"
#include "Graph.h"
#include "Score.h"

#include "IScene.h"

class FinishScene;

class GameScene : public IScene{
public:

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameScene();
   
    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize()override;

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update()override;

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw()override;

    /// <summary>
    /// シーン終了フラグ
    /// </summary>
    bool isEnd_ = false;

public:

    /// <summary>
    /// シーン変遷
    /// </summary>    
    bool IsEnd() const override { return isEnd_; }
    IScene* NextScene() const override;

    SceneName GetSceneName() const override { return SceneName::InGame; }  // シーン名

private:

    KamataEngine::DirectXCommon* dxCommon_ = nullptr;
    KamataEngine::WorldTransform* worldTransform_;
    KamataEngine::Camera* camera_;

    // モデル
    KamataEngine::Model2* model_ = nullptr;
    uint32_t textureHandle_;

    // ステージ
    Stage* stage_ = nullptr;

    // Player
    Player* player_ = nullptr;

    // 2Dグラフ
    Graph* graph_ = nullptr;

    // スコア
    Score* score_ = nullptr;
};

