#pragma once

#include <KamataEngine.h>

#include "IScene.h"
class TitleScene;

class FinishScene : public IScene {
public:

    /// <summary>
    /// 
    /// </summary>
    FinishScene();

    /// <summary>
    /// 
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
    bool IsEnd() const override { return isEnd_; }
    IScene* NextScene() const override;

    SceneName GetSceneName() const override { return SceneName::Finish; }

private:

    KamataEngine::Input* input_ = nullptr;

    bool isEnd_ = false;
};

