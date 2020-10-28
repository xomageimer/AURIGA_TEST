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
}
