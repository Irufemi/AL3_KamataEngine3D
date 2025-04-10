#pragma once
#include "KamataEngine.h"

#include "Player.h"

#include <vector>

// ゲームシーン
class GameScene {

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// 3Dモデルデータ(player)
	KamataEngine::Model* modelPlayer_ = nullptr;

	//3Dモデルデータ(ブロック)
	KamataEngine::Model* modelBlock_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	//自キャラ
	Player* player_ = nullptr;

	//ブロック用のワールドトランスフォーム(可変個配列)
	std::vector < std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

	//デバッグカメラ有効
	bool isDebugCameraActive_ = false;

	//デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

public:
	// コンストラクタ
	GameScene();

	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();
};
