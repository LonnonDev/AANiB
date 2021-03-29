int counter = 0;
int a[10], n, i;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
int decimalToBinary(int n) {
  String FinalNum;
  for (i = 0; n > 0; i++)
  {
    a[i] = n % 2;
    n = n / 2;
  }
  for (i = i - 1 ; i >= 0 ; i--)
  {
    FinalNum += String(a[i]);
  }
  //print(String(FinalNum));
  return FinalNum.toInt();
}
void print(String arg) {
  Serial.println(arg);
}

void loop() {
  if (counter != 15) {
    counter++;
    delay(1000);
    String BinNum = String(decimalToBinary(counter));
    if ((String(BinNum.length())) == "1") {
      BinNum = ("000" + String(BinNum));
    } else if ((String(BinNum.length())) == "2") {
      BinNum = ("00" + String(BinNum));
    } else if ((String(BinNum.length())) == "3") {
      BinNum = ("0" + String(BinNum));
    }
    //print(String(String(BinNum).length()));
    print(String(BinNum));
    //char dn[1] = {String(decimalToBinary(counter))};
    if (BinNum.substring(0,1) == "1") { digitalWrite(2, HIGH); } else { digitalWrite(2, LOW); }
    if (BinNum.substring(1,2) == "1") { digitalWrite(3, HIGH); } else { digitalWrite(3, LOW); }
    if (BinNum.substring(2,3) == "1") { digitalWrite(4, HIGH); } else { digitalWrite(4, LOW); }
    if (BinNum.substring(3,4) == "1") { digitalWrite(5, HIGH); } else { digitalWrite(5, LOW); }
  } else {
    delay(5000);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  
}
