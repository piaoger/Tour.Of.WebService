#ifndef GUARD_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H
#define GUARD_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H

// Plateform Selector
//

// Microsoft Windows
// 
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(_WIN64)
#	define SMCP_PLATFORM_HEADER <BedRock/Config/Details/Plateform/Windows.h>

// Unsupported Plateforms
//
#else
#	error("It's not on the schedule of SolidMCP.")
#endif



// Compiler Selector
//

// Microsoft Visual Studio C++
//
#if defined(_MSC_VER)
#	define SMCP_COMPILER_HEADER <BedRock/Config/Details/Compiler/VC.h>

// Unsupported Compilers
//
#else
#	error("It's not on the schedule of SolidMCP.")
#endif


#if defined(SMCP_COMPILER_HEADER)
#	include SMCP_COMPILER_HEADER
#endif


#if defined(SMCP_PLATFORM_HEADER)
#	include SMCP_PLATFORM_HEADER
#endif


#define PRAGMA_MESSAGE SMCP_COMPILER "  Version " SMCP_STRINGIZE(SMCP_COMPILER_VERSION)
#pragma message(PRAGMA_MESSAGE)
#undef PRAGMA_MESSAGE


#endif // GUARD_BEDROCK_CONFIG_CROSSTHINGS_SELECTOR_H
