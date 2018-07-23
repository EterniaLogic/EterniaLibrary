#ifndef crc32_H
#define crc32_H

#include <stdint.h>
#include <stdlib.h>

// crc usually tends to be 0.
uint32_t crc32(uint32_t crc, const void *buf, size_t size);

#endif
