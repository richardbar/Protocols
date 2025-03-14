/**
 * (c) 2025 Rikarnto Bariampa
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include <Protocols/defs.h>

PROTOCOLS_UINT8 Protocols_defs_GetVersionMajor(void)
{
    return PROTOCOLS_VERSION_MAJOR;
}

PROTOCOLS_UINT8 Protocols_defs_GetVersionMinor(void)
{
    return PROTOCOLS_VERSION_MINOR;
}

PROTOCOLS_UINT16 Protocols_defs_GetVersionPatch(void)
{
    return PROTOCOLS_VERSION_PATCH;
}

PROTOCOLS_UINT32 Protocols_defs_GetVersion(void)
{
    return PROTOCOLS_VERSION;
}
