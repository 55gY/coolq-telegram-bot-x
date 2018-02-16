// 
// pack_class.h : Define Pack class,
// which is to help parse information from raw bytes.
// 
// Copyright (C) 2017  Richard Chien <richardchienthebest@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 

#pragma once

#include "common.h"

class BytesNotEnoughError : public std::runtime_error {
    using runtime_error::runtime_error;
};

class Pack {
public:
    Pack() : bytes_(""), curr_(0) {}
    explicit Pack(const bytes &b) : bytes_(b), curr_(0) {}

    size_t size() const { return bytes_.size() - curr_; }
    bool empty() const { return size() == 0; }

    template <typename IntType>
    IntType pop_int() {
        constexpr auto size = sizeof(IntType);
        check_enough(size);

        auto s = this->bytes_.substr(this->curr_, size);
        this->curr_ += size;
        std::reverse(s.begin(), s.end());

        IntType result;
        memcpy(static_cast<void *>(&result), s.data(), size);
        return result;
    }

    std::string pop_string();
    bytes pop_bytes(const size_t len);
    bytes pop_token();
    bool pop_bool();

private:
    bytes bytes_;
    size_t curr_;

    void check_enough(const size_t needed) const;
};
