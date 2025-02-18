# Hello Bazel Test Lib

This is a simple example of setting up a bazel project using Dockerized builds, APIs, and automated unit tests.

## Dockerized Builds

Running dockerized builds in Bazel is as simple as using the [publicly available container](https://bazel.build/install/docker-container).

To save the trouble of writing wrapper scrips for every esoteric use case, we define a wrapper for the `bazel` command in the `setup_enviornmet.sh` script.  

Once you've [installed Docker](https://docs.docker.com/engine/install/), initialize the environment with:

`source setup_environment.sh`

Now your `bazel` commands will run in the docker container without needing to change anything else.

Test it with

`bazel version`

Since this isn't a Docker tutorial, we'll save the nitty-gritty for another time.

## Project Structure

### `app` directory

This directory contains any standalone applications associated with this build, such as the "hello-world" application entry point.

### `lib` directory

This directory contains libraries that can be used by other projects.  In "framework" style projects, the library is the key deliverable of this repository, intended to be used in a larger project.

### `test` directory

This directory contains unit tests (and only unit tests), which are expected to be run on the developer's host machine (or CI platform).

Unit tests are meant to validate the expected behavior of the source code, not that the code functions as expected on the hardware platform.