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

#include "Protocols/I2c/I2cDevice.hpp"

using Protocols::I2c::I2cBus;
using Protocols::I2c::I2cDevice;

I2cDevice::I2cDevice(const I2cBus &bus, int deviceAddress) : bus(bus), deviceAddress(deviceAddress) {}

I2cDevice::I2cDevice(const I2cDevice &obj) : bus(obj.bus), deviceAddress(obj.deviceAddress) {}

I2cDevice::I2cDevice(I2cDevice &&deadObj) noexcept : bus(std::move(deadObj.bus)), deviceAddress(deadObj.deviceAddress)
{
    deadObj.deviceAddress = -1;
}

std::optional<I2cDevice> I2cDevice::TryCreate(const I2cBus &bus, int deviceAddress) noexcept
{
    const bool invalidDeviceAddress = (deviceAddress < 0);
    if (invalidDeviceAddress)
    {
        return std::nullopt;
    }

    try
    {
        const auto &device = I2cDevice(bus, deviceAddress);

        return device;
    }
    catch (const std::exception &)
    {
        return std::nullopt;
    }
}

bool I2cDevice::WriteRead(const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                          std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept
{
    bool invalidDeviceAddress = (deviceAddress < 0);
    if (invalidDeviceAddress)
    {
        return false;
    }

    const bool result = bus.WriteRead(deviceAddress, writeBuffer, writeBufferSize, readBuffer, readBufferSize);

    return result;
}

I2cDevice &I2cDevice::operator=(const I2cDevice &obj)
{
    const bool sameObj = (this == &obj);
    if (sameObj)
    {
        return *this;
    }

    bus = obj.bus;
    deviceAddress = obj.deviceAddress;

    return *this;
}

I2cDevice &I2cDevice::operator=(I2cDevice &&deadObj) noexcept
{
    const bool sameObj = (this == &deadObj);
    if (sameObj)
    {
        return *this;
    }

    bus = std::move(deadObj.bus);
    deviceAddress = deadObj.deviceAddress;

    deadObj.deviceAddress = -1;

    return *this;
}

I2cDevice::~I2cDevice() {}
