from numpy import cos, sin
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *

class Forma:
    def __init__(self, numId: int, vertices: list):
        self.id = numId
        self.vert = vertices

    def getVert(self):
        return self.vert

    def getId(self):
        return (int)(self.id)

    def translate(self, posX: float, posY: float):
        changeX = posX - self.vert[0].getX()
        changeY = posY - self.vert[0].getY()
        self.atualizarVertices(changeX, changeY)

    def atualizarVertices(self, changeX, changeY):
        for i in range(len(self.vert)):
            self.vert[i].vert[0] += changeX
            self.vert[i].vert[1] += changeY

    def rotate(self, angle: float):
        for i in range(len(self.vert)):
            self.vert[i].vert[0] = (self.vert[i].getX() * cos(angle)) - (self.vert[i].getY() * sin(angle))
            self.vert[i].vert[1] = (self.vert[i].getX() * sin(angle)) - (self.vert[i].getY() * cos(angle))

class Ponto(Forma):
    def __init__(self, numId: int, x: float, y: float):
        super().__init__(numId, [x, y])
        self.forma = 'Ponto'
    
    def getX(self):
        return self.vert[0]
    
    def getY(self):
        return self.vert[1]

    def translate(self, posX: float, posY: float):
        self.vert[0] = posX
        self.vert[1] = posY

class Triangulo(Forma):
    def __init__(self, numId: int, vertices: list):
        super().__init__(numId, vertices)
        self.forma = 'Triangulo'
    
    def getV1(self):
        return self.vert[0]
    
    def getV2(self):
        return self.vert[1]
    
    def getV3(self):
        return self. vert[2]

class Poligono(Forma):
    def __init__(self, numId: int, vertices: list):
        super().__init__(numId, vertices)
        self.forma = 'Poligono'

    def draw(self):
        print('Desenhando Poligono')