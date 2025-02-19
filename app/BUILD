cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        "//lib:greeting",
    ],
)

cc_binary(
    name = "api-service",
    srcs = ["api-service.cc"],
    deps = [
        "//api:greeting_lib",
        "@libzmq//:libzmq",
        "@cppzmq//:cppzmq",
        "//lib:greeting",
    ],
    linkopts = ["-lpthread"]
)

cc_binary(
    name = "api-client",
    srcs = ["api-client.cc"],
    deps = [
        "//api:greeting_lib",
        "@libzmq//:libzmq",
        "@cppzmq//:cppzmq",
        "//lib:greeting",
    ],
    linkopts = ["-lpthread"]
)