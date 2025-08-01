#pragma once

#include <KamataEngine.h>
#include <vector>
#include <list>

#include "Stage.h"
#include "Model2.h"
#include "Player.h"
#include "Graph.h"
#include "Score.h"
#include "Enemy.h"
#include "Particle.h"

#include "IScene.h"
class FinishScene;

class GameScene : public IScene {
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

public:

    /// <summary>
    /// シーン変遷
    /// </summary>    
    bool IsEnd() const override { return isEnd_; }  // シーン終了フラグ
    IScene* NextScene() const override;             // 次のシーンを返す

    SceneName GetSceneName() const override { return SceneName::InGame; }  // シーン名

private:

    KamataEngine::DirectXCommon* dxCommon_ = nullptr;  // DirectX関連
    KamataEngine::WorldTransform* worldTransform_;     // ワールド変換
    KamataEngine::Camera* camera_;                     // カメラ

    // モデル
    KamataEngine::Model2* model_ = nullptr;
    uint32_t textureHandle_;

    // ステージ
    Stage* stage_ = nullptr;

    // Player
    Player* player_ = nullptr;

    // Enemy
    std::vector<Enemy*>enemies_;
    float enemySpawnTimer_ = 0.0f;

    // particle
    KamataEngine::Model* particleModel_ = nullptr;
    std::list<Particle*> particles_;

    // 2Dグラフ
    Graph* graph_ = nullptr;
    float timer_ = 1.0f;

    // スコア
    Score* score_ = nullptr;

    // シーン終了フラグ
    bool isEnd_ = false;

};

