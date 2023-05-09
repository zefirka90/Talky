cmake_minimum_required(VERSION 3.15)
project(Talky C CXX)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCES
    ${SOURCE_DIR}/main.cpp
    ${SOURCE_DIR}/bindings/imgui_impl_glfw.cpp
    ${SOURCE_DIR}/bindings/imgui_impl_opengl3.cpp
)
set(HEADERS
    ${SOURCE_DIR}/bindings/imgui_impl_glfw.h
    ${SOURCE_DIR}/bindings/imgui_impl_opengl3.h
)

include_directories(
    ${CMAKE_INCLUDE_PATH}
    PRIVATE ${SOURCE_DIR}/bindings

)

add_executable(${PROJECT_NAME} src/main.cpp

)

target_sources(${PROJECT_NAME} PUBLIC ${HEADERS} PRIVATE ${SOURCES})

find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)
find_package(xorg REQUIRED)
 
target_link_libraries(${PROJECT_NAME}
    GLEW::glew_s glfw3 xorg::xorg
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_LIBRARY_PATH}
)

include_directories(
    ${CMAKE_INCLUDE_PATH}
)
