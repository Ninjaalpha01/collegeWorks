// UTFPR - Ciencia da Computacao
// Created by Gabriel Leonardo Martins - ra:2317940

//declaração de bibliotecas
#define GLEW_STATIC
#include <iostream>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gl/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

//constantes de características da window
const int gWindowWidth = 800;
const int gWindowHeight = 700;
const char* TITLE = "Lista de Exercicio 1";

//variáveis globais
GLFWwindow* pWindow = NULL;
GLuint shaderProgram;
GLuint vao[13];
GLuint vbo[13];
GLuint ebo[2];

//vertex shader
static const char* vs_source[] =
{
	"#version 330 core                                      \n"
	"                                                       \n"
	"layout (location = 0) in vec3 pos;                     \n"
	"layout (location = 1) in vec3 color;                   \n"
	"uniform mat4 projection;								\n"
	"uniform mat4 translation;								\n"
	"uniform mat4 rotating;									\n"
	"out vec3 vert_color;                                   \n"
	"                                                       \n"
	"void main()                                            \n"
	"{                                                      \n"
	"   gl_Position = projection * translation * vec4(pos.x, pos.y, pos.z, 1.0);\n"
	"   vert_color = color;                                 \n"
	"}                                                      \n"
};

//fragment shader
static const char* fs_source[] =
{
	"#version 330 core                                      \n"
	"                                                       \n"
	"in vec3 vert_color;                                    \n"
	"out vec4 frag_color;                                   \n"
	"//uniform vec4 ourColor;								\n"
	"                                                       \n"
	"void main()                                            \n"
	"{                                                      \n"
	"   frag_color = vec4(vert_color, 1.0f);				\n"
	"	//frag_color = ourColor;							\n"
	"}                                                      \n"
};

bool initOpenGL();
void startup();
void generateVs(GLuint indice, GLfloat* vertices, GLuint tamanho);
void render();
void shutdown();

int main(void)
{
	//iniciando o opengl
	if (!initOpenGL())
	{
		std::cerr << "GLFW initialization failed" << std::endl;
		return -1;
	}

	//criando os vértices, formas e compilando os shaders
	startup();

	//loop de renderização
	while (!glfwWindowShouldClose(pWindow))
	{
		glfwPollEvents();

		//chama função que desenha os objetos
		render();

		glfwSwapBuffers(pWindow);
	}

	//deleta os espaços alocados para vao e vbo
	shutdown();

	glfwTerminate();

	return 0;
}

//inicia opengl
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

	pWindow = glfwCreateWindow(gWindowWidth, gWindowHeight, TITLE, NULL, NULL);
	if (pWindow == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(pWindow);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cerr << "Failed to initialize GLEW" << std::endl;
		return false;
	}

	return true;
}

//função que cria matriz de vértices e compila os shaders
void startup()
{

	//shaders
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, vs_source, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, fs_source, NULL);
	glCompileShader(fs);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);

	glDeleteShader(vs);
	glDeleteShader(fs);
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

void render()
{
	const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, color);
	glUseProgram(shaderProgram);

	//mudar a cor com base no tempo
	/*float timeValue = glfwGetTime();
	float timeValue2 = glfwGetTime();
	float timeValue3 = glfwGetTime();
	float colorValue = (sin(timeValue) / 2.0f) + 0.5f;
	float colorValue2 = (-sin(timeValue2) / 2.0f) + 0.5f;
	float colorValue3 = (-cos(timeValue3) / 2.0f) + 0.5f;

	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	glUniform4f(vertexColorLocation, colorValue, colorValue2, colorValue3, 1.0f);*/

	//translation
	glm::mat4 trans = glm::mat4(1.0f);									//criando matriz identidade
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));			//fazendo a translacao para o ponto nos parametros de vec3
	GLuint matrix = glGetUniformLocation(shaderProgram, "translation");	//aplicando a translacao no programa "translation" eh o nome que esta escrito no vs_shader
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));		//parametros (valor da variavel uniforme, quantas matrizes serao transformadas, se eh transposta, ponteiro para matriz)

	//scaling
	trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));
	matrix = glGetUniformLocation(shaderProgram, "scaling");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	//rotating
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	matrix = glGetUniformLocation(shaderProgram, "rotating");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 projection = glm::ortho(-70.0f, 70.0f, -70.0f, 70.0f, -1.0f, 1.0f);
	GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));



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
	glDeleteVertexArrays(1, &vao[8]);
	glDeleteVertexArrays(1, &vao[9]);
	glDeleteVertexArrays(1, &vao[10]);
	glDeleteVertexArrays(1, &vao[11]);
	glDeleteVertexArrays(1, &vao[12]);
	glDeleteBuffers(1, &vbo[0]);
	glDeleteBuffers(1, &vbo[1]);
	glDeleteBuffers(1, &vbo[2]);
	glDeleteBuffers(1, &vbo[3]);
	glDeleteBuffers(1, &vbo[4]);
	glDeleteBuffers(1, &vbo[5]);
	glDeleteBuffers(1, &vbo[6]);
	glDeleteBuffers(1, &vbo[7]);
	glDeleteBuffers(1, &vbo[8]);
	glDeleteBuffers(1, &vbo[9]);
	glDeleteBuffers(1, &vbo[10]);
	glDeleteBuffers(1, &vbo[11]);
	glDeleteBuffers(1, &vbo[12]);
	//usar depth para profundidade
}