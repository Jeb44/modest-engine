//Vector2.cpp
#include "math/Vector2.h"

Vector2::Vector2() {
	this->x = 0.0f;
	this->y = 0.0f;
}

Vector2::Vector2(F32 scalar){
	this->x = scalar;
	this->y = scalar;
}

Vector2::Vector2(F32 x, F32 y){
	this->x = x;
	this->y = y;
}
Vector2::~Vector2() {}

Vector2& Vector2::operator+=(const Vector2& rhs){
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

Vector2 operator+(Vector2 lhs, const Vector2& rhs){
	lhs += rhs;
	return lhs;
}

Vector2& Vector2::operator +=(const F32 scalar){
	this->x += scalar;
	this->y += scalar;
	return *this;
}
Vector2 operator +(Vector2 lhs, const F32 scalar){
	lhs += scalar;
	return lhs;
}
	
Vector2& Vector2::operator-=(const Vector2& rhs){
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

Vector2 operator-(Vector2 lhs, const Vector2& rhs){
	lhs -= rhs;
	return lhs;
}

Vector2& Vector2::operator -=(const F32 scalar){
	this->x -= scalar;
	this->y -= scalar;
	return *this;
}
Vector2 operator -(Vector2 lhs, const F32 scalar){
	lhs -= scalar;
	return lhs;
}

Vector2& Vector2::operator *=(const F32 scalar){
	this->x *= scalar;
	this->y *= scalar;
	return *this;
}
Vector2 operator *(Vector2 lhs, const F32 scalar){
	lhs *= scalar;
	return lhs;
}

bool operator ==(const Vector2& lhs, const Vector2& rhs){
	if(lhs.x != rhs.x)
		return false;
	if(lhs.y != rhs.y)
		return false;
	
	return true;
}
bool operator !=(const Vector2& lhs, const Vector2& rhs){
	if(lhs.x == rhs.x)
		return false;
	if(lhs.y == rhs.y)
		return false;
	
	return true;
}

Vector2 Vector2::negate(const Vector2& v){
	return v * -1.0f;
}

Vector2 Vector2::negate(){
	return *this *= -1.0f;
}

F32 Vector2::magnitude(const Vector2& v){
	return sqrt(v.x * v.x + 
				v.y * v.y);
}
F32 Vector2::magnitude(){
	return sqrt(this->x * this->x + 
				this->y * this->y);
}

F32 Vector2::squareMagnitude(const Vector2& v){
	return v.x * v.x + 
			v.y * v.y;
}

F32 Vector2::squareMagnitude(){
	return this->x * this->x + 
			this->y * this->y;
}

Vector2 Vector2::normalize(Vector2& v){
	F32 magnitude = v.magnitude();
	ASSERT(magnitude > 0);
	return  v *= (1 / v.magnitude());
}

Vector2 Vector2::normalize(){
	F32 magnitude = this->magnitude();
	ASSERT(magnitude > 0);
	return *this *= (1 / magnitude);
}

F32 Vector2::dot(const Vector2& lhs, const Vector2& rhs){
	return lhs.x * rhs.x + 
			lhs.y * rhs.y;
}

F32 Vector2::dot(const Vector2& rhs){
	return this->x * rhs.x + 
			this->y * rhs.y;
}

Vector2 Vector2::project(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs * (dot(lhs, rhs) / squareMagnitude(lhs)));
}

Vector2 Vector2::project(const Vector2& rhs) {
	float s = this->dot(rhs) / this->squareMagnitude();
	return *this * s;
}

Vector2 Vector2::lerp(const Vector2& lhs, const Vector2& rhs, const F32 t) {
	return Vector2(
		(1-t)*lhs.x + t*rhs.x,
		(1-t)*lhs.y + t*rhs.y
	);	
}

Vector2 Vector2::lerp(const Vector2& rhs, const F32 t) {
	return Vector2(
		(1-t)*this->x + t*rhs.x,
		(1-t)*this->y + t*rhs.y
	);
}

Vector2 Vector2::right(){
	return Vector2(1.0f, 0.0f);
}

Vector2 Vector2::up(){
	return Vector2(0.0f, 1.0f);
}

std::string Vector2::toString(const Vector2& v){
	return "(" + Helper::toString(v.x)
		+ ", " + Helper::toString(v.y) + ")";
}

std::string Vector2::toString(){
	return "(" + Helper::toString(this->x)
		+ ", " + Helper::toString(this->y) + ")";
}