#version 330 core

layout (location = 0) in vec3 attr_pos;

void
main()
{
    // translate to the top left corner a bit
    vec3 tr_pos = attr_pos;
    gl_Position = vec4(tr_pos.x, tr_pos.y, tr_pos.z, 1.0);
}
