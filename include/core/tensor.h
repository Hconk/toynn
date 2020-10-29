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

#ifndef _TOYNN_CORE_TENSOR_H_
#define _TOYNN_CORE_TENSOR_H_
#include <vector>
#include <memory>

namespace toynn
{
    template <typename T>
    class tensor
    {
    private:
        uint8_t m_dims;
        uint8_t m_type;
        uint8_t m_layout;
        uint8_t m_dim_num;
        uint8_t m_elem_num;

        std::shared_ptr<T> data;

    public:
        tensor(std::initializer_list<T> ilist);
        ~tensor();
    };

} // namespace toynn

#endif