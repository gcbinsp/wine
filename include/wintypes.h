/*
 * Basic types definitions
 *
 * Copyright 1996 Alexandre Julliard
 */

#ifndef __WINE_WINTYPES_H
#define __WINE_WINTYPES_H

#ifdef WINELIB
# ifdef WINELIB16
#  undef WINELIB32
# else
#  ifndef WINELIB32
#   define WINELIB32
#  endif
# endif
#else
# ifdef WINELIB32
#  undef WINELIB16
#  define WINELIB
# endif
# ifdef WINELIB16
#  define WINELIB
# endif
#endif

/* Macros to map Winelib names to the correct implementation name */
/* depending on WINELIB16, WINELIB32 and UNICODE macros.          */

#ifdef WINELIB
# ifdef WINELIB32
#  define WINELIB_NAME(func)     func##32
#  ifdef UNICODE
#   define WINELIB_NAME_AW(func) func##32W
#  else
#   define WINELIB_NAME_AW(func) func##32A
#  endif  /* UNICODE */
# else   /* WINELIB32 */
#  define WINELIB_NAME(func)     func##16
#  define WINELIB_NAME_AW(func)  func##16
# endif  /* WINELIB32 */
#else   /* WINELIB */
# define WINELIB_NAME(func)      this is a syntax error
# define WINELIB_NAME_AW(func)   this is a syntax error
#endif  /* WINELIB */

#ifdef WINELIB
# define DECL_WINELIB_TYPE(type)     typedef WINELIB_NAME(type) type
# define DECL_WINELIB_TYPE_AW(type)  typedef WINELIB_NAME_AW(type) type
#else   /* WINELIB */
# define DECL_WINELIB_TYPE(type)     /* nothing */
# define DECL_WINELIB_TYPE_AW(type)  /* nothing */
#endif  /* WINELIB */

/* Standard data types. These are the same for emulator and library. */

typedef void            VOID;
typedef short           INT16;
typedef unsigned short  UINT16;
typedef int             INT32;
typedef unsigned int    UINT32;
typedef unsigned short  WORD;
typedef unsigned long   DWORD;
typedef unsigned char   BYTE;
typedef long            LONG;
typedef char            CHAR;
/* Some systems might have wchar_t, but we really need 16 bit characters */
typedef unsigned short  WCHAR;
typedef unsigned short  BOOL16;
typedef int             BOOL32;

/* Handles types. These are the same for emulator and library. */

typedef UINT16          HANDLE16;
typedef UINT32          HANDLE32;
typedef UINT16          WPARAM16;
typedef UINT32          WPARAM32;
typedef LONG            LPARAM;
typedef LONG            LRESULT;
typedef WORD            ATOM;
typedef WORD            CATCHBUF[9];
typedef WORD           *LPCATCHBUF;
typedef DWORD           ACCESS_MASK;
typedef ACCESS_MASK     REGSAM;
typedef INT16           HFILE;
typedef HANDLE32        HHOOK;
typedef HANDLE32        HKEY;

/* Pointers types. These are the same for emulator and library. */

typedef CHAR           *LPSTR;
typedef const CHAR     *LPCSTR;
typedef WCHAR          *LPWSTR;
typedef const WCHAR    *LPCWSTR;
typedef BYTE           *LPBYTE;
typedef WORD           *LPWORD;
typedef DWORD          *LPDWORD;
typedef LONG           *LPLONG;
typedef VOID           *LPVOID;
typedef const VOID     *LPCVOID;
typedef INT16          *LPINT16;
typedef UINT16         *LPUINT16;
typedef INT32          *LPINT32;
typedef UINT32         *LPUINT32;
typedef HKEY           *LPHKEY;

/* Special case: a segmented pointer is just a pointer in the library. */

#ifdef WINELIB
typedef void* SEGPTR;
#else  /* WINELIB */
typedef DWORD SEGPTR;
#endif /* WINELIB */

/* Handle types that exist both in Win16 and Win32. */

#define DECLARE_HANDLE(a)  typedef HANDLE16 a##16; typedef HANDLE32 a##32;
DECLARE_HANDLE(HACCEL);
DECLARE_HANDLE(HBITMAP);
DECLARE_HANDLE(HBRUSH);
DECLARE_HANDLE(HCURSOR);
DECLARE_HANDLE(HDC);
DECLARE_HANDLE(HDROP);
DECLARE_HANDLE(HDRVR);
DECLARE_HANDLE(HDWP);
DECLARE_HANDLE(HFONT);
DECLARE_HANDLE(HGDIOBJ);
DECLARE_HANDLE(HGLOBAL);
DECLARE_HANDLE(HICON);
DECLARE_HANDLE(HINSTANCE);
DECLARE_HANDLE(HLOCAL);
DECLARE_HANDLE(HMENU);
DECLARE_HANDLE(HMETAFILE);
DECLARE_HANDLE(HMIDI);
DECLARE_HANDLE(HMIDIIN);
DECLARE_HANDLE(HMIDIOUT);
DECLARE_HANDLE(HMMIO);
DECLARE_HANDLE(HMODULE);
DECLARE_HANDLE(HPALETTE);
DECLARE_HANDLE(HPEN);
DECLARE_HANDLE(HQUEUE);
DECLARE_HANDLE(HRGN);
DECLARE_HANDLE(HRSRC);
DECLARE_HANDLE(HTASK);
DECLARE_HANDLE(HWAVE);
DECLARE_HANDLE(HWAVEIN);
DECLARE_HANDLE(HWAVEOUT);
DECLARE_HANDLE(HWND);
#undef DECLARE_HANDLE

/* Callback function pointers types for Win16. */

#ifdef WINELIB
typedef LRESULT (*DLGPROC16)(HWND16,UINT16,WPARAM16,LPARAM);
typedef LRESULT (*FARPROC16)();
typedef LRESULT (*WNDENUMPROC16)(HWND16,LPARAM);
typedef LRESULT (*WNDPROC16)(HWND16,UINT16,WPARAM16,LPARAM);
#else
/* Function pointers are SEGPTR in Win16 */
typedef SEGPTR DLGPROC16;
typedef SEGPTR FARPROC16;
typedef SEGPTR WNDENUMPROC16;
typedef SEGPTR WNDPROC16;
#endif

/* Callback function pointers types for Win32. */

typedef LRESULT (*DLGPROC32)(HWND32,UINT32,WPARAM32,LPARAM);
typedef LRESULT (*FARPROC32)();
typedef LRESULT (*WNDENUMPROC32)(HWND32,LPARAM);
typedef LRESULT (*WNDPROC32)(HWND32,UINT32,WPARAM32,LPARAM);

/* TCHAR data types definitions for Winelib. */
/* These types are _not_ defined for the emulator, because they */
/* depend on the UNICODE macro that only exists in user's code. */

#ifdef WINELIB
# if defined(WINELIB32) && defined(UNICODE)
typedef WCHAR TCHAR;
typedef LPWSTR LPTSTR;
typedef LPCWSTR LPCTSTR;
# else  /* WINELIB32 && UNICODE */
typedef CHAR TCHAR;
typedef LPSTR LPTSTR;
typedef LPCSTR LPCTSTR;
# endif /* WINELIB32 && UNICODE */
#endif   /* WINELIB */

/* Data types specific to the library. These do _not_ exist in the emulator. */

DECL_WINELIB_TYPE(INT);
DECL_WINELIB_TYPE(LPINT);
DECL_WINELIB_TYPE(LPUINT);
DECL_WINELIB_TYPE(UINT);
DECL_WINELIB_TYPE(BOOL);
DECL_WINELIB_TYPE(WPARAM);

DECL_WINELIB_TYPE(HACCEL);
DECL_WINELIB_TYPE(HANDLE);
DECL_WINELIB_TYPE(HBITMAP);
DECL_WINELIB_TYPE(HBRUSH);
DECL_WINELIB_TYPE(HCURSOR);
DECL_WINELIB_TYPE(HDC);
DECL_WINELIB_TYPE(HDROP);
DECL_WINELIB_TYPE(HDRVR);
DECL_WINELIB_TYPE(HDWP);
DECL_WINELIB_TYPE(HFONT);
DECL_WINELIB_TYPE(HGDIOBJ);
DECL_WINELIB_TYPE(HGLOBAL);
DECL_WINELIB_TYPE(HICON);
DECL_WINELIB_TYPE(HINSTANCE);
DECL_WINELIB_TYPE(HLOCAL);
DECL_WINELIB_TYPE(HMENU);
DECL_WINELIB_TYPE(HMETAFILE);
DECL_WINELIB_TYPE(HMIDI);
DECL_WINELIB_TYPE(HMIDIIN);
DECL_WINELIB_TYPE(HMIDIOUT);
DECL_WINELIB_TYPE(HMMIO);
DECL_WINELIB_TYPE(HMODULE);
DECL_WINELIB_TYPE(HPALETTE);
DECL_WINELIB_TYPE(HPEN);
DECL_WINELIB_TYPE(HQUEUE);
DECL_WINELIB_TYPE(HRGN);
DECL_WINELIB_TYPE(HRSRC);
DECL_WINELIB_TYPE(HTASK);
DECL_WINELIB_TYPE(HWAVE);
DECL_WINELIB_TYPE(HWAVEIN);
DECL_WINELIB_TYPE(HWAVEOUT);
DECL_WINELIB_TYPE(HWND);

DECL_WINELIB_TYPE(DLGPROC);
DECL_WINELIB_TYPE(FARPROC);
DECL_WINELIB_TYPE(WNDENUMPROC);
DECL_WINELIB_TYPE(WNDPROC);

/* Misc. constants. */

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef TRUE
#undef TRUE
#endif
#define TRUE  1

#ifdef NULL
#undef NULL
#endif
#define NULL  0

/* Define some empty macros for compatibility with Windows code. */

#ifdef WINELIB
#define CALLBACK
#define NEAR
#define FAR
#define PASCAL
#define WINAPI
#define _far
#define _near
#define _pascal
#define __export
#endif  /* WINELIB */

/* Macro for structure packing. */

#ifdef WINELIB
#define WINE_PACKED
#else
#define WINE_PACKED __attribute__ ((packed))
#endif  /* WINELIB */

/* Macros to split words and longs. */

#define LOBYTE(w)              ((BYTE)(WORD)(w))
#define HIBYTE(w)              ((BYTE)((WORD)(w) >> 8))

#define LOWORD(l)              ((WORD)(DWORD)(l))
#define HIWORD(l)              ((WORD)((DWORD)(l) >> 16))

#define SLOWORD(l)             ((INT16)(LONG)(l))
#define SHIWORD(l)             ((INT16)((LONG)(l) >> 16))

#define MAKELONG(low,high)     ((LONG)(((WORD)(low)) | \
                                       (((DWORD)((WORD)(high))) << 16)))
#define MAKELPARAM(low,high)   ((LPARAM)MAKELONG(low,high))
#define MAKEWPARAM(low,high)   ((WPARAM32)MAKELONG(low,high))
#define MAKEINTATOM(atom)      ((LPCSTR)MAKELONG((atom),0))

#define SELECTOROF(ptr)     (HIWORD(ptr))
#define OFFSETOF(ptr)       (LOWORD(ptr))

/* Macros to access unaligned or wrong-endian WORDs and DWORDs. */

#if !defined(WINELIB) || defined(__i386__)
#define PUT_WORD(ptr,w)   (*(WORD *)(ptr) = (w))
#define GET_WORD(ptr)     (*(WORD *)(ptr))
#define PUT_DWORD(ptr,dw) (*(DWORD *)(ptr) = (dw))
#define GET_DWORD(ptr)    (*(DWORD *)(ptr))
#else
#define PUT_WORD(ptr,w)   (*(BYTE *)(ptr) = LOBYTE(w), \
                           *((BYTE *)(ptr) + 1) = HIBYTE(w))
#define GET_WORD(ptr)     ((WORD)(*(BYTE *)(ptr) | \
                                  (WORD)(*((BYTE *)(ptr)+1) << 8)))
#define PUT_DWORD(ptr,dw) (PUT_WORD((ptr),LOWORD(dw)), \
                           PUT_WORD((WORD *)(ptr)+1,HIWORD(dw)))
#define GET_DWORD(ptr)    ((DWORD)(GET_WORD(ptr) | \
                                   ((DWORD)GET_WORD((WORD *)(ptr)+1) << 16)))
#endif  /* !WINELIB || __i386__ */

/* MIN and MAX macros */

#ifdef MAX
#undef MAX
#endif
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

#ifdef MIN
#undef MIN
#endif
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

#endif /* __WINE_WINTYPES_H */
