#include "alltests.h"
#include "urlconfigurationtest.h"
#include "authorizationtest.h"

AllTests::AllTests(QObject *parent) :
    QObject(parent){}


void AllTests::runAllTests() {
    URLConfigurationTest urlConfigTest;
    QTest::qExec(&urlConfigTest);

    AuthorizationTest authTest;
    QTest::qExec(&authTest);
}
