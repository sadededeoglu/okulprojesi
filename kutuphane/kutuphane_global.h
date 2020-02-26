#ifndef KUTUPHANE_GLOBAL_H
#define KUTUPHANE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(KUTUPHANE_LIBRARY)
#  define KUTUPHANE_EXPORT Q_DECL_EXPORT
#else
#  define KUTUPHANE_EXPORT Q_DECL_IMPORT
#endif

#endif // KUTUPHANE_GLOBAL_H
