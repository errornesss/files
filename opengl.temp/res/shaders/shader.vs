#version 460 core

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec4 aColour;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColour;
out vec2 texCoord;

void main() {
  gl_Position = aPosition;
  ourColour = aColour;
  texCoord = aTexCoord;
}
