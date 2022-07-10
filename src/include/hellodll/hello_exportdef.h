#ifndef INCLUDE_HELLODLL_HELLO_EXPORTDEF_H_
#define INCLUDE_HELLODLL_HELLO_EXPORTDEF_H_

#if defined(WINDOWS_PLATORM)		// windows platform
#  if defined(HELLO_DLL)
#    define HELLO_EXPORT __declspec(dllexport)
#  else
#    define HELLO_EXPORT __declspec(dllimport)
#  endif
#  pragma warning( disable : 4251 4275) 
#else	// other platform
#  define HELLO_EXPORT
#endif


#endif