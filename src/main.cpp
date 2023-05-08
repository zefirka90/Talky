#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>

int main(){
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1000, 1000, "fuck", NULL, NULL);
	glfwMakeContextCurrent(window);
	glewInit();

	glClearColor(1, 0.5f, 0.1f, 1);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);

	return 0;
}