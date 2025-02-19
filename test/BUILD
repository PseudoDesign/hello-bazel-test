cc_test(
    name = "test_lib_greeting",
    size = "small",
    srcs = ["test_lib_greeting.cc"],
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "//lib:greeting"
    ],
)

cc_test(
    name = "test_api_greeting",
    size = "small",
    srcs = ["test_api_greeting.cc"],
    deps = [
        "//api:greeting_lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)