void setup() {
  // Inicializa a porta serial com velocidade de 9600bps
   Serial.begin(9600);  
}
int umidade;
char buf;

void ligaDesliga(bool opcao){
  if(opcao == true){
     digitalWrite(4, HIGH);
     Serial.println("Bomba Ligada !");
  }else{
     digitalWrite(4, LOW);
     Serial.println("Bomba Desligada !");
  }
}

void loop() {
    umidade = analogRead(A0);
    Serial.println(umidade);
    delay(1000);
    
    if(umidade < 400){
      ligaDesliga(false);//desliga
    }else{
      ligaDesliga(true);//Liga
    }
    
  while(Serial.available() > 0)
  {
     buf = Serial.read();
     Serial.println(buf);

      //LIGA A BOMBA
      if(buf == 'L' ){

      //SO LIGA A BOMBA CASO A UMIDADE ESTEJA MENOR QUE 800
      ligaDesliga(true);//Liga
      //digitalWrite(4, HIGH);
      Serial.println("Bomba Ligada sdsds !");
      delay(6000);
     }

     //DESLIGA A BOMBA
     if(buf == 'D'){
        ligaDesliga(false);//Desliga
        //digitalWrite(4, LOW);    
        Serial.println("Bomba Desligada dasda!");
        delay(6000);
     }
  }     
}
