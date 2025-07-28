#pragma once

#include <KamataEngine.h>

#include "IScene.h"
class TitleScene;

class FinishScene : public IScene {
public:

    /// <summary>
    /// インストラクタ
    /// </summary>
    FinishScene();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FinishScene();

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

    SceneName GetSceneName() const override { return SceneName::Finish; }  // シーン名

private:

    KamataEngine::Input* input_ = nullptr;  // 入力関連

    bool isEnd_ = false;  // シーン終了フラグ
};

