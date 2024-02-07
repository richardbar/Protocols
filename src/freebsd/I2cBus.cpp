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

#include <optional>
#include <string>

#include <fcntl.h>
#include <dev/iicbus/iic.h>
#include <sys/ioctl.h>

using Protocols::I2c::I2cBus;

std::optional<I2cBus> I2cBus::TryCreate(int busNumber) noexcept
{
    const std::string path = "/dev/iic" + std::to_string(busNumber);
    const int fd = open(path.c_str(), O_RDWR);
    const bool invalidFd = (fd < 0);
    if (invalidFd)
    {
        return std::nullopt;
    }

    I2cBus bus = I2cBus(fd);
    return bus;
}

bool I2cBus::WriteRead(const int deviceAddress,
                       const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                       std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept
{
    struct iic_msg messages[2];
    unsigned int numberOfMessages = 0;

    const bool writeIsRequested = (writeBuffer != nullptr);
    const bool readIsRequested = (readBuffer != nullptr);

    if (writeIsRequested)
    {
        messages[numberOfMessages].addr = deviceAddress;
        messages[numberOfMessages].flags = IIC_M_WR;
        messages[numberOfMessages].buf = const_cast<std::uint8_t *>(writeBuffer);
        messages[numberOfMessages].len = writeBufferSize;

        numberOfMessages++;
    }

    if (readIsRequested)
    {
        messages[numberOfMessages].addr = deviceAddress;
        messages[numberOfMessages].flags = IIC_M_RD;
        messages[numberOfMessages].buf = readBuffer;
        messages[numberOfMessages].len = readBufferSize;

        numberOfMessages++;
    }

    const bool noMessagesRequested = (numberOfMessages == 0);
    if (noMessagesRequested)
    {
        return false;
    }

    struct iic_rdwr_ioctl_data data = {
        .msgs = messages,
        .nmsgs = numberOfMessages};

    const int ioctlResult = ioctl(_fd, I2C_RDWR, &data);

    return (ioctlResult == numberOfMessages);
}
