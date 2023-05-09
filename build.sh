mkdir build
conan install . -of=./build --build=missing
cmake . -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=./build/conan_toolchain.cmake -B ./build -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release

