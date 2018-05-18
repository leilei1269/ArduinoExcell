float potpin = 0;    //  variavel que define a porta do potenciometro.
int ROW = 0;         // variavel que se refere as linhas do excel
int LABEL = 1;   
int val = 0;               // variavel que guarda o valor lido do potenciometro
void setup(){
Serial.begin(9600);                     //  inicialização da comunicação serial
Serial.println("CLEARDATA");            // Reset da comunicação serial
Serial.println("LABEL,Time,val,ROW");   // Nomeia as colunas
}

void loop(){

val = analogRead(potpin);   // faz a leitura do potenciometro e guarda o valor em val.
ROW++; // incrementa a linha do excel para que a leitura pule de linha em linha

Serial.print("DATA,TIME,"); //inicia a impressão de dados, sempre iniciando 
Serial.print(val); 
Serial.print(",");
Serial.println(ROW);

if (ROW > 100) //laço para limitar a quantidade de dados
{
ROW = 0;
Serial.println("ROW,SET,2"); // alimentação das linhas com os dados sempre iniciando
}
delay(200);  // espera 200 milisegundos


}
