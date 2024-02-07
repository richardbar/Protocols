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

#include <array>
#include <cstddef>
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

        public:
            I2cBus() = delete;
            I2cBus(const I2cBus &obj);
            I2cBus(I2cBus &&deadObj) noexcept;

            static std::optional<I2cBus> TryCreate(int busNumber) noexcept;

            bool WriteRead(const int deviceAddress, const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                           std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept;

            inline bool Write(const int deviceAddress, const std::uint8_t *writeBuffer,
                              const std::size_t writeBufferSize) const noexcept
            {
                return WriteRead(deviceAddress, writeBuffer, writeBufferSize, nullptr, 0);
            }

            inline bool Read(const int deviceAddress, std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(deviceAddress, nullptr, 0, readBuffer, readBufferSize);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool WriteRead(const int deviceAddress, const std::array<std::uint8_t, WriteSize> &writeBuffer,
                                  std::array<std::uint8_t, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(deviceAddress, writeBuffer.data(), WriteSize, readBuffer.data(), ReadSize);
            }

            template <std::size_t WriteSize>
            inline bool Write(const int deviceAddress, const std::array<std::uint8_t, WriteSize> &writeBuffer) const noexcept
            {
                return WriteRead(deviceAddress, writeBuffer.data(), WriteSize, nullptr, 0);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool Read(const int deviceAddress, std::array<std::uint8_t, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(deviceAddress, nullptr, 0, readBuffer.data(), ReadSize);
            }

#if defined(__cpp_lib_byte)
            bool WriteRead(const int deviceAddress, const std::byte *writeBuffer, const std::size_t writeBufferSize,
                           std::byte *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(deviceAddress, reinterpret_cast<const std::uint8_t *>(writeBuffer), writeBufferSize,
                                 reinterpret_cast<std::uint8_t *>(readBuffer), readBufferSize);
            }

            inline bool Write(const int deviceAddress, const std::byte *writeBuffer,
                              const std::size_t writeBufferSize) const noexcept
            {
                return WriteRead(deviceAddress, reinterpret_cast<const std::uint8_t *>(writeBuffer), writeBufferSize, nullptr,
                                 0);
            }

            inline bool Read(const int deviceAddress, std::byte *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(deviceAddress, nullptr, 0, reinterpret_cast<std::uint8_t *>(readBuffer), readBufferSize);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool WriteRead(const int deviceAddress, const std::array<std::byte, WriteSize> &writeBuffer,
                                  std::array<std::byte, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(deviceAddress, reinterpret_cast<const std::uint8_t *>(writeBuffer.data()), WriteSize,
                                 reinterpret_cast<std::uint8_t *>(readBuffer.data()), ReadSize);
            }

            template <std::size_t WriteSize>
            inline bool Write(const int deviceAddress, const std::array<std::byte, WriteSize> &writeBuffer) const noexcept
            {
                return WriteRead(deviceAddress, reinterpret_cast<const std::uint8_t *>(writeBuffer.data()), WriteSize, nullptr,
                                 0);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool Read(const int deviceAddress, std::array<std::byte, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(deviceAddress, nullptr, 0, reinterpret_cast<std::uint8_t *>(readBuffer.data()), ReadSize);
            }
#endif

            I2cBus &operator=(const I2cBus &obj);
            I2cBus &operator=(I2cBus &&deadObj) noexcept;

            ~I2cBus();
        };
    } // namespace I2c
} // namespace Protocols

#endif /*__PROTOCOLS__I2C__I2C_BUS__H__*/
