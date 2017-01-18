#ifndef VxMacros_h__
#define VxMacros_h__

#include <cstring>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#ifdef _EXPORTING
#define VXAPI __declspec(dllexport)
#else
#define VXAPI __declspec(dllimport)
#endif

#define VxZeroArray(src) memset(src, 0, sizeof(src));

#endif // VxMacros_h__
