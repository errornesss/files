#version 460 core

out vec4 fragColour;
in vec4 ourColour;

void main() {
  fragColour = ourColour;
}
