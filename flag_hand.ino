#include <Servo.h>

Servo servoPulgar;
Servo servoIndice;
Servo servoMedio;
Servo servoAnular;
Servo servoMenique;

// Variables de bandera (multiplicadores de dirección)
// 1 = Se mueve hacia adelante, -1 = Se mueve en reversa
int dirNormal = 1;
int dirReversa = -1;

void setup() {
  servoPulgar.attach(8);  
  servoIndice.attach(9);
  servoMedio.attach(10);
  servoAnular.attach(11);
  servoMenique.attach(12);  
}

// Función generalizada usando las banderas propuestas
void moverDedos(int baseNormal, int baseReversa, int direccionMano) {
  for (int i = 0; i <= 75; i += 1) { 
    
    // Si direccionMano es 1 (Cerrar), dirNormal suma y dirReversa resta.
    // Si direccionMano es -1 (Abrir), dirNormal resta y dirReversa suma.
    int avanceNormal = baseNormal + (dirNormal * direccionMano * i);
    int avanceReversa = baseReversa + (dirReversa * direccionMano * i);

    servoPulgar.write(avanceNormal);
    servoMedio.write(avanceNormal);
    servoMenique.write(avanceNormal);
    
    servoIndice.write(avanceReversa);
    servoAnular.write(avanceReversa);
    
    delay(7);
  }
}

void loop() {
  // TENSAR (Dirección 1)
  // Bases iniciales: 70 para los normales, 145 para los en reversa
  moverDedos(70, 145, 1);
  
  delay(2000); 
  
  // RELAJAR (Dirección -1)
  // Bases iniciales: 130 para los normales, 70 para los en reversa
  moverDedos(130, 70, -1);
  
  delay(2000);
}