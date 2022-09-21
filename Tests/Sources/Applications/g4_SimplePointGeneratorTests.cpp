#include <g4/generators/g4_Types.h>
#include <g4/util/g4_SimplePointGenerator.h>
#include <gtest/gtest.h>

#include <array>
#include <cmath>

TEST(SimplePointGenerator, Simple)
{
    constexpr std::array<g4::Point, 4> expected = {{
        {{
             0.0f,
             0.1f,
             0.0f,
             0.0f,
         },
         {0.0f, 1.0f, 0.0f}},
        {{
             0.0f,
             0.0f,
             0.1f,
             0.0f,
         },
         {0.0f, 0.0f, 1.0f}},
        {{
             0.0f,
             -0.1f,
             0.0f,
             0.0f,
         },
         {0.0f, -1.0f, 0.0f}},
        {{
             0.0f,
             0.0f,
             -0.1f,
             0.0f,
         },
         {0.0f, 0.0f, -1.0f}},
    }};

    const g4::Vertex vertex         = {0.0f, 0.0f, 0.0f, 0.0f};
    const g4::Vertex gradient       = {1.0f, 0.0f, 0.0f, 0.0f};
    std::array<g4::Point, 4> points = {};
    g4::util::SimplePointGenerator generator;
    generator.Generate(points.data(), static_cast<int>(points.size()), vertex, gradient);

    for (auto index = 0; index < points.size(); ++index) {
        const auto& position         = points[index].vertex;
        const auto& normal           = points[index].normal;
        const auto& expectedPosition = expected[index].vertex;
        const auto& expectedNormal   = expected[index].normal;

        EXPECT_FLOAT_EQ(position.x, expectedPosition.x);
        EXPECT_FLOAT_EQ(position.y, expectedPosition.y);
        EXPECT_FLOAT_EQ(position.z, expectedPosition.z);
    }
}

TEST(SimplePointGenerator, AxisY)
{
    constexpr std::array<g4::Point, 4> expected = {{
        {{
             -0.1f,
             1.0f,
             0.0f,
             0.0f,
         },
         {1.0f, 0.0f, 0.0f}},
        {{
             0.0f,
             1.0f,
             0.1f,
             0.0f,
         },
         {0.0f, 0.0f, 1.0f}},
        {{
             0.1f,
             1.0f,
             0.0f,
             0.0f,
         },
         {-1.0f, 0.0f, 0.0f}},
        {{
             0.0f,
             1.0f,
             -0.1f,
             0.0f,
         },
         {0.0f, 0.0f, -1.0f}},
    }};

    const g4::Vertex vertex         = {0.0f, 1.0f, 0.0f, 0.0f};
    const g4::Vertex gradient       = {0.0f, 1.0f, 0.0f, 0.0f};
    std::array<g4::Point, 4> points = {};
    g4::util::SimplePointGenerator generator;
    generator.Generate(points.data(), static_cast<int>(points.size()), vertex, gradient);

    for (auto index = 0; index < points.size(); ++index) {
        const auto& position         = points[index].vertex;
        const auto& normal           = points[index].normal;
        const auto& expectedPosition = expected[index].vertex;
        const auto& expectedNormal   = expected[index].normal;

        EXPECT_FLOAT_EQ(position.x, expectedPosition.x);
        EXPECT_FLOAT_EQ(position.y, expectedPosition.y);
        EXPECT_FLOAT_EQ(position.z, expectedPosition.z);
    }
}

// (0, 1, 0) と (0, 0, 1) の間の点から Point を生成
TEST(SimplePointGenerator, LineYZ)
{
    constexpr std::array<g4::Point, 4> expected = {{
        {{
             -0.1f,
             1.0f,
             0.0f,
             0.0f,
         },
         {1.0f, 0.0f, 0.0f}},
        {{
             0.0f,
             1.0f,
             0.1f,
             0.0f,
         },
         {0.0f, 0.0f, 1.0f}},
        {{
             0.1f,
             1.0f,
             0.0f,
             0.0f,
         },
         {-1.0f, 0.0f, 0.0f}},
        {{
             0.0f,
             1.0f,
             -0.1f,
             0.0f,
         },
         {0.0f, 0.0f, -1.0f}},
    }};

    const g4::Vertex vertex         = {0.0f, 0.5f, 0.5f, 0.0f};
    const g4::Vertex gradient       = {0.0f, -std::sqrt(2.0f) / 2.0f, std::sqrt(2.0f) / 2.0f, 0.0f};
    std::array<g4::Point, 4> points = {};
    g4::util::SimplePointGenerator generator;
    generator.Generate(points.data(), static_cast<int>(points.size()), vertex, gradient);

    for (auto index = 0; index < points.size(); ++index) {
        const auto& position         = points[index].vertex;
        const auto& normal           = points[index].normal;
        const auto& expectedPosition = expected[index].vertex;
        const auto& expectedNormal   = expected[index].normal;

        EXPECT_FLOAT_EQ(position.x, expectedPosition.x);
        EXPECT_FLOAT_EQ(position.y, expectedPosition.y);
        EXPECT_FLOAT_EQ(position.z, expectedPosition.z);
    }
}
