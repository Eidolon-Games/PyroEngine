#include "PyroEnginePCH.h"
#include "MathF.h"

namespace PyroEngine
{
	void MathF::ResetVector2(float* dst)
	{
		dst[0] = 0.0f;
		dst[1] = 0.0f;
	}

	void MathF::ResetVector3(float* dst)
	{
		dst[0] = 0.0f;
		dst[1] = 0.0f;
		dst[2] = 0.0f;
	}

	void MathF::ResetVector4(float* dst)
	{
		dst[0] = 0.0f;
		dst[1] = 0.0f;
		dst[2] = 0.0f;
		dst[3] = 0.0f;
	}

	void MathF::AddVector2(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
	}

	void MathF::AddVector3(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
	}

	void MathF::AddVector4(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] + vec2[0];
		dst[1] = vec1[1] + vec2[1];
		dst[2] = vec1[2] + vec2[2];
		dst[3] = vec1[3] + vec2[3];
	}

	void MathF::SubVector2(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
	}

	void MathF::SubVector3(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
	}

	void MathF::SubVector4(float* dst, float* vec1, float* vec2)
	{
		dst[0] = vec1[0] - vec2[0];
		dst[1] = vec1[1] - vec2[1];
		dst[2] = vec1[2] - vec2[2];
		dst[3] = vec1[3] - vec2[3];
	}

	float MathF::DotVector2(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		return xSq + ySq;
	}

	float MathF::DotVector3(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		float zSq = vec1[2] * vec2[2];
		return xSq + ySq + zSq;
	}

	float MathF::DotVector4(float* vec1, float* vec2)
	{
		float xSq = vec1[0] * vec2[0];
		float ySq = vec1[1] * vec2[1];
		float zSq = vec1[2] * vec2[2];
		float wSq = vec1[3] * vec2[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF::SqMagnitudeVector2(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		return xSq + ySq;
	}

	float MathF::SqMagnitudeVector3(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		return xSq + ySq + zSq;
	}

	float MathF::SqMagnitudeVector4(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		float wSq = vec1[3] * vec1[3];
		return xSq + ySq + zSq + wSq;
	}

	float MathF::MagnitudeVector2(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		return std::sqrt(xSq + ySq);
	}

	float MathF::MagnitudeVector3(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		return std::sqrt(xSq + ySq + zSq);
	}

	float MathF::MagnitudeVector4(float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		float wSq = vec1[3] * vec1[3];
		return std::sqrt(xSq + ySq + zSq + wSq);
	}

	void MathF::NormaliseVector2(float* dst, float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float mag = std::sqrt(xSq + ySq);
		dst[0] = vec1[0] / mag;
		dst[1] = vec1[1] / mag;
	}

	void MathF::NormaliseVector3(float* dst, float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		float mag = std::sqrt(xSq + ySq + zSq);
		dst[0] = vec1[0] / mag;
		dst[1] = vec1[1] / mag;
		dst[2] = vec1[2] / mag;
	}

	void MathF::NormaliseVector4(float* dst, float* vec1)
	{
		float xSq = vec1[0] * vec1[0];
		float ySq = vec1[1] * vec1[1];
		float zSq = vec1[2] * vec1[2];
		float wSq = vec1[3] * vec1[3];
		float mag = std::sqrt(xSq + ySq + zSq + wSq);
		dst[0] = vec1[0] / mag;
		dst[1] = vec1[1] / mag;
		dst[2] = vec1[2] / mag;
		dst[3] = vec1[3] / mag;
	}
}