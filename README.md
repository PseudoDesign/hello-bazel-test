# Hello Bazel Test

This is a simple example of setting up a bazel project using Dockerized builds, APIs, and automated tests.

## Dockerized Builds

Running dockerized builds in Bazel is as simple as using the [publicly available container](https://bazel.build/install/docker-container).

To save the trouble of writing wrapper scrips for every esoteric use case, we define a wrapper for the `bazel` command in the `setup_enviornmet.sh` script.  

Once you've [installed Docker](https://docs.docker.com/engine/install/), initialize the environment with:

`source setup_environment.sh`

Now your `bazel` commands will run in the docker container without needing to change anything else.

Test it with

`bazel version`

Since this isn't a Docker tutorial, we'll save the nitty-gritty for another time.

