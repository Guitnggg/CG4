#pragma once

#include <KamataEngine.h>

#include "IScene.h"
#include "Model2.h"


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

    //　終了フラグ
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

};

