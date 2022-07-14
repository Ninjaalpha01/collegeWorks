from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *

from Forma import Forma, Ponto, Triangulo, Poligono
from ViewPort import ViewPort

class MainWin(QMainWindow):
    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)

        self.title = "Janela Principal"
        self.posicao = [200, 200]
        self.tamanho = [800, 600]

        self.setWindowTitle(self.title)
        self.setGeometry(self.posicao[0], self.posicao[1], self.tamanho[0], self.tamanho[1])

        self.centralwidget = QWidget()
        self.centralwidget.setObjectName("centralwidget")
        
        self.labelObjetos = QLabel(self.centralwidget)
        self.labelObjetos.setGeometry(QRect(30, 20, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelObjetos.setFont(font)
        self.labelObjetos.setObjectName("labelObjetos")
        
        self.comboBoxObjetos = QComboBox(self.centralwidget)
        self.comboBoxObjetos.setGeometry(QRect(30, 50, 201, 30))
        self.comboBoxObjetos.setObjectName("comboBoxObjetos")
        
        self.labelViewPort = QLabel(self.centralwidget)
        self.labelViewPort.setGeometry(QRect(270, 20, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelViewPort.setFont(font)
        self.labelViewPort.setObjectName("labelViewPort")
        
        self.botaoVertices = QPushButton(self.centralwidget)
        self.botaoVertices.setGeometry(QRect(30, 90, 100, 30))
        font = QFont()
        font.setPointSize(10)
        self.botaoVertices.setFont(font)
        self.botaoVertices.setObjectName("botaoVertices")
        
        self.botaoTransformada = QPushButton(self.centralwidget)
        self.botaoTransformada.setGeometry(QRect(130, 90, 100, 30))
        font = QFont()
        font.setPointSize(10)
        self.botaoTransformada.setFont(font)
        self.botaoTransformada.setObjectName("botaoTransformada")
        
        self.frameVertices = QFrame(self.centralwidget)
        self.frameVertices.setGeometry(QRect(20, 130, 221, 421))
        self.frameVertices.setStyleSheet("\n")
        self.frameVertices.setFrameShape(QFrame.StyledPanel)
        self.frameVertices.setFrameShadow(QFrame.Raised)
        self.frameVertices.setObjectName("frameVertices")
        
        self.framePoint = QFrame(self.frameVertices)
        self.framePoint.setGeometry(QRect(0, 30, 221, 231))
        self.framePoint.setFrameShape(QFrame.StyledPanel)
        self.framePoint.setFrameShadow(QFrame.Raised)
        self.framePoint.setObjectName("framePoint")
        
        self.listWidgetPoint = QListWidget(self.framePoint)
        self.listWidgetPoint.setGeometry(QRect(10, 10, 200, 211))
        self.listWidgetPoint.setObjectName("listWidgetPoint")
        
        self.botaoDelete = QPushButton(self.frameVertices)
        self.botaoDelete.setGeometry(QRect(111, 321, 101, 30))
        self.botaoDelete.setObjectName("botaoDelete")
        
        self.spinBoxX = QDoubleSpinBox(self.frameVertices)
        self.spinBoxX.setGeometry(QRect(21, 271, 81, 31))
        font = QFont()
        font.setPointSize(10)
        self.spinBoxX.setFont(font)
        self.spinBoxX.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinBoxX.setAlignment(Qt.AlignCenter)
        self.spinBoxX.setMinimum(-1000.0)
        self.spinBoxX.setMaximum(1000.0)
        self.spinBoxX.setObjectName("spinBoxX")
        
        self.spinBoxY = QDoubleSpinBox(self.frameVertices)
        self.spinBoxY.setGeometry(QRect(121, 271, 81, 31))
        font = QFont()
        font.setPointSize(10)
        self.spinBoxY.setFont(font)
        self.spinBoxY.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinBoxY.setAlignment(Qt.AlignCenter)
        self.spinBoxY.setPrefix("")
        self.spinBoxY.setMinimum(-1000.0)
        self.spinBoxY.setMaximum(1000.0)
        self.spinBoxY.setObjectName("spinBoxY")
        
        self.botaoOk = QPushButton(self.frameVertices)
        self.botaoOk.setGeometry(QRect(11, 321, 101, 30))
        self.botaoOk.setObjectName("botaoOk")
        
        self.labelVertices = QLabel(self.frameVertices)
        self.labelVertices.setGeometry(QRect(11, 1, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelVertices.setFont(font)
        self.labelVertices.setAlignment(Qt.AlignCenter)
        self.labelVertices.setObjectName("labelVertices")
        
        self.frameTri = QFrame(self.frameVertices)
        self.frameTri.setGeometry(QRect(0, 30, 221, 231))
        self.frameTri.setFrameShape(QFrame.StyledPanel)
        self.frameTri.setFrameShadow(QFrame.Raised)
        self.frameTri.setObjectName("frameTri")
        
        self.listWidgetTri = QListWidget(self.frameTri)
        self.listWidgetTri.setGeometry(QRect(10, 10, 200, 211))
        self.listWidgetTri.setObjectName("listWidgetTri")
        
        self.framePoly = QFrame(self.frameVertices)
        self.framePoly.setGeometry(QRect(0, 30, 221, 231))
        self.framePoly.setFrameShape(QFrame.StyledPanel)
        self.framePoly.setFrameShadow(QFrame.Raised)
        self.framePoly.setObjectName("framePoly")
        
        self.listWidgetPoly = QListWidget(self.framePoly)
        self.listWidgetPoly.setGeometry(QRect(10, 10, 200, 151))
        self.listWidgetPoly.setObjectName("listWidgetPoly")

        self.boxQntPoints = QSpinBox(self.framePoly)
        self.boxQntPoints.setGeometry(QRect(120, 180, 80, 30))
        font = QFont()
        font.setPointSize(10)
        self.boxQntPoints.setFont(font)
        self.boxQntPoints.setAlignment(Qt.AlignCenter)
        self.boxQntPoints.setMinimum(4)
        self.boxQntPoints.setMaximum(10)
        self.boxQntPoints.setObjectName("spinQntPoints")

        self.labelQntPoints = QLabel(self.framePoly)
        self.labelQntPoints.setGeometry(QRect(20, 180, 80, 30))
        font = QFont()
        font.setBold(True)
        font.setPointSize(8)
        self.labelQntPoints.setFont(font)
        self.labelQntPoints.setAlignment(Qt.AlignCenter)
        self.labelQntPoints.setObjectName("labelQntPoints")
        
        self.botaoDesenha = QPushButton(self.frameVertices)
        self.botaoDesenha.setGeometry(QRect(50, 370, 121, 41))
        font = QFont()
        font.setPointSize(10)
        self.botaoDesenha.setFont(font)
        self.botaoDesenha.setObjectName("botaoDesenha")
        
        self.frameTransformada = QFrame(self.centralwidget)
        self.frameTransformada.setGeometry(QRect(20, 130, 221, 421))
        self.frameTransformada.setFrameShape(QFrame.StyledPanel)
        self.frameTransformada.setFrameShadow(QFrame.Raised)
        self.frameTransformada.setObjectName("frameTransformada")
        
        self.labelTransformada = QLabel(self.frameTransformada)
        self.labelTransformada.setGeometry(QRect(10, 0, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelTransformada.setFont(font)
        self.labelTransformada.setAlignment(Qt.AlignCenter)
        self.labelTransformada.setObjectName("labelTransformada")
        
        self.labelTranslate = QLabel(self.frameTransformada)
        self.labelTranslate.setGeometry(QRect(10, 80, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelTranslate.setFont(font)
        self.labelTranslate.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelTranslate.setObjectName("labelTranslate")
        
        self.boxXTranslate = QDoubleSpinBox(self.frameTransformada)
        self.boxXTranslate.setGeometry(QRect(20, 120, 60, 30))
        font = QFont()
        font.setPointSize(8)
        font.setWeight(50)
        self.boxXTranslate.setFont(font)
        self.boxXTranslate.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.boxXTranslate.setAlignment(Qt.AlignCenter)
        self.boxXTranslate.setPrefix("")
        self.boxXTranslate.setMinimum(-1000.0)
        self.boxXTranslate.setMaximum(1000.0)
        self.boxXTranslate.setObjectName("boxXTranslate")
        
        self.botaoOkTranslate = QPushButton(self.frameTransformada)
        self.botaoOkTranslate.setGeometry(QRect(140, 120, 70, 30))
        font = QFont()
        font.setWeight(50)
        self.botaoOkTranslate.setFont(font)
        self.botaoOkTranslate.setObjectName("botaoOkTranslate")
        
        self.labelRotate = QLabel(self.frameTransformada)
        self.labelRotate.setGeometry(QRect(10, 300, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelRotate.setFont(font)
        self.labelRotate.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelRotate.setObjectName("labelRotate")
        
        self.labelXTranslate = QLabel(self.frameTransformada)
        self.labelXTranslate.setGeometry(QRect(20, 150, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelXTranslate.setFont(font)
        self.labelXTranslate.setAlignment(Qt.AlignCenter)
        self.labelXTranslate.setObjectName("labelXTranslate")
        
        self.labelYTranslate = QLabel(self.frameTransformada)
        self.labelYTranslate.setGeometry(QRect(80, 150, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelYTranslate.setFont(font)
        self.labelYTranslate.setAlignment(Qt.AlignCenter)
        self.labelYTranslate.setObjectName("labelYTranslate")
        
        self.labelScale = QLabel(self.frameTransformada)
        self.labelScale.setGeometry(QRect(10, 190, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelScale.setFont(font)
        self.labelScale.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelScale.setObjectName("labelScale")
        
        self.boxXScale = QDoubleSpinBox(self.frameTransformada)
        self.boxXScale.setGeometry(QRect(20, 230, 120, 30))
        font = QFont()
        font.setPointSize(8)
        font.setWeight(50)
        self.boxXScale.setFont(font)
        self.boxXScale.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.boxXScale.setAlignment(Qt.AlignCenter)
        self.boxXScale.setValue(1.00)
        self.boxXScale.setMinimum(0.001)
        self.boxXScale.setMaximum(100.0)
        self.boxXScale.setObjectName("boxXScale")
        
        self.labelXScale = QLabel(self.frameTransformada)
        self.labelXScale.setGeometry(QRect(20, 260, 111, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelXScale.setFont(font)
        self.labelXScale.setAlignment(Qt.AlignCenter)
        self.labelXScale.setObjectName("labelXScale")
        
        self.botaoOkScale = QPushButton(self.frameTransformada)
        self.botaoOkScale.setGeometry(QRect(140, 230, 70, 30))
        font = QFont()
        font.setWeight(50)
        self.botaoOkScale.setFont(font)
        self.botaoOkScale.setObjectName("botaoOkScale")
        
        self.radioButtonX = QRadioButton(self.frameTransformada)
        self.radioButtonX.setGeometry(QRect(20, 340, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonX.setFont(font)
        self.radioButtonX.setObjectName("radioButtonX")
        
        self.radioButtonY = QRadioButton(self.frameTransformada)
        self.radioButtonY.setGeometry(QRect(20, 360, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonY.setFont(font)
        self.radioButtonY.setObjectName("radioButtonY")
        
        self.radioButtonZ = QRadioButton(self.frameTransformada)
        self.radioButtonZ.setGeometry(QRect(20, 380, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonZ.setFont(font)
        self.radioButtonZ.setChecked(True)
        self.radioButtonZ.setObjectName("radioButtonZ")
        
        self.spinAngle = QSpinBox(self.frameTransformada)
        self.spinAngle.setGeometry(QRect(80, 350, 60, 30))
        font = QFont()
        font.setPointSize(10)
        self.spinAngle.setFont(font)
        self.spinAngle.setAlignment(Qt.AlignCenter)
        self.spinAngle.setMaximum(359)
        self.spinAngle.setObjectName("spinAngle")
        
        self.labelAngle = QLabel(self.frameTransformada)
        self.labelAngle.setGeometry(QRect(80, 380, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelAngle.setFont(font)
        self.labelAngle.setAlignment(Qt.AlignCenter)
        self.labelAngle.setObjectName("labelAngle")
        
        self.botaoOkRotate = QPushButton(self.frameTransformada)
        self.botaoOkRotate.setGeometry(QRect(140, 350, 71, 31))
        font = QFont()
        font.setWeight(50)
        self.botaoOkRotate.setFont(font)
        self.botaoOkRotate.setObjectName("botaoOkRotate")

        self.boxYTranslate = QDoubleSpinBox(self.frameTransformada)
        self.boxYTranslate.setGeometry(QRect(80, 120, 60, 30))
        font = QFont()
        font.setPointSize(8)
        self.boxYTranslate.setFont(font)
        self.boxYTranslate.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.boxYTranslate.setAlignment(Qt.AlignCenter)
        self.boxYTranslate.setPrefix("")
        self.boxYTranslate.setMinimum(-1000.0)
        self.boxYTranslate.setMaximum(1000.0)
        self.boxYTranslate.setObjectName("boxYTranslate")

        self.labelForma = QLabel(self.frameTransformada)
        self.labelForma.setGeometry(QRect(10, 40, 111, 30))
        font = QFont()
        font.setBold(True)
        font.setWeight(100)
        font.setPointSize(10)
        self.labelForma.setFont(font)
        self.labelForma.setAlignment(Qt.AlignCenter)
        self.labelForma.setObjectName("labelForma")

        self.comboBoxID = QComboBox(self.frameTransformada)
        self.comboBoxID.setGeometry(QRect(130, 40, 81, 30))
        self.comboBoxID.setObjectName("comboBoxID")

        self.viewPort = ViewPort(self.centralwidget)
        self.viewPort.setGeometry(QRect(270, 50, 500, 500))
        self.viewPort.setObjectName("viewPort")
        # self.<nomeObjeto> = <objeto>(self.viewPort)

        self.botaoClip = QPushButton(self.centralwidget)
        self.botaoClip.setGeometry(QRect(650, 10, 101, 31))
        font = QFont()
        font.setBold(True)
        font.setWeight(50)
        self.botaoClip.setFont(font)
        self.botaoClip.setObjectName("botaoClip")

        self.labelClipAtivo = QLabel(self.centralwidget)
        self.labelClipAtivo.setGeometry(QRect(550, 10, 100, 30))
        font = QFont()
        font.setBold(True)
        font.setWeight(100)
        font.setPointSize(10)
        self.labelClipAtivo.setFont(font)
        self.labelClipAtivo.setAlignment(Qt.AlignCenter)
        self.labelClipAtivo.setObjectName("albelClipAtivo")

        self.setCentralWidget(self.centralwidget)
        self.statusbar = QStatusBar(self)
        self.statusbar.setObjectName("statusbar")
        self.setStatusBar(self.statusbar)

        self.retranslateUi()
        QMetaObject.connectSlotsByName(self)

        self.countPon = 0           # contador de pontos existentes
        self.countTri = 0           # contador de triangulo existentes
        self.countPol = 0           # contador de poligonos existentes
        self.countTransf = 0        # contador de transformadas / variavel auxiliar

        self.listaPontos = []       # lista com todos os pontos
        self.idsPointList = []          # lista com todos ids dos pontos
        self.listaTriangulos = []   # lista com todos os triangulos
        self.idsTriangleList = []      # lista com todos ids dos triangulos
        self.listaPoligonos = []    # lista com todos os poligonos
        self.idsPoligonList = []       # lista com todos ids dos poligonos

        self.countPonTri = 0        # contador de pontos no triangulo / variavel de controle
        self.qntdPonTri = 3         # quantidade de pontos no triangulo / variavel de auxilio
        self.verticesTri = []           # lista de vertices do triangulo / variavel de controle

        self.countPonPol = 0        # contador de pontos dentro do poligono
        self.qntdPonPol = 0         # quantidade de pontos no poligono / variavel de controle
        self.verticesPol = []           # lista de vertices do poligono / variavel de controle

        self.isClipActive = False

        self.startUi()

    def retranslateUi(self):
        self.setWindowTitle("Computação Gráfica")
        self.labelObjetos.setText("Objetos")
        self.labelViewPort.setText("Viewport")
        self.botaoVertices.setText("Vertices")
        self.botaoTransformada.setText("Transformada")
        self.labelQntPoints.setText("Qntd. Pontos:")
        self.botaoDelete.setText("Delete")
        self.botaoOk.setText("OK")
        self.labelVertices.setText("Vértices")
        self.botaoDesenha.setText("Desenha")
        self.labelTransformada.setText("Transformadas")
        self.labelForma.setText("ID Forma:")
        self.labelTranslate.setText("Translação:")
        self.botaoOkTranslate.setText("OK")
        self.labelRotate.setText("Rotação:")
        self.labelXTranslate.setText("X")
        self.labelYTranslate.setText("Y")
        self.labelScale.setText("Escala:")
        self.labelXScale.setText("Multiplicador")
        self.botaoOkScale.setText("OK")
        self.radioButtonX.setText("X")
        self.radioButtonY.setText("Y")
        self.radioButtonZ.setText("Z")
        self.spinAngle.setSuffix("°")
        self.labelAngle.setText("Ângulo")
        self.botaoOkRotate.setText("OK")
        self.botaoClip.setText("Clipping")
        self.labelClipAtivo.setText("Ativo")
    
    def startUi(self):
        self.setupFrameState()
        self.setupFormsList()

        self.comboBoxObjetos.addItems(['Ponto', 'Triangulo', 'Poligono'])

        self.setupFirstPageButtons()

    def setupFrameState(self):
        self.frameVertices.close()
        self.frameTransformada.close()
        self.labelClipAtivo.close()
    
    def setupFormsList(self):
        self.listWidgetPoint.addItem('Pontos:')
        self.listWidgetTri.addItem('Triangulos:')
        self.listWidgetPoly.addItem('Poligonos:')
    
    def setupFirstPageButtons(self):
        self.botaoVertices.clicked.connect(self.selectVertFrame)
        self.botaoTransformada.clicked.connect(self.selectTransFrame)
        self.botaoClip.clicked.connect(self.switchClip)

    def switchClip(self):
        self.viewPort.clippingTurnOnOff()
        self.isClipActive = not(self.isClipActive)
        if self.isClipActive == True:
            self.labelClipAtivo.show()
        else:
            self.labelClipAtivo.close()

    def selectVertFrame(self):
        self.setupVertFrame()
        objeto = self.comboBoxObjetos.currentText()
        
        if objeto == 'Ponto':
            self.framePoint.show()
            self.frameTri.close()
            self.framePoly.close()
            self.botaoOk.clicked.connect(self.createPoint)
        
        elif objeto == 'Triangulo':
            self.framePoint.close()
            self.frameTri.show()
            self.framePoly.close()
            self.botaoOk.clicked.connect(self.configTriangle)
        
        elif objeto == 'Poligono':
            self.framePoint.close()
            self.frameTri.close()
            self.framePoly.show()
            self.botaoOk.clicked.connect(self.configPolygon) 

    def setupVertFrame(self):
        self.reconfigVertFrameButtons()
        self.showVerticesFrame()

    def reconfigVertFrameButtons(self):
        self.botaoOk.disconnect()
        # self.botaoDelete.disconnect()

    def showVerticesFrame(self):
        self.frameVertices.show()
        self.frameTransformada.close() 
            
    def createPoint(self):
        ponto = Ponto(self.countPon+1, self.spinBoxX.value(), self.spinBoxY.value())
        self.setPoint(ponto)

    def setPoint(self, ponto: Ponto):
        def desenhaPon():
           self.desenha(ponto)
        self.botaoDesenha.disconnect()
        self.listarPonto(ponto)
        self.botaoDesenha.clicked.connect(desenhaPon)

    def listarPonto(self, ponto):
        if self.countPon < 10:
            self.listaPontos.append(ponto)
            self.listWidgetPoint.addItem(f'{ponto.getId()}:\t {ponto.getVert()}')    # adiciona o ponto para uma lista que é mostrada na tela
            self.countPon += 1
            self.idsPointList.append((str)(ponto.getId()))                      # adiciona o id do ponto que foi criado à lista de ids

        else:
            print('limite de pontos excedidos')

    def configTriangle(self):
        if self.countTri >= 2:
            print('limite de triangulos excedidos')
            return

        self.getTrianglePoints()
        self.countPonTri += 1

        if self.countPonTri == self.qntdPonTri:
            self.createTriangle()

    def getTrianglePoints(self):
        if self.countPonTri < self.qntdPonTri:
            vertice = (Ponto)(self.countPonTri, self.spinBoxX.value(), self.spinBoxY.value())
            self.listTrianglePoints(vertice)
    
    def listTrianglePoints(self, vertice):
        self.verticesTri.append(vertice)

        if self.countPonTri == 0:
            self.listWidgetTri.addItem(f'{self.countTri+1} :')

        self.listWidgetTri.addItem(f'     Ponto {self.countPonTri+1}: ({vertice.getX()}, {vertice.getY()})')
    
    def createTriangle(self):
        tri = []
        for i in range(self.qntdPonTri):
            tri.append(self.verticesTri[i])
        self.verticesTri.clear()
        self.setTriangle(Triangulo(self.countTri+1, tri))

    def setTriangle(self, triangulo: Triangulo):
        def desenhaTri():
            self.desenha(triangulo)
        self.botaoDesenha.disconnect()
        self.setOnTriangleList(triangulo)
        self.countPonTri = 0
        self.botaoDesenha.clicked.connect(desenhaTri)

    def setOnTriangleList(self, triangulo):
        if self.countTri < 2:
            self.listaTriangulos.append(triangulo)
            self.countTri += 1
            self.idsTriangleList.append((str)(triangulo.getId()))
    
    def configPolygon(self):
        if self.countPol > 0:
            print('limite de poligonos excedidos')
            return

        self.getQntdPonPol()

        self.getPolygonPoints()
        self.countPonPol += 1

        if self.countPonPol == self.qntdPonPol:
            self.createPolygon()

    def getQntdPonPol(self):
        if self.countPonPol == 0:
            self.qntdPonPol = self.boxQntPoints.value()

    def getPolygonPoints(self):
        if self.countPonPol < self.qntdPonPol:
            vertice = (Ponto)(self.countPonPol, self.spinBoxX.value(), self.spinBoxY.value())
            self.verticesPol.append(vertice)
            self.listPolygonPoints(vertice)

    def listPolygonPoints(self, vertice):
        if self.countPonPol == 0:
            self.listWidgetPoly.addItem(f'{self.countPol+1} :')
        self.listWidgetPoly.addItem(f'     Ponto {self.countPonPol}: ({vertice.getX()}, {vertice.getY()})')
    
    def createPolygon(self):
        pol = []
        for i in range(self.qntdPonPol):
            pol.append(self.verticesPol[i])

        self.verticesPol.clear()
        self.setPolygon(Poligono(self.countPol+1, pol))

    def setPolygon(self, poligono: Poligono):
        def desenhaPol():
            self.desenha(poligono)
        self.botaoDesenha.disconnect()
        self.setOnPolygonList(poligono)
        self.countPonPol = 0
        self.botaoDesenha.clicked.connect(desenhaPol)

    def setOnPolygonList(self, poligono):
        if self.countPol < 1:
            self.listaPoligonos.append(poligono)
            self.countPol += 1
            self.idsPoligonList.append((str)(poligono.getId()))
    
    def desenha(self, forma):
        if forma.forma == 'Ponto':
            self.viewPort.newPoint(forma)
        elif forma.forma == 'Triangulo':
            self.viewPort.newTriangle(forma)
        elif forma.forma == 'Poligono':
            self.viewPort.newPoligon(forma, self.qntdPonPol)

    def selectTransFrame(self):
        self.setupTransFrame()
        objeto = self.comboBoxObjetos.currentText()

        if objeto == 'Ponto':
            def transPon():
                self.translation('Ponto')
            
            self.comboBoxID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Ponto:')

            while self.countTransf in range(self.countPon):
                self.comboBoxID.addItem((str)(self.idsPointList[self.countTransf]))
                self.countTransf += 1
            
            self.botaoOkTranslate.clicked.connect(transPon)

        elif objeto == 'Triangulo':
            self.botaoOkRotate.disconnect()

            def transTri():
                self.translation('Triangulo')
            def rotateTri():
                self.rotation('Triangulo')
            
            self.comboBoxID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Triangulo:')

            while self.countTransf in range(self.countTri):
                self.comboBoxID.addItem((str)(self.idsTriangleList[self.countTransf]))
                self.countTransf += 1

            self.botaoOkTranslate.clicked.connect(transTri)
            self.botaoOkRotate.clicked.connect(rotateTri)
        
        elif objeto == 'Poligono':
            self.botaoOkRotate.disconnect()

            def transPol():
                self.translation('Poligono')
            def rotatePol():
                self.rotation('Poligono')

            self.comboBoxID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Poligono:')

            while self.countTransf in range(self.countPol):
                self.comboBoxID.addItem((str)(self.idsPoligonList[self.countTransf]))
                self.countTransf += 1
            
            self.botaoOkTranslate.clicked.connect(transPol)
            self.botaoOkRotate.clicked.connect(rotatePol)

    def setupTransFrame(self):
        self.showTransFrame()
        self.reconfigTransFrameButtons()
        self.botaoOkScale.clicked.connect(self.scaling)

    def showTransFrame(self):
        self.frameVertices.close()
        self.frameTransformada.show()
    
    def reconfigTransFrameButtons(self):
        self.botaoOkScale.disconnect()
        self.botaoOkTranslate.disconnect()

    def getCurrentId(self):
        if self.comboBoxID.currentText() == '':
            return -1
        else:
            return (int)(self.comboBoxID.currentText())
    
    def translation(self, forma):
        Id = self.getCurrentId()
        if Id == -1:
            return
        if forma == 'Ponto':
            self.translatePoint(Id)

        elif forma == 'Triangulo':
            self.translateTriangle(Id)
        
        elif forma == 'Poligono':
            self.translatePolygon(Id)

    def translatePoint(self, Id):
        for i in range(len(self.listaPontos)):
            if (self.listaPontos)[i].getId() == Id:
                ponto = self.listaPontos[i]
                ponto.translate(self.boxXTranslate.value(), self.boxYTranslate.value())
                self.desenha(ponto)
                break

    def translateTriangle(self, Id):
        for i in range(len(self.listaTriangulos)):
            if self.listaTriangulos[i].getId() == Id:
                triangulo = self.listaTriangulos[i]
                triangulo.translate(self.boxXTranslate.value(), self.boxYTranslate.value())
                self.desenha(triangulo)
                break

    def translatePolygon(self, Id):
        for i in range(len(self.listaPoligonos)):
            if self.listaPoligonos[i].getId() == Id:
                poligono = self.listaPoligonos[i]
                poligono.translate(self.boxXTranslate.value(), self.boxYTranslate.value())
                self.desenha(poligono)
                break
 
    def rotation(self, forma):
        Id = self.getCurrentId()                
        if forma == 'Triangulo':
            self.rotateTriangle(Id)

    def rotateTriangle(self, Id):
        for i in range(len(self.listaTriangulos)):
            if self.listaTriangulos[i].getId() == Id:
                triangulo = self.listaTriangulos[i]
                triangulo.rotate(self.spinAngle.value())
                self.desenha(triangulo)
                break

    def scaling(self):
        self.viewPort.setScale(self.boxXScale.value())


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    app.setStyle('fusion')
    w = MainWin()
    w.show()
    sys.exit(app.exec_())
