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
    name = "test_proto_greeting",
    size = "small",
    srcs = ["test_proto_greeting.cc"],
    deps = [
        "//proto:greeting_lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

py_test(
    name = "test_python_proto",
    srcs = ["test_python_proto.py"],
    deps = [
        "//proto:greeting_py_pb2",
    ],
)