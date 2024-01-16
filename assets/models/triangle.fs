#version 330 core

out vec4 frag_color;

uniform vec4 uv4_custom_color;

void
main()
{
    frag_color = uv4_custom_color;
}
