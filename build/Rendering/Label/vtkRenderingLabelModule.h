
#ifndef VTKRENDERINGLABEL_EXPORT_H
#define VTKRENDERINGLABEL_EXPORT_H

#ifdef VTKRENDERINGLABEL_STATIC_DEFINE
#  define VTKRENDERINGLABEL_EXPORT
#  define VTKRENDERINGLABEL_NO_EXPORT
#else
#  ifndef VTKRENDERINGLABEL_EXPORT
#    ifdef RenderingLabel_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGLABEL_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define VTKRENDERINGLABEL_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef VTKRENDERINGLABEL_NO_EXPORT
#    define VTKRENDERINGLABEL_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef VTKRENDERINGLABEL_DEPRECATED
#  define VTKRENDERINGLABEL_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef VTKRENDERINGLABEL_DEPRECATED_EXPORT
#  define VTKRENDERINGLABEL_DEPRECATED_EXPORT VTKRENDERINGLABEL_EXPORT VTKRENDERINGLABEL_DEPRECATED
#endif

#ifndef VTKRENDERINGLABEL_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGLABEL_DEPRECATED_NO_EXPORT VTKRENDERINGLABEL_NO_EXPORT VTKRENDERINGLABEL_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGLABEL_NO_DEPRECATED
#    define VTKRENDERINGLABEL_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingLabelModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKRENDERINGLABEL_EXPORT_H */
