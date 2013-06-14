#include "stdafx.h"

#include <tut.h>
#include <tut_reporter.h>

#include <exception>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
#if defined(PLAYWEBSERVICE_MODULE_TESTER)
    PlayWebServiceModuleTester::Run();
#endif
    return 1;
}
