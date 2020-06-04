#ifndef ANALIZ_GLOBAL_H
#define ANALIZ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ANALIZ_LIBRARY)
#  define ANALIZ_EXPORT Q_DECL_EXPORT
#else
#  define ANALIZ_EXPORT Q_DECL_IMPORT
#endif

#endif // ANALIZ_GLOBAL_H
