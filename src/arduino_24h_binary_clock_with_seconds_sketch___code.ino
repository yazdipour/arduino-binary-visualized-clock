// This clock does not (yet) synchronise with any time server and does not use a real clock module to stay exactly on time (yet).
// It just runs a basic seconds count with a 1000 millisecond delay in the sketch. LEDs are connected to PWM 3 to 19 with a resistor each.
// PWM pins 14 to 19 are the Analog pins 0 to 5.
// pins 2 - 13 are the regular digital pwm pins.
int ledPinsSec[] = {2, 3, 4, 5, 6, 7};
int ledPinsMin[] = {8, 9, 10, 11, 12, 13};

// pins 14 - 20 are the analog pins 0 - 5 used as digital pwm pins  
int ledPinsHr[] = {14, 15, 16, 17, 18, 19};

// set Start time here
int countS = 0;   // Seconds
int countM = 13;  // Minutes
int countH = 23;  // Hours

byte countSec;
byte countMin;
byte countHr;
#define nBitsSec sizeof(ledPinsSec)/sizeof(ledPinsSec[0])
#define nBitsMin sizeof(ledPinsMin)/sizeof(ledPinsMin[0])
#define nBitsHr sizeof(ledPinsHr)/sizeof(ledPinsHr[0])

void setup(void)
{
  for (byte i = 0; i < nBitsSec; i++) {
    pinMode(ledPinsSec[i], OUTPUT);
  }

  for (byte i = 0; i < nBitsMin; i++) {
    pinMode(ledPinsMin[i], OUTPUT);
  }

  for (byte i = 0; i < nBitsHr; i++) {
    pinMode(ledPinsHr[i], OUTPUT);
  }
}

// ----- Main Routine -------------------------------------------------

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

  dispBinarySec(countS);
  dispBinaryMin(countM);
  dispBinaryHr(countH);

  delay(1000);   // 1000 milliseconds = approx. 1 second delay
  // ADJUST for fast or slow running clock here, in milliseconds.
}

// ----- Subroutines ---------------------------------------------------

void dispBinarySec(byte nSec)
{
  for (byte i = 0; i < nBitsSec; i++) {
    digitalWrite(ledPinsSec[i], nSec & 1);
    nSec /= 2;
  }
}

void dispBinaryMin(byte nMin)
{
  for (byte i = 0; i < nBitsMin; i++) {
    digitalWrite(ledPinsMin[i], nMin & 1);
    nMin /= 2;
  }
}

void dispBinaryHr(byte nHr)
{
  for (byte i = 0; i < nBitsHr; i++) {
    digitalWrite(ledPinsHr[i], nHr & 1);
    nHr /= 2;
  }
}
