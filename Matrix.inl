#include "Matrix.h"

template<typename T>
T& Matrix<T>::operator[](int index)
{
	if (index < 16)
	{
		return M[index];
	}
	else
	{
		throw std::out_of_range ("Matrix don't have this index");
	}
}


template<typename T>
inline T Matrix<T>::operator[](int index) const
{
	if (index < 16)
	{
		return M[index];
	}
	else
	{
		throw std::out_of_range("Matrix don't have this index");
	}
}



template<typename T>
 Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
{
	Matrix<T> M;

	M[0] = a[0] * b[0] + a[1] * b[4] + a[2] * b[8] + a[3] * b[12];
	M[1] = a[0] * b[1] + a[1] * b[5] + a[2] * b[9] + a[3] * b[13];
	M[2] = a[0] * b[2] + a[1] * b[6] + a[2] * b[10] + a[3] * b[14];
	M[3] = a[0] * b[3] + a[1] * b[7] + a[2] * b[11] + a[3] * b[15];

	M[4] = a[4] * b[0] + a[5] * b[4] + a[6] * b[8] + a[7] * b[12];
	M[5] = a[4] * b[1] + a[5] * b[5] + a[6] * b[9] + a[7] * b[13];
	M[6] = a[4] * b[2] + a[5] * b[6] + a[6] * b[10] + a[7] * b[14];
	M[7] = a[4] * b[3] + a[5] * b[7] + a[6] * b[11] + a[7] * b[15];

	M[8] = a[8] * b[0] + a[9] * b[4] + a[10] * b[8] + a[11] * b[12];
	M[9] = a[8] * b[1] + a[9] * b[5] + a[10] * b[9] + a[11] * b[13];
	M[10] = a[8] * b[2] + a[9] * b[6] + a[10] * b[10] + a[11] * b[14];
	M[11] = a[8] * b[3] + a[9] * b[7] + a[10] * b[11] + a[11] * b[15];

	M[12] = a[12] * b[0] + a[13] * b[4] + a[14] * b[8] + a[15] * b[12];
	M[13] = a[12] * b[1] + a[13] * b[5] + a[14] * b[9] + a[15] * b[13];
	M[14] = a[12] * b[2] + a[13] * b[6] + a[14] * b[10] + a[15] * b[14];
	M[15] = a[12] * b[3] + a[13] * b[7] + a[14] * b[11] + a[15] * b[15];


	return M;
}

 template<typename T>
 inline Vector4<T> operator*(const Matrix<T>& a, const Vector4<T>& b)
 {
	 Vector4<T> V;

	 V.x = a[0] * b.x + a[1] * b.y + a[2] * b.z + a[3] * b.w;
	 V.y = a[4] * b.x + a[5] * b.y + a[6] * b.z + a[7] * b.w;
	 V.z = a[8] * b.x + a[9] * b.y + a[10] * b.z + a[11] * b.w;
	 V.w = a[12] * b.x + a[13] * b.y + a[14] * b.z + a[15] * b.w;

	 return V;
 }




template<typename T>
inline void Matrix<T>::moving(const Vector4<T>& v)
{
	Matrix<T> Ma;

	Ma[3] = v.x;
	Ma[7] = v.y;
	Ma[11] = v.y;

	*this = (*this) * Ma;
}


template<typename T>
inline void Matrix<T>::scaling(const Vector4<T>& v)
{
	Matrix<T> Ma;

	Ma[0] = v.x;
	Ma[5] = v.y;
	Ma[10] = v.z;

	*this =  (*this) * Ma;
}





template<typename T>
inline void Matrix<T>::scaling_X(double v)
{
	Matrix<T> Ma;

	Ma[0] = v;

	*this = (*this) * Ma;
}


template<typename T>
inline void Matrix<T>::scaling_Y(double v)
{
	Matrix<T> Ma;

	Ma[5] = v;

	*this = (*this) * Ma;
}


template<typename T>
inline void Matrix<T>::scaling_Z(double v)
{
	Matrix<T> Ma;

	Ma[10] = v;

	*this = (*this) * Ma;
}







template<typename T>
inline void Matrix<T>::RotX(double angle)
{
	Matrix<T> Ma;

	Ma[5] = cos(angle / 180 * 3.14);
	Ma[6] = -sin(angle / 180 * 3.14);
	Ma[9] = sin(angle / 180 * 3.14);
	Ma[10] = cos(angle / 180 * 3.14);

	*this = (*this) * Ma;
}



template<typename T>
inline void Matrix<T>::RotY(double angle)
{
	Matrix<T> Ma;

	Ma[0] = cos(angle/180 * 3.14);
	Ma[2] = sin(angle/180 * 3.14);
	Ma[8] = -sin(angle/ 180 * 3.14);
	Ma[10] = cos(angle/ 180 * 3.14);

	*this = (*this) * Ma;
}



template<typename T>
inline void Matrix<T>::RotZ(double angle)
{
	Matrix<T> Ma;

	Ma[0] = cos(angle / 180 * 3.14);
	Ma[1] = -sin(angle / 180 * 3.14);
	Ma[4] = sin(angle / 180 * 3.14);
	Ma[5] = cos(angle / 180 * 3.14);

	*this = (*this) * Ma;
}