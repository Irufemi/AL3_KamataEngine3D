#include "GameScene.h"

// #include "ImGuiManager.h"

// #include "PrimitiveDrawer.h"

using namespace KamataEngine;

// コンストラクタ
GameScene::GameScene() {}

// デストラクタ
GameScene::~GameScene() {
	delete sprite_;
	delete model_;
	delete debugCamera_;
}

// 初期化
void GameScene::Initialize() {

	// ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("uvChecker.png");

	// スプライトインスタンスの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});

	// 3Dモデルの生成
	model_ = Model::Create();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	// カメラの初期化
	camera_.Initialize();

	// サウンドデータの読み込み
	soundDataHandle_ = Audio::GetInstance()->LoadWave("mokugyo.wav");

	// 音声再生
	//voiceHandle_ = Audio::GetInstance()->PlayWave(soundDataHandle_, true);

	// ライン描画が参照するカメラを指定する(アドレス渡し)
	PrimitiveDrawer::GetInstance()->SetCamera(&camera_);

	//デバッグカメラの生成
	debugCamera_ = new DebugCamera(
	    1280, // 画面横幅
	    720   // 画面縦幅
	);

	//軸方向の表示を有効にする
	AxisIndicator::GetInstance()->SetVisible(true);
	//縦軸方向表示が参照するビュープロジェクションを指定する(アドレス渡し)
	AxisIndicator::GetInstance()->SetTargetCamera(&debugCamera_->GetCamera());

}

// 更新
void GameScene::Update() {

	/*

	#ifdef _DEBUG

	// デバッグテキストの表示
	ImGui::Begin("Debug1");
	ImGui::Text("Suehiro Koichi %d.%d.%d", 2050, 12, 31);
	ImGui::End();

	ImGui::Begin("Debug2");
	// float3入力ボックス
	ImGui::InputFloat3("InputFloat3", inputFloat3);
	// float3スライダー
	ImGui::SliderFloat3("SliderFloat3", inputFloat3, 0.0f, 1.0f);
	ImGui::End();

	// でもウィンドウの表示を有効化
	ImGui::ShowDemoWindow();

#endif

	*/

	// スプライトの今の座標を取得
	Vector2 position = sprite_->GetPosition();
	// 座標を{ 2, 1 }移動
	position.x += 2.0f;
	position.y += 1.0f;
	// 移動した座標をスプライトに反映
	sprite_->SetPosition(position);

	//デバッグカメラの更新
	debugCamera_->Update();

}

// 描画
void GameScene::Draw() {

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	// 3Dモデル描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	// スプライトの描画
	// sprite_->Draw();

	// 3Dモデル描画
	model_->Draw(worldTransform_, debugCamera_->GetCamera(), textureHandle_);

	// ラインを描画する

	/*

	for (int i = 0; i <= 20; i++) {

	    PrimitiveDrawer::GetInstance()->DrawLine3d(
	        {0.5f * i - 0.5f * 10, -5.0f, 0.0f}, // 始点座標
	        {0.5f * i - 0.5f * 10, 5.0f, 0.0f},  // 終点座標
	        {1.0f, 0.0f, 0.0f, 1.0f}             // 色(RGBA)
	    );

	    PrimitiveDrawer::GetInstance()->DrawLine3d(
	        {-5.0f, 0.5f * i - 0.5f * 10, 0.0f},  // 始点座標
	        {5.0f, 0.5f * i - 0.5f * 10, 0.0f}, // 終点座標
	        {0.0f, 0.0f, 1.0f, 1.0f}             // 色(RGBA)
	    );
	}

	*/

	// スペースキーを押した瞬間
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		// 音声停止
		Audio::GetInstance()->StopWave(voiceHandle_);
	}

	// スプライト描画後処理
	Sprite::PostDraw();

	// 3Dモデル描画後処理
	Model::PostDraw();
}