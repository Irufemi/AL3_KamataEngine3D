#include <Windows.h>

/*01_01 KAMATA ENGINE*/

#include "KamataEngine.h"

#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	/*01_01 KAMATA ENGINE*/

	/// 初期化処理

	// エンジンの初期化
	KamataEngine::Initialize(L"LE1B_1_スエヒロ_コウイチ_AL3");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Initialize();

	/*01_01 KAMATA ENGINE*/

	/// メインループ

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw(); // 描画ターゲットの設定

		// ゲームシーンの描画
		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw(); // 描画コマンドを実行する
	}

	/*01_01 KAMATA ENGINE*/

	/// 解放処理

	// ゲームシーンの解放
	delete gameScene;
	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
