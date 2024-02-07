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

#include "Protocols/I2c/I2cConnectionSettings.hpp"

using Protocols::I2c::I2cConnectionSettings;

I2cConnectionSettings::I2cConnectionSettings(int busNumber, int deviceAddress) noexcept
    : _busNumber(busNumber), _deviceAddress(deviceAddress) {}

I2cConnectionSettings::I2cConnectionSettings(const I2cConnectionSettings &obj) noexcept
    : _busNumber(obj._busNumber), _deviceAddress(obj._deviceAddress) {}

I2cConnectionSettings::I2cConnectionSettings(I2cConnectionSettings &&deadObj) noexcept
    : _busNumber(deadObj._busNumber), _deviceAddress(deadObj._deviceAddress) {}

int I2cConnectionSettings::GetBusNumber() const noexcept
{
    return _busNumber;
}

int I2cConnectionSettings::GetDeviceAddress() const noexcept
{
    return _deviceAddress;
}

I2cConnectionSettings &I2cConnectionSettings::operator=(const I2cConnectionSettings &obj) noexcept
{
    _busNumber = obj._busNumber;
    _deviceAddress = obj._deviceAddress;
    return *this;
}

I2cConnectionSettings &I2cConnectionSettings::operator=(I2cConnectionSettings &&deadObj) noexcept
{
    _busNumber = deadObj._busNumber;
    _deviceAddress = deadObj._deviceAddress;
    return *this;
}

I2cConnectionSettings::~I2cConnectionSettings() noexcept {}
