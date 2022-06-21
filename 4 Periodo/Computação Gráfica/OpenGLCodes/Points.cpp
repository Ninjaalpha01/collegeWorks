//
//  main.cpp
//  TemplateJanela
//
//  Created by Mauren Louise Sguario on 18/11/20.
// 1 - Mover as inicializações initOpenGL(), limpar main()
// 2 - gWindow -> variavel global

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
const char* TITLE = { "Hello Triangle - part I" };
GLFWwindow* gWindow = NULL;

//Shaders
const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
"layout (location = 1) in vec3 color;"
"\n"
"uniform mat4 projection;"
"uniform mat4 translation;"
"uniform mat4 scaling;"
"uniform mat4 rotating;"
"out vec3 vert_color;"
"void main()"
"{"
"   vert_color = color;"
"   gl_Position = projection * translation * vec4(pos.x, pos.y, pos.z, 1.0);"
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

int main(void)
{

    if (!initOpenGL())
    {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }

    //Array of vertices for a triangle
    GLfloat vertices[]{
        //position           //Color
         0.0f,  0.0f, 0.0f,   1.0f, 0.0f, 0.0f,  //Top Red
        20.0f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f,  //Right Green
        20.0f, 20.0f, 0.0f,   0.0f, 0.0f, 1.0f,  //Left Blue
         0.0f, 20.0f, 0.0f,   0.0f, 1.0f, 1.0f,  //Left Blue
        10.0f, 25.0f, 0.0f,   1.0f, 0.0f, 1.0f,  //Left Blue
    };

    //Buffers on the GPU
    GLuint vbo, vao;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Modern Opengl requires that we use a vertex array object
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //Position attribute, identified as "0"
    glVertexAttribPointer(
        0, //Attribute index, "0". The vertex shader should have layou "0" for position of the vertex
        3, //Number of components of attribute "0". In this case 3 floats for x, y, z.
        GL_FLOAT, //The data type of each component
        GL_FALSE, //Normalize component values to [-1,1]
        sizeof(GLfloat) * 6, //Stride, number of bytes between two instances of the attribute in the buffer
        NULL); //offset

        //Color attribute, identified as "1"
    glVertexAttribPointer(
        1, //Attribute index, "1". The vertex shader should have layou "1" for color of the each vertex
        3, //Number of components of attribute "1". In this case 3 floats for r, g, b.
        GL_FLOAT, //The data type of each component
        GL_FALSE, //Normalize component values to [-1,1]
        sizeof(GLfloat) * 6, //Stride, number of bytes between two instances of the attribute in the buffer
        (GLvoid*)(sizeof(GLfloat) * 3)); //offset


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    //Create vertex shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertexShaderSrc, NULL);
    glCompileShader(vs);

    //Create fragment shader
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
    glCompileShader(fs);

    //Create a program shader
    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);

    glDeleteShader(vs);
    glDeleteShader(fs);

    //Entre 0 e 1 - 0 -> preto, 1 - Branco (0 a 255, 0 -> preto, 255 - Branco);
    glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gWindow))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //Render the triangle
        glUseProgram(shaderProgram);

        //translation
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(15.0f, 15.0f, 0.0f));
        GLuint matrix = glGetUniformLocation(shaderProgram, "translation");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

        //scaling
        trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
        matrix = glGetUniformLocation(shaderProgram, "scaling");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

        //rotating
        trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
        matrix = glGetUniformLocation(shaderProgram, "rotating");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));


        glm::mat4 projection = glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, -1.0f, 1.0f);

        GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
        glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));


        glBindVertexArray(vao);
        glPointSize(10.0f);
        glDrawArrays(GL_POINTS, 0, 5);
        glBindVertexArray(0);

        /* Swap front and back buffers */
        glfwSwapBuffers(gWindow);
    }

    //Clean UP
    glDeleteProgram(shaderProgram);
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);

    glfwTerminate();
    return 0;
}

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
    return true;
}