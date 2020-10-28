#include "mat4x4.h"

mat4x4::mat4x4(mat4x4::f *arr) {
    try {
        for (u_int i = 0; i < 4; i++) {
            for (u_int j = 0; j < 4; j++) {
                (*this)[i][j] = *arr;
                arr++;
            }
        }
    } catch (...){
        std::cerr << "cant init it" << std::endl;
    }
}

mat4x4::mat4x4(float val) {
    assert(val == 1.f);
    for (u_int i = 0; i < 4; i++) {
        for (u_int j = 0; j < 4; j++) {
            (*this)[i][j] = 0;
            if (i == j)
                (*this)[i][j] = 1;
        }
    }
}

mat4x4::e &mat4x4::operator[](mat4x4::u_int i) {
    return raw[i];
}

mat4x4::f &mat4x4::node::operator[](mat4x4::u_int i) {
    return raw[i];
}

const mat4x4::e &mat4x4::operator[](mat4x4::u_int i) const {
    return raw[i];
}

const mat4x4::f &mat4x4::node::operator[](mat4x4::u_int i) const {
    return raw[i];
}

mat4x4 mat4x4::operator+(const mat4x4 & sec) const {
    mat4x4 tmp;
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            tmp[i][j] = (*this)[i][j] + sec[i][j];
        }
    }
    return tmp;
}

mat4x4 mat4x4::operator-(const mat4x4 & sec) const {
    mat4x4 tmp;
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            tmp[i][j] = (*this)[i][j] - sec[i][j];
        }
    }
    return tmp;
}

mat4x4 mat4x4::operator*(float val) const {
    mat4x4 tmp;
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            tmp[i][j] = (*this)[i][j] * val;
        }
    }
    return tmp;
}

mat4x4 &mat4x4::operator+=(const mat4x4 & sec) {
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            (*this)[i][j] = (*this)[i][j] + sec[i][j];
        }
    }
    return *this;
}

mat4x4 &mat4x4::operator-=(const mat4x4 & sec) {
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            (*this)[i][j] = (*this)[i][j] - sec[i][j];
        }
    }
    return *this;
}

mat4x4 mat4x4::operator*(const mat4x4 & sec) const {
    mat4x4 tmp;
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            tmp[i][j]=0;
            for(int k=0; k < 4; k++)
                tmp[i][j] += (*this)[i][k] * sec[k][j];
        }
    }
    return tmp;
}

mat4x4 mat4x4::operator*=(const mat4x4 & sec) {
    for (u_int i = 0; i < 4; i++){
        for (u_int j = 0; j < 4; j++){
            f tmp = 0;
            for(int k=0; k < 4; k++)
                tmp += (*this)[i][k] * sec[k][j];
            (*this)[i][j] = tmp;
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const mat4x4 & mat) {
    for (unsigned int i = 0; i < 4; i++){
        os << '|';
        for (unsigned int j = 0; j < 4; j++){
            os << std::setw (5) << std::right << mat[i][j] << ' ';
        }
        os << '|' << '\n';
    }
    return os;
}
