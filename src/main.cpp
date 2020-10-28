#include "mat4x4.h"
#include <sstream>

int main() {
    float values[] = {1.f, 2.f, 3.f, 4.f,
                      1.4f, 2.5f, 17.f, 11.f,
                      3.f, 2.f, 1.f, 0.f,
                      11.f, 12.f, -0.3f, 11.f
    };
    mat4x4 m (values);
    mat4x4 m_1(1.f);
    std::cout << '\n' << m;
    std::cout << std::setw(23) << "\x1b[41;3m+\x1b[m" << std::endl;
    std::cout << m_1;
    std::cout << std::setw(23) << "\x1b[41;3m=\x1b[m" << std::endl;
    std::cout << m + m_1;

    std::cout << std::endl;
    float values_1[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    float values_2[] = {95, 22, 24, 39, 52, 41, 80, 71, 39, 65, 95, 97, 13, 12, 58, 18};
    mat4x4 lhs_mat(values_1);
    mat4x4 rhs_mat(values_2);
    std::stringstream answer;
    answer << (lhs_mat * rhs_mat);
    std::cout << answer.str();
}
