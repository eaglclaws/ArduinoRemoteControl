#include <IRremote.h>

static const long int hex[21]
{
  0xFFA25D, //: CH-
  0xFF629D, //: CH
  0xFFE21D, //: CH+

  0xFF22DD, //: PREV
  0xFF02FD, //: NEXT
  0xFFC23D, //: PLAY/PAUSE

  0xFFE01F, //: VOL
  0xFFA857, //: VOL+
  0xFF906F, //: EQ

  0xFF6897, //: 0
  0xFF9867, //: 100+
  0xFFB04F,  //: 200+

  0xFF30CF, //: 1
  0xFF18E7, //: 2 
  0xFF7A85, //: 3

  0xFF10EF, //: 4
  0xFF38C7, //: 5
  0xFF5AA5, //: 6

  0xFF42BD, //: 7
  0xFF4AB5, //: 8
  0xFF52AD, //: 9
};

decode_results CHdown;
decode_results CH;
decode_results CHup; 

decode_results PREV;
decode_results NEXT;
decode_results PLAY;

decode_results VOLdown;
decode_results VOLup;
decode_results EQ;

decode_results BUT0;
decode_results BUT100up;
decode_results BUT200up;

decode_results BUT1;
decode_results BUT2;
decode_results BUT3;

decode_results BUT4;
decode_results BUT5;
decode_results BUT6;

decode_results BUT7;
decode_results BUT8;
decode_results BUT9;


int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  CHdown.value = hex[0];
  CH.value = hex[1];
  CHup.value = hex[2];

  PREV.value = hex[3];
  NEXT.value = hex[4];
  PLAY.value = hex[5];

  VOLdown.value = hex[6];
  VOLup.value = hex[7];
  EQ.value = hex[8];

  BUT0.value = hex[9];
  BUT100up.value = hex[10];
  BUT200up.value = hex[11];
  
  BUT1.value = hex[12];
  BUT2.value = hex[13];
  BUT3.value =  hex[14];
  
  BUT4.value = hex[15];
  BUT5.value = hex[16];
  BUT6.value = hex[17];
  
  BUT7.value = hex[18];
  BUT8.value = hex[19];
  BUT9.value = hex[20];
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
    switch(results.value)
    {
      case 0xFFA25D:
        Serial.println("CH-");
        break;
      case 0xFF629D:
        Serial.println("CH");
        break;
      case 0xFFE21D:
        Serial.println("CH+");
        break;
      case 0xFF22DD:
        Serial.println("PREV");
        break;
      case 0xFF02FD:
        Serial.println("NEXT");
        break;
      case 0xFFC23D:
        Serial.println("PLAY/PAUSE");
        break;
      case 0xFFE01F:
        Serial.println("VOL-");
        break;
     case 0xFFA857:
        Serial.println("VOL+");
        break;
      case 0xFF906F:
        Serial.println("EQ");
        break;
      case 0xFF6897:
        Serial.println("0");
        break;
      case 0xFF9867:
        Serial.println("100+");
        break;
      case 0xFFB04F:
        Serial.println("200+");
        break;
      case 0xFF30CF:
        Serial.println("1");
        break;
      case 0xFF18E7:
        Serial.println("2");
        break;
      case 0xFF7A85:
        Serial.println("3");
        break;
      case 0xFF10EF:
        Serial.println("4");
        break;
      case 0xFF38C7:
        Serial.println("5");
        break;
      case 0xFF5AA5:
        Serial.println("6");
        break;
      case 0xFF42BD:
        Serial.println("7");
        break;
      case 0xFF4AB5:
        Serial.println("8");
        break;
      case 0xFF52AD:
        Serial.println("9");
        break;
      default:
        Serial.println("Please Wait");
        break;
    }
    //Serial.println(results.value, HEX);
    irrecv.resume();
  }
  delay(100);
}
