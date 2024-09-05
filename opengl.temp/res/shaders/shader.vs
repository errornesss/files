#version 460 core

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec4 aColour;
out vec4 ourColour;

void main() {
  gl_Position = aPosition;
  ourColour = aColour;
}
