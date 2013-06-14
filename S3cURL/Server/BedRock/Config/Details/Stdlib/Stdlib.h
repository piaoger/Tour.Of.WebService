
// Add #includes of Standard C++/C headers are encouraged to be placed here.
//
//
#ifndef GUARD_BEDROCK_STD_H
#define GUARD_BEDROCK_STD_H

#include <BedRock/Config/Details/Stdlib/Std_Includes.h>

// snprintf / swnprintf
//

#ifndef snprintf
#	ifdef SMCP_MSVC
#		ifndef _snprintf
#			define snprintf _snprintf
#		else
#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#		endif
#	else
#		error ("snprintf is not defined.")
#	endif
#endif

#ifndef snwprintf
#	ifdef SMCP_MSVC
#		ifndef _snwprintf
#			define snwprintf _snwprintf
#		else
#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
#		endif
#	else
#		error ("snprintf is not defined.")
#	endif
#endif

#ifdef SMCP_MSVC
#define wcsicmp		_wcsicmp
#define stricmp		_stricmp
#endif

//#define BASE_BINARY BASE_BINARY  =  2,
//BASE_OCTAL   =  8,
//BASE_DECIMAL = 10,
//BASE_HEX     = 16,


//#ifndef csicmp
//#	ifdef SMCP_MSVC
//#		ifndef _snprintf
//#			define strcmp _tcsicmp
//#		else
//#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
//#		endif
//#	else
//#		error ("snprintf is not defined.")
//#	endif
//#endif
//
//#ifndef snwprintf
//#	ifdef SMCP_MSVC
//#		ifndef _snwprintf
//#			define snwprintf _snwprintf
//#		else
//#			error ("snprintf is not defined. Please include <stdio.h> or <cstdio>")
//#		endif
//#	else
//#		error ("snprintf is not defined.")
//#	endif
//#endif

//BEGIN_NAMESPCE_BEDROCK
//
//using ::snprintf;
//
//END_NAMESPCE_BEDROCK






#endif // GUARD_BEDROCK_STD_H
