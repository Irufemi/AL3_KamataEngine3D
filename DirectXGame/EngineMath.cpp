#include "EngineMath.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

namespace KamataEngine {

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	struct Matrix4x4 multiplyResult = {0};
	multiplyResult.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];
	multiplyResult.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];
	multiplyResult.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];
	multiplyResult.m[0][3] = m1.m[1][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];
	multiplyResult.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];
	multiplyResult.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];
	multiplyResult.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];
	multiplyResult.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];
	multiplyResult.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];
	multiplyResult.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];
	multiplyResult.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];
	multiplyResult.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];
	multiplyResult.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];
	multiplyResult.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];
	multiplyResult.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];
	multiplyResult.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];
	return multiplyResult;
}

Matrix4x4 MakeRotateXMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = 1.0f;
	matrix.m[0][1] = 0.0f;
	matrix.m[0][2] = 0.0f;
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = 0.0f;
	matrix.m[1][1] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][2] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = 0.0f;
	matrix.m[2][1] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][2] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

Matrix4x4 MakeRotateYMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][1] = 0.0f;
	matrix.m[0][2] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = 0.0f;
	matrix.m[1][1] = 1.0f;
	matrix.m[1][2] = 0.0f;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][1] = 0.0f;
	matrix.m[2][2] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

Matrix4x4 MakeRotateZMatrix(const float& theta) {
	static Matrix4x4 matrix;
	matrix.m[0][0] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][1] = std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[0][2] = 0.0f;
	matrix.m[0][3] = 0.0f;
	matrix.m[1][0] = -std::sin(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][1] = std::cos(theta * static_cast<float>(M_PI) / 180.0f);
	matrix.m[1][2] = 0.0f;
	matrix.m[1][3] = 0.0f;
	matrix.m[2][0] = 0.0f;
	matrix.m[2][1] = 0.0f;
	matrix.m[2][2] = 1.0f;
	matrix.m[2][3] = 0.0f;
	matrix.m[3][0] = 0.0f;
	matrix.m[3][1] = 0.0f;
	matrix.m[3][2] = 0.0f;
	matrix.m[3][3] = 1.0f;
	return matrix;
}

Matrix4x4 MakeRotateXYZMatrix(const float& thetaX, const float& thetaY, const float& thetaZ) {
	Matrix4x4 matrix = Multiply(MakeRotateXMatrix(thetaX), Multiply(MakeRotateYMatrix(thetaY), MakeRotateZMatrix(thetaZ)));
	return matrix;
}

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 rotateMatrix = MakeRotateXYZMatrix(rotate.x, rotate.y, rotate.z);
	static Matrix4x4 affineMatrix;
	affineMatrix.m[0][0] = scale.x * rotateMatrix.m[0][0];
	affineMatrix.m[0][1] = scale.x * rotateMatrix.m[0][1];
	affineMatrix.m[0][2] = scale.x * rotateMatrix.m[0][2];
	affineMatrix.m[0][3] = 0.0f;
	affineMatrix.m[1][0] = scale.y * rotateMatrix.m[1][0];
	affineMatrix.m[1][1] = scale.y * rotateMatrix.m[1][1];
	affineMatrix.m[1][2] = scale.y * rotateMatrix.m[1][2];
	affineMatrix.m[1][3] = 0.0f;
	affineMatrix.m[2][0] = scale.z * rotateMatrix.m[2][0];
	affineMatrix.m[2][1] = scale.z * rotateMatrix.m[2][1];
	affineMatrix.m[2][2] = scale.z * rotateMatrix.m[2][2];
	affineMatrix.m[2][3] = 0.0f;
	affineMatrix.m[3][0] = translate.x;
	affineMatrix.m[3][1] = translate.y;
	affineMatrix.m[3][2] = translate.z;
	affineMatrix.m[3][3] = 1.0f;
	return affineMatrix;
}

} // namespace KamataEngine
