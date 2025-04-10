#pragma once

#include "KamataEngine.h"

namespace KamataEngine {

/// <summary>
/// 
/// </summary>
/// <param name="m1"></param>
/// <param name="m2"></param>
/// <returns></returns>
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

/// <summary>
/// 4x4 X軸周り回転行列の作成関数
/// </summary>
/// <param name="theta">Xを軸にした回転角度</param>
/// <returns></returns>
Matrix4x4 MakeRotateXMatrix(const float& theta);

/// <summary>
/// 4x4 Y軸周り回転行列の作成関数
/// </summary>
/// <param name="theta">Yを軸にした回転角度</param>
/// <returns></returns>
Matrix4x4 MakeRotateYMatrix(const float& theta);

/// <summary>
/// 4x4 Z軸周り回転行列の作成関数
/// </summary>
/// <param name="theta">Zを軸にした回転角度</param>
/// <returns></returns>
Matrix4x4 MakeRotateZMatrix(const float& theta);

/// <summary>
/// 3次元回転行列の作成関数
/// </summary>
/// <param name="thetaX">Xを軸にした回転角度</param>
/// <param name="thetaY">Yを軸にした回転角度</param>
/// <param name="thetaZ">Zを軸にした回転角度</param>
/// <returns></returns>
Matrix4x4 MakeRotateXYZMatrix(const float& thetaX, const float& thetaY, const float& thetaZ);

/// <summary>
/// 4x4アフィン変換行列を高速に生成する
/// </summary>
/// <param name="scale">大きさ。倍率。</param>
/// <param name="rotate">角度</param>
/// <param name="translate">位置。座標。</param>
/// <returns></returns>
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

} // namespace KamataEngine
