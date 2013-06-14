
#pragma once

#if defined(PLAYWEBSERVICE_MODULE_TESTER)

#pragma comment(lib, "PlayWebService.lib")

#include <PlayWebService/Global/Global.h>
#include <PlayWebService/Global/TestProxy.h>

using namespace SolidMCP;

struct PlayWebServiceModuleTester
{
    static void Run()
    {
        PlayWebService::TestProxy::Run();
    }
};

#endif