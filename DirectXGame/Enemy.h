#pragma once

#include <3d/WorldTransform.h>
#include <3d/Model.h>
#include <3d/Camera.h>
#include <math/Vector3.h>

class Enemy {
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    Enemy();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Enemy();

    /// <summary>
    /// 初期化処理
    /// </summary>
    void Initialize(KamataEngine::Camera* camera);

    /// <summary>
    /// 更新処理
    /// </summary>
    void Update();

    /// <summary>
    /// 描画処理
    /// </summary>
    void Draw();

    /// <summary>
    /// 画面外に出たかどうか
    /// </summary>
    bool IsOutOfScreen() const;

public:

    /// <summary>
    /// Getter
    /// </summary>
    const KamataEngine::Vector3& GetPosition() const { return worldTransform_.translation_; }

private:

    KamataEngine::WorldTransform worldTransform_;
    KamataEngine::Model* model_ = nullptr;
    KamataEngine::Camera* camera_ = nullptr;

    float speed_ = 0.5f;
};

