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

TEST(add_test, should_return_sum_of_the_given_int_values)
{
  EXPECT_EQ(3, add(1, 2));
}

TEST(tensor_create, should_create_new_tensor_of_the_given_dims)
{
  toynn::tensor<int, 1> tm_tensor = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(1, tm_tensor.dims());
}