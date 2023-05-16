#include <QTest>
#include <QLineEdit>
#include "urlconfigurationtest.h"
#include "urlconfiguration.h"


URLConfigurationTest::URLConfigurationTest(QObject *parent) :
    QObject(parent)
{
}


void URLConfigurationTest::testQLineEditURL() {
    QLineEdit leURL;
    QTest::keyClicks(&leURL, "http://example.com");
    QCOMPARE(leURL.text(), QString("http://example.com"));
    QVERIFY(leURL.isModified());
}

void URLConfigurationTest::testQLineEditNotURL() {
    QLineEdit leURL;
    QTest::keyClicks(&leURL, "236dsfIADFГФВоАЫФ");

    URLConfiguration config;
    config.getURLFromUser(leURL.text().toStdString());

    QCOMPARE(config.getURLList().size(), 0);
    QVERIFY(leURL.isModified());
}

void URLConfigurationTest::testGetURLList() {
    URLConfiguration config;
    std::string expectedFirstString = "http://example.com";
    std::string expectedSecondString = "http://example.org";
    config.getURLFromUser(expectedFirstString);
    config.getURLFromUser(expectedSecondString);
    std::vector<std::string> expectedList = {"http://example.com", "https://example.org"};
    QCOMPARE(config.getURLList(), expectedList);
}

void URLConfigurationTest::testEmptyURLList() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {};
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testAddNotURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {};
    urlConfig.getURLFromUser("Не URL");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testAddURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com", "https://www.example.com"};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("https://www.example.com");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testRemoveURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com"};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("https://www.example.com");
    urlConfig.removeURL("https://www.example.com");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testClearURLList() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("https://www.example.com");
    urlConfig.clearURLList();
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testInvalidURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {};
    urlConfig.getURLFromUser("not a URL");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testDuplicateURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com"};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("http://www.example.com");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testEmptyURL() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {};
    urlConfig.getURLFromUser("");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testURLWithSpaces() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com"};
    urlConfig.getURLFromUser("http://www.example.com ");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testURLWithDifferentProtocols() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com", "https://www.example.com"};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("https://www.example.com");
    urlConfig.getURLFromUser("ftp://www.example.com");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}

void URLConfigurationTest::testURLWithDifferentPorts() {
    URLConfiguration urlConfig;
    std::vector<std::string> expectedURLList = {"http://www.example.com", "http://www.example.com:8080"};
    urlConfig.getURLFromUser("http://www.example.com");
    urlConfig.getURLFromUser("http://www.example.com:8080");
    QCOMPARE(urlConfig.getURLList(), expectedURLList);
}
