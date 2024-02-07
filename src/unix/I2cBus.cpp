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

#include <stdexcept>

#include <unistd.h>

using Protocols::I2c::I2cBus;

I2cBus::I2cBus(const int fd) : _fd(fd) {}

I2cBus::I2cBus(const I2cBus &obj) : _fd(dup(obj._fd))
{
    const bool validFd = (0 <= _fd);
    if (validFd)
    {
        return;
    }

    throw std::runtime_error("Failed to duplicate file descriptor");
}
I2cBus::I2cBus(I2cBus &&deadObj) noexcept : _fd(deadObj._fd)
{
    deadObj._fd = -1;
}

I2cBus &I2cBus::operator=(const I2cBus &obj)
{
    const bool sameObj = (this == &obj);
    if (sameObj)
    {
        return *this;
    }

    const bool validOldFd = (0 <= _fd);
    if (validOldFd)
    {
        close(_fd);
        _fd = -1;
    }

    _fd = dup(obj._fd);
    const bool validNewFd = (0 <= _fd);
    if (validNewFd)
    {
        return *this;
    }

    throw std::runtime_error("Failed to duplicate file descriptor");
}

I2cBus &I2cBus::operator=(I2cBus &&deadObj) noexcept
{
    const bool sameObj = (this == &deadObj);
    if (sameObj)
    {
        return *this;
    }

    const bool validOldFd = (0 <= _fd);
    if (validOldFd)
    {
        close(_fd);
        _fd = -1;
    }

    _fd = deadObj._fd;
    deadObj._fd = -1;

    return *this;
}

I2cBus::~I2cBus()
{
    const bool invalidFd = (_fd < 0);
    if (invalidFd)
    {
        return;
    }

    close(_fd);
    _fd = -1;
}
