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

#ifndef __PROTOCOLS__I2C__I2C_CONNECTION_SETTINGS__H__
#define __PROTOCOLS__I2C__I2C_CONNECTION_SETTINGS__H__

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

namespace Protocols
{
    namespace I2c
    {
        class I2cConnectionSettings
        {
        private:
            int _busNumber;
            int _deviceAddress;

        public:
            I2cConnectionSettings() = delete;
            I2cConnectionSettings(int busNumber, int deviceAddress) noexcept;
            I2cConnectionSettings(const I2cConnectionSettings &obj) noexcept;
            I2cConnectionSettings(I2cConnectionSettings &&deadObj) noexcept;

            [[nodiscard]] int GetBusNumber() const noexcept;
            [[nodiscard]] int GetDeviceAddress() const noexcept;

            I2cConnectionSettings &operator=(const I2cConnectionSettings &obj) noexcept;
            I2cConnectionSettings &operator=(I2cConnectionSettings &&deadObj) noexcept;

            ~I2cConnectionSettings() noexcept;
        };
    } // namespace I2c
} // namespace Protocols

#endif /*__PROTOCOLS__I2C__I2C_CONNECTION_SETTINGS__H__*/
