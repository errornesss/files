#version 460 core

layout (location = 0) in vec3 aPosition;
// layout (location = 1) in vec4 aColour;
layout (location = 1) in vec2 aTexCoord;

out vec4 outCol;
out vec2 texCoord;

uniform mat4 transform;

void main() {
  gl_Position = vec4(aPosition, 1.0f) * transform;
  // outCol = aColour;
  texCoord = aTexCoord;
}
