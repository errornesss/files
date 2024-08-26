#include <stdio.h>

#include "include/glfw3.h"

#include "utils/utils.h"

i32 main(/* i32 argc, char *argv[] */) {
  if (!glfwInit()) {
    printf("glfw failed to initialise");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(640, 480, "OpenGL Template", NULL, NULL);
  if (!window) {
    printf("failed to create window");
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glfwTerminate();
  return 0;
}
