#include "stdafx.h"
#include "javasample_Win32.h"
#include <windows.h>
#include <jni.h>
#include <jawt.h>
#include <jawt_md.h>
#include <tchar.h>

HMODULE _hAWT = nullptr;

/// <summary>
// This method is used for getting the native win32 handle for given Java component
// Reference: http://stackoverflow.com/a/413895/1672927
/// </summary>
/// <param name="env">Jni environment pointer</param>
/// <param name="cls">Static Java class variable</param>
/// <param name="comp">Java component to get handle</param>
JNIEXPORT jint JNICALL Java_javasample_Win32_getWindowHandle
(JNIEnv *env, jclass cls, jobject comp) {
    HWND hWnd;
    typedef jboolean(JNICALL *PJAWT_GETAWT)(JNIEnv*, JAWT*);
    JAWT awt;

    //Load AWT Library
    if (!_hAWT) {
        //for Java 1.4
        _hAWT = LoadLibrary(_T("jawt.dll"));
    }
    if (!_hAWT) {
        //for Java 1.3
        _hAWT = LoadLibrary(_T("awt.dll"));
    }
    if (_hAWT) {
        PJAWT_GETAWT JAWT_GetAWT = PJAWT_GETAWT(GetProcAddress(_hAWT, "_JAWT_GetAWT@8"));
        if (JAWT_GetAWT) {
            awt.version = JAWT_VERSION_1_4; // Init here with JAWT_VERSION_1_3 or JAWT_VERSION_1_4
            //Get AWT API Interface
            jboolean result = JAWT_GetAWT(env, &awt);
            if (result != JNI_FALSE) {
                JAWT_DrawingSurface* ds = awt.GetDrawingSurface(env, comp);
                if (ds != nullptr) {
                    jint lock = ds->Lock(ds);
                    if ((lock & JAWT_LOCK_ERROR) == 0) {
                        JAWT_DrawingSurfaceInfo* dsi = ds->GetDrawingSurfaceInfo(ds);
                        if (dsi) {
                            JAWT_Win32DrawingSurfaceInfo* dsi_win = static_cast<JAWT_Win32DrawingSurfaceInfo*>(dsi->platformInfo);
                            if (dsi_win) {
                                hWnd = dsi_win->hwnd;
                            }
                            else {
                                hWnd = HWND(-1);
                            }
                            ds->FreeDrawingSurfaceInfo(dsi);
                        }
                        else {
                            hWnd = HWND(-2);
                        }
                        ds->Unlock(ds);
                    }
                    else {
                        hWnd = HWND(-3);
                    }
                    awt.FreeDrawingSurface(ds);
                }
                else {
                    hWnd = HWND(-4);
                }
            }
            else {
                hWnd = HWND(-5);
            }
        }
        else {
            hWnd = HWND(-6);
        }
    }
    else {
        hWnd = HWND(-7);
    }
    return jint(hWnd);
}
