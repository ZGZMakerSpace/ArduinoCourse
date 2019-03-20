int a1=6;
int a2=5;
int b1=4;
int b2=3;
unsigned int step_delay;
unsigned long last_step;
int rpm =150;

void setup(){
	initMotor();//El tiempo entre pasos es lo que nos dará la velocidad de giro, hay que tener en cuenta, que el giro conlleva un tiempo, si se intenta ir más rápido electrónicamente que el giro físico el comportamiento será errático.//tiempo entre pasos= Milisegundos en un minuto / pasos por vuelta / revoluciones por minutostep_delay = 60L * 1000L / 200 / rpm;
}

void loop(){
	motorControl(200);
	delay(500);
	motorControl(-200);
	delay(500);
}

void initMotor(){
	pinMode(a1,OUTPUT);
	pinMode(a2,OUTPUT);
	pinMode(b1,OUTPUT);
	pinMode(b2,OUTPUT);//Todos los pines HIGH el motor estará parado pero frenado//Todos los pines LOW el motor estará parado pero libre
	digitalWrite(a1,HIGH);
	digitalWrite(a2,HIGH);
	digitalWrite(b1,HIGH);
	digitalWrite(b2,HIGH);
	last_step= millis();
}

void motorControl(int pasos){
	int totalPasos= abs(pasos);
	int contadorPasos=0;

	if (pasos >0){	
		while (contadorPasos < totalPasos){
			if (millis() - last_step >= step_delay){
				last_step = millis();
				pasoDerecha(contadorPasos);
				contadorPasos++;
			}
		}
	}else{
		while (contadorPasos < totalPasos){
			if (millis() - last_step >= step_delay){
				last_step=millis();
				pasoIzquierda(contadorPasos);
				contadorPasos++;
			}
		}
	}
}//La combinación de los pasos es lo que nos dará un sentido de giro u otro//El step_delay nos dará la velocidad

void pasoDerecha(int numeroPaso){
	switch(numeroPaso%4){
		case 0:
			digitalWrite(a1,HIGH);
			digitalWrite(a2,LOW);
			digitalWrite(b1,HIGH);
			digitalWrite(b2,LOW);
		break;
		case 1:digitalWrite(a1,HIGH);
			digitalWrite(a2,LOW);
			digitalWrite(b1,LOW);
			digitalWrite(b2,HIGH);
		break;
		case 2:
			digitalWrite(a1,LOW);
			digitalWrite(a2,HIGH);
			digitalWrite(b1,LOW);
			digitalWrite(b2,HIGH);
		break;
		case 3:
			digitalWrite(a1,LOW);
			digitalWrite(a2,HIGH);
			digitalWrite(b1,HIGH);
			digitalWrite(b2,LOW);
		break;
	}
}

void pasoIzquierda(int numeroPaso){
	switch(numeroPaso % 4){
		case 0:
			digitalWrite(b2,HIGH);
			digitalWrite(b1,LOW);
			digitalWrite(a2,HIGH);
			digitalWrite(a1,LOW);
		break;
		case 1:
			digitalWrite(b2,HIGH);
			digitalWrite(b1,LOW);
			digitalWrite(a2,LOW);
			digitalWrite(a1,HIGH);
		break;
		case 2:
			digitalWrite(b2,LOW);
			digitalWrite(b1,HIGH);
			digitalWrite(a2,LOW);
			digitalWrite(a1,HIGH);
		break;
		case 3:
			digitalWrite(b2,LOW);
			digitalWrite(b1,HIGH);
			digitalWrite(a2,HIGH);
			digitalWrite(a1,LOW);
		break;
	}
}