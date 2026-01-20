#ifndef __XPLAT_LIKELY_H__
#define __XPLAT_LIKELY_H__
#include "Builtin.h"


#define XPLAT_LIKELY(...) XPLAT_BUILTIN_EXPECT((__VA_ARGS__), 1)

#define XPLAT_UNLIKELY(...) XPLAT_BUILTIN_EXPECT((__VA_ARGS__), 0)

#endif