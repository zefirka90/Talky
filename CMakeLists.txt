cmake_minimum_required(VERSION 3.15)
project(Talky C CXX)


add_executable(${PROJECT_NAME} src/main.cpp)

find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)
 
target_link_libraries(${PROJECT_NAME}
    GLEW::glew_s glfw3
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_LIBRARY_PATH}
)

include_directories(
    ${CMAKE_INCLUDE_PATH}
)