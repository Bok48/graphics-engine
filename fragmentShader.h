#pragma once

#include <string>


static const std::string fragmentShaderSrc = R"(
#version 330 core
out vec4 FragColor;

void main()
{
    // Sets red, green, blue, alpha values
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
)";