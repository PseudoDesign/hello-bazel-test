cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cc"],
    deps = [
        "//lib:greeting",
    ],
)

cc_binary(
    name = "proto-service",
    srcs = ["proto-service.cc"],
    deps = [
        "//proto:greeting_lib",
        "@libzmq//:libzmq",
        "@cppzmq//:cppzmq",
        "//lib:greeting",
    ],
    linkopts = ["-lpthread"]
)

cc_binary(
    name = "proto-client",
    srcs = ["proto-client.cc"],
    deps = [
        "//proto:greeting_lib",
        "@libzmq//:libzmq",
        "@cppzmq//:cppzmq",
        "//lib:greeting",
    ],
    linkopts = ["-lpthread"]
)