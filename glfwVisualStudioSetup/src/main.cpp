#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <openglErrorReporting.h>

#include <iostream>

float triangleData[] = {
	// positions   // colors
	//x, y, z      // r, g, b
	  0, 1, 0,        1, 0, 0,
	  -1, -1, 0,      0, 1, 0,
	  1, -1, 0,       0, 0, 1
};

int main() {
	if (!glfwInit()) {
		std::cout << "GLFW Initialization error!\n";
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Simple Window", NULL, NULL);
	if (!window) {
		std::cout << "Window initialization error!\n";
		return 1;
	}

	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return 1;
	}

	enableReportGlErrors();

	// create the buffer
#pragma region buffer
	GLuint buffer = 0;
	glGenBuffers(1, &buffer);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData, GL_STATIC_DRAW);
#pragma endregion

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &buffer);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
