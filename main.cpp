#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "vertexShader.h"
#include "fragmentShader.h"

// Resize the viewport
void framebuffer_size_callback(GLFWwindow* window, int width, int height);



int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required for Mac OS X
#endif

	GLFWwindow* window = glfwCreateWindow(800, 600, "GraphicsEngine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}


	glViewport(0, 0, 800, 600);

	// resizes viewport when user resizes window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Generate and bind Vertex Array Object
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// Generate and bind Vertex Buffer Object
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Generate and compile vertex shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	const GLchar* vss = vertexShaderSrc.c_str(); // glShaderSource wants GLchar type
	glShaderSource(vertexShader, 1, &vss, NULL);
	glCompileShader(vertexShader);

	// Check vertex shader compilation results
	int vertexSuccess;
	char vertexInfoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vertexSuccess);
	if (!vertexSuccess)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, vertexInfoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << vertexInfoLog << std::endl;
	}



	// Generate and compile fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar* fss = fragmentShaderSrc.c_str();

	glShaderSource(fragmentShader, 1, &fss, NULL);
	glCompileShader(fragmentShader);

	// Check fragment shader compilation results
	int fragmentSuccess;
	char fragmentInfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragmentSuccess);
	if (!fragmentSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragmentInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragmentInfoLog << std::endl;
	}

	
	// Generate and link final shader program
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	// Check shaderProgram success
	int shaderSuccess;
	char shaderInfoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderSuccess);
	if (!shaderSuccess) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, shaderInfoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKINK::FAILED\n" 
			      << shaderInfoLog << std::endl;
	}

	glUseProgram(shaderProgram); // Shaders are now being used


	// Unneeded after linking to shaderProgram
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Tells OpenGL how the data is stored (3 floats per vertex)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


	float triangle[]{ // Unit triangle
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};


	float square[]{ // Unit square
		// Consists of two triangles
		-0.5f, 0.5f, 0.0f, // Top left
		-0.5f, -0.5f, 0.0f, // Bottom left
		0.5f, -0.5f, 0.0f, // Bottom right
		0.5f, 0.5f, 0.0f, // Top right
	};

	unsigned int indices[]{
		0, 1, 2,
		2, 3, 0,
	};

	// Generate and bind Element Buffer Object
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);


	// Copy unit triangle or square into currently bound buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Generate and bind Vertex Array Object
	unsigned int VAO2;
	glGenVertexArrays(1, &VAO2);
	glBindVertexArray(VAO2);

	// Generate and bind Vertex Buffer Object
	unsigned int VBO2;
	glGenBuffers(1, &VBO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
	    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}


	glfwTerminate();
	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}