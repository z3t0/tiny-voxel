#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {

  glfwInit();

  // Context Creation
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "tiny voxel", NULL, NULL);

  glfwMakeContextCurrent(window);

  // GLEW: Determines available OpenGL functions on machine
  glewExperimental = GL_TRUE;
  glewInit();

  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);
  printf("%u\n", vertexBuffer);

  // Event Loop
  while(!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  
  }

  // Close window if escape is pressed
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }

  glfwTerminate();
}
