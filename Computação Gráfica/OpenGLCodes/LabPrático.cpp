//Lab Prático - Computacao Grafica
//Gabriel Leonardo Martins de Oliveira - ra: a2317940

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
bool pWireFrame = false;
bool ativarLinhas = true;

//constantes globais
const int tamVetLineStrip = (int)(20 / 0.25);
const int qntdTriangulo = 100;
const int qntdPontos = 500;
const GLdouble PI = 3.14159265;

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
	"   gl_Position = projection * translation * vec4(pos.x, -pos.y, pos.z, 1.0);\n"
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
void questao1();
void questao2();
void questao3();
void questao4();
void questao5();
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
	questao1();
	questao2();
	questao3();
	questao4();
	questao5();

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

void questao1()
{
	//vetores de vértices e rgb dos dois triangulos
	GLfloat doisTriangulos[]{
		0.0f, 30.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		30.0f, 50.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		15.0f, 60.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		-10.0f, 30.0f, 0.0f,	1.0f, 0.0f, 0.0f,
		-40.0f, 50.0f, 0.0f,	1.0f, 0.0f, 0.0f,
		-25.0f, 60.0f, 0.0f,	1.0f, 0.0f, 0.0f,
	};

	//gerando vao e vbo para o vetor criado
	generateVs(0, doisTriangulos, sizeof(doisTriangulos));
}

void questao2()
{
	GLfloat triangulo[]{
		-20.0f, -10.0f, 0.0f,	1.0f, 0.0f, 1.0f,
		-40.0f, -10.0f, 0.0f,	1.0f, 0.0f, 1.0f,
		-20.0f, 10.0f, 0.0f,	1.0f, 0.0f, 1.0f,
	};
	generateVs(1, triangulo, sizeof(triangulo));

	GLfloat triangulo2[]{
		-15.0f, -10.0f, 0.0f,	1.0f, 0.0f, 1.0f,
		5.0f, -10.0f, 0.0f,		1.0f, 0.0f, 1.0f,
		-15.0f, 10.0f, 0.0f,	1.0f, 0.0f, 1.0f,
	};
	generateVs(2, triangulo2, sizeof(triangulo2));
}

void questao3()
{
	GLfloat tAmarelo[]{
		-20.0f, -30.0f, 0.0f,	1.0f, 1.0f, 0.0f,
		-40.0f, -30.0f, 0.0f,	1.0f, 1.0f, 0.0f,
		-20.0f, -10.0f, 0.0f,	1.0f, 1.0f, 0.0f,
	};
	generateVs(3, tAmarelo, sizeof(tAmarelo));

	GLfloat tVerde[]{

		-15.0f, -30.0f, 0.0f,	0.0f, 1.0f, 0.3f,
		5.0f, -30.0f, 0.0f,		0.0f, 1.0f, 0.3f,
		-15.0f, -10.0f, 0.0f,	0.0f, 1.0f, 0.3f,
	};
	generateVs(4, tVerde, sizeof(tVerde));
}

void questao4()
{

}

void questao5()
{

}

//função que renderiza todos os objetos criados e também ajusta translação, escala, rotação e projeção
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

	glm::mat4 trans = glm::mat4(1.0f);
	GLuint matrix;

	//rotating
	trans = glm::rotate(trans, glm::radians(45.0f), glm::vec3(0.0, 0.0, 1.0));
	matrix = glGetUniformLocation(shaderProgram, "rotating");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 projection = glm::ortho(-70.0f, 70.0f, -70.0f, 70.0f, -1.0f, 1.0f);
	GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));

	//questao 1
	glBindVertexArray(vao[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//questao 2
	glBindVertexArray(vao[1]);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//questao 3
	glBindVertexArray(vao[2]);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//questao 4
	glBindVertexArray(vao[3]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(vao[4]);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//questao 5
	trans = glm::translate(trans, glm::vec3(30.0f, 30.0f, 0.0f));
	matrix = glGetUniformLocation(shaderProgram, "translation");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	glBindVertexArray(0);
}

//função que configura as teclas para apresentar respectivos retornos
void glfw_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(pWindow, GL_TRUE);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		pWireFrame = !pWireFrame;
		if (pWireFrame)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//Press enter to transform points in lines and vice-versa
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
	{
		ativarLinhas = !ativarLinhas;
	}
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