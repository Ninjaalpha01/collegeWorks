//
//  main.cpp
//  TemplateJanela
//
//  Created by Mauren Louise Sguario on 18/11/20.
// 1 - Primeiro Triangulo
//

#include <iostream>
#include <stack>
using namespace std;

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#define numVAOs 1
#define numVBOs 3

//Global Variables
const int gWindowWidth = 800;
const int gWindowHeight = 600;
const char* TITLE = { "Hello Cube" };
GLFWwindow* gWindow = NULL;
bool gWireframe = false;
GLfloat cameraX, cameraY, cameraZ;
GLfloat cubeLocX, cubeLocY, cubeLocZ;
GLfloat pyramidLocX, pyramidLocY, pyramidLocZ;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];
stack<glm::mat4> mvStack;

float deltaTime = 0.0f;    // Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

vec3 cameraPos = vec3(0.0f, 0.0f, 3.0f);
vec3 cameraFront = vec3(0.0f, 0.0f, -1.0f);
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);


GLuint mvLoc, vmLoc, projLoc;
int width, height;


void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode);
bool initOpenGL();
GLuint createShaderProgram();
void init();
void setupBuffer();
void cubo(int n);
void triangulo(int n);

void display(GLuint shaderProgram, double currentTime);

int main(void)
{
    GLuint shaderProgram;

    if (!initOpenGL())
    {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }

    init();
    setupBuffer();
    cubo(0);
    cubo(2);
    triangulo(1);

    shaderProgram = createShaderProgram();

    //Entre 0 e 1 - 0 -> preto, 1 - Branco (0 a 255, 0 -> preto, 255 - Branco);
    glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gWindow))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //Render the triangle
        display(shaderProgram, glfwGetTime());

        /* Swap front and back buffers */
        glfwSwapBuffers(gWindow);

    }

    //Clean UP
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, vao);
    glDeleteBuffers(1, vbo);

    glfwTerminate();
    return 0;
}

///
bool initOpenGL()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cerr << "GLFW initialization failed" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //only to support MAC
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, TITLE, NULL, NULL);
    if (gWindow == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(gWindow);


    //Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glfwSetKeyCallback(gWindow, glfw_key);
    return true;
}

///
void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    const float cameraSpeed = 0.05f;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(gWindow, GL_TRUE);
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        gWireframe = !gWireframe;
        if (gWireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        cameraPos += cameraSpeed + cameraFront;
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
        cameraPos -= cameraSpeed + cameraFront;
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;


}

void cubo(int n)
{
    //36 vertices, 12 triangles, 2x2x2 cube
    GLfloat cubePosition[]{
        -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f, -1.0f,
         1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f, -1.0f,
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo[n]); //cubePosition
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubePosition), cubePosition, GL_STATIC_DRAW);

}

void triangulo(int n)
{
    //18 vertices, 6 triangles,
    GLfloat pyramidPosition[]{
        -1.0f, -1.0f,  1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  1.0f, 0.0f, //front face
         1.0f, -1.0f,  1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  1.0f, 0.0f, //right face
         1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  1.0f, 0.0f, //back face
        -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  1.0f, 0.0f, //left face
        -1.0f, -1.0f, -1.0f,  1.0f, -1.0f,  1.0f, -1.0f, -1.0f, 1.0f, //base - left face
         1.0f, -1.0f,  1.0f, -1.0f, -1.0f, -1.0f,  1.0f, -1.0f, -1.0f //base - right face
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo[n]); //pyramidPosition
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidPosition), pyramidPosition, GL_STATIC_DRAW);

}

void setupBuffer()
{
    //Buffers on the GPU
    //Modern Opengl requires that we use a vertex array object
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
    glGenBuffers(numVBOs, vbo);

}

GLuint createShaderProgram()
{
    //Shaders
    const GLchar* vertexShaderSrc =
        "#version 330 core\n"
        "layout (location = 0) in vec3 pos;"
        "uniform mat4 mv_matrix;"
        "uniform mat4 vm_matrix;"
        "uniform mat4 proj_matrix;"
        "out vec4 varyingColor;"
        "void main()"
        "{"
        "   varyingColor = vec4(pos, 1.0) * 0.5 + vec4(0.5, 0.5, 0.5, 0.5);"
        "   gl_Position = proj_matrix * vm_matrix * mv_matrix * vec4(pos.x, pos.y, pos.z, 1.0);"
        "}";

    const GLchar* fragmentShaderSrc =
        "#version 330 core\n"
        "out vec4 frag_color;"
        "in vec4 varyingColor;"
        "void main()"
        "{"
        "    frag_color = varyingColor;"
        "}";

    //Create vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSrc, NULL);
    glCompileShader(vs);

    //Create fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fs);

    //Create a program shader
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return shaderProgram;

}

void init()
{
    cameraX = 0.0f; cameraY = 0.0f; cameraZ = 8.0f;
    cubeLocX = 0.0f; cubeLocY = -2.0f; cubeLocZ = 0.0f;
    pyramidLocX = 2.0f; pyramidLocY = -5.0f; pyramidLocZ = 0.0f;


}

void display(GLuint shaderProgram, double currentTime)
{
    glClear(GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    //model view matrix
    mvLoc = glGetUniformLocation(shaderProgram, "mv_matrix");

    //view matrix
    vmLoc = glGetUniformLocation(shaderProgram, "vm_matrix");

    //projection matrix
    projLoc = glGetUniformLocation(shaderProgram, "proj_matrix");

    //cube 1
    //build model view (translate, rotate, scale
    //mat4 trans = translate(mat4(1.0f), vec3(cubeLocX, cubeLocY, cubeLocZ));
    mat4 mvT = translate(mat4(1.0f), vec3(-cameraX, -cameraY, -cameraZ));

    //build camera
    vec3 Eye(0.0f, 0.0f, 10.0f);
    //vec3 Center(0.0f, 0.0f, 0.0f);
    //vec3 Up(0.0f, 1.0f, 0.0f);
    //mat4 vmMat = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    mat4 vmMat = lookAt(Eye, cameraPos + cameraFront, cameraUp);

    //empilha matriz da camera na pilha
    mvStack.push(vmMat);

    //build perspective matrix
    glfwGetFramebufferSize(gWindow, &width, &height);
    GLfloat aspect = (GLfloat)gWindowWidth / (GLfloat)gWindowHeight;
    mat4 projMat = perspective(radians(45.0f), aspect, 0.1f, 1000.0f);
    //mat4 projMat = ortho(-30.0f, 30.0f, -30.0f, 30.0f);

    mvStack.push(mvStack.top());
    mvStack.top() *= translate(mat4(1.0f), vec3(0.0f, -2.0f, 0.0f));//position
    mvStack.push(mvStack.top());
    mvStack.top() *= rotate(mat4(1.0f), (float)currentTime, vec3(1.0f, 0.0f, 0.0f));//rotation

    //copy uniform
    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, value_ptr(mvStack.top()));
    glUniformMatrix4fv(vmLoc, 1, GL_FALSE, value_ptr(vmMat));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projMat));

    //draw Cube
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    mvStack.pop();

    //cube 2
    //push view matrix onto the stack
    //build model view (translate, rotate, scale
    //mat4 trans = translate(mat4(1.0f), vec3(cubeLocX, cubeLocY, cubeLocZ));
    mvT = translate(mat4(1.0f), vec3(-cameraX, -cameraY, -cameraZ));
    mvStack.push(mvT);

    //build camera
    //vec3 Eye(0.0f, 0.0f, 10.0f);
    //vec3 Center(0.0f, 0.0f, 0.0f);
    //vec3 Up(0.0f, 1.0f, 0.0f);
    vmMat = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

    mvStack.push(mvStack.top());
    mvStack.top() *= translate(mat4(1.0f), vec3(0.0f, 3.0f, 0.0f));//position
    mvStack.push(mvStack.top());
    mvStack.top() *= rotate(mat4(1.0f), (float)currentTime, vec3(0.0f, 0.0f, 1.0f));//rotation

    //copy uniform
    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, value_ptr(mvStack.top()));
    glUniformMatrix4fv(vmLoc, 1, GL_FALSE, value_ptr(vmMat));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projMat));

    //draw Cube
    glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    mvStack.pop();

    //draw Pyramid

    //build model view (translate, rotate, scale
   // trans = translate(mat4(1.0f), vec3(pyramidLocX, pyramidLocY, pyramidLocZ));
    //mvT = translate(mat4(1.0f), vec3(-cameraX, -cameraY, -cameraZ));
    //mvMat = trans * mvT;
    mvStack.push(mvStack.top());
    mvStack.top() *= translate(glm::mat4(1.0f), vec3(sin((float)currentTime) * 4.0, 0.0f, cos((float)currentTime) * 4.0)); mvStack.push(mvStack.top());
    mvStack.top() *= rotate(mat4(1.0f), (float)currentTime, vec3(0.0, 1.0, 0.0));//copy uniform

    glUniformMatrix4fv(mvLoc, 1, GL_FALSE, value_ptr(mvStack.top()));
    glUniformMatrix4fv(vmLoc, 1, GL_FALSE, value_ptr(vmMat));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(projMat));


    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);
    glDrawArrays(GL_TRIANGLES, 0, 18);
    mvStack.pop();

}
