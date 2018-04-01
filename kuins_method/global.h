#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef _MSC_VER

	#ifdef KUAINRULE_EXPORTS  
	#define KUAINRULE_API __declspec(dllexport)   
	#else  
	#define KUAINRULE_API __declspec(dllimport)   
	#endif

#elif __MINGW32__

    #include <QtCore/qglobal.h>

	#ifdef KUAINRULE_EXPORTS
	#  define KUAINRULE_API Q_DECL_EXPORT
	#else
	#  define KUAINRULE_API Q_DECL_IMPORT
	#endif

#else

    #error MSVC or Qt + MinGW compiler required.

#endif

#endif // GLOBAL_H
