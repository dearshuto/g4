#include <gtest/gtest.h>

int main(int argc, char** argv) noexcept
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
