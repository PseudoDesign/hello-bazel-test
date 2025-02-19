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
        "@libzmq//:libzmq",
        "@cppzmq//:cppzmq",
        "//lib:greeting",
    ],
    linkopts = ["-lpthread"]
)