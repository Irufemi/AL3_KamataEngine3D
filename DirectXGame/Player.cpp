#include "Player.h"

#include <cassert>

using namespace KamataEngine;

// コンストラクタ
Player::Player() {}

// デストラクタ
Player::~Player() {}

// 初期化
void Player::Initialize(Model* model, uint32_t textureHnadle, KamataEngine::Camera* camera) {
	// NULLポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する

	// モデル
	model_ = model;

	// テクスチャハンドル
	textureHandle_ = textureHnadle;

	// カメラ
	camera_ = camera;

	// ワールド変換の初期化
	worldTransform_.Initialize();
}

// 更新
void Player::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

// 描画
void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *camera_, textureHandle_);

}