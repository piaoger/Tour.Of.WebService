
#include <PlayWebService/Global/TestProxy.h>
#include <tut.h>
#include <tut_reporter.h>

#include <exception>
#include <iostream>

using tut::runner;

using std::exception;
using std::cout;
using std::cerr;
using std::endl;

#include <iostream>
using namespace std;

namespace tut
{
    test_runner_singleton runner;
}

BEGIN_NAMESPCE_PLAYWEBSERVICE

int TestProxy::Run()
{
    tut::console_reporter reporter;
    try {
        runner.get().set_callback(&reporter);
        runner.get().run_tests();

        if (!reporter.all_ok()) {
            cout << endl;
            cout << "*********************************************************"
                << endl;
            cout << "WARNING: THIS VERSION OF TUT IS UNUSABLE DUE TO ERRORS!!!"
                << endl;
            cout << "*********************************************************"
                << endl;
        } else {
            cout << endl;
            cout << "THIS VERSION OF TUT IS CORRECT" << endl;
        }
    } catch (const std::exception& ex) {
        cerr << "tut raised ex: " << ex.what() << endl;
        return 1;
    } catch( ... ) {
        cerr << "tut raised unknown exception" << endl;
        return 1;
    }

    return !reporter.all_ok();
}

END_NAMESPCE_PLAYWEBSERVICE