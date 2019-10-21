// Vector2.h
#pragma once

#include <string>
#include <math.h>

#include "common/typedef.h"
#include "common/assert.h"
#include "common/Helper.h"

#include "MathUtilities.h"

class Vector2 {
public:	
	explicit Vector2();
	explicit Vector2(F32 scalar);
	explicit Vector2(F32 x, F32 y);
	virtual ~Vector2();

	F32 x, y;
	// x -> pos values: go "right"
	// y -> pos values: go "up"
	
	// Addition by vector
	Vector2& operator +=(const Vector2& rhs);
	friend Vector2 operator +(Vector2 lhs, const Vector2& rhs);
	
	// Addition by scalar
	Vector2& operator +=(const F32 scalar);
	friend Vector2 operator +(Vector2 lhs, const F32 scalar);

	// Subtraction by vector
	Vector2& operator -=(const Vector2& rhs);
	friend Vector2 operator -(Vector2 lhs, const Vector2& rhs);
	
	// Subtraction by scalar
	Vector2& operator -=(const F32 scalar);
	friend Vector2 operator -(Vector2 lhs, const F32 scalar);

	// Muliplication by scalar
	Vector2& operator *=(const F32 scalar);
	friend Vector2 operator *(Vector2 lhs, const F32 scalar);

	// Comparison
	friend bool operator ==(const Vector2& lhs, const Vector2& rhs);
	friend bool operator !=(const Vector2& lhs, const Vector2& rhs);
	
	// Vector functions
	// use "normal" variants to change your current vector
	// use static variants to return a new vector
	static Vector2 negate(const Vector2& v);
	Vector2 negate();
	static F32 magnitude(const Vector2& v);
	F32 magnitude();
	static F32 squareMagnitude(const Vector2& v);
	F32 squareMagnitude();
	static Vector2 normalize(Vector2& v);
	Vector2 normalize();
	static F32 dot(const Vector2& lhs, const Vector2& rhs);
	F32 dot(const Vector2& rhs);
	static Vector2 project(const Vector2& lhs, const Vector2& rhs);
	Vector2 project(const Vector2& rhs);
	static Vector2 lerp(const Vector2& lhs, const Vector2& rhs, const F32 t);
	Vector2 lerp(const Vector2& rhs, const F32 t);

	// Static functions for directions
	static Vector2 right();
	static Vector2 up();

	// Other Functions
	static std::string toString(const Vector2& v);
	std::string toString();
	
};