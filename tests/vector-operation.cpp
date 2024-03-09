#include <conjugate/conjugate.hpp>
#include <gtest/gtest.h>

TEST(EQUALITY, ORACLE) {
    conjugate::Vector<float, 100> xs(1.0f);
    conjugate::Vector<float, 100> ys(1.0f);
    conjugate::Vector<float, 100> zs(2.0f);

    EXPECT_EQ(xs, ys);
    EXPECT_NE(xs, zs);
}

TEST(ADDITION, ORACLE) {
    conjugate::Vector<float, 100> xs(1.0f);
    conjugate::Vector<float, 100> ys(2.0f);
    conjugate::Vector<float, 100> zs(3.0f);

    EXPECT_EQ(xs + ys, zs);
}

TEST(ADDITION, COMMUTATIVE) {
    conjugate::Vector<float, 100> xs(1.0f);
    conjugate::Vector<float, 100> ys(2.0f);

    EXPECT_EQ(xs + ys, ys + xs);
}

TEST(ADDITION, IDENTITY) {
    conjugate::Vector<float, 100> xs(1.0f);
    conjugate::Vector<float, 100> ys(0.0f);

    EXPECT_EQ(xs + ys, xs);
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
