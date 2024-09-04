#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "include/glad.h"
#include "include/glfw3.h"

#include "utils/utils.h"
#include "config.h"

u32 CompileShader(u32 type, const char *source) {
  u32 id = glCreateShader(type);
  glShaderSource(id, 1, &source, NULL);
  glCompileShader(id);

  i32 success;
  const char *typeStr;
  switch (type) {
    case GL_VERTEX_SHADER: { typeStr = "vertex"; } break;
    case GL_FRAGMENT_SHADER: { typeStr = "fragment"; } break;
  }
  char infoLog[512];
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id, sizeof(infoLog)/sizeof(infoLog[0]), NULL, infoLog);
    printf("%s shader failed to compile\n%s\n", typeStr, infoLog);
  }

  return id;
}

u32 CreateShader(const char *vertexShader, const char *fragmentShader) {
  u32 program = glCreateProgram();
  u32 vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  u32 fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glValidateProgram(program);

  i32 success;
  char infoLog[512];
  glGetProgramiv(program, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(program, sizeof(infoLog)/sizeof(infoLog[0]), NULL, infoLog);
    printf("failed to link shader program\n%s", infoLog);
  }

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

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

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
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

  f32 verticies[] = {
    0.0f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f
  };

  u32 indicies[] = {
    0, 1, 2,
  };

  u32 VAO, VBO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(verticies[0]), (void *)0);
  glEnableVertexAttribArray(0);

  char *vertexShader = FileToString("shaders/shader.vs"); 
  char *fragmentShader = FileToString("shaders/shader.fs"); 
  u32 shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);

  free(vertexShader);
  free(fragmentShader);

  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, sizeof(indicies)/sizeof(indicies[0]), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shader);
  glfwTerminate();
  return 0;
}
