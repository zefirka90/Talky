cmake_minimum_required(VERSION 3.15)
project(Talky C CXX)

include_directories(
    ${CMAKE_INCLUDE_PATH}
)

add_executable(${PROJECT_NAME}  src/main.cpp 
                                src/ChatPanel.cpp  
                                src/Application.cpp
                                src/imgui/imgui_impl_glfw.cpp 
                                src/imgui/imgui_impl_opengl3.cpp
                                )

find_package(glew REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(${PROJECT_NAME}
    GLEW::glew_s glfw3 imgui
)

if (UNIX)
    find_package(xorg REQUIRED)
    target_link_libraries(${PROJECT_NAME}
        xorg::xorg
    )
endif (UNIX)  

target_link_directories(${PROJECT_NAME} 
    PRIVATE ${CMAKE_LIBRARY_PATH}
)