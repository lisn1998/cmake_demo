#ifndef INCLUDE_CEXPORTDEMODLL_CEXPORTDEMODLL_EXPORTDEF_H_
#define INCLUDE_CEXPORTDEMODLL_CEXPORTDEMODLL_EXPORTDEF_H_

#if defined(WINDOWS_PLATORM)		// windows platform
#  if defined(CEXPORTDEMODLL_DLL)
#    define CEXPORTDEMODLL_EXPORT __declspec(dllexport)
#  else
#    define CEXPORTDEMODLL_EXPORT __declspec(dllimport)
#  endif
#  pragma warning( disable : 4251 4275) 
#else	// other platform
#  define CEXPORTDEMODLL_EXPORT
#endif


#endif