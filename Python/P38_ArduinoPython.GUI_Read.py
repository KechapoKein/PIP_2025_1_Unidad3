import sys
from PyQt5 import uic, QtWidgets
import  serial as placa
from PyQt5.uic.properties import QtCore

qtCreatorFile = "P37_ArduinoPython.GUI.ui"  # Nombre del archivo aquí.
Ui_MainWindow, QtBaseClass = uic.loadUiType(qtCreatorFile)
class MyApp(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        QtWidgets.QMainWindow.__init__(self)
        Ui_MainWindow.__init__(self)
        self.setupUi(self)
        # Área de los Signals

        self.txt_com.setText("/dev/cu.usbmodem")

        self.arduino = None
        self.btn_accion.clicked.connect(self.accion)

        self.segundoPlano = QtCore.QTimer()
        self.segundoPlano.timeout.connect(self.lecturas)

    # Área de los Slots

    def lecturas(self):
        if self.arduino.isOpen():
            if self.arduino.inWaiting():
                lectura = self.arduino.readline().decode().strip()
                print(lectura)
                self.lista_datos.addItem(lectura)
                self.lista_datos.setCurrentRow(self.lista_datos.count()-1)

    def accion(self):
        texto = self.btn_accion.text().upper()
        if texto == "CONECTAR":
            com = "COM" + self.txt_com.text()
            self.btn_accion.Text("DESCONECTAR")
            self.txt_estado.Text("CONECTADO")
            self.arduino = placa.Serial(com, baudrate=9600, timeout=1)
            self.segundoPlano.start(100)
        elif texto == "DESCONECTAR":
            self.btn_accion.Text("RECONECTAR")
            self.txt_estado.Text("DESCONECTADO")
            self.segundoPlano.stop()
            self.arduino.close()
        else:
            self.btn_accion.setText("DESCONECTAR")
            self.txt_estado.setText("RECONECTADO")
            self.arduino.open()
            self.segundoPlano.start(100)

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = MyApp()
    window.show()
    sys.exit(app.exec_())