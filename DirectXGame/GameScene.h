#pragma once

#include <KamataEngine.h>

#include "IScene.h"
#include "Stage.h"
#include "Model2.h"
#include "Player.h"
#include "Graph.h"
#include "Score.h"


class GameScene : public IScene
{
public:

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameScene();
   
    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// シーン終了フラグ
    /// </summary>
    bool isEnd_ = false;

public:

    /// <summary>
    /// シーン変遷
    /// </summary>    
    bool IsEnd() const override { return isEnd_; }
    IScene* NextScene() const override { return nullptr; }  // 一旦ゲームが終了するようになっている

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

