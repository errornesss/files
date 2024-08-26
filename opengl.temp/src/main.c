#include <stdio.h>
#include <stdbool.h>

#include "include/glad.h"
#include "include/glfw3.h"

#include "utils/utils.h"
#include "config.h"

void framebuffer_size_callback(GLFWwindow *window, i32 width, i32 height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  /* if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
    glfwSetWindowShouldClose(window, true); */
}

i32 main(/* i32 argc, char *argv[] */) {
  if (!glfwInit()) {
    printf("glfw failed to initialise\n");
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_RESIZABLE, false);

  GLFWwindow *window = glfwCreateWindow(WID, HEI, "OpenGL Template", NULL, NULL);
  if (!window) {
    printf("failed to create window\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("failed to initialise glad\n");
    return -1;
  }

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
