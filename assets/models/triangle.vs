#version 330 core

layout (location = 0) in vec3 attr_pos;

out vec4 uv4_custom_color;

void
main()
{
    gl_Position = vec4(attr_pos.x * 0.5, attr_pos.y, attr_pos.z, 1.0);
}
