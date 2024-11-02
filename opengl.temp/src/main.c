#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "../lib/glad.h"
#include "../lib/glfw.h"
#include "../lib/cglm.h"
#include "../lib/stb.h"

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
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
    glfwSetWindowShouldClose(window, true);
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

  GLFWwindow *window = glfwCreateWindow(WID, HEI, TITLE, NULL, NULL);
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

  glEnable(GL_DEPTH_TEST);

/*
  f32 verticies[] = {
//  | position            | colour                 | texcoord
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 1.0f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f,  1.0f, 0.0f,
  };
*/

  f32 verticies[] = {
//  | position            | texcoord
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
  };

  u32 indicies[] = {
    0, 1, 2, 2, 3, 0,
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 9,
    12, 13, 14, 14, 15, 13,
    16, 17, 18, 18, 19, 17,
    20, 21, 22, 22, 23, 21,
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

  u8 sov = 5 * sizeof(f32); // size of vertex 
  glVertexAttribPointer(0, 3, GL_FLOAT, false, sov, (void *)0);
  glEnableVertexAttribArray(0);
  // glVertexAttribPointer(1, 4, GL_FLOAT, false, sov, (void *)(3 * sizeof(f32)));
  // glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 2, GL_FLOAT, false, sov, (void *)(3 * sizeof(f32)));
  glEnableVertexAttribArray(1);

  stbi_set_flip_vertically_on_load(true);
  u32 texture0, texture1;
  glGenTextures(1, &texture0);
  glBindTexture(GL_TEXTURE_2D, texture0);
  i32 width, height, nrChannels;
  uchar *data = stbi_load("../res/textures/container.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    printf("failed to load texture1\n");
  }
  stbi_image_free(data);

  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  data = stbi_load("../res/textures/awesomeface.png", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    printf("failed to load texture2\n");
  }
  stbi_image_free(data);

  glUniform1i(glGetUniformLocation(shader, "texture0"), 0);
  glUniform1i(glGetUniformLocation(shader, "texture1"), 1);

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while (!glfwWindowShouldClose(window)) {
    ProcessInput(window);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* mat4 transform;
    glm_mat4_identity(transform);
    glm_scale_uni(transform, 0.5f);
    glm_rotate(transform, glfwGetTime(), (vec3){0.0f, 1.0f, 0.0f});
    glm_translate(transform, (vec3){cos(glfwGetTime())/2, sin(glfwGetTime())/2, 0});
    u32 transformLoc = glGetUniformLocation(shader, "transform");
    glUniformMatrix4fv(transformLoc, 1, false, transform[0]); */

    mat4 model, view, projection;
    glm_mat4_identity(model);
    glm_mat4_identity(view);
    glm_mat4_identity(projection);
    glm_rotate(model, glfwGetTime() * PI/2, (vec3){1.0f, 1.0f, 1.0f});
    glm_translate(view, (vec3){0.0f, 0.0f, -3.0f});
    glm_scale_uni(view, 1.0f);
    glm_perspective(PI/4, (float)WID/HEI, 0.1f, 100.0f, projection);
    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, false, model[0]);
    glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, false, view[0]);
    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, false, projection[0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture1);
  
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, sizeof(indicies)/sizeof(u32), GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  glDeleteTextures(1, &texture0);
  glDeleteTextures(1, &texture1);

  glDeleteProgram(shader);

  glfwTerminate();
  return 0;
}
