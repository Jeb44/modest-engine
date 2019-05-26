//Vector3.cpp
#include "math/Vector3.h"

Vector3::Vector3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3::Vector3(F32 x, F32 y, F32 z){
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3::~Vector3() {}

Vector3& Vector3::operator+=(const Vector3& rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	return *this;
}

Vector3 operator+(Vector3 lhs, const Vector3& rhs){
	lhs += rhs;
	return lhs;
}

Vector3& Vector3::operator +=(const F32 scalar){
	this->x += scalar;
	this->y += scalar;
	this->z += scalar;
	return *this;
}
Vector3 operator +(Vector3 lhs, const F32 scalar){
	lhs += scalar;
	return lhs;
}
	
Vector3& Vector3::operator-=(const Vector3& rhs){
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;
}

Vector3 operator-(Vector3 lhs, const Vector3& rhs){
	lhs -= rhs;
	return lhs;
}

Vector3& Vector3::operator -=(const F32 scalar){
	this->x -= scalar;
	this->y -= scalar;
	this->z -= scalar;
	return *this;
}
Vector3 operator -(Vector3 lhs, const F32 scalar){
	lhs -= scalar;
	return lhs;
}

Vector3& Vector3::operator *=(const F32 scalar){
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	return *this;
}
Vector3 operator *(Vector3 lhs, const F32 scalar){
	lhs *= scalar;
	return lhs;
}

bool operator ==(const Vector3& lhs, const Vector3& rhs){
	if(lhs.x != rhs.x)
		return false;
	if(lhs.y != rhs.y)
		return false;
	if(lhs.z != rhs.z)
		return false;
	
	return true;
}
bool operator !=(const Vector3& lhs, const Vector3& rhs){
	if(lhs.x == rhs.x)
		return false;
	if(lhs.y == rhs.y)
		return false;
	if(lhs.z == rhs.z)
		return false;
	
	return true;
}

Vector3 Vector3::negate(const Vector3& v){
	return v * -1.0f;
}

Vector3 Vector3::negate(){
	return *this *= -1.0f;
}

F32 Vector3::magnitude(const Vector3& v){
	return sqrt(v.x * v.x + 
				v.y * v.y + 
				v.z * v.z);
}
F32 Vector3::magnitude(){
	return sqrt(this->x * this->x + 
				this->y * this->y + 
				this->z * this->z);
}

F32 Vector3::squareMagnitude(const Vector3& v){
	return v.x * v.x + 
			v.y * v.y + 
			v.z * v.z;
}

F32 Vector3::squareMagnitude(){
	return this->x * this->x + 
			this->y * this->y + 
			this->z * this->z;
}

Vector3 Vector3::normalize(Vector3& v){
	return  v *= (1 / v.magnitude());
}

Vector3 Vector3::normalize(){
	return *this *= (1 / this->magnitude());
}

F32 Vector3::dot(const Vector3& lhs, const Vector3& rhs){
	return lhs.x * rhs.x + 
			lhs.y * rhs.y +
			lhs.z * rhs.z;
}

F32 Vector3::dot(const Vector3& rhs){
	return this->x * rhs.x + 
			this->y * rhs.y +
			this->z * rhs.z;
}



Vector3 Vector3::right(){
	return Vector3(1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::up(){
	return Vector3(0.0f, 1.0f, 0.0f);
}

Vector3 Vector3::forward(){
	return Vector3(0.0f, 0.0f, 1.0f);
}

std::string Vector3::toString(const Vector3& v){
	return "(" + StringHelper::floatToString(v.x)
		+ ", " + StringHelper::floatToString(v.y)
		+ ", " + StringHelper::floatToString(v.z) + ")";
}

std::string Vector3::toString(){
	return "(" + StringHelper::floatToString(this->x)
		+ ", " + StringHelper::floatToString(this->y)
		+ ", " + StringHelper::floatToString(this->z) + ")";
}
