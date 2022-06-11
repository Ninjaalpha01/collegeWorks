//
//  main.cpp
//  Created by Gabriel Leonardo Martins on 16/03/2022
//

#include <iostream>

//GLEW
#define GLEW_STATIC
#include <GL/glew.h>

//GLFW
#include <GLFW/glfw3.h>

//OpenGL/gl.h
#include <gl/gl.h>

//OpenGL Mathematics
#include <glm/glm.hpp>

//Global Variables
const int gWindowWidth = 800;
const int gWindowHeight = 600;
const char* TITLE = { "Hello Triangle" };

GLFWwindow* pWindow = NULL;
GLuint shaderProgram;
GLuint vao [2];
GLuint vbo [2];//Array, Vértices e Atributos (Obrigatório pois vai criar o buffer na GPU)

//vertex shader string que vai conter codigo GLSL
//"uniform vec2 posOffset;                                \n"
//"gl_Position = vec4(pos.x + posOffset.x, pos.y + posOffset.y, pos.z, 1.0);"
static const char* vs_source[] =
{
    "#version 330 core                                      \n"
    "                                                       \n"
    "layout (location = 0) in vec3 pos;                     \n"
    "layout (location = 1) in vec3 color;                   \n"
    "out vec3 vert_color;                                   \n"
    "                                                       \n"
    "void main()                                            \n"
    "{                                                      \n"
    "   gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);       \n"
    "   vert_color = color;                                 \n"
    "}                                                      \n"

};

//cor RGBA - red, green, blue, alpha
static const char* fs_source[] =
{
    "#version 330 core                                      \n"
    "                                                       \n"
    "in vec3 vert_color;                                    \n"
    "out vec4 frag_color;                                   \n"
    "                                                       \n"
    "void main()                                            \n"
    "{                                                      \n"
    "   frag_color = vec4(vert_color, 1.0f);                \n"
    "//single color down                                    \n"       
    "   //frag_color = vec4(0.0f, 0.8f, 0.0f, 1.0f);        \n"
    "}                                                      \n"
};

bool initOpenGL();
void startup();
void render();
void shutdown();

int main(void)
{

    if (!initOpenGL())
    {
        //ocorrencia de erro
        std::cerr << "GLFW initialization failed" << std::endl;
        return -1;
    }

    startup();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(pWindow))
    {
        // Poll for and process events
        glfwPollEvents();

        // Render here
        render();

        // Swap front and back buffers
        glfwSwapBuffers(pWindow);
    }

    shutdown();

    //Clean UP
    glfwTerminate();

    return 0;
}

//Inicialização GLFW e OpenGL
bool initOpenGL()
{
    // Initialize the library
    if (!glfwInit())
    {
        std::cerr << "GLFW initialization failed" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //only to support MAC
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a windowed mode window and its OpenGL context
    pWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, TITLE, NULL, NULL);
    if (pWindow == NULL)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    // Make the window's context current
    glfwMakeContextCurrent(pWindow);

    //Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    return true;
}

//funcao para escrever o shader program
void startup()
{
    //Create Program
    shaderProgram = glCreateProgram();

    //Array of vertices for a triangle
    //first triangle
    GLfloat vertices[]{ //Posição
        0.0f, 0.5f, 0.0f, 0.2f, 0.0f, 0.5f, //top
        0.5f, 0.0f, 0.0f, 0.0f, 0.8f, 0.0f,//right
        0.5f, 0.5f, 0.0f, 0.5f, 0.0f, 0.0f//left
    };

    //second triangle
    GLfloat vertices_PC[]{ //Posição e cor
        0.0f, 0.5f, 0.0f, 0.5f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.8f, 0.0f,
        0.5f, 0.0f, 0.0f, 0.2f, 0.0f, 0.5f
    };

    //Buffer on the GPU
    glGenBuffers(1, &vbo[0]); //Criando 1 buffer com as informações do vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); //informações que estão no vbo são do tipo array
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //Usado o Static_Draw pq vai ser usado muitas vezes; como ultimo parametro pode ser GL_STREAM_DRAW

    //Create vertex array object (VAO)
    glGenVertexArrays(1, &vao[0]);
    glBindVertexArray(vao[0]);
    glVertexAttribPointer(
        0, //Attribute index/ID, "0". The vertex shader should have layout "0" for position of the vertex
        3, // Number of components of attribute "0". In this case 3 floats for x, y, z.
        GL_FLOAT, //The data type of each component
        GL_FALSE, //Normalize component values to [-1,1]
        6*sizeof(GLfloat), //Stride, number of bytes between two instances of the attribute in the buffer
        (GLvoid*)(sizeof(GLfloat)*0)); //Offset
    glVertexAttribPointer(
        1, //Attribute index/ID, "0". The vertex shader should have layout "0" for position of the vertex
        3, // Number of components of attribute "0". In this case 3 floats for x, y, z.
        GL_FLOAT, //The data type of each component
        GL_FALSE, //Normalize component values to [-1,1]
        6 * sizeof(GLfloat), //Stride, number of bytes between two instances of the attribute in the buffer
        (GLvoid*)(sizeof(GLfloat) * 3)); //Offset

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &vbo[1]); //Criando 1 buffer com as informações do vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]); //informações que estão no vbo são do tipo array
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_PC), vertices_PC, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao[1]);
    glBindVertexArray(vao[1]);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 0));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(sizeof(GLfloat) * 3));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //create and compile vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, vs_source, NULL);
    glCompileShader(vs);

    //create and compile fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, fs_source, NULL);
    glCompileShader(fs);

    //Attach shaders to program and link it
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);
}

void render()
{
    const GLfloat color[] = { 0.23f, 0.38f, 0.47, 1.0f };
    glClearBufferfv(GL_COLOR, 0, color);
    //Render the triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(vao[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(vao[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    
    /* point
    const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, color);
    glUseProgram(shaderProgram);
    glPointSize(40.0f);
    glDrawArrays(GL_POINTS, 0, 1);
    */

    //swap buffer na main
}


void shutdown()
{
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vao[0]);
    glDeleteVertexArrays(1, &vao[1]);
    glDeleteBuffers(1, &vbo[0]);
    glDeleteBuffers(1, &vbo[1]);
}