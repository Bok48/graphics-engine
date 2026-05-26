#pragma once


float unitTriangle[]{ // Unit triangle
	// Positions         // Colors
	-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
};


float unitSquare[]{ // Unit square
	// Consists of two triangles
	-0.5f,  0.5f, 0.0f,  1.0f, 0.5f, 0.2f, // Top left
	-0.5f, -0.5f, 0.0f,  1.0f, 0.5f, 0.2f, // Bottom left
	 0.5f, -0.5f, 0.0f,  1.0f, 0.5f, 0.2f, // Bottom right
	 0.5f,  0.5f, 0.0f,  1.0f, 0.5f, 0.2f, // Top right
};

// Tells which vertexes of a square to use
unsigned int squareIndices[]{
	0, 1, 2,
	2, 3, 0,
};