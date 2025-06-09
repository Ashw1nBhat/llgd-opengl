#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <openglErrorReporting.h>

#include <iostream>

#include <shader.h>

float triangleData[] = {
	// positions   // colors
	//x, y, z      // r, g, b
	  0.5, 0.5, 0,        1, 0, 0, // vertex 1
	  -0.5, 0.5, 0,      0, 1, 0, // vertex 2
	  -0.5, -0.5, 0,       0, 0, 1, // vertex 3
	   0.5, -0.5, 0,   0, 0, 1
};

unsigned short indices[]{
	0, 1, 2, // First triangle
	0, 2, 3  // Second triangle
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

#pragma region vao
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
#pragma endregion

#pragma region index buffer
	GLuint indexBuffer = 0;
	glGenBuffers(1, &indexBuffer);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
#pragma endregion

#pragma region buffer
	// create the buffer
	GLuint buffer = 0;
	glGenBuffers(1, &buffer);

	int vertexSize = sizeof(float) * 6;

	// send the data to the buffer
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleData), triangleData, GL_STATIC_DRAW);

	// attribute representing the position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize, 0);

	// attribute representing the color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)(sizeof(float) * 3));

#pragma endregion

	// Unbind VAO
	glBindVertexArray(0);

#pragma region load shaders
	Shader shader;
	shader.loadShaderProgramFromFile("resources/myShader.vert", "resources/myShader.frag");
	shader.bind();
#pragma endregion

	while (!glfwWindowShouldClose(window)) {
		// Tell OpenGL that we resized the window
		int w = 0, h = 0;
		glfwGetWindowSize(window, &w, &h);
		glViewport(0, 0, w, h);

		glClear(GL_COLOR_BUFFER_BIT);

		// Bind the VAO to specify the vertex buffer, index buffer and the attributes
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &indexBuffer);

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
