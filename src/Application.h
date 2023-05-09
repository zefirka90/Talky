#pragma once
#include "glIncl.h"

class Application{
public:
    Application(int _width, int _height, const char* _name);
    void run();
    ~Application();
private:
    int width, height;
    GLFWwindow* winHandle;
};