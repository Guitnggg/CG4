#pragma once

#include <KamataEngine.h>

#include "IScene.h"
#include "GameScene.h"

class TitleScene : public IScene {
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~TitleScene();

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
    /// GameSceneへのシーン変遷
    /// </summary>
    bool IsEnd()const override { return isEnd_; }
    IScene* NextScene()const override { return new GameScene(); }

    SceneName GetSceneName() const override { return SceneName::Title; }  // シーン名

private:

    KamataEngine::DirectXCommon* dxCommon_ = nullptr;
    KamataEngine::Input* input_ = nullptr;
    KamataEngine::WorldTransform* worldTransform_;
    KamataEngine::Camera* camera_;

    KamataEngine::Model* model_ = nullptr;

    // 各テクスチャ
    uint32_t BackgroundTextureHandle_ = 0;
    KamataEngine::Sprite* BackgroundSprite_ = nullptr;
    uint32_t TitleTextureHandle_ = 0;
    KamataEngine::Sprite* TitleSprite_ = nullptr;
    uint32_t StartTextureHandle_ = 0;
    KamataEngine::Sprite* StartSprite_ = nullptr;

    // 終了フラグ
    bool isEnd_ = false;

    // スタート点滅用
    float blinkTimer_ = 0.0f;
    float blinkInterval_ = 1.0f;

    // タイトル移動用
    KamataEngine::Vector2 titlePosition_ = { 110.0f,-500.0f };       // 初期位置
    KamataEngine::Vector2 titleTargetPosition_ = { 110.0f,150.0f };  // ゴール位置
    float titleFallSpeed_ = 3.0f;       // 移動速度
    bool isTitleFallFinished_ = false;  // 移動終了判定
};

