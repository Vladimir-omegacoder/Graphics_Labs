#pragma once
#include "SFML/Graphics.hpp"
#include "Vector4.h"
#include<cmath>
#include <iostream>


template <typename T>
class Matrix
{
private:
    T M[16] = { 
                 1,0,0,0,  
                 0,1,0,0,  
                 0,0,1,0,  
                 0,0,0,1 
                          };

public:

    T& operator[](int index);
    T operator[](int index) const;



    void moving(const Vector4<T>& v);

    void scaling(const Vector4<T>& v);


    void scaling_X(double v);

    void scaling_Y(double v);

    void scaling_Z(double v);




    void RotX(double angle);

    void RotY(double angle);

    void RotZ(double angle);

};

template <typename T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b);


template <typename T>
Vector4<T> operator*(const Matrix<T>& a, const Vector4<T>& b);


template struct Matrix<float>;
using Matrix_f = Matrix<float>;

#include "Matrix.inl"
