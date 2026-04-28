#include <Servo.h>

Servo servoPulgar;
Servo servoIndice;
Servo servoMedio;
Servo servoAnular;
Servo servoMenique;
/* El prefijo `Servo` significa que es un tipo de dato, y cada uno de los servoNombreDedo 
es simplemente una instanciación (o un objeto) de ese tipo de dato Servo. Hacemos esto 
porque de esta forma podemos manipular cada uno de los dedos de forma independiente. */

void setup() {
  // Un solo setup para inicializar los pines
  servoPulgar.attach(8);  
  servoIndice.attach(9);
  servoMedio.attach(10);
  servoAnular.attach(11);
  servoMenique.attach(12);  
  /* El método attach es una función que mapea cada uno de los servos a un pin específico 
  del Arduino. Hacemos esto porque el arduino envía vía estos pines la Modulación por 
  Ancho de Pulso (PWM) necesaria para que los servos se muevan. */
}
/* La función setup en archivos de extensión .ino son para que las variables sean declaradas. */

void loop() {
  // TENSAR
  // Usamos una variable "i" como un contador de pasos (0 a 80 pasos)
  for (int i = 0; i <= 75; i += 1) { 
    
    // El Pulgar se mueve hacia adelante: 70 + 0, 70 + 1... hasta 145
    servoPulgar.write(70 + i);
    servoMedio.write(70 + i);
    servoMenique.write(70 + i);    

    servoIndice.write(145 - i);
    servoAnular.write(145 - i);
    
    delay(7);
  }

  delay(2000); // Pausa con la mano tensada
  /* Este retraso es de 2 segundos, el cual es perceptible para ojos humanos y nos permite 
  notar un claro contraste entre que la mano esté cerrada antes de que empiece a abrirse de nuevo. */
  
  // RELAJAR
  // Hacemos el proceso exactamente inverso
  for (int i = 0; i <= 75; i += 1) { 
    
    // El pulgar regresa a su posición inicial
    servoPulgar.write(130 - i);
    servoMedio.write(130 - i);  
    servoMenique.write(130 - i);  
    /* Mientras que estas instrucciones están escritas secuencialmente, la computadora es tan 
    rápida que crea la "ilusión" de que cada dedo se está moviendo al mismo tiempo. */
    
    // El índice y anular regresan a su posición inicial
    servoIndice.write(70 + i);
    servoAnular.write(70 + i);    
    
    delay(7); 
  }
  
  delay(2000);
}