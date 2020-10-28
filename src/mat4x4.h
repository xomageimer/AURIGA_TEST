#ifndef AURIGA_MAT4X4_H
#define AURIGA_MAT4X4_H

#include <iostream>
#include <cassert>
#include <iomanip>

#define NODISC [[nodiscard]]

struct mat4x4 {
public:
    using f = float;
    using u_int = unsigned int;

    struct node{
        union {
            struct {f k, s, t, p;};
            f raw[4];
        };
        NODISC f & operator[](u_int i);
        NODISC const f & operator[](u_int i) const;
    };

    using e = node;

    union {
        struct {e x, y, z, w;};
        e raw[4];
    };

    mat4x4() : x(), y(), z(), w() {}
    mat4x4(f * arr);
    mat4x4(float val);
    mat4x4(const mat4x4 &) = default;
    mat4x4& operator=(const mat4x4 &) = default;
    mat4x4(mat4x4&&) = default;
    mat4x4& operator=(mat4x4&&) = default;

    NODISC e & operator[](u_int i);
    NODISC const e & operator[](u_int i) const;

    NODISC mat4x4 operator+(const mat4x4 &) const;
    NODISC mat4x4 operator-(const mat4x4 &) const;
    NODISC mat4x4 & operator+=(const mat4x4 &);
    NODISC mat4x4 & operator-=(const mat4x4 &);
    NODISC mat4x4 operator*(float) const;
    NODISC mat4x4 operator*(const mat4x4 &) const;
    NODISC mat4x4 operator*=(const mat4x4 &);

    friend std::ostream& operator<<(std::ostream& os, const mat4x4 &);
};


#endif //AURIGA_MAT4X4_H
