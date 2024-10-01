#version 460 core

out vec4 fragColour;

in vec4 ourColour;
in vec2 texCoord;

uniform vec4 uCol;
uniform sampler2D texture1;

void main() {
  fragColour = texture(texture1, texCoord) * uCol;
}
