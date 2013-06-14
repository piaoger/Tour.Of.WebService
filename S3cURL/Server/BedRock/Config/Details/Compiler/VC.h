#ifndef GUARD_BEDROCK_CONFIG_COMPILER_VC_H
#define GUARD_BEDROCK_CONFIG_COMPILER_VC_H

#ifndef _MSC_VER
# pragma error("Uncompatiable compiler is detected..")
#endif

#define SMCP_COMPILER "Microsoft Visual Studio C++"

#define SMCP_COMPILER_VERSION  _MSC_VER

#define SMCP_MSVC _MSC_VER


#define SMCP_FORCE_INLINE  __forceinline

#endif // GUARD_BEDROCK_CONFIG_COMPILER_VC_H
