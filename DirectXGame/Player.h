#pragma once

#include <3d/WorldTransform.h>
#include <3d/Model.h>
#include <3d/Camera.h>
#include <input/Input.h>

class Player{

    /// <summary>
    /// インストラクタ
    /// </summary>
    Player();

    /// <summary>
    /// 
    /// </summary>
    ~Player();

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

    WorldTransform* worldTransform_;
    Camera* camera_;
    Model* model_ = nullptr;
    Input* input_ = nullptr;

    uint32_t playerTextureHandle_ = 0u;

};

