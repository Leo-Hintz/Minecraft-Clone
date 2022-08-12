#version 450


layout(location = 0) in vec4 pos;
 
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

layout(location = 0) out vec3 col;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * pos;
    col = vec3(1,0,0);
}