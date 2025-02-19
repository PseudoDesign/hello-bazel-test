#include <gtest/gtest.h>
#include "api/greeting.pb.h"

TEST(ApiGreeting, EncodeAndDecode) {
    greeting::GetGreet my_greeting, parsed_greeting;
    std::string serialized;

    my_greeting.set_name("Adam");
    my_greeting.SerializeToString(&serialized);
    parsed_greeting.ParseFromString(serialized);
    EXPECT_EQ("Adam", parsed_greeting.name());
}