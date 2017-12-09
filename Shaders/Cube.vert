#version 440 core

layout (location = 0) in vec3 Pos;
layout (location = 1) in vec2 Uv;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

out vec2 UV;

void main()
{
    gl_Position = Projection * View * Model * vec4(Pos, 1.0);
    UV = Uv;
}