#ifndef __XPLAT_BUILTIN_H__
#define __XPLAT_BUILTIN_H__



#define XPLAT_BUILTIN_EXPECT(exp, c) __builtin_expect(static_cast<bool>(exp), c)

#endif