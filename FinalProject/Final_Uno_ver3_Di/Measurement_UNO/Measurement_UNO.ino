//define hardware delay time
unsigned long long startMillis;
unsigned long long currentMillis;
const unsigned long period = 500; //delay 500ms

//define temperature measurement
int reading;
int temperature;

//define digital pins for pressuremeasurement
const int buttonPin_inc = 11;
const int buttonPin_dec = 12;

int flag5ms = 1;
int pressure_buff = 100;
int pressure_sys=0; //value to record the maximum pressure in the range of 110~150 mmHg
int pressure_dia=0; //value to record the minimum pressure in the range of 50~80 mmHg
int pressure_sys_prev = 0;
int pressure_dia_prev = 80;
int pressure_sys_flag = 0;// set the flag presure_sys measurement is finished
int pressure_dia_flag = 0;// set the flag pressure_dia measurement is finished

int buttonState_inc=0;
int buttonState_dec=0;
int lastbuttonState_inc=0;
int lastbuttonState_dec=0;

//define interrupt for pulse rate measurement
int pulserate_pin = 2;
int respirationrate_pin = 3;
volatile unsigned int pulserate;
volatile unsigned int respirationrate;

//flag received from MEGA
char intByte;

void setup() {
  Serial.begin(9600);
  //define temperature measurement pin
  pinMode(A0, INPUT);
  //define pressure measurement pin
  pinMode(buttonPin_dec,INPUT);
  pinMode(buttonPin_inc,INPUT);
  //define pulserate measurement pin
  attachInterrupt(0,count_pulse,RISING);
  attachInterrupt(1,count_respiration,RISING);
}

void loop() {
  //analog temperature reading
  reading = analogRead(A0);
  //float voltage = reading/1024.0*5.0;
  temperature = 15+(50-15)*(reading-500)/(1024-500);  //temperature range:15 (reading = 500)~50 (reading =1024) //mapping function
  //Serial.println(voltage);

  //pressure reading
  if (flag5ms) {
    buttonState_inc = digitalRead(buttonPin_inc);
    buttonState_dec = digitalRead(buttonPin_dec);
  }
  //Serial.print("increase button state is:");
  //Serial.println(buttonState_inc);
  //Serial.print("decrease buttong state is:");
  //Serial.println(buttonState_dec);
  if(buttonState_inc!=lastbuttonState_inc)
    if(buttonState_inc==HIGH)
      {pressure_buff=pressure_buff*1.1;
      //Serial.println(pressure_buff);
      lastbuttonState_inc=HIGH;}
     else
      lastbuttonState_inc=LOW;

  if(buttonState_dec!=lastbuttonState_dec)
    if(buttonState_dec==HIGH)
      {pressure_buff=pressure_buff*0.9;
      //Serial.println(pressure_buff);
      lastbuttonState_dec=HIGH;}
     else
      lastbuttonState_dec=LOW;

  if (pressure_buff>=110 && pressure_buff<=150)//record pressure_sys value
    if (pressure_buff>=pressure_sys_prev)
      pressure_sys_prev = pressure_buff;
      else
      {pressure_sys = pressure_sys_prev; //record the maximum sys value in the record range
      pressure_sys_flag = 1;} //pressure_sys measurement has been finished
  if (pressure_buff>150)
      {pressure_sys =150;
      pressure_sys_flag = 1;} //pressure_sys measurement has been finished 

  if (pressure_buff>=50 && pressure_buff<=80) //record pressure_dia value
    if (pressure_buff<=pressure_dia_prev)
      {pressure_dia_prev = pressure_buff;}//pressure_dia measurement has been finished
      else
      {pressure_dia = pressure_dia_prev; //recording the minimum dia vallue in the record range
      pressure_dia_flag = 1;
      }
  if (pressure_buff<50)
      {pressure_dia=50;
      pressure_dia_flag = 1;} //presssure_dia measurement has been finished

 
  //pulse rate & respiration rate reading
    pulserate = 0;
    respirationrate =0;
    interrupts();
    //delay(500);
    startMillis=millis(); //get the initial "time" 
    currentMillis=millis(); //get the current "time"
    while (currentMillis-startMillis<period)
    {currentMillis =millis();}
    noInterrupts();
    //Serial.print("Pulse rate is:");
    //Serial.println(pulserate);
    //Serial.print("Respiration rate is:");
    //Serial.println(respirationrate);
     //delay(1000);

  if (Serial.available()>0)
    intByte = Serial.read();
  if (intByte == '1') //'1' is the flag to run Temperature Measurement in Uno
    { //Serial.println("Test Temperature");
      //Serial.print('U');
    Serial.println(temperature);
    intByte=0;}
  if (intByte == '2') // '2' is the flag to run Blood Pressure Measurement in Uno
    { 
      if(pressure_sys_flag == 1 && pressure_dia_flag ==1)
      {Serial.print(pressure_sys);
      //Serial.print("\t");
      Serial.println(pressure_dia);
      intByte=0;
      
       //restore the initial value
       pressure_sys_prev=0;
       pressure_dia_prev=80;
       pressure_buff = 100;
       pressure_sys_flag = 0;// set the flag presure_sys measurement is finished
       pressure_dia_flag = 0;// set the flag pressure_dia measurement is finished
     }
      else
      {
       Serial.println(pressure_buff);
       intByte=0;
       //Serial.print("Pressure sys is:");Serial.println(pressure_sys);
       //Serial.print("Pressure dia is:");Serial.println(pressure_dia);
      }
      
    }
  if (intByte == '3') // '3' is the flag to run the Pulse Rate Measurement in Uno
    {Serial.println(2*pulserate);
    intByte=0;}//500ms
  if (intByte == '4') // '4' is the flag to run the Respiration Rate Measurement in Uno
    {Serial.println(2*respirationrate);//500ms
    intByte=0;}
}

void count_pulse()
{
  pulserate ++;
  }

void count_respiration()
{
 respirationrate ++;  
}
