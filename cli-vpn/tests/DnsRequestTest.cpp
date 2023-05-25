#include "gtest/gtest.h"
#include "DnsRequest.hpp"

TEST(DnsRequestTest, IPv4Request) {
  DnsRequest dns_request;
  dns_request.Request("www.google.com");
  std::string ip_list = dns_request.getPoint();
  EXPECT_NE(ip_list, "Error Invalid Arguments");
}

TEST(DnsRequestTest, InvalidDomainName) {
  DnsRequest dns_request;
  dns_request.Request("invalid domain name");
  std::string ip_list = dns_request.getPoint();
  EXPECT_EQ(ip_list, "Error Invalid Arguments");
}