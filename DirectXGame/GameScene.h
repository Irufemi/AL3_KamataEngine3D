#pragma once
#include "KamataEngine.h"

// #include "DebugCamera.h"

//ゲームシーン
class GameScene {

private:

    //テクスチャハンドル
	uint32_t textureHandle_ = 0;

    //スプライト
	KamataEngine::Sprite* sprite_ = nullptr;

    //3Dモデル
	KamataEngine::Model* model_ = nullptr;

    //ワールドトランスフォーム
	KamataEngine::WorldTransform worldTransform_;

    //カメラ
	KamataEngine::Camera camera_;

    //サウンドデータハンドル
	uint32_t soundDataHandle_ = 0;

    //音声再生ハンドル
	uint32_t voiceHandle_ = 0;

    //ImGuiで値を入力する変数
	float inputFloat3[3] = {0, 0, 0};

    //デバッグカメラ
	KamataEngine::DebugCamera* debugCamera_ = nullptr;


public:
    //コンストラクタ
	GameScene();

    //デストラクタ
	~GameScene();

    //初期化
	void Initialize();

    //更新
	void Update();

    //描画
	void Draw();


};
