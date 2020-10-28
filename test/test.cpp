#include <gtest/gtest.h>
#include <string>
#include <sstream>
#include "../src/mat4x4.h"

TEST (mat4x4, identity_matrix){
    mat4x4 mat (1.f);
    ASSERT_EQ(mat[0][0], 1.f);
    ASSERT_EQ(mat[1][1], 1.f);
    ASSERT_EQ(mat[2][2], 1.f);
    ASSERT_EQ(mat[3][3], 1.f);
}

/*
82 58 56 97
95 78 98 21
77 69 65 24
30 6 63 3
 */

/*
95 22 24 39
52 41 80 71
39 65 95 97
13 12 58 18
 */

TEST (mat4x4, sum_mat){
    float values_1[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    float values_2[] = {95, 22, 24, 39, 52, 41, 80, 71, 39, 65, 95, 97, 13, 12, 58, 18};
    mat4x4 lhs_mat(values_1);
    mat4x4 rhs_mat(values_2);

    std::stringstream answer;
    answer << (lhs_mat + rhs_mat);
    std::string expected {
        "|  177    80    80   136 |\n"
        "|  147   119   178    92 |\n"
        "|  116   134   160   121 |\n"
        "|   43    18   121    21 |\n"
    };

    EXPECT_TRUE(expected == answer.str());
}

TEST (mat4x4, sub_mat){
    float values_1[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    float values_2[] = {95, 22, 24, 39, 52, 41, 80, 71, 39, 65, 95, 97, 13, 12, 58, 18};
    mat4x4 lhs_mat(values_1);
    mat4x4 rhs_mat(values_2);

    std::stringstream answer;
    answer << (lhs_mat - rhs_mat);
    std::string expected {
            "|  -13    36    32    58 |\n"
            "|   43    37    18   -50 |\n"
            "|   38     4   -30   -73 |\n"
            "|   17    -6     5   -15 |\n"
    };

    EXPECT_TRUE(expected == answer.str());
}

TEST (mat4x4, mult_mat){
    float values_1[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    float values_2[] = {95, 22, 24, 39, 52, 41, 80, 71, 39, 65, 95, 97, 13, 12, 58, 18};
    mat4x4 lhs_mat(values_1);
    mat4x4 rhs_mat(values_2);

    std::stringstream answer;
    answer << (lhs_mat * rhs_mat);
    std::string expected {
            "|14251  8986 17554 14494 |\n"
            "|17176 11910 19048 19127 |\n"
            "|13750  9036 14935 14639 |\n"
            "| 5658  5037  7359  7761 |\n"
    };

    EXPECT_TRUE(expected == answer.str());
}

TEST (mat4x4, pass_x_1){
    float values[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    mat4x4 mat(values);

    ASSERT_EQ(mat.x.k, 82.f);
    ASSERT_EQ(mat.raw[0].k, 82.f);
}

TEST (mat4x4, pass_x_2){
    float values[] = {82, 58, 56, 97, 95, 78, 98, 21, 77, 69, 65, 24, 30, 6, 63, 3};
    mat4x4 mat(values);

    ASSERT_EQ(mat.x.p, 97.f);
    ASSERT_EQ(mat.raw[0].p, 97.f);
}