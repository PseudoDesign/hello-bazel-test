#!/bin/bash

bazel() { 
    mkdir -p ${HOME}/.bazel-build
    docker run \
    -it \
    -e USER="$(id -u)" \
    -u="$(id -u)" \
    -v ${PWD}:/workspace/src \
    -v "${HOME}/.bazel-build:${HOME}/.bazel-build" \
    -w /workspace/src \
    gcr.io/bazel-public/bazel:latest \
    --output_user_root=${HOME}/.bazel-build \
    "$@"
}