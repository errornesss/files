#version 460 core

layout (location = 0) in vec3 aPosition;
// layout (location = 1) in vec4 aColour;
layout (location = 1) in vec2 aTexCoord;

out vec4 outCol;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
  gl_Position = projection * view * model * vec4(aPosition, 1.0f);
  // outCol = aColour;
  texCoord = aTexCoord;
}
