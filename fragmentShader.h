#pragma once

#include <string>


static const std::string fragmentShaderSrc = R"(
#version 330 core

in vec3 ourColor;
out vec4 FragColor;

// uniform vec4 ourColor;

void main()
{
    // Sets red, green, blue, alpha values
    FragColor = vec4(ourColor, 1.0f);
}
)";
