// Made by Gabriel Leonardo Martins - a2317940

//  Created by Gabriel Leonardo M de Oliveira - 24/05/2022.

#include <iostream>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

//Global Variables
const int gWindowWidth = 800;
const int gWindowHeight = 600;
const char* TITLE = { "Hello Triangle" };
GLFWwindow* gWindow = NULL;

bool pWireFrame = false;

GLuint vao[8], vbo[8];
GLint shaderProgram;

//Shaders
const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"layout (location = 1) in vec3 color;"
"\n"
"uniform mat4 projection;"
"uniform mat4 transform;"
"uniform mat4 rotating2;"

"out vec3 vert_color;"
"void main()"
"{"
"   vert_color = color;"
"   gl_Position = projection * transform * vec4(pos.x, pos.y, pos.z, 1.0) * rotating2;"
"}";

const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"in vec3 vert_color;"
"out vec4 frag_color;"
"void main()"
"{"
"    frag_color = vec4(vert_color, 1.0f);"
"}";

bool initOpenGL();
void startup();
void curva();
void generateVs(GLuint indice, GLfloat* vertices, GLuint tamanho);
void renderCurva();
void render(GLuint ivao, GLuint qntdT, GLfloat tx, GLfloat ty,
    GLfloat sx, GLfloat sy, GLfloat angulo, GLfloat angEixo);
void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode);
void shutdown();

int main(void)
{

    if (!initOpenGL())
    {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }

    startup();

    while (!glfwWindowShouldClose(gWindow))
    {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        renderCurva();

        glfwSwapBuffers(gWindow);
    }

    shutdown();
    glfwTerminate();

    return 0;
}

bool initOpenGL()
{
    if (!glfwInit())
    {
        std::cerr << "GLFW initialization failed" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    gWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, TITLE, NULL, NULL);
    if (gWindow == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(gWindow);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    glfwSetKeyCallback(gWindow, glfw_key);

    return true;
}

void startup()
{
    curva();

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSrc, NULL);
    glCompileShader(vs);

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fs);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    glClearColor(0.23f, 0.38f, 0.47f, 1.0f);
}

void generateVs(GLuint indice, GLfloat* vertices, GLuint tamanho)
{
    glGenBuffers(1, &vbo[indice]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[indice]);
    glBufferData(GL_ARRAY_BUFFER, tamanho, vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao[indice]);
    glBindVertexArray(vao[indice]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), NULL);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
}

void curva()
{
    uint i = 0, t = 2;

    GLfloat A[] = { 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f },
            B[] = { 0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f },
            C[] = { 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f };

    GLfloat vertices[100];

    while (i < 100)
    {
        if (i == 0)
        {
            vertices[i++] = A[0];
            vertices[i++] = A[1];
            vertices[i++] = 0.0f;
            vertices[i++] = 1.0f;
            vertices[i++] = 1.0f;
            vertices[i++] = 1.0f;
        }
        else
        {
            if (i == 93)
            {
                vertices[i++] = C[0];
                vertices[i++] = C[1];
                vertices[i++] = 0.0f;
                vertices[i++] = 1.0f;
                vertices[i++] = 1.0f;
                vertices[i++] = 1.0f;
            }
            else
            {
                vertices[i++] = pow((1 - t), 2) * A[0] + 2 * (1 - t) * B[0] + pow(t, 2) * C[0];
                vertices[i++] = pow((1 - t), 2) * A[1] + 2 * (1 - t) * B[1] + pow(t, 2) * C[1];
                vertices[i++] = 0.0f;
                vertices[i++] = 1.0f;
                vertices[i++] = 1.0f;
                vertices[i++] = 1.0f;
            }
        }
    }

    generateVs(0, vertices, 100);
}

void renderCurva()
{
    glUseProgram(shaderProgram);


    glBindVertexArray(vao[0]);
    glDrawArrays(GL_LINES, 0, 100);

    glBindVertexArray(0);
}

void render(GLuint ivao, GLuint qntdT, GLfloat tx, GLfloat ty,
    GLfloat sx, GLfloat sy, GLfloat angulo, GLfloat angEixo)
{
    mat4 trans = mat4(1.0f);
    trans = translate(trans, vec3(tx * sx, ty * sy, 0.0f));
    trans = scale(trans, vec3(sx, sy, 0.0f));
    trans = rotate(trans, radians(angEixo), vec3(0.0f, 0.0f, 1.0f));

    glUseProgram(shaderProgram);
    GLuint matrix = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

    trans = mat4(1.0f);
    trans = rotate(trans, radians(angulo), vec3(0.0f, 0.0f, 1.0f));
    matrix = glGetUniformLocation(shaderProgram, "rotating2");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, value_ptr(trans));

    mat4 projection = ortho(-50.0f, 50.0f, -50.0f, 50.0f, -1.0f, 1.0f);
    GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));

    glBindVertexArray(vao[ivao]);
    glDrawArrays(GL_TRIANGLES, 0, qntdT * 3);

    glBindVertexArray(0);
}

void shutdown()
{
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vao[0]);
    glDeleteVertexArrays(1, &vao[1]);
    glDeleteVertexArrays(1, &vao[2]);
    glDeleteVertexArrays(1, &vao[3]);
    glDeleteVertexArrays(1, &vao[4]);
    glDeleteVertexArrays(1, &vao[5]);
    glDeleteVertexArrays(1, &vao[6]);
    glDeleteVertexArrays(1, &vao[7]);
    glDeleteBuffers(1, &vbo[0]);
    glDeleteBuffers(1, &vbo[1]);
    glDeleteBuffers(1, &vbo[2]);
    glDeleteBuffers(1, &vbo[3]);
    glDeleteBuffers(1, &vbo[4]);
    glDeleteBuffers(1, &vbo[5]);
    glDeleteBuffers(1, &vbo[6]);
    glDeleteBuffers(1, &vbo[7]);
}

void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(gWindow, GL_TRUE);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        pWireFrame = !pWireFrame;
        if (pWireFrame)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}