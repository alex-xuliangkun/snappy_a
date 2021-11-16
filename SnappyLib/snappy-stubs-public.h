//
//  snappy-stubs-public.h
//  Snappy
//
//  Created by xlk on 2021/10/20.
//

#ifndef snappy_stubs_public_h
#define snappy_stubs_public_h

#include <stdint.h>
#include <stddef.h>
#include <sys/uio.h>


#define SNAPPY_MAJOR 1
#define SNAPPY_MINOR 1
#define SNAPPY_PATCHLEVEL 3
#define SNAPPY_VERSION \
    ((SNAPPY_MAJOR << 16) | (SNAPPY_MINOR << 8) | SNAPPY_PATCHLEVEL)

#include <string>

namespace snappy {

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;


typedef std::string string;

// Windows does not have an iovec type, yet the concept is universally useful.
// It is simple to define it ourselves, so we put it inside our own namespace.
struct iovec {
    void* iov_base;
    size_t iov_len;
};


}


#endif /* snappy_stubs_public_h */
