#include <Windows.h>
#include <KamataEngine.h>

#include "TitleScene.h"
#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
    // KamataEngineの初期化
    KamataEngine::Initialize(L"LE3C_14_タカキ_ケンゴ");

    // DirectXCommonのインスタンスの取得
    DirectXCommon* dxCommon = DirectXCommon::GetInstance();

    /// 各シーン初期化 ///
    // TitleScene
    TitleScene* titleScene = new TitleScene();  // インスタンス生成
    titleScene->Initialize();                   // 初期化
    
    // GameScene
    GameScene* gameScene = new GameScene();  // インスタンス生成
    gameScene->Initialize();                 // 初期化

    //===============
    // Mainループ
    //===============
    while (true) {

        // エンジンの更新
        if (KamataEngine::Update()) {
            break;
        }

        //=============
        // 更新処理
        //=============

        titleScene->Update();  // TitleScene
        gameScene->Update();   // GameScene

        //=============
        // 描画処理 
        //=============

        // 描画処理開始       
        dxCommon->PreDraw();

        titleScene->Draw();  // TitleScene 
        gameScene->Draw();   // GameScene

        //描画処理終了       
        dxCommon->PostDraw();
    }

    /// 各シーン解放
    // TitleScene
    delete titleScene;
    titleScene = nullptr;

    // GameScene
    delete gameScene;
    gameScene = nullptr;


    // KamataEngineの終了 
    KamataEngine::Finalize();

    return 0;
}
