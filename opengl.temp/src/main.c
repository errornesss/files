#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "include/glad.h"
#include "include/glfw.h"
#include "include/cglm.h"
#include "include/stb.h"

#include "utils/utils.h"
#include "config.h"

u32 CompileShader(u32 type, const char *source) {
  u32 id = glCreateShader(type);
  glShaderSource(id, 1, &source, NULL);
  glCompileShader(id);

  i32 success;
  const char *typeStr;
  switch (type) {
    case GL_VERTEX_SHADER: typeStr = "vertex"; break;
    case GL_FRAGMENT_SHADER: typeStr = "fragment"; break;
  }
  char infoLog[512];
  glGetShaderiv(id, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(id, sizeof(infoLog), NULL, infoLog);
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
    glGetProgramInfoLog(program, sizeof(infoLog), NULL, infoLog);
    printf("failed to link shader program\n%s", infoLog);
  }

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

void framebuffer_size_callback(GLFWwindow *window, i32 width, i32 height) {
  glViewport(0, 0, width, height);
}

void ProcessInput(GLFWwindow *window) {
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

  char *vertexShader = FileToString("../res/shaders/shader.vs"); 
  char *fragmentShader = FileToString("../res/shaders/shader.fs"); 
  u32 shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);

  free(vertexShader);
  free(fragmentShader);

  f32 verticies[] = {
//  | position           | colour                 | tex coord
    //  0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.5f, 1.0f,
    // -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,
    //  0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,  1.0f, 0.0f,

     0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,  1.0f, 0.0f,
  };

  u32 indicies[] = {
    0, 1, 2,
    2, 3, 0,
  };

  u32 VAO, VBO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

  u8 sov = 9 * sizeof(f32); // size of vertex 
  glVertexAttribPointer(0, 3, GL_FLOAT, false, sov, (void *)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 4, GL_FLOAT, false, sov, (void *)(3 * sizeof(f32)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, false, sov, (void *)(7 * sizeof(f32)));
  glEnableVertexAttribArray(2);

  u32 texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  i32 width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  uchar *data = stbi_load("../res/textures/wall.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    printf("failed to load texture\n");
  }
  stbi_image_free(data);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  i32 vertexColourLocation = glGetUniformLocation(shader, "uCol");

  while (!glfwWindowShouldClose(window)) {
    ProcessInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  
    {
      f32 colr = 0.5f + 0.5f * cos(glfwGetTime());
      f32 colg = 0.5f + 0.5f * cos(glfwGetTime() + 2);
      f32 colb = 0.5f + 0.5f * cos(glfwGetTime() + 4);
      glUniform4f(vertexColourLocation, colr, colg, colb, 1.0f);
    }

    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, sizeof(indicies)/sizeof(u32), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteTextures(1, &texture);
  glDeleteProgram(shader);

  glfwTerminate();
  return 0;
}
