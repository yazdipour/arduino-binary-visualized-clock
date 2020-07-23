int ledPinsSec[] = {2, 3, 4, 5, 6, 7};
int ledPinsMin[] = {8, 9, 10, 11, 12, 13};
int ledPinsHr[] = {14, 15, 16, 17, 18, 19};
int countS = 50;
int countM = 59;
int countH = 23;

byte countSec;
byte countMin;
byte countHr;

void setup(void)
{
  for (byte i = 0; i < 6; i++) {
    pinMode(ledPinsSec[i], OUTPUT);
    pinMode(ledPinsMin[i], OUTPUT);
    pinMode(ledPinsHr[i], OUTPUT);
  }
}

void loop(void)
{
  countS = (countS + 1);
  if (countS > 59)
  {
    countS = 0;
    countM = (countM + 1);
    if (countM > 59)
    {
      countM = 0;
      countH = (countH + 1);
      if (countH > 23)
      {
        countH = 0;
        countM = 0;
        countS = 0;
      }
    }
  }

  disp(countS,countM,countH);
  delay(1000);
}

void disp(byte nSec, byte nMin, byte nHr)
{
  for (byte i = 0; i < 6; i++) {
    digitalWrite(ledPinsSec[i], nSec & 1);
    nSec /= 2;
    digitalWrite(ledPinsMin[i], nMin & 1);
    nMin /= 2;
    digitalWrite(ledPinsHr[i], nHr & 1);
    nHr /= 2;
  }
}
