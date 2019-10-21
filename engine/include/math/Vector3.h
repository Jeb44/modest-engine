//Vector3.h
#pragma once

#include <string>
#include <math.h>

#include "common/typedef.h"
#include "common/assert.h"
#include "common/Helper.h"

// Add F64 support (see how Matthias handled it)

class Vector3 {
public:
	explicit Vector3();
	explicit Vector3(F32 scalar);
	explicit Vector3(F32 x, F32 y, F32 z);
	virtual ~Vector3();

	F32 x, y, z;
	// x -> pos values: go "right"
	// y -> pos values: go "up"
	// z -> pos values: go "forward" (meaning away from camera)
	
	// Addition by vector
	Vector3& operator +=(const Vector3& rhs);
	friend Vector3 operator +(Vector3 lhs, const Vector3& rhs);
	
	// Addition by scalar
	Vector3& operator +=(const F32 scalar);
	friend Vector3 operator +(Vector3 lhs, const F32 scalar);

	// Subtraction by vector
	Vector3& operator -=(const Vector3& rhs);
	friend Vector3 operator -(Vector3 lhs, const Vector3& rhs);
	
	// Subtraction by scalar
	Vector3& operator -=(const F32 scalar);
	friend Vector3 operator -(Vector3 lhs, const F32 scalar);

	// Muliplication by scalar
	Vector3& operator *=(const F32 scalar);
	friend Vector3 operator *(Vector3 lhs, const F32 scalar);

	// Comparison
	friend bool operator ==(const Vector3& lhs, const Vector3& rhs);
	friend bool operator !=(const Vector3& lhs, const Vector3& rhs);

	// Vector functions
	// use "normal" variants to change your current vector
	// use static variants to return a new vector
	static Vector3 negate(const Vector3& v);
	Vector3 negate();
	static F32 magnitude(const Vector3& v);
	F32 magnitude();
	static F32 squareMagnitude(const Vector3& v);
	F32 squareMagnitude();
	static Vector3 normalize(Vector3& v);
	Vector3 normalize();
	static F32 dot(const Vector3& lhs, const Vector3& rhs);
	F32 dot(const Vector3& rhs);
	static Vector3 cross(const Vector3& lhs, const Vector3& rhs);
	Vector3 cross(const Vector3& rhs);
	static Vector3 project(const Vector3& lhs, const Vector3& rhs);
	Vector3 project(const Vector3& rhs);
	static Vector3 lerp(const Vector3& lhs, const Vector3& rhs, const F32 t);
	Vector3 lerp(const Vector3& rhs, const F32 t);

	// Static functions for directions
	static Vector3 right();
	static Vector3 up();
	static Vector3 forward();

	// Other Functions
	static std::string toString(const Vector3& v);
	std::string toString();

};

// komponentenprodukt (lhs.x * rhs.x, ..., ...)
// orthonormalbasis (Alg. s. GPH script)