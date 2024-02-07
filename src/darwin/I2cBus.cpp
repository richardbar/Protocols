/*
 * MIT License
 *
 * Copyright (c) 2024 Rikarnto Bariampa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Protocols/I2c/I2cBus.hpp"

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <optional>

using Protocols::I2c::I2cBus;

I2cBus::I2cBus(const I2cBus &obj)
{
    throw std::runtime_error("Unsupported operation");
}

I2cBus::I2cBus(I2cBus &&deadObj) noexcept
{
    return;
}

std::optional<I2cBus> I2cBus::TryCreate(int busNumber) noexcept
{
    return std::nullopt;
}

bool I2cBus::WriteRead(const int deviceAddress,
                       const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                       std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept
{
    return false;
}

I2cBus &I2cBus::operator=(const I2cBus &obj)
{
    throw std::runtime_error("Unsupported operation");
}

I2cBus &I2cBus::operator=(I2cBus &&deadObj) noexcept
{
    return *this;
}

I2cBus::~I2cBus() {}
