/**
 * (c) 2025 Rikarnto Bariampa
 * This code is licensed under MIT license (see LICENSE for details)
 */

#ifndef __PROTOCOLS__DEFS__H__
#define __PROTOCOLS__DEFS__H__

#ifndef __cplusplus
    #include <stdint.h>
#else
    #include <cstdint>
#endif

#ifndef __cplusplus
    #define PROTOCOLS_UINT8 uint8_t
    #define PROTOCOLS_UINT16 uint16_t
    #define PROTOCOLS_UINT32 uint32_t
    #define PROTOCOLS_UINT64 uint64_t

    #define PROTOCOLS_INT8 int8_t
    #define PROTOCOLS_INT16 int16_t
    #define PROTOCOLS_INT32 int32_t
    #define PROTOCOLS_INT64 int64_t
#else
    #define PROTOCOLS_UINT8 std::uint8_t
    #define PROTOCOLS_UINT16 std::uint16_t
    #define PROTOCOLS_UINT32 std::uint32_t
    #define PROTOCOLS_UINT64 std::uint64_t

    #define PROTOCOLS_INT8 std::int8_t
    #define PROTOCOLS_INT16 std::int16_t
    #define PROTOCOLS_INT32 std::int32_t
    #define PROTOCOLS_INT64 std::int64_t
#endif

#define PROTOCOLS_VERSION_MAJOR ((PROTOCOLS_UINT8)UINT8_C(1))
#define PROTOCOLS_VERSION_MINOR ((PROTOCOLS_UINT8)UINT8_C(0))
#define PROTOCOLS_VERSION_PATCH ((PROTOCOLS_UINT16)UINT16_C(0))
#define PROTOCOLS_VERSION ((PROTOCOLS_UINT32)((((PROTOCOLS_UINT32)PROTOCOLS_VERSION_MAJOR) << 24) | (((PROTOCOLS_UINT32)PROTOCOLS_VERSION_MINOR) << 16) | ((PROTOCOLS_UINT32)PROTOCOLS_VERSION_PATCH)))

#ifndef __cplusplus
    #define PROTOCOLS_EXTERN extern
#else
    #define PROTOCOLS_EXTERN extern "C"
#endif

/**
 * @brief Get the major version of the library
 * 
 * @return PROTOCOLS_UINT8 The major version of the library
 */
PROTOCOLS_EXTERN PROTOCOLS_UINT8 Protocols_defs_GetVersionMajor(void);

/**
 * @brief Get the minor version of the library
 * 
 * @return PROTOCOLS_UINT8 The minor version of the library
 */
PROTOCOLS_EXTERN PROTOCOLS_UINT8 Protocols_defs_GetVersionMinor(void);

/**
 * @brief Get the patch version of the library
 * 
 * @return PROTOCOLS_UINT16 The patch version of the library
 */
PROTOCOLS_EXTERN PROTOCOLS_UINT16 Protocols_defs_GetVersionPatch(void);

/**
 * @brief Get the version of the library
 * 
 * @return PROTOCOLS_UINT32 The version of the library
 */
PROTOCOLS_EXTERN PROTOCOLS_UINT32 Protocols_defs_GetVersion(void);

#endif/*__PROTOCOLS__DEFS__H__*/
