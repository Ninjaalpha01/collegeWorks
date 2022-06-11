//Lista de Exercicios 1 - Computacao Grafica
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
GLuint vao [13];
GLuint vbo [13];
GLuint ebo [2];
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
void doisTriangulos();
void casa();
void telhado();
void pontos();
void curva();
void circulo();
void pointInCircle(GLfloat cx, GLfloat cy, GLfloat radius);
void elipse();
void formInElipse(GLfloat pontos[2], GLfloat radius[2]);
double getTheta(GLfloat radius[2]);
double getRaioMax(GLfloat radius[2], GLdouble theta);
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
	doisTriangulos();
	pontos();
	casa();
	telhado();
	curva();
	circulo();
	elipse();

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

void doisTriangulos()
{
	//vetores de vértices e rgb dos dois triangulos
	GLfloat tVerde[]{
		30.0f, 30.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		60.0f, 50.0f, 0.0f,		0.0f, 1.0f, 0.0f,
		45.0f, 60.0f, 0.0f,		0.0f, 1.0f, 0.0f,
	};

	//gerando vao e vbo para o vetor criado
	generateVs(11, tVerde, sizeof(tVerde));

	GLfloat tVermelho[]{
		-10.0f, 30.0f, 0.0f,	1.0f, 0.0f, 0.0f,
		-40.0f, 50.0f, 0.0f,	1.0f, 0.0f, 0.0f,
		-25.0f, 60.0f, 0.0f,	1.0f, 0.0f, 0.0f,
	};
	
	generateVs(12, tVermelho, sizeof(tVermelho));
}

void pontos()
{
	GLfloat pontos[]{
		0.0f,  0.0f,  0.0f,		1.0f, 1.0f, 0.0f,
		20.0f, 0.0f,  0.0f,		0.0f, 1.0f, 0.0f,
		20.0f, 20.0f, 0.0f,		1.0f, 0.0f, 0.0f,
		0.0f,  20.0f, 0.0f,		1.0f, 0.0f, 1.0f,
		10.0f, 25.0f, 0.0f,		0.0f, 1.0f, 1.0f,
	};

	generateVs(5, pontos, sizeof(pontos));
}

void casa() 
{
	GLfloat parede[]{
		//parede
		0.0f,  20.0f, 0.0f,		1.0f, 0.8f, 0.8f,
		20.0f, 0.0f,  0.0f,		1.0f, 0.8f, 0.8f,
		0.0f, 0.0f,  0.0f,		1.0f, 0.8f, 0.8f,
		20.0f, 20.0f, 0.0f,		1.0f, 0.8f, 0.8f,
	};

	GLuint indicesParede[]{
		0, 1, 2,	//parede
		0, 1, 3,	//parede
	};

	generateVs(0, parede, sizeof(parede));

	//validando vetor de indices que compõe a parede
	glGenBuffers(1, &ebo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesParede), indicesParede, GL_STATIC_DRAW);

	GLfloat porta[] =
	{
		12.5f, 6.0f, 0.0f,		0.7f, 0.3f, 0.0f,
		7.5f, 0.0f, 0.0f,		0.7f, 0.3f, 0.0f,
		12.5f, 0.0f, 0.0f,		0.7f, 0.3f, 0.0f,
		7.5f, 6.0f, 0.0f,		0.7f, 0.3f, 0.0f,
	};

	generateVs(1, porta, sizeof(porta));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);

	GLfloat janela1[] =
	{
		3.0f, 15.0f, 0.0f,		0.0f, 0.4f, 0.8f,
		7.0f, 10.0f, 0.0f,		0.0f, 0.4f, 0.8f,
		3.0f, 10.0f, 0.0f,		0.8f, 0.8f, 0.8f,
		7.0f, 15.0f, 0.0f,		0.0f, 0.4f, 0.8f,
	};

	generateVs(2, janela1, sizeof(janela1));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);

	GLfloat janela2[] =
	{
		13.0f, 15.0f, 0.0f,		0.0f, 0.4f, 0.8f,
		17.0f, 10.0f, 0.0f,		0.0f, 0.4f, 0.8f,
		13.0f, 10.0f, 0.0f,		0.8f, 0.8f, 0.8f,
		17.0f, 15.0f, 0.0f,		0.0f, 0.4f, 0.8f,
	};

	generateVs(3, janela2, sizeof(janela2));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
}

void telhado()
{
	GLfloat telhado[] = {

		20.0f, 20.0f, 0.0f,		1.0f, 0.5f, 0.0f,
		0.0f,  20.0f, 0.0f,		1.0f, 0.5f, 0.0f,
		10.0f, 25.0f, 0.0f,		1.0f, 0.5f, 0.0f,
	};

	generateVs(4, telhado, sizeof(telhado));
}

void curva() 
{
	GLuint i = 0;
	GLfloat x = -10;
	GLfloat funcao[tamVetLineStrip * 6];

	//enquanto x estiver dentro do limite -10 < x < 10 executa o loop
	while (x < 10)
	{
		funcao[i++] = x;

		if (x == 0)
			funcao[i++] = 1;
		else
			funcao[i++] = sin(x) / x;

		funcao[i++] = 0.0f;

		//depois dos pontos, as 3 posições de rgb
		funcao[i++] = 1.0f;
		funcao[i++] = 1.0f;
		funcao[i++] = 1.0f;

		//passo dado no exercício
		x += 0.25;
	}

	generateVs(6, funcao, sizeof(funcao));
}

void circulo()
{
	GLfloat cx = -40.0f, cy = -30.0f;
	GLfloat radius = 15.0f;
	GLdouble angulo = 2.0f * PI / qntdTriangulo;
	GLint passo = 0;
	GLint i = 0;

	GLfloat circulo[qntdTriangulo * 18];

	while (passo < qntdTriangulo)
	{
		passo--;

		for (int j = 0; j < 2; j++)
		{
			circulo[i++] = cx + (radius * sin(angulo * passo));
			circulo[i++] = cy + (radius * cos(angulo * passo));
			circulo[i++] = 0.0f;
			circulo[i++] = 0.4f;
			circulo[i++] = 0.3f;
			circulo[i++] = 0.9f;
			passo++;
		}

		circulo[i++] = cx;
		circulo[i++] = cy;
		circulo[i++] = 0.0f;
		circulo[i++] = 0.4f;		//0.7f;
		circulo[i++] = 0.3f;		//0.7f;
		circulo[i++] = 0.9f;		//0.0f;
	}

	//teste manual
	/*GLdouble teste[] = {
		0.0f, 0.0f, 0.0f,											1.0f, 0.0f, 0.0f,
		10.0f, 0.0f, 0.0f,											1.0f, 0.5f, 0.0f,
		10.0f * sqrt(2) / 2.0f, 10.0f * sqrt(2) / 2.0f, 0.0f,		1.0f, 0.5f, 0.0f,
		0.0f, 10.0f, 0.0f,											0.0f, 1.0f, 0.0f,
		10.0f * (- sqrt(2)) / 2.0f, 10.0f * sqrt(2) / 2.0f, 0.0f,	0.0f, 1.0f, 0.0f,
		-10.0f, 0.0f, 0.0f,											0.0f, 0.0f, 1.0f,
		10.0f * (-sqrt(2)) / 2.0f, 10.0f * (-sqrt(2)) / 2.0f, 0.0f,	0.0f, 0.0f, 1.0f,
		0.0f, -10.0f, 0.0f,											0.9f, 0.3f, 0.7f,
		10.0f * sqrt(2) / 2.0f, 10.0f * (-sqrt(2)) / 2.0f, 0.0f,	0.9f, 0.3f, 0.7f,
	};

	GLuint indices2[] = {
		0, 1, 2,
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6,
		0, 6, 7,
		0, 7, 8,
		0, 8, 1,
	};
	glGenBuffers(1, &ebo[1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);*/

	generateVs(7, circulo, sizeof(circulo));

	//chama função que desenha pontos dentro da área do círculo criado
	pointInCircle(cx, cy, radius);
}

void pointInCircle(GLfloat cx, GLfloat cy, GLfloat raio)
{
	const GLuint tamInCircle = qntdPontos * 6;
	GLuint i = 0;
	GLfloat randX, randY;
	GLfloat inCircle[tamInCircle];

	//para usar números randomicos
	srand((unsigned)time(NULL));

	while (i < tamInCircle)
	{
		do
		{
			randX = ((rand() % (int)(raio * 100)) / 100.0f) * 2 - raio;
			randY = ((rand() % (int)(raio * 100)) / 100.0f) * 2 - raio;
		} while (!(randX * randX + randY * randY < raio * raio));

		inCircle[i++] = cx + randX;
		inCircle[i++] = cy + randY;
		inCircle[i++] = 0.0f;
		inCircle[i++] = (rand() % 100) / 100.0f;
		inCircle[i++] = (rand() % 100) / 100.0f;
		inCircle[i++] = (rand() % 100) / 100.0f;
	}

	generateVs(8, inCircle, sizeof(inCircle));
}

void elipse()
{
	GLfloat center[2] = { 40.0f, -30.0f };
	GLfloat radius[2] = { 15.0f, 20.0f };
	GLdouble angulo = 2.0f * PI / qntdTriangulo;
	GLint passo = 0;
	GLint i = 0;

	GLfloat elipse[qntdTriangulo * 18];

	while (passo < qntdTriangulo)
	{
		passo--;

		for (int j = 0; j < 2; j++)
		{
			elipse[i++] = center[0] + (radius[0] * sin(angulo * passo));
			elipse[i++] = center[1] + (radius[1] * cos(angulo * passo));
			elipse[i++] = 0.0f;
			elipse[i++] = 0.0f;
			elipse[i++] = 0.68f;
			elipse[i++] = 0.0f;
			passo++;
		}

		elipse[i++] = center[0];
		elipse[i++] = center[1];
		elipse[i++] = 0.0f;
		elipse[i++] = 0.0f;		//0.7f;
		elipse[i++] = 0.68f;	//0.7f;
		elipse[i++] = 0.0f;		//0.0f;
	}

	generateVs(9, elipse, sizeof(elipse));

	//chama função que desenha triangulos e linhas dentro da área da elipse
	formInElipse(center, radius);
}

void formInElipse(GLfloat pontos[2], GLfloat radius[2])
{
	const GLuint tamInElipse = qntdPontos * 6;
	GLuint i = 0;
	GLfloat randX, randY;
	GLfloat inElipse[tamInElipse];
	srand((unsigned)time(NULL));

	GLdouble theta;
	GLdouble raioMax, randRaio;

	while (i < tamInElipse)
	{
		theta = getTheta(radius);
		raioMax = getRaioMax(radius, theta);

		randRaio = raioMax * sqrt((rand() % 100) / 100.0f);
		randX = randRaio * cos(theta);
		randY = -randRaio * sin(theta);

		/*std::cout << "Raio Max: " << raioMax << std::endl;
		std::cout << "Ponto (" << randX << "," << randY << ")" << std::endl;
		std::cout << "========== Raio Rand: ============" << randRaio << std::endl;*/

		inElipse[i++] = pontos[0] + randX;
		inElipse[i++] = pontos[1] + randY;
		inElipse[i++] = 0.0f;
		inElipse[i++] = (rand() % 100) / 100.0f;
		inElipse[i++] = (rand() % 100) / 100.0f;
		inElipse[i++] = (rand() % 100) / 100.0f;
	}

	generateVs(10, inElipse, sizeof(inElipse));
}

//funcao para gerar um angulo aleatorio
double getTheta(GLfloat radius[2])
{
	GLdouble u, v, theta;

	u = (rand() % 100) / 100.0f / 4.0;
	theta = atan(radius[1] / radius[0] * tan(2 * PI * u));

	v = (rand() % 100) / 100.0f;
	if (v < 0.25)
		return theta;
	else
		if (v < 0.5)
			return PI - theta;
		else
			if (v < 0.75)
				return PI + theta;
			else
				return -theta;
}

//funcao que pega o raio maximo da elipse de acordo com o angulo gerado
double getRaioMax(GLfloat radius[2], GLdouble theta)
{
	GLdouble raioMax = radius[0] * radius[1] / sqrt(pow((radius[1] * cos(theta)), 2) + pow((radius[0] * sin(theta)), 2));
	return raioMax;
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

	//translation
	glm::mat4 trans = glm::mat4(1.0f);									//criando matriz identidade
	trans = glm::translate(trans, glm::vec3(0.0f, 0.0f, 0.0f));			//fazendo a translacao para o ponto nos parametros de vec3
	GLuint matrix = glGetUniformLocation(shaderProgram, "translation");	//aplicando a translacao no programa "translation" eh o nome que esta escrito no vs_shader
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));		//parametros (valor da variavel uniforme, quantas matrizes serao transformadas, se eh transposta, ponteiro para matriz)

	//rotating
	trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
	matrix = glGetUniformLocation(shaderProgram, "rotating");
	glUniformMatrix4fv(matrix, 1, GL_FALSE, glm::value_ptr(trans));

	glm::mat4 projection = glm::ortho(-70.0f, 70.0f, -70.0f, 70.0f, -1.0f, 1.0f);
	GLint modelLoc2 = glGetUniformLocation(shaderProgram, "projection");
	glUniformMatrix4fv(modelLoc2, 1, GL_FALSE, glm::value_ptr(projection));

	//dois triangulos
	glBindVertexArray(vao[11]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(vao[12]);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//pontos
	glBindVertexArray(vao[5]);
	glPointSize(10.0f);
	glDrawArrays(GL_POINTS, 0, 5);

	//parede casa
	glBindVertexArray(vao[0]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//porta casa
	glBindVertexArray(vao[1]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//janela1 casa
	glBindVertexArray(vao[2]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//janela2 casa
	glBindVertexArray(vao[3]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	//telhado casa
	glBindVertexArray(vao[4]);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	//curva da funcao
	glBindVertexArray(vao[6]);
	glLineWidth(1.0f);
	glDrawArrays(GL_LINE_STRIP, 0, tamVetLineStrip);

	//circulo
	glBindVertexArray(vao[7]);
	glDrawArrays(GL_TRIANGLES, 0, qntdTriangulo * 3);

	//pontos dentro do circulo
	glBindVertexArray(vao[8]);
	glPointSize(2.0f);
	glDrawArrays(GL_POINTS, 0, qntdPontos);

	//elipse
	glBindVertexArray(vao[9]);
	glDrawArrays(GL_TRIANGLES, 0, qntdTriangulo * 3);

	//linhas dentro da elipse
	if (ativarLinhas)
	{
		glBindVertexArray(vao[10]);
		glDrawArrays(GL_LINES, 0, qntdPontos);
	}
	//triangulos dentro da elipse
	else
	{
		glBindVertexArray(vao[10]);
		glDrawArrays(GL_TRIANGLES, 0, qntdPontos);
	}

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