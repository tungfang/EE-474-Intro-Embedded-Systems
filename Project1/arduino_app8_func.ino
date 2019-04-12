void arduino_app8_func(unsigned long delay1, unsigned long delay2, char str[]) 
{ 
  tft.print(str);
  tft.setCursor(0,0);
  user_delay(delay1);
  tft.fillScreen(BLACK);
  tft.print("       ");
  tft.setCursor(0,0);
  user_delay(delay2);
}


// Delay Function
void user_delay(int delay_sec)
{
  volatile long i = 0;
  for (i = 600000 * delay_sec; i > 0;) 
  {
    i--;
  }
}
