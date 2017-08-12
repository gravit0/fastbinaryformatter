#ifndef _FAST_BINARY_FORMATTER_H
#define _FAST_BINARY_FORMATTER_H
#include <iostream>
#include <list>
#if defined(linux) || defined(__linux)
#define C_EXPORT
#endif
#if defined(_WIN32) || defined (_WIN64) /*первый для обеих определён*/
#define C_EXPORT __declspec(dllexport)
#endif
#ifdef __cplusplus  
extern "C" {  // only need to export C interface if  
              // used by C++ source code  
#endif
C_EXPORT extern std::list<std::string> fastbinaryformatter1_decode(std::string str);
C_EXPORT extern std::string fastbinaryformatter1_encode(std::list<std::string> list);
#ifdef __cplusplus  
}
#endif
#endif
