#ifndef Macros_h__
#define Macros_h__

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#if defined(_WIN32)
#ifdef _EXPORTING
#define RTSPAPI __declspec(dllexport)
#else
#define RTSPAPI __declspec(dllimport)
#endif
#else
#define RTSPAPI
#endif

#endif // Macros_h__
