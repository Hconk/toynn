// Copyright 2020 Hconk
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <ops/add.h>
#include <core/tensor.h>

TEST(tensor_test, tensor_init_from_initializer_list_1dim)
{
    std::vector<int> vi = {1, 2, 3, 4, 5, 6};
    toynn::tensor<int> tensor_int_1dim = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(tensor_int_1dim.dims(), 1);
    auto data = tensor_int_1dim.data();
    for (size_t i = 0; i < vi.size(); i++)
    {
        EXPECT_EQ(vi[i], data.get()[i]);
    }
}

TEST(tensor_test, tensor_init_from_vector_1dim)
{
    std::vector<int> vi = {1, 2, 3, 4, 5, 6};
    toynn::tensor<int> tensor_int_1dim = vi;
    EXPECT_EQ(tensor_int_1dim.dims(), 1);
    auto data = tensor_int_1dim.data();
    for (size_t i = 0; i < vi.size(); i++)
    {
        EXPECT_EQ(vi[i], data.get()[i]);
    }
}

TEST(tensor_test, tensor_init_from_vector_2dim)
{
    std::vector<std::vector<int>> vi = {{1, 2, 3}, {4, 5, 6}};
    toynn::tensor<int, 2> tensor_int_2dim = vi;
    EXPECT_EQ(tensor_int_2dim.dims(), 2);
    auto data = tensor_int_2dim.data();
    int h = vi.size();
    int w = vi[0].size();
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            EXPECT_EQ(data.get()[i * w + j], vi[i][j]);
        }
    }
}