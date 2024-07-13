#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 vertex_normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 lightPos;
out vec3 Normal, LightDir, ViewDir;

void main(){
    vec4 v = vec4(vertex, 1.0);
    gl_Position = projection * view * model * v;

    // compute normal in view space
    vec4 n = vec4(vertex_normal, 0.0);
    mat4 normalMat = transpose(inverse(view * model));
    Normal = (normalMat * n).xyz;

    // compute light direction in view space
    vec4 lp = view * vec4(lightPos, 1.0);
    vec4 P = (view * model * v);
    LightDir = (lp - P).xyz;

    // specular term
    ViewDir = -P.xyz;
}
