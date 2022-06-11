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
const char* TITLE = { "Nova janela" };
GLFWwindow* pWindow = NULL;

GLuint vao;
GLuint program;

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
    /*
    //Criando vetor de vértices
    GLfloat vertices[]{
        0.0f, 0.5f, 0.0f, //top
        0.5f, -0.5f, 0.0f, //right
        -0.5f, -0.5f, 0.0f, //left
    };

    Buffer on the GPU
    GLuint vao; //Buffer para vbo
    GLuint vbo; //Array, Vértices e Atributos (Obrigatório pois vai criar o buffer na GPU)

    glGenBuffers(1, &vbo); //Criando 1 buffer com as informações do vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo); //informações que estão no vbo são do tipo array
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //Usado o Static_Draw pq vai ser usado muitas vezes; como ultimo parametro pode ser GL_STREAM_DRAW

    //Modern Opengl vao
    */
    
    startup();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(pWindow))
    {
        // Render here
        render();

        // Poll for and process events
        glfwPollEvents();

        //glClear(GL_COLOR_BUFFER_BIT);

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

    //Entre 0 e 1 - 0 -> preto, 1 - Branco (0 a 255, 0 -> preto, 255 - Branco);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    return true;
}

//funcao para escrever o shader program
void startup()
{
    //vertex shader string que vai conter codigo GLSL
    static const char* vs_source[] =
    {
        "#version 330 core                                      \n"
        "                                                       \n"
        "void main(void)                                        \n"
        "{                                                      \n"
        "   gl_Position = vec4(0.0, 0.0, 0.0, 1.0);             \n"
        "}                                                      \n"

    };

    //cor RGBA - red, green, blue, alpha
    static const char* fs_source[] =
    {
        "#version 330 core                                      \n"
        "                                                       \n"
        "out vec4 color;                                        \n"
        "                                                       \n"
        "void main(void)                                        \n"
        "{                                                      \n"
        "   color = vec4(0.0, 0.8, 1.0, 1.0);                   \n"
        "}                                                      \n"
    };

    //Create Program
    program = glCreateProgram();

    //create and compile vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, vs_source, NULL);
    glCompileShader(vs);

    //create and compile fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, fs_source, NULL);
    glCompileShader(fs);

    //Attach shaders to program and link it
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    //Create vertex array object (VAO)
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void render()
{
    const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glClearBufferfv(GL_COLOR, 0, color);
    glUseProgram(program);
    glPointSize(40.0f);
    glDrawArrays(GL_POINTS, 0, 1);
}

void shutdown()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(program);
}
