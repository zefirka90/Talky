mkdir build
conan install . -of=./build --build=missing
cmake . -G "Visual Studio 16 2019" -DCMAKE_TOOLCHAIN_FILE=./build/conan_toolchain.cmake -B ./build
cmake --build ./build --config Release