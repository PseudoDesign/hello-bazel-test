# Builds a representation of the API using Protobuf.
# These libraries are used to expose the C++ library code to a Python test engine.
# Bazel Ref: https://bazel.build/reference/be/protocol-buffer# BUILD.bazel


load("@protobuf//bazel:py_proto_library.bzl", "py_proto_library")

package(default_visibility = [
    "//app:__pkg__",
    "//test:__pkg__",
    ])

# greeting_py_pb - Python protobuf wrapper
py_proto_library(
    name = "greeting_py_pb2",
    deps = [":greeting_proto"],
)

# lib - generate a C++ library from C++ code
cc_library(
    name = "greeting_lib",
    deps = [":greeting_cc_proto"],
    alwayslink = True,
)

# greeting_cc_proto - Generate C++ code from .proto files.
# Ref: https://protobuf.dev/getting-started/cpptutorial/
cc_proto_library(
    name = "greeting_cc_proto",
    deps = [":greeting_proto"],
)

# greeting_proto - A reference to a .proto file.
proto_library(
    name = "greeting_proto",
    srcs = ["greeting.proto"],
)