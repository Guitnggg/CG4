#pragma once

#include <3d/WorldTransform.h>
#include <3d/Model.h>
#include <3d/Camera.h>
#include <input/Input.h>

class Player{
public:

    /// <summary>
    /// インストラクタ
    /// </summary>
    Player();

    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Player();

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
    /// HPを減らす
    /// </summary>
    void TakeDamage(int amount);

    /// <summary>
    /// 現在のHPを取得
    /// </summary>
    int GetHP() const { return currentHP_; }

    /// <summary>
    /// 死亡しているかどうか
    /// </summary>
    bool IsDead() const { return currentHP_ <= 0; }

private:

    KamataEngine::WorldTransform* worldTransform_;
    KamataEngine::Camera* camera_;
    KamataEngine::Model* model_ = nullptr;
    KamataEngine::Input* input_ = nullptr;

    uint32_t textureHandle_ = 0u;

    float moveSpeed_ = 0.5f;

    int maxHP_ = 100;
    int currentHP_ = 100;
};

