#include <g4/generators/g4_Types.h>
#include <g4/util/g4_LinearInterpolator.h>
#include <gtest/gtest.h>

#include <array>
#include <cmath>

// 補間しない
TEST(LinearInterpolationTest, Empty)
{
    const g4::Vertex vertex0 = {0.0f, 0.0f, 0.0f, 0.0f};
    const g4::Vertex vertex1 = {1.0f, 0.0f, 0.0f, 0.0f};
    g4::util::LinearInterpolator interpolator;
    interpolator.Execute(nullptr, 0, vertex0, vertex1);
    // 落ちなければ OK
}

// 1 点だけ補間
TEST(LinearInterpolationTest, MinSize)
{
    const g4::Vertex vertex0                                   = {0.0f, 0.0f, 0.0f, 0.0f};
    const g4::Vertex vertex1                                   = {1.0f, 0.0f, 0.0f, 0.0f};
    std::array<g4::InterpolatedVertex, 1> interpolatedVertices = {};
    g4::util::LinearInterpolator interpolator;
    interpolator.Execute(interpolatedVertices.data(), static_cast<int>(interpolatedVertices.size()),
                         vertex0, vertex1);

    const auto& position = interpolatedVertices[0].position;
    EXPECT_FLOAT_EQ(position.x, 0.5f);
    EXPECT_FLOAT_EQ(position.y, 0.0f);
    EXPECT_FLOAT_EQ(position.z, 0.0f);

    const auto& gradient = interpolatedVertices[0].gradient;
    EXPECT_FLOAT_EQ(gradient.x, 1.0f);
    EXPECT_FLOAT_EQ(gradient.y, 0.0f);
    EXPECT_FLOAT_EQ(gradient.z, 0.0f);
}

// 3 点補間
TEST(LinearInterpolationTest, Quarter)
{
    const g4::Vertex vertex0                                   = {0.0f, 0.0f, 0.0f, 0.0f};
    const g4::Vertex vertex1                                   = {1.0f, 0.0f, 0.0f, 0.0f};
    std::array<g4::InterpolatedVertex, 3> interpolatedVertices = {};
    g4::util::LinearInterpolator interpolator;
    interpolator.Execute(interpolatedVertices.data(), static_cast<int>(interpolatedVertices.size()),
                         vertex0, vertex1);

    const auto& position0 = interpolatedVertices[0].position;
    EXPECT_FLOAT_EQ(position0.x, 0.25f);
    EXPECT_FLOAT_EQ(position0.y, 0.0f);
    EXPECT_FLOAT_EQ(position0.z, 0.0f);

    const auto& position1 = interpolatedVertices[1].position;
    EXPECT_FLOAT_EQ(position1.x, 0.5f);
    EXPECT_FLOAT_EQ(position1.y, 0.0f);
    EXPECT_FLOAT_EQ(position1.z, 0.0f);

    const auto& position2 = interpolatedVertices[2].position;
    EXPECT_FLOAT_EQ(position2.x, 0.75f);
    EXPECT_FLOAT_EQ(position2.y, 0.0f);
    EXPECT_FLOAT_EQ(position2.z, 0.0f);

    for (const auto interpolatedVertex : interpolatedVertices) {
        const auto& gradient = interpolatedVertex.gradient;
        EXPECT_FLOAT_EQ(gradient.x, 1.0f);
        EXPECT_FLOAT_EQ(gradient.y, 0.0f);
        EXPECT_FLOAT_EQ(gradient.z, 0.0f);
    }
}

// 斜め補間
TEST(LinearInterpolationTest, InterpolationYZ)
{
    const g4::Vertex vertex0                                   = {0.0f, 1.0f, 0.0f, 0.0f};
    const g4::Vertex vertex1                                   = {0.0f, 0.0f, 1.0f, 0.0f};
    std::array<g4::InterpolatedVertex, 3> interpolatedVertices = {};
    g4::util::LinearInterpolator interpolator;
    interpolator.Execute(interpolatedVertices.data(), static_cast<int>(interpolatedVertices.size()),
                         vertex0, vertex1);

    const auto& position0 = interpolatedVertices[0].position;
    EXPECT_FLOAT_EQ(position0.x, 0.0f);
    EXPECT_FLOAT_EQ(position0.y, 0.75f);
    EXPECT_FLOAT_EQ(position0.z, 0.25f);

    const auto& position1 = interpolatedVertices[1].position;
    EXPECT_FLOAT_EQ(position1.x, 0.0f);
    EXPECT_FLOAT_EQ(position1.y, 0.5f);
    EXPECT_FLOAT_EQ(position1.z, 0.5f);

    const auto& position2 = interpolatedVertices[2].position;
    EXPECT_FLOAT_EQ(position2.x, 0.0f);
    EXPECT_FLOAT_EQ(position2.y, 0.25f);
    EXPECT_FLOAT_EQ(position2.z, 0.75f);

    for (const auto interpolatedVertex : interpolatedVertices) {
        const auto& gradient = interpolatedVertex.gradient;
        EXPECT_FLOAT_EQ(gradient.x, 0.0f);
        EXPECT_FLOAT_EQ(gradient.y, -std::sqrt(2.0f) / 2.0f);
        EXPECT_FLOAT_EQ(gradient.z, std::sqrt(2.0f) / 2.0f);
    }
}
