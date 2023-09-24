
#ifndef VTKTESTINGRENDERING_EXPORT_H
#define VTKTESTINGRENDERING_EXPORT_H

#ifdef VTKTESTINGRENDERING_STATIC_DEFINE
#  define VTKTESTINGRENDERING_EXPORT
#  define VTKTESTINGRENDERING_NO_EXPORT
#else
#  ifndef VTKTESTINGRENDERING_EXPORT
#    ifdef TestingRendering_EXPORTS
        /* We are building this library */
#      define VTKTESTINGRENDERING_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKTESTINGRENDERING_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKTESTINGRENDERING_NO_EXPORT
#    define VTKTESTINGRENDERING_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKTESTINGRENDERING_DEPRECATED
#  define VTKTESTINGRENDERING_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKTESTINGRENDERING_DEPRECATED_EXPORT
#  define VTKTESTINGRENDERING_DEPRECATED_EXPORT VTKTESTINGRENDERING_EXPORT VTKTESTINGRENDERING_DEPRECATED
#endif

#ifndef VTKTESTINGRENDERING_DEPRECATED_NO_EXPORT
#  define VTKTESTINGRENDERING_DEPRECATED_NO_EXPORT VTKTESTINGRENDERING_NO_EXPORT VTKTESTINGRENDERING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKTESTINGRENDERING_NO_DEPRECATED
#    define VTKTESTINGRENDERING_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkTestingRenderingModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKTESTINGRENDERING_EXPORT_H */
