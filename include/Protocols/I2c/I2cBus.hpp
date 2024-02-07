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

#ifndef __PROTOCOLS__I2C__I2C_BUS__H__
#define __PROTOCOLS__I2C__I2C_BUS__H__

#include <cstdint>
#include <optional>

namespace Protocols
{
    namespace I2c
    {
        class I2cBus
        {
        private:
#if defined(__unix__)
            int _fd = -1;

            explicit I2cBus(const int fd);
#endif

            bool WriteRead(const int deviceAddress, const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                           std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept;

        public:
            I2cBus() = delete;
            I2cBus(const I2cBus &obj);
            I2cBus(I2cBus &&deadObj) noexcept;

            static std::optional<I2cBus> TryCreate(int busNumber) noexcept;

            I2cBus &operator=(const I2cBus &obj);
            I2cBus &operator=(I2cBus &&deadObj) noexcept;

            ~I2cBus();

#if defined(__PROTOCOLS__I2C__I2C_DEVICE__H__)
            friend class I2cDevice;
#endif /*__PROTOCOLS__I2C__I2C_DEVICE__H__*/
        };
    } // namespace I2c
} // namespace Protocols

#endif /*__PROTOCOLS__I2C__I2C_BUS__H__*/
