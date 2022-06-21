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
        
        self.comboObj = QComboBox(self.centralwidget)
        self.comboObj.setGeometry(QRect(30, 50, 201, 30))
        self.comboObj.setObjectName("comboObj")
        
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
        
        self.botaoTransf = QPushButton(self.centralwidget)
        self.botaoTransf.setGeometry(QRect(130, 90, 100, 30))
        font = QFont()
        font.setPointSize(10)
        self.botaoTransf.setFont(font)
        self.botaoTransf.setObjectName("botaoTransf")
        
        self.frameVert = QFrame(self.centralwidget)
        self.frameVert.setGeometry(QRect(20, 130, 221, 421))
        self.frameVert.setStyleSheet("\n")
        self.frameVert.setFrameShape(QFrame.StyledPanel)
        self.frameVert.setFrameShadow(QFrame.Raised)
        self.frameVert.setObjectName("frameVert")
        
        self.framePon = QFrame(self.frameVert)
        self.framePon.setGeometry(QRect(0, 30, 221, 231))
        self.framePon.setFrameShape(QFrame.StyledPanel)
        self.framePon.setFrameShadow(QFrame.Raised)
        self.framePon.setObjectName("framePon")
        
        self.listWP = QListWidget(self.framePon)
        self.listWP.setGeometry(QRect(10, 10, 200, 211))
        self.listWP.setObjectName("listWP")
        
        self.botaoDelete = QPushButton(self.frameVert)
        self.botaoDelete.setGeometry(QRect(111, 321, 101, 30))
        self.botaoDelete.setObjectName("botaoDelete")
        
        self.spinX = QDoubleSpinBox(self.frameVert)
        self.spinX.setGeometry(QRect(21, 271, 81, 31))
        font = QFont()
        font.setPointSize(10)
        self.spinX.setFont(font)
        self.spinX.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinX.setAlignment(Qt.AlignCenter)
        self.spinX.setMinimum(-1000.0)
        self.spinX.setMaximum(1000.0)
        self.spinX.setObjectName("spinX")
        
        self.spinY = QDoubleSpinBox(self.frameVert)
        self.spinY.setGeometry(QRect(121, 271, 81, 31))
        font = QFont()
        font.setPointSize(10)
        self.spinY.setFont(font)
        self.spinY.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinY.setAlignment(Qt.AlignCenter)
        self.spinY.setPrefix("")
        self.spinY.setMinimum(-1000.0)
        self.spinY.setMaximum(1000.0)
        self.spinY.setObjectName("spinY")
        
        self.botaoOk = QPushButton(self.frameVert)
        self.botaoOk.setGeometry(QRect(11, 321, 101, 30))
        self.botaoOk.setObjectName("botaoOk")
        
        self.labelVertices = QLabel(self.frameVert)
        self.labelVertices.setGeometry(QRect(11, 1, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelVertices.setFont(font)
        self.labelVertices.setAlignment(Qt.AlignCenter)
        self.labelVertices.setObjectName("labelVertices")
        
        self.frameTri = QFrame(self.frameVert)
        self.frameTri.setGeometry(QRect(0, 30, 221, 231))
        self.frameTri.setFrameShape(QFrame.StyledPanel)
        self.frameTri.setFrameShadow(QFrame.Raised)
        self.frameTri.setObjectName("frameTri")
        
        self.listWT = QListWidget(self.frameTri)
        self.listWT.setGeometry(QRect(10, 10, 200, 211))
        self.listWT.setObjectName("listWT")
        
        self.framePol = QFrame(self.frameVert)
        self.framePol.setGeometry(QRect(0, 30, 221, 231))
        self.framePol.setFrameShape(QFrame.StyledPanel)
        self.framePol.setFrameShadow(QFrame.Raised)
        self.framePol.setObjectName("framePol")
        
        self.listWF = QListWidget(self.framePol)
        self.listWF.setGeometry(QRect(10, 10, 200, 151))
        self.listWF.setObjectName("listWF")

        self.spinQntP = QSpinBox(self.framePol)
        self.spinQntP.setGeometry(QRect(120, 180, 80, 30))
        font = QFont()
        font.setPointSize(10)
        self.spinQntP.setFont(font)
        self.spinQntP.setAlignment(Qt.AlignCenter)
        self.spinQntP.setMinimum(4)
        self.spinQntP.setMaximum(10)
        self.spinQntP.setObjectName("spinQntP")

        self.labelQntP = QLabel(self.framePol)
        self.labelQntP.setGeometry(QRect(20, 180, 80, 30))
        font = QFont()
        font.setBold(True)
        font.setPointSize(8)
        self.labelQntP.setFont(font)
        self.labelQntP.setAlignment(Qt.AlignCenter)
        self.labelQntP.setObjectName("labelQntP")
        
        self.botaoDesenha = QPushButton(self.frameVert)
        self.botaoDesenha.setGeometry(QRect(50, 370, 121, 41))
        font = QFont()
        font.setPointSize(10)
        self.botaoDesenha.setFont(font)
        self.botaoDesenha.setObjectName("botaoDesenha")
        
        self.frameTransf = QFrame(self.centralwidget)
        self.frameTransf.setGeometry(QRect(20, 130, 221, 421))
        self.frameTransf.setFrameShape(QFrame.StyledPanel)
        self.frameTransf.setFrameShadow(QFrame.Raised)
        self.frameTransf.setObjectName("frameTransf")
        
        self.labelTransf = QLabel(self.frameTransf)
        self.labelTransf.setGeometry(QRect(10, 0, 200, 30))
        font = QFont()
        font.setPointSize(12)
        font.setBold(True)
        font.setWeight(75)
        self.labelTransf.setFont(font)
        self.labelTransf.setAlignment(Qt.AlignCenter)
        self.labelTransf.setObjectName("labelTransf")
        
        self.labelTranslate = QLabel(self.frameTransf)
        self.labelTranslate.setGeometry(QRect(10, 80, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelTranslate.setFont(font)
        self.labelTranslate.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelTranslate.setObjectName("labelTranslate")
        
        self.spinXT = QDoubleSpinBox(self.frameTransf)
        self.spinXT.setGeometry(QRect(20, 120, 60, 30))
        font = QFont()
        font.setPointSize(8)
        font.setWeight(50)
        self.spinXT.setFont(font)
        self.spinXT.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinXT.setAlignment(Qt.AlignCenter)
        self.spinXT.setPrefix("")
        self.spinXT.setMinimum(-1000.0)
        self.spinXT.setMaximum(1000.0)
        self.spinXT.setObjectName("spinXT")
        
        self.botaoOkT = QPushButton(self.frameTransf)
        self.botaoOkT.setGeometry(QRect(140, 120, 70, 30))
        font = QFont()
        font.setWeight(50)
        self.botaoOkT.setFont(font)
        self.botaoOkT.setObjectName("botaoOkT")
        
        self.labelRotate = QLabel(self.frameTransf)
        self.labelRotate.setGeometry(QRect(10, 300, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelRotate.setFont(font)
        self.labelRotate.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelRotate.setObjectName("labelRotate")
        
        self.labelXT = QLabel(self.frameTransf)
        self.labelXT.setGeometry(QRect(20, 150, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelXT.setFont(font)
        self.labelXT.setAlignment(Qt.AlignCenter)
        self.labelXT.setObjectName("labelXT")
        
        self.labelYT = QLabel(self.frameTransf)
        self.labelYT.setGeometry(QRect(80, 150, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelYT.setFont(font)
        self.labelYT.setAlignment(Qt.AlignCenter)
        self.labelYT.setObjectName("labelYT")
        
        self.labelScale = QLabel(self.frameTransf)
        self.labelScale.setGeometry(QRect(10, 190, 71, 30))
        font = QFont()
        font.setPointSize(10)
        font.setWeight(50)
        self.labelScale.setFont(font)
        self.labelScale.setAlignment(Qt.AlignLeading|Qt.AlignLeft|Qt.AlignVCenter)
        self.labelScale.setObjectName("labelScale")
        
        self.spinXS = QDoubleSpinBox(self.frameTransf)
        self.spinXS.setGeometry(QRect(20, 230, 120, 30))
        font = QFont()
        font.setPointSize(8)
        font.setWeight(50)
        self.spinXS.setFont(font)
        self.spinXS.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinXS.setAlignment(Qt.AlignCenter)
        self.spinXS.setValue(1.00)
        self.spinXS.setMinimum(0.001)
        self.spinXS.setMaximum(100.0)
        self.spinXS.setObjectName("spinXS")
        
        self.labelXS = QLabel(self.frameTransf)
        self.labelXS.setGeometry(QRect(20, 260, 111, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelXS.setFont(font)
        self.labelXS.setAlignment(Qt.AlignCenter)
        self.labelXS.setObjectName("labelXS")
        
        self.botaoOkS = QPushButton(self.frameTransf)
        self.botaoOkS.setGeometry(QRect(140, 230, 70, 30))
        font = QFont()
        font.setWeight(50)
        self.botaoOkS.setFont(font)
        self.botaoOkS.setObjectName("botaoOkS")
        
        self.radioButtonX = QRadioButton(self.frameTransf)
        self.radioButtonX.setGeometry(QRect(20, 340, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonX.setFont(font)
        self.radioButtonX.setObjectName("radioButtonX")
        
        self.radioButtonY = QRadioButton(self.frameTransf)
        self.radioButtonY.setGeometry(QRect(20, 360, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonY.setFont(font)
        self.radioButtonY.setObjectName("radioButtonY")
        
        self.radioButtonZ = QRadioButton(self.frameTransf)
        self.radioButtonZ.setGeometry(QRect(20, 380, 41, 17))
        font = QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.radioButtonZ.setFont(font)
        self.radioButtonZ.setChecked(True)
        self.radioButtonZ.setObjectName("radioButtonZ")
        
        self.spinAngle = QSpinBox(self.frameTransf)
        self.spinAngle.setGeometry(QRect(80, 350, 60, 30))
        font = QFont()
        font.setPointSize(10)
        self.spinAngle.setFont(font)
        self.spinAngle.setAlignment(Qt.AlignCenter)
        self.spinAngle.setMaximum(359)
        self.spinAngle.setObjectName("spinAngle")
        
        self.labelAngle = QLabel(self.frameTransf)
        self.labelAngle.setGeometry(QRect(80, 380, 41, 21))
        font = QFont()
        font.setBold(True)
        font.setWeight(75)
        self.labelAngle.setFont(font)
        self.labelAngle.setAlignment(Qt.AlignCenter)
        self.labelAngle.setObjectName("labelAngle")
        
        self.botaoOkR = QPushButton(self.frameTransf)
        self.botaoOkR.setGeometry(QRect(140, 350, 71, 31))
        font = QFont()
        font.setWeight(50)
        self.botaoOkR.setFont(font)
        self.botaoOkR.setObjectName("botaoOkR")

        self.spinYT = QDoubleSpinBox(self.frameTransf)
        self.spinYT.setGeometry(QRect(80, 120, 60, 30))
        font = QFont()
        font.setPointSize(8)
        self.spinYT.setFont(font)
        self.spinYT.setLocale(QLocale(QLocale.English, QLocale.UnitedStates))
        self.spinYT.setAlignment(Qt.AlignCenter)
        self.spinYT.setPrefix("")
        self.spinYT.setMinimum(-1000.0)
        self.spinYT.setMaximum(1000.0)
        self.spinYT.setObjectName("spinYT")

        self.labelForma = QLabel(self.frameTransf)
        self.labelForma.setGeometry(QRect(10, 40, 111, 30))
        font = QFont()
        font.setBold(True)
        font.setWeight(100)
        font.setPointSize(10)
        self.labelForma.setFont(font)
        self.labelForma.setAlignment(Qt.AlignCenter)
        self.labelForma.setObjectName("labelForma")

        self.comboID = QComboBox(self.frameTransf)
        self.comboID.setGeometry(QRect(130, 40, 81, 30))
        self.comboID.setObjectName("comboID")

        self.viewPort = ViewPort(self.centralwidget)
        self.viewPort.setGeometry(QRect(270, 50, 500, 500))
        self.viewPort.setObjectName("viewPort")
        # self.<nomeObjeto> = <objeto>(self.viewPort)

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
        self.idsPonto = []          # lista com todos ids dos pontos
        self.listaTriangulos = []   # lista com todos os triangulos
        self.idsTriangulo = []      # lista com todos ids dos triangulos
        self.listaPoligonos = []    # lista com todos os poligonos
        self.idsPoligono = []       # lista com todos ids dos poligonos

        self.countPonTri = 0        # contador de pontos no triangulo / variavel de controle
        self.qntdPonTri = 3         # quantidade de pontos no triangulo / variavel de auxilio
        self.vertTri = []           # lista de vertices do triangulo / variavel de controle

        self.countPonPol = 0        # contador de pontos dentro do poligono
        self.qntdPonPol = 0         # quantidade de pontos no poligono / variavel de controle
        self.vertPol = []           # lista de vertices do poligono / variavel de controle

        self.main()

    def retranslateUi(self):
        self.setWindowTitle("Computação Gráfica")
        self.labelObjetos.setText("Objetos")
        self.labelViewPort.setText("Viewport")
        self.botaoVertices.setText("Vertices")
        self.botaoTransf.setText("Transformada")
        self.labelQntP.setText("Qntd. Pontos:")
        self.botaoDelete.setText("Delete")
        self.botaoOk.setText("OK")
        self.labelVertices.setText("Vértices")
        self.botaoDesenha.setText("Desenha")
        self.labelTransf.setText("Transformadas")
        self.labelForma.setText("ID Forma:")
        self.labelTranslate.setText("Translação:")
        self.botaoOkT.setText("OK")
        self.labelRotate.setText("Rotação:")
        self.labelXT.setText("X")
        self.labelYT.setText("Y")
        self.labelScale.setText("Escala:")
        self.labelXS.setText("Multiplicador")
        self.botaoOkS.setText("OK")
        self.radioButtonX.setText("X")
        self.radioButtonY.setText("Y")
        self.radioButtonZ.setText("Z")
        self.spinAngle.setSuffix("°")
        self.labelAngle.setText("Ângulo")
        self.botaoOkR.setText("OK")
    
    def main(self):
        # definindo padrões iniciais
        self.frameVert.close()
        self.frameTransf.close()
        self.listWP.addItem('Pontos:')
        self.listWT.addItem('Triangulos:')
        self.listWF.addItem('Poligonos:')

        self.comboObj.addItems(['Ponto', 'Triangulo', 'Poligono'])

        # primeiras interações
        self.botaoVertices.clicked.connect(self.vertices)
        self.botaoTransf.clicked.connect(self.transformadas)
    
    def vertices(self):
        # quando botaoVertices é acionado dispara esta função que por sua
        # vez mostra qual frame que será exibido

        self.botaoOk.disconnect()
        # self.botaoDelete.disconnect()
        self.frameVert.show()
        self.frameTransf.close()
        
        objeto = self.comboObj.currentText()            # pegando valor da combo box
        
        if objeto == 'Ponto':
            self.framePon.show()
            self.frameTri.close()
            self.framePol.close()
            self.botaoOk.clicked.connect(self.getPonto)
        
        elif objeto == 'Triangulo':
            self.framePon.close()
            self.frameTri.show()
            self.framePol.close()
            self.botaoOk.clicked.connect(self.getTriangulo)
        
        elif objeto == 'Poligono':
            self.framePon.close()
            self.frameTri.close()
            self.framePol.show()
            self.botaoOk.clicked.connect(self.getPoligono)  
            
    def getPonto(self):
        # configura o ponto com os atributos que estão nas double boxes
        ponto = Ponto(self.countPon+1, self.spinX.value(), self.spinY.value())
        self.setPonto(ponto)

    def setPonto(self, ponto: Ponto):
        # seta o ponto de fato colocando na lista de pontos e também deixando pronto
        # para ser desenhado
        self.botaoDesenha.disconnect()

        def desenhaPon():
           self.desenha(ponto)

        if self.countPon < 10:
            self.listaPontos.append(ponto)
            self.listWP.addItem(f'{ponto.getId()}:\t {ponto.getVert()}')    # adiciona o ponto para uma lista que é mostrada na tela
            self.countPon += 1
            self.idsPonto.append((str)(ponto.getId()))                      # adiciona o id do ponto que foi criado à lista de ids

        else:
            print('limite de pontos excedidos')

        self.botaoDesenha.clicked.connect(desenhaPon)

    def getTriangulo(self):
        # configura cada ponto do triangulo, quando todos os 3 pontos forem lidos
        # dispara a função que de fato cria o triangulo
        if self.countTri >= 2:
            print('limite de triangulos excedidos')
            return

        if self.countPonTri < self.qntdPonTri:
            vertice = (Ponto)(self.countPonTri, self.spinX.value(), self.spinY.value())
            self.vertTri.append(vertice)

            if self.countPonTri == 0:
                self.listWT.addItem(f'{self.countTri+1} :')

            self.listWT.addItem(f'     Ponto {self.countPonTri+1}: ({vertice.getX()}, {vertice.getY()})')

        self.countPonTri += 1

        if self.countPonTri == self.qntdPonTri:      # lógica usada para que se passe um vetor de pontos para criar o triangulo
            tri = []
            for i in range(self.qntdPonTri):
                tri.append(self.vertTri[i])
            self.vertTri.clear()
            self.setTriangulo(Triangulo(self.countTri+1, tri))

    def setTriangulo(self, triangulo: Triangulo):
        # função que de fato cria o triangulo e o deixa pronto para ser desenhado
        self.botaoDesenha.disconnect()

        if self.countTri < 2:
            def desenhaTri():
                self.desenha(triangulo)
            
            self.listaTriangulos.append(triangulo)
            self.countTri += 1
            self.idsTriangulo.append((str)(triangulo.getId()))
        
        self.countPonTri = 0
        self.botaoDesenha.clicked.connect(desenhaTri)
    
    def getPoligono(self):
        # usando o mesmo principio da função getTriangulo configura-se os
        # pontos do poligono de acordo com a quantidade de pontos capturada pela spin box
        if self.countPol > 0:
            return

        if self.countPonPol == 0:
            self.qntdPonPol = self.spinQntP.value()             # guarda quantos pontos serão necessários para o poligono

        if self.countPonPol < self.qntdPonPol: #reseta no setPoligono
            vertice = (Ponto)(self.countPonPol, self.spinX.value(), self.spinY.value())
            self.vertPol.append(vertice)

            if self.countPonPol == 0:
                self.listWF.addItem(f'{self.countPol+1} :')

            self.listWF.addItem(f'     Ponto {self.countPonPol}: ({vertice.getX()}, {vertice.getY()})')

        self.countPonPol += 1

        if self.countPonPol == self.qntdPonPol:
            pol = []                                        # vetor de poligonos
            for i in range(self.qntdPonPol):
                pol.append(self.vertPol[i])

            self.vertPol.clear()
            self.setPoligono(Poligono(self.countTri+1, pol))

    def setPoligono(self, poligono: Poligono):
        self.botaoDesenha.disconnect()

        def desenhaPol():
            self.desenha(poligono)

        if self.countPol < 1:
            self.listaPoligonos.append(poligono)
            self.countPol += 1
            self.idsPoligono.append((str)(poligono.getId()))

        self.countPonPol = 0
        self.botaoDesenha.clicked.connect(desenhaPol)
    
    def desenha(self, forma):
        # recebe uma forma por parâmetro e de acordo com a forma
        # passada chama a função para desenhá-la
        if forma.forma == 'Ponto':
            self.viewPort.newPoint(forma)
        elif forma.forma == 'Triangulo':
            self.viewPort.newTriangle(forma)
        elif forma.forma == 'Poligono':
            self.viewPort.newPoligon(forma, self.qntdPonPol)

    def transformadas(self):
        # configura a visualização e lógica do frameTransf
        self.frameVert.close()
        self.frameTransf.show()

        self.botaoOkT.disconnect()
        self.botaoOkS.disconnect()
        self.botaoOkS.clicked.connect(self.scaling)

        objeto = self.comboObj.currentText()

        # lógica feita para que possa ter controle de qual objeto irá realizar
        # as transformadas
        if objeto == 'Ponto':
            def transPon():
                self.translation('Ponto')
            
            self.comboID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Ponto:')

            while self.countTransf in range(self.countPon):
                self.comboID.addItem((str)(self.idsPonto[self.countTransf]))
                self.countTransf += 1
            
            self.botaoOkT.clicked.connect(transPon)

        elif objeto == 'Triangulo':
            self.botaoOkR.disconnect()

            def transTri():
                self.translation('Triangulo')
            def rotateTri():
                self.rotating('Triangulo')
            
            self.comboID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Triangulo:')

            while self.countTransf in range(self.countTri):
                self.comboID.addItem((str)(self.idsTriangulo[self.countTransf]))
                self.countTransf += 1

            self.botaoOkT.clicked.connect(transTri)
            self.botaoOkR.clicked.connect(rotateTri)
        
        elif objeto == 'Poligono':
            self.botaoOkR.disconnect()

            def transPol():
                self.translation('Poligono')
            def rotatePol():
                self.rotating('Poligono')

            self.comboID.clear()
            self.countTransf = 0
            self.labelForma.setText('ID Poligono:')

            while self.countTransf in range(self.countPol):
                self.comboID.addItem((str)(self.idsPoligono[self.countTransf]))
                self.countTransf += 1
            
            self.botaoOkT.clicked.connect(transPol)
            self.botaoOkR.clicked.connect(rotatePol)
            
    def translation(self, forma):
        if self.comboID.currentText() == '':
            return

        Id = (int)(self.comboID.currentText())
        if forma == 'Ponto':
            for i in range(len(self.listaPontos)):
                if (self.listaPontos)[i].getId() == Id:
                    ponto = self.listaPontos[i]
                    ponto.translate(self.spinXT.value(), self.spinYT.value())
                    self.desenha(ponto)
                    break

        elif forma == 'Triangulo':
            for i in range(len(self.listaTriangulos)):
                if self.listaTriangulos[i].getId() == Id:
                    triangulo = self.listaTriangulos[i]
                    triangulo.translate(self.spinXT.value(), self.spinYT.value())
                    self.desenha(triangulo)
                    break
        
        elif forma == 'Poligono':
            for i in range(len(self.listaPoligonos)):
                if self.listaPoligonos[i].getId() == Id:
                    poligono = self.listaPoligonos[i]
                    poligono.translate(self.spinXT.value(), self.spinYT.value())
                    self.desenha(poligono)
                    break
    
    def rotating(self, forma):
        Id = (int)(self.comboID.currentText())                
        if forma == 'Triangulo':
            for i in range(len(self.listaTriangulos)):
                if self.listaTriangulos[i].getId() == Id:
                    triangulo = self.listaTriangulos[i]
                    triangulo.rotate(self.spinAngle.value())
                    self.desenha(triangulo)
                    break

    def scaling(self):
        self.viewPort.setScale(self.spinXS.value())


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    app.setStyle('fusion')
    w = MainWin()
    w.show()
    sys.exit(app.exec_())
