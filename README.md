# json_cpp

Example project of how to use `nlohmann_json` library with
`{fmt}` and `conan 2.0` using the conan-generator `CMakeDeps`

Make sure that the conan profile configuration matches the cmake configuration.
i.e. if the conan profile has `build_type=Debug` then
use `CMAKE_BUILD_TYPE=Debug`.

[cmake-conan](https://github.com/conan-io/cmake-conan) is not yet compatible with conan 2.0 so before loading the cmake
project (to e.g. `./build`) run:

    conan profile show
    conan install . --output-folder=build --build=missing
