#include <conjugate/conjugate.hpp>
#include <gtest/gtest.h>
#include <numeric>

TEST(EQUALITY, ORACLE) {
    conjugate::Matrix<float, 100, 100> xs(1.0f);
    conjugate::Matrix<float, 100, 100> ys(1.0f);
    conjugate::Matrix<float, 100, 100> zs(2.0f);

    EXPECT_EQ(xs, ys);
    EXPECT_NE(xs, zs);
}

TEST(ADDITION, ORACLE) {
    conjugate::Matrix<float, 10, 10> xs(1.0f);
    conjugate::Matrix<float, 10, 10> ys(2.0f);
    conjugate::Matrix<float, 10, 10> zs(3.0f);

    EXPECT_EQ(xs + ys, zs);
}

TEST(ADDITION, COMMUTATIVE) {
    conjugate::Matrix<float, 100, 100> xs;
    conjugate::Matrix<float, 100, 100> ys;

    for (std::size_t i = 0; i < 100; i++) {
    for (std::size_t j = 0; j < 100; j++) {
        std::pair<std::size_t, std::size_t> p{i, j};
        xs[p] = i; ys[p] = j;
    }
    }

    EXPECT_EQ(xs + ys, ys + xs);
}

TEST(ADDITION, IDENTITY) {
    conjugate::Matrix<float, 100, 100> xs(1.0f);
    conjugate::Matrix<float, 100, 100> ys(0.0f);

    EXPECT_EQ(xs + ys, xs);
}

TEST(MULTIPLICATION, GAUSS) {
    {
        conjugate::Matrix<float, 10, 5> xs(1.0f);
        conjugate::Vector<float, 10>    ys(1.0f);

        for (std::size_t i = 0; i < ys.size(); i++) {
            ys[i] += static_cast<float>(i);
        }
        float sum = std::accumulate(ys.begin(), ys.end(), 0.0f);

        conjugate::Vector<float, 5> zs(sum);
        EXPECT_EQ(zs, xs * ys);
    }
    {
        conjugate::Matrix<float, 5, 10> xs(1.0f);
        conjugate::Vector<float, 10>    ys(1.0f);

        for (std::size_t i = 0; i < ys.size(); i++) {
            ys[i] += static_cast<float>(i);
        }
        float sum = std::accumulate(ys.begin(), ys.end(), 0.0f);

        conjugate::Vector<float, 5> zs(sum);
        EXPECT_EQ(zs, ys * xs);
    }
}

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
