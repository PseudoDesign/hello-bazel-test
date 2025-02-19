#include <gtest/gtest.h>
#include "lib/greeting.h"

TEST(LibGreeting, TypicalNames) {
    EXPECT_EQ(get_greet("Adam"), "Hello Adam");
    EXPECT_EQ(get_greet("Patty"), "Hello Patty");
    EXPECT_EQ(get_greet("Shiva"), "Hello Shiva");
    EXPECT_EQ(get_greet("Murphy"), "Hello Murphy");
}

TEST(LibGreeting, EmptyName) {
    EXPECT_EQ(get_greet(""), "Hello ");
}

TEST(LibGreeting, VeryLongNames) {
    EXPECT_EQ(
        get_greet("asdhgbenwbjerqnwergniquwehibndzkjbvhubweijbnireuqbhvfdijbajengoijnwhiobrnejeabdhfbahsdbfhsdabnkjdnbkjnasbdfjneqwjkmgiopqhngowihnciosduniovbandsoibvnqeiowugnisengiarsndgskjnfalgjnajnbhisadfnbbiaodnfbiadfnboifadjnb"), 
        "Hello asdhgbenwbjerqnwergniquwehibndzkjbvhubweijbnireuqbhvfdijbajengoijnwhiobrnejeabdhfbahsdbfhsdabnkjdnbkjnasbdfjneqwjkmgiopqhngowihnciosduniovbandsoibvnqeiowugnisengiarsndgskjnfalgjnajnbhisadfnbbiaodnfbiadfnboifadjnb"
    );
}

TEST(LibGreeting, NamesWithSpace) {
    EXPECT_EQ(get_greet(" Adam"), "Hello  Adam");
    EXPECT_EQ(get_greet("Adam "), "Hello Adam ");
    EXPECT_EQ(get_greet("Adam Schafer"), "Hello Adam Schafer");
}

TEST(LibGreeting, NamesWithDashes) {
    EXPECT_EQ(get_greet("Schafer-Shaffer"), "Hello Schafer-Shaffer");
}