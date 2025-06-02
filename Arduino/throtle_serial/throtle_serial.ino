// Throttle Kanan
int pinKanan = A1;
//int ThrottleKanan = analogRead(pinKanan);
int ThrottleKanan = 0;
int LastThrottleKanan = 0;

// Throttle Kiri
int pinKiri = A0;
//int ThrottleKiri = analogRead(pinKiri);
int ThrottleKiri = 0;
int LastThrottleKiri = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{ 
  ThrottleKanan = analogRead(pinKanan);
  ThrottleKiri = analogRead(pinKiri);

    if (LastThrottleKanan != ThrottleKanan) {
      LastThrottleKanan = ThrottleKanan;
    }

    if (LastThrottleKiri != ThrottleKiri) {
      LastThrottleKiri = ThrottleKiri;
    }

    String stdata = String('\02') + "t;" +   String(LastThrottleKiri) + ";" + String(LastThrottleKanan) + "#" + String('\03');
    Serial.print(stdata);
  
  delay(1000);
}
