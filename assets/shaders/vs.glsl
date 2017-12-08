#version 330 core
layout (location = 0) in vec2 vertex;

uniform mat4 model;
uniform mat4 projection;

void main()
{
    gl_Position = projection * model * vec2(vertex.xy);
}
