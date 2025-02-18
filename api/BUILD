# Builds a representation of the API using Protobuf.
# These libraries are used to expose the C++ library code to a Python test engine.
# Bazel Ref: https://bazel.build/reference/be/protocol-buffer

# cc_library - generate a C++ library from C++ code
cc_library(
    name = "greeting_cc_lib",
    deps = [":greeting_cc_proto"],
)

# cc_proto_library - Generate C++ code from .proto files.
# Ref: https://protobuf.dev/getting-started/cpptutorial/
cc_proto_library(
    name = "greeting_cc_proto",
    deps = [":greeting_proto"],
)

# proto_library - A reference to a .proto file.
proto_library(
    name = "greeting_proto",
)