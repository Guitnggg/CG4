#pragma once

#include <KamataEngine.h>

class TitleScene
{
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
    void Initialize();

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

private:

    KamataEngine::WorldTransform* worldTransform_;
    KamataEngine::Camera* camera_;
    KamataEngine::Model* model_ = nullptr;
};

