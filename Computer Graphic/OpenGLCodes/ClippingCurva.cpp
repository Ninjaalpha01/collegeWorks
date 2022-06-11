//Trabalho Clipping de Curvas - Computacao Grafica
//Gabriel L Martins de Oliveira - ra: a2317940
//Gabriel de Andrade Sauter - ra: a2258943
//Guilherme Quinteiro Lorenzi - ra: a

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
using namespace std;

//constantes de características da window
const int gWindowWidth = 800;
const int gWindowHeight = 700;
const char* TITLE = "Lista de Exercicio 1";

//variáveis globais
GLFWwindow* pWindow = NULL;
GLuint shaderProgram;
GLuint vao[3];
GLuint vbo[3];
bool viewPort = false;

//constantes globais
const int tamVetLineStrip = (int)(20 / 0.01);

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

//escopo de funções
bool initOpenGL();
void startup();
void generateVs(GLuint indice, GLfloat* vertices, GLuint tamanho);
void ret();
void curva1();
void render();
void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode);
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

	//chama o método de teclas para configurar as funções descritas
	glfwSetKeyCallback(pWindow, glfw_key);

	return true;
}

//função que cria matriz de vértices e compila os shaders
void startup()
{
	//chama cada função para criação dos objetos
	curva1();
	ret();

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

//Esta funcao executa a criacao do vbo e vao de acordo com os parametros
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

void ret()
{
	GLfloat black[]{
		-20.0f, 9.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		20.0f, 9.0f, 0.0f,		0.0f, 0.0f, 0.0f,
		20.0f, 10.0f, 0.0f,		0.0f, 0.0f, 0.0f,
	};
	generateVs(0, black, sizeof(black));
}

void curva1() 
{
	GLuint i = 0;
	GLfloat x = -60.0f;
	GLfloat funcao[tamVetLineStrip * 6];

	//enquanto x estiver dentro do limite -10 < x < 10 executa o loop
	while (x < 60)
	{
		funcao[i++] = x;

		if (x == 0)
			funcao[i++] = 20;
		else
			funcao[i++] = 20 * sin(x) / x;

		funcao[i++] = 0.0f;

		//depois dos pontos, as 3 posições de rgb
		funcao[i++] = 1.0f;
		funcao[i++] = 1.0f;
		funcao[i++] = 1.0f;

		//passo dado no exercício
		x += 0.25;
	}

	generateVs(1, funcao, sizeof(funcao));

	GLfloat funcaoClipping[tamVetLineStrip * 6];
	GLuint j = 0;
	GLuint count;
	x = -60.0f;
	i = 0;

	while (x < 60)
	{
		if ((funcao[i] < 20.0f && funcao[i] > -20.0f) && (funcao[i + 1] < 10.0f && funcao[i + 1] > -10.0f))
		{
			for (count = 0; count < 6; count++)
				funcaoClipping[j++] = funcao[i++];
		}
		else
			i += 6;

		x += 0.25;
	}

	generateVs(2, funcaoClipping, sizeof(funcaoClipping));
}

void render()
{
	const GLfloat color[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, color);
	glUseProgram(shaderProgram);

	//translation
	glm::mat4 trans = glm::mat4(1.0f);									//criando matriz identidade
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));			//fazendo a translacao para o ponto nos parametros de vec3
	GLuint matrix = glGetUniformLocation(shaderProgram, "translation");	//aplicando a translacao no programa "translation" eh o nome que esta escrito no vs_shader
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));		//parametros (valor da variavel uniforme, quantas matrizes serao transformadas, se eh transposta, ponteiro para matriz)

	//rotating
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	matrix = glGetUniformLocation(shaderProgram, "rotating");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 projection = glm::ortho(-60.0f, 60.0f, -60.0f, 60.0f, -1.0f, 1.0f);
	GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));

	if (!viewPort)
	{
		glBindVertexArray(vao[1]);
		glDrawArrays(GL_LINE_STRIP, 0, 600);
	}
	else
	{
		glBindVertexArray(vao[2]);
		glDrawArrays(GL_LINE_STRIP, 0, 600);

		glBindVertexArray(vao[0]);
		glDrawArrays(GL_TRIANGLES, 0, 6);
	}

	glBindVertexArray(0);
}

void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(pWindow, GL_TRUE);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		viewPort = !viewPort;
}

void shutdown()
{
	glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &vao[0]);
	glDeleteVertexArrays(1, &vao[1]);
	glDeleteVertexArrays(1, &vao[2]);
	glDeleteBuffers(1, &vbo[0]);
	glDeleteBuffers(1, &vbo[1]);
	glDeleteBuffers(1, &vbo[2]);
	//usar depth para profundidade
}