from ast import For
from asyncio.windows_events import NULL
from PyQt5 import QtCore
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from matplotlib import scale

from Forma import Forma, Ponto, Triangulo, Poligono

class ViewPort(QWidget):
    def __init__(self, parent):
        super().__init__(parent)
        self.listPoint = []
        self.listTriangle = []
        self.listPoligon = []
        self.hasClipping = False
        self.hasPoint = False
        self.hasTriangle = False
        self.hasPoligon = False
        self.qntPointsPoligon = 0
        self.scale = 1.0
        self.angle = 0.0
    
    def newPoint(self, point: Ponto):
        self.listPoint.append(point)
        if self.hasPoint == False:
            self.hasPoint = True
        self.repaint()
    
    def newTriangle(self, triangle: Triangulo):
        if len(self.listTriangle) < 2:
            self.listTriangle.append(triangle)
            if self.hasTriangle == False:
                self.hasTriangle = True
        self.repaint()

    def newPoligon(self, poligon: Poligono, qntdPontos: int):
        self.listPoligon.append(poligon)
        if self.hasPoligon == False:
            self.hasPoligon = True
        self.qntPointsPoligon = qntdPontos
        self.repaint()

    def setScale(self, scale: float):
        self.scale = scale
        self.repaint()
    
    def setAngle(self, angle: float):
        self.angle = angle
        self.repaint()

    def clippingTurnOnOff(self):
        if self.hasClipping:
            self.hasClipping = False
        else:
            self.hasClipping = True
        self.repaint()

    def paintEvent(self, e):
        painter = self.setUpBackground(e)
        self.alternarClipping(painter)
        if self.hasPoint:
            self.desenharPontos(painter)
        if self.hasTriangle:
            self.desenharTriangulos(painter)
        if self.hasPoligon:
            self.desenharPoligonos(painter)

    def alternarClipping(self, painter):
        regiao = QRect(100, 100, 300, 300)
        if self.hasClipping:
            painter.setClipRect(regiao)

    def desenharPontos(self, painter):
        self.setUpColor(painter, Qt.blue)
        for i in range(len(self.listPoint)):
            ponto = self.listPoint[i]
            x = 250 + (ponto.getX() * self.scale)
            y = 250 - (ponto.getY() * self.scale)
            painter.setPen(QPen(Qt.blue, 7, cap=Qt.RoundCap))
            painter.drawPoint(x, y)

    def desenharTriangulos(self, painter):
        self.setUpColor(painter, Qt.red)
        for i in range(len(self.listTriangle)):
            tri = self.listTriangle[i]
            pointsT = QPolygon([])
            self.desenharVerticesTri(tri, pointsT)
            painter.drawPolygon(pointsT, 4)

    def desenharPoligonos(self, painter):
        self.setUpColor(painter, Qt.green)
        for i in range(len(self.listPoligon)):
            pol = self.listPoligon[i]
            pointsP = QPolygon([])
            self.desenharVerticesPol(pol, pointsP)
            painter.drawPolygon(pointsP, self.qntPointsPoligon)

    def desenharVerticesTri(self, tri, pointsT):
        for j in range(3):
            x = (250 + ((tri.getVert())[j].getX() * self.scale))
            y = (250 - ((tri.getVert())[j].getY() * self.scale))
            pointsT.append(QPoint(x, y))

    def desenharVerticesPol(self, pol, pointsP):
        for j in range(self.qntPointsPoligon):
            x = (250 + ((pol.getVert())[j].getX() * self.scale))
            y = (250 - ((pol.getVert())[j].getY() * self.scale))
            pointsP.append(QPoint(x, y))
    
    def setUpBackground(self, e):
        painter = QPainter(self)
        painter.fillRect(e.rect(), Qt.white)

        self.setUpCenterLines(painter)
        return painter

    def setUpCenterLines(self, painter):
        painter.setPen(QPen(Qt.green))
        painter.drawLine(250, 0, 250, 500)
        painter.drawLine(0, 250, 500, 250)

    def setUpColor(self, painter, color):
        painter.setPen(QPen(color))
        painter.setBrush(QBrush(color, Qt.SolidPattern))