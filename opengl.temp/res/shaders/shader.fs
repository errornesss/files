#version 460 core

out vec4 fragColour;
in vec4 ourColour;

void main() {
  fragColour = vec4(ourColour.xyz, 0.0f);
}
