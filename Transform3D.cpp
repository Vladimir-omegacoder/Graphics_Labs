#include "Transform3D.h"






Transform3D operator*(const Transform3D& left, const Transform3D& right)
{

	Transform3D res;

	res[0] = left[0] * right[0] + left[1] * right[4] + left[2] * right[8] + left[3] * right[12];
	res[1] = left[0] * right[1] + left[1] * right[5] + left[2] * right[9] + left[3] * right[13];
	res[2] = left[0] * right[2] + left[1] * right[6] + left[2] * right[10] + left[3] * right[14];
	res[3] = left[0] * right[3] + left[1] * right[7] + left[2] * right[11] + left[3] * right[15];

	res[4] = left[4] * right[0] + left[5] * right[4] + left[6] * right[8] + left[7] * right[12];
	res[5] = left[4] * right[1] + left[5] * right[5] + left[6] * right[9] + left[7] * right[13];
	res[6] = left[4] * right[2] + left[5] * right[6] + left[6] * right[10] + left[7] * right[14];
	res[7] = left[4] * right[3] + left[5] * right[7] + left[6] * right[11] + left[7] * right[15];

	res[8] = left[8] * right[0] + left[9] * right[4] + left[10] * right[8] + left[11] * right[12];
	res[9] = left[8] * right[1] + left[9] * right[5] + left[10] * right[9] + left[11] * right[13];
	res[10] = left[8] * right[2] + left[9] * right[6] + left[10] * right[10] + left[11] * right[14];
	res[11] = left[8] * right[3] + left[9] * right[7] + left[10] * right[11] + left[11] * right[15];

	res[12] = left[12] * right[0] + left[13] * right[4] + left[14] * right[8] + left[15] * right[12];
	res[13] = left[12] * right[1] + left[13] * right[5] + left[14] * right[9] + left[15] * right[13];
	res[14] = left[12] * right[2] + left[13] * right[6] + left[14] * right[10] + left[15] * right[14];
	res[15] = left[12] * right[3] + left[13] * right[7] + left[14] * right[11] + left[15] * right[15];

	return res;

}



Vector4f operator*(const Vector4f& left, const Transform3D& right)
{

	Vector4f res;

	res.x = left.x * right[0] + left.y * right[4] + left.z * right[8] + right[12];
	res.y = left.x * right[1] + left.y * right[5] + left.z * right[9] + right[13];
	res.z = left.x * right[2] + left.y * right[6] + left.z * right[10] + right[14];
	res.w = left.x * right[3] + left.y * right[7] + left.z * right[11] + right[15];

	return res;

}



void Transform3D::rotate_x(float angle)
{

	Transform3D rotation;

	angle = PI / 180 * -angle; // convert deg to rad

	rotation[5] = rotation[10] = cos(angle);
	rotation[6] = -(rotation[9] = sin(angle));

	(*this) = (*this) * rotation;

}

void Transform3D::rotate_y(float angle)
{

	Transform3D rotation;

	angle = PI / 180 * -angle; // convert deg to rad

	rotation[0] = rotation[10] = cos(angle);
	rotation[8] = -(rotation[2] = sin(angle));

	(*this) = (*this) * rotation;

}

void Transform3D::rotate_z(float angle)
{

	Transform3D rotation;

	angle = PI / 180 * -angle; // convert deg to rad

	rotation[0] = rotation[5] = cos(angle);
	rotation[1] = -(rotation[4] = sin(angle));

	(*this) = (*this) * rotation;

}



void Transform3D::translate(float x, float y, float z)
{
	
	Transform3D translation;

	translation[12] = x;
	translation[13] = y;
	translation[14] = z;

	(*this) = (*this) * translation;

}

void Transform3D::translate(const sf::Vector3f& offset)
{

	Transform3D translation;

	translation[12] = offset.x;
	translation[13] = offset.y;
	translation[14] = offset.z;

	(*this) = (*this) * translation;

}
