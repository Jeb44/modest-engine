//Vector3.cpp
#include "math/Vector3.h"

Vector3::Vector3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Vector3::Vector3(F32 scalar){
	this->x = scalar;
	this->y = scalar;
	this->z = scalar;
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
	F32 magnitude = v.magnitude();
	ASSERT(magnitude > 0);
	return  v *= (1 / v.magnitude());
}

Vector3 Vector3::normalize(){
	F32 magnitude = this->magnitude();
	ASSERT(magnitude > 0);
	return *this *= (1 / magnitude);
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

Vector3 Vector3::cross(const Vector3& lhs, const Vector3& rhs) {
	return Vector3(
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
	);
}

Vector3 Vector3::cross(const Vector3& rhs) {
	return Vector3(
		this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x
	);
}

Vector3 Vector3::project(const Vector3& lhs, const Vector3& rhs) {
	return Vector3(lhs * (dot(lhs, rhs) / squareMagnitude(lhs)));
}

Vector3 Vector3::project(const Vector3& rhs) {
	float s = this->dot(rhs) / this->squareMagnitude();
	return *this * s;
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
	return "(" + Helper::toString(v.x)
		+ ", " + Helper::toString(v.y)
		+ ", " + Helper::toString(v.z) + ")";
}

std::string Vector3::toString(){
	return "(" + Helper::toString(this->x)
		+ ", " + Helper::toString(this->y)
		+ ", " + Helper::toString(this->z) + ")";
}
