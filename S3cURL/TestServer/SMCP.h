
#pragma once


#if defined(MYWORK_MODULE_TESTER)

#pragma comment(lib, "BedRock.lib")
#include <BedRock/Global/Global.h>
#include <BedRock/Global/TestProxy.h>

#pragma comment(lib, "Framework.lib")
#include <Framework/Global/Global.h>
#include <Framework/Global/TestProxy.h>
//
//#pragma comment(lib, "Network.lib")
//#include <Network/Global/Global.h>
//#include <Network/Global/TestProxy.h>
//
#pragma comment(lib, "AWS.lib")
#include <AWS/Global/Global.h>
#include <AWS/Global/TestProxy.h>
//
//#pragma comment(lib, "CAGD.lib")
//#include <Geometry/CAGD/Global/Global.h>
//#include <Geometry/CAGD/Global/TestProxy.h>


using namespace SolidMCP;

struct MyWorkModuleTester
{
	static void Run()
	{
		//BedRock::TestProxy::Run();
		//Framework::TestProxy::Run();
		//Network::TestProxy::Run();
		//CAGD::TestProxy::Run();
		AWS::TestProxy::Run();
	}
};


#endif
