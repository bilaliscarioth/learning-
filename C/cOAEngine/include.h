#include <GLFW/glfw3.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <glad/glad.h>
#include <GL/glew.h>
#include <stdio.h>

#define MAX_SPEED 0.4
#define ZOOM_SPEED 0.1
#define SPEED 0.1

struct Vector3D {
	float x, y, z;
} Vector3D;

struct Vector3D createVector3D(float x, float y, float z){
	struct Vector3D temp;
	temp.x = x;
	temp.y = y;
	temp.z = z;
	return temp;
};

void close();
void framebufferSizeCallback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
