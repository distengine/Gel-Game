#version 440 core

uniform sampler2D texture1;

in vec2 UV;

out vec4 FragColor;

void main()
{
    FragColor = texture(texture1, UV);
}