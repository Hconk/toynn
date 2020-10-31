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
    template <typename T, uint8_t dim = 1>
    class tensor
    {
    private:
        uint8_t m_dims;
        uint8_t m_type;
        uint8_t m_layout;
        static const uint8_t m_dim_num = dim;
        uint8_t m_elem_num;

        std::shared_ptr<T[]> m_data;

    public:
        uint8_t dims() const
        {
            return m_dim_num;
        }

        std::shared_ptr<T[]> data() const
        {
            return m_data;
        }
        tensor<T, dim>(const std::initializer_list<T>);
        tensor<T, dim>(const std::vector<T> &);

        ~tensor<T, dim>() {}
    };

    template <typename T>
    class tensor<T, 2>
    {
    private:
        uint8_t m_dims;
        uint8_t m_type;
        uint8_t m_layout;
        static const uint8_t m_dim_num = 2;
        uint8_t m_elem_num;

        std::shared_ptr<T[]> m_data;

    public:
        uint8_t dims() const
        {
            return m_dim_num;
        }

        std::shared_ptr<T[]> data() const
        {
            return m_data;
        }
        tensor<T, 2>(const std::initializer_list<T>) {}
        tensor<T, 2>(const std::vector<std::vector<T>>);
        //tensor<T>(const std::vector<T> &);

        ~tensor<T, 2>() {}
    };

    template <typename T, uint8_t dims>
    tensor<T, dims>::tensor(const std::initializer_list<T> ilist) : tensor<T, 1>(std::vector<T>(ilist))
    {
    }

    template <typename T, uint8_t dims>
    tensor<T, dims>::tensor(const std::vector<T> &data)
    {
        m_data = std::shared_ptr<T[]>(new T[data.size()]);
        std::copy(data.begin(), data.end(), m_data.get());
    }

    template <typename T>
    tensor<T, 2>::tensor(const std::vector<std::vector<T>> ilist)
    {
        int h = ilist.size();
        int w = ilist.begin()->size();
        m_data = std::shared_ptr<T[]>(new T[w * h]);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                m_data[i * w + j] = ilist[i][j];
            }
        }
    }

} // namespace toynn

#endif