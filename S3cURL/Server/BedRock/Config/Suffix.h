#ifndef GUARD_BEDROCK_SUFFIX_H
#define GUARD_BEDROCK_SUFFIX_H

#pragma message("SolidMCP BEDROCK")


#define SMCP_STRINGIZE(X) SMCP_DO_STRINGIZE(X)
#define SMCP_DO_STRINGIZE(X) #X

#define SMCP_JOIN(X, Y ) SMCP_DO_JOIN( X, Y )
#define SMCP_DO_JOIN(X, Y ) X##Y


// Disable warnings about conversion from size_t to unsigned long and long.
#   pragma warning (disable : 4267)

// disable: "<type> needs to have dll-interface to be used by clients'
// Happens on STL member variables which are not public therefore is ok
//
#   pragma warning (disable : 4390)

// disable: "non dll-interface class used as base for dll-interface class"
//
#   pragma warning (disable : 4275)

// disable: deprecation warnings when using CRT calls in VC8
//
#   pragma warning ( disable: 4996)

// Plateform/Compiler Selecting.Using following Macro in your applications.
// SMCP_PLATEFORM_WINDOWS
#include <BedRock/Config/Details/CrossThings_Selector.h>

// Only support MSVC currently
//
#ifndef SMCP_MSVC
#	error("Notice: Only working on MSVC now, Compatiable? You bet it!")
#endif

// Standard C/C++ Libarary
//
#include <BedRock/Config/Details/Stdlib/Stdlib.h>

// Macros for namespace
//
#define SMCP_BEGIN_NAMESPCE(ns) namespace ns {
#define SMCP_END_NAMESPCE(ns)                }

#endif // GUARD_BEDROCK_SUFFIX_H