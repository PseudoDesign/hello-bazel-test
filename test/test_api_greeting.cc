#include <gtest/gtest.h>
#include "proto/greeting.pb.h"

TEST(ApiGetGreet, EncodeAndDecode) {
    greeting::GetGreet my_greeting, parsed_greeting;
    std::string serialized;

    my_greeting.set_name("Adam");
    my_greeting.SerializeToString(&serialized);
    parsed_greeting.ParseFromString(serialized);
    EXPECT_EQ("Adam", parsed_greeting.name());
}

TEST(ApiGetGreetResponse, EncodeAndDecode) {
    greeting::GetGreetResponse my_response, parsed_response;
    std::string serialized;

    my_response.set_greeting("Hello Adam");
    my_response.SerializeToString(&serialized);
    parsed_response.ParseFromString(serialized);
    EXPECT_EQ("Hello Adam", parsed_response.greeting());
}