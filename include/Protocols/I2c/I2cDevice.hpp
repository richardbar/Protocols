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

#ifndef __PROTOCOLS__I2C__I2C_DEVICE__H__
#define __PROTOCOLS__I2C__I2C_DEVICE__H__

#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>

#include <Protocols/I2c/I2cBus.hpp>
#include <Protocols/I2c/I2cConnectionSettings.hpp>

namespace Protocols
{
    namespace I2c
    {
        class I2cDevice
        {
        private:
            I2cBus bus;
            int deviceAddress;

            I2cDevice(const I2cBus &bus, int deviceAddress);

        public:
            I2cDevice() = delete;
            I2cDevice(const I2cDevice &obj);
            I2cDevice(I2cDevice &&deadObj) noexcept;

            static std::optional<I2cDevice> TryCreate(const I2cConnectionSettings &i2cConnectionSettings) noexcept;

            bool WriteRead(const std::uint8_t *writeBuffer, const std::size_t writeBufferSize,
                           std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept;

            inline bool Write(const std::uint8_t *writeBuffer, const std::size_t writeBufferSize) const noexcept
            {
                return WriteRead(writeBuffer, writeBufferSize, nullptr, 0);
            }

            inline bool Read(std::uint8_t *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(nullptr, 0, readBuffer, readBufferSize);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool WriteRead(const std::array<std::uint8_t, WriteSize> &writeBuffer, std::array<std::uint8_t, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(writeBuffer.data(), WriteSize, readBuffer.data(), ReadSize);
            }

            template <std::size_t WriteSize>
            inline bool Write(const std::array<std::uint8_t, WriteSize> &writeBuffer) const noexcept
            {
                return Write(writeBuffer.data(), WriteSize);
            }

            template <std::size_t ReadSize>
            inline bool Read(std::array<std::uint8_t, ReadSize> &readBuffer) const noexcept
            {
                return Read(readBuffer.data(), ReadSize);
            }

#if defined(__cpp_lib_byte)
            bool WriteRead(const std::byte *writeBuffer, const std::size_t writeBufferSize,
                           std::byte *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(reinterpret_cast<const std::uint8_t *>(writeBuffer), writeBufferSize,
                                 reinterpret_cast<std::uint8_t *>(readBuffer), readBufferSize);
            }

            inline bool Write(const std::byte *writeBuffer,
                              const std::size_t writeBufferSize) const noexcept
            {
                return WriteRead(reinterpret_cast<const std::uint8_t *>(writeBuffer), writeBufferSize, nullptr, 0);
            }

            inline bool Read(std::byte *readBuffer, const std::size_t readBufferSize) const noexcept
            {
                return WriteRead(nullptr, 0, reinterpret_cast<std::uint8_t *>(readBuffer), readBufferSize);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool WriteRead(const std::array<std::byte, WriteSize> &writeBuffer,
                                  std::array<std::byte, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(reinterpret_cast<const std::uint8_t *>(writeBuffer.data()), WriteSize,
                                 reinterpret_cast<std::uint8_t *>(readBuffer.data()), ReadSize);
            }

            template <std::size_t WriteSize>
            inline bool Write(const std::array<std::byte, WriteSize> &writeBuffer) const noexcept
            {
                return WriteRead(reinterpret_cast<const std::uint8_t *>(writeBuffer.data()), WriteSize, nullptr, 0);
            }

            template <std::size_t WriteSize, std::size_t ReadSize>
            inline bool Read(std::array<std::byte, ReadSize> &readBuffer) const noexcept
            {
                return WriteRead(nullptr, 0, reinterpret_cast<std::uint8_t *>(readBuffer.data()), ReadSize);
            }
#endif

            I2cDevice &operator=(const I2cDevice &obj);
            I2cDevice &operator=(I2cDevice &&deadObj) noexcept;

            ~I2cDevice();
        };
    } // namespace I2c
} // namespace Protocols

#endif /*__PROTOCOLS__I2C__I2C_DEVICE__H__*/
