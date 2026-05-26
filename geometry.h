#pragma once


float unitTriangle[]{ // Unit triangle
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
};


float unitSquare[]{ // Unit square
	// Consists of two triangles
	-0.5f, 0.5f, 0.0f, // Top left
	-0.5f, -0.5f, 0.0f, // Bottom left
	0.5f, -0.5f, 0.0f, // Bottom right
	0.5f, 0.5f, 0.0f, // Top right
};

unsigned int squareIndices[]{
	0, 1, 2,
	2, 3, 0,
};