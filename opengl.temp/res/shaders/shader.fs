#version 460 core

out vec4 fragColour;

// in vec4 outCol;
in vec2 texCoord;

uniform sampler2D texture0;
uniform sampler2D texture1;

void main() {
  fragColour = mix(texture(texture0, texCoord), texture(texture1, texCoord), 0.2f);
}
