#pragma once
#include "KamataEngine.h"

#include "Player.h"

// ゲームシーン
class GameScene {

private:
	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// 3Dモデルデータ
	KamataEngine::Model* model_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;

	//自キャラ
	Player* player_ = nullptr;

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
