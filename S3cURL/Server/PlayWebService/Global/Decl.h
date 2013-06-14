#ifndef SMCPCORE_DEC_PLAYWEBSERVICE_H
#define SMCPCORE_DEC_PLAYWEBSERVICE_H 

#include <BedRock/Config.h>

#ifdef SMCP_DLL
    #ifdef SMCPCORE_PLAYWEBSERVICE_DECL
        #define EXPORT_CORE_PLAYWEBSERVICE __declspec(dllexport)
    #else
        #define EXPORT_CORE_PLAYWEBSERVICE __declspec(dllimport)
    #endif
#else
    #define EXPORT_CORE_PLAYWEBSERVICE
#endif

// Macros for namespace
// SolidMCP::PlayWebService
//
#define BEGIN_NAMESPCE_PLAYWEBSERVICE SMCP_BEGIN_NAMESPCE(SolidMCP) \
                                 SMCP_BEGIN_NAMESPCE(PlayWebService)

#define END_NAMESPCE_PLAYWEBSERVICE SMCP_END_NAMESPCE(SolidMCP) \
                               SMCP_END_NAMESPCE(PlayWebService)


// SolidMCP::AWS::S3
//
#define BEGIN_NAMESPCE_PLAYWEBSERVICE_JSON BEGIN_NAMESPCE_PLAYWEBSERVICE \
                                 SMCP_BEGIN_NAMESPCE(JSON)

#define END_NAMESPCE_PLAYWEBSERVICE_JSON END_NAMESPCE_PLAYWEBSERVICE \
                               SMCP_END_NAMESPCE(JSON)

#endif //SMCPCORE_DEC_PLAYWEBSERVICE_H