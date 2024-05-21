#include <SPI.h>
#define VSPI_MISO   MISO 
#define VSPI_MOSI   MOSI
#define VSPI_SCLK   SCK
#define VSPI_SS     SS
#define GPIO1 D1
#define GPIO0 D0
#define LED_BUILTIN D2
static const int NCC[8] = {0,0,1,1,0,0,1,1}; //broadcast adress !0xCC
static const int NAA[8] = {0,1,0,1,0,1,0,1}; //scratchpad command for read !0xAA
int powerClass[8];

static const int spiClk = 1000000; //1 MHz clock frequency for LTC4296-1

static const int t_w1l = 300;         
static const int t_w0l = 2000;        
static const int t_w2l = t_w0l-t_w1l; 
static const int t_charge = 500;      
static const int t_write1 = t_w2l+t_charge;
static const int t_read = 2350;

bool a = false;
int c;
char cBuffer[128];
int cIndex = 0;
int i;
int j = 0;

SPIClass * spi = NULL; //initializes SPIClass pointer

void setup() 
{
  delay(10);
  pinMode(GPIO1, OUTPUT);
  pinMode(GPIO0, INPUT);
  spi = new SPIClass(SPI); //creating the SPIClass object
  spi->begin(VSPI_SCLK, VSPI_MISO, VSPI_MOSI, VSPI_SS); //assigning SPI pins to class
  pinMode(spi->pinSS(), OUTPUT); //setting the chip-select pin
  Serial.begin(115200);
  while ( !Serial ) {
    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
    delay(500);    
  }
  digitalWrite(GPIO1, LOW);
  Serial.println("Initilized");
  Serial.println("Write to SPI using commands below: ");
  Serial.println("a : global config.... ");
  Serial.println("b : port 0 statuses..... ");
  Serial.println("c : port to idle..... ");
  Serial.println("d : force power-good..... ");
  Serial.println("e : reset P0CFG0.... ");
  Serial.println("f : ports are searching.... ");
  Serial.println("g : SCCP init and write.... ");
  Serial.println("SCCP is ready.... ");
}
void loop() 
{
  digitalWrite(GPIO1, LOW); //assert line HIGH between operations
  if (Serial.available()) 
  {
    c = Serial.read();
    //cBuffer[cIndex] = c;
    //Serial.println(c);
    if (c == 0x61) //if letter is a
    {
      Serial.println("a : enable write and global config.....");
      spiWrite2(spi, 0x08, 0x00, 0x05, 0x0005); //write enable
      delay(1);
      spiWrite2(spi, 0x09, 0x00, 0x3D, 0x003D); //making lowfaults
      delay(1);
      spiWrite2(spi, 0x14, 0x00, 0x0C, 0x000C); //disable detection timer
      delay(1);
      spiWrite2(spi, 0x13, 0x00, 0x03, 0x0002);
      delay(1);
      Serial.print("P0CG0 status: ");
      Serial.println(spiRead(spi, 0x13), HEX); //disabled to idle
      delay(1);
      Serial.print("P0ST status: ");
      Serial.println(spiRead(spi, 0x12), HEX);
      delay(1);
      Serial.print("P0EV status: ");
      Serial.println(spiRead(spi, 0x10), HEX);
      delay(1);
      Serial.println("");
    }
        if (c == 0x62) //if letter is b
    {
      Serial.println("b : reading port 0.....");
      Serial.print("P0CG0 status: ");
      Serial.println(spiRead(spi, 0x13)); //disabled to idle
      delay(1);
      Serial.print("P0EV status: ");
      Serial.println(spiRead(spi, 0x10), HEX);
      delay(1);
      Serial.print("P0ST status: ");
      Serial.println(spiRead(spi, 0x012), HEX);
      delay(1);
      Serial.print("P0CFG0 status: ");
      Serial.println(spiRead(spi, 0x013), HEX);
      delay(1);
      Serial.print("P0CFG1 status: ");
      Serial.println(spiRead(spi, 0x014), HEX);
      delay(1);
      Serial.print("P0ADCDAT status: ");
      Serial.println(spiRead(spi, 0x016), HEX);
      delay(1);
      Serial.println("");
    }
    if (c == 0x63) //if letter is c
    {
      delay(1);
      Serial.println("c : idle state set.....");
      spiWrite2(spi, 0x13, 0x00, 0x03, 0x0001 | 0x0002); //disabled to idle
      delay(1);
      Serial.print("reading P0CG0 regiser.... ");
      Serial.println(spiRead(spi, 0x13)); //disabled to idle
      delay(1);
      Serial.print("P0EV status: ");
      Serial.println(spiRead(spi, 0x10), HEX);
      delay(1);
      Serial.print("P0ST status: ");
      Serial.println(spiRead(spi, 0x012), HEX);
      delay(1);
      Serial.print("P0CFG0 status: ");
      Serial.println(spiRead(spi, 0x013), HEX);
      delay(1);
      Serial.println("");
    //cIndex++;
    }
    if (c == 0x64) //if letter is d
    {
      delay(1);
      Serial.println("d : simulated power on.....");
      spiWrite2(spi, 0x13, 0x88, 0x27, 0x8827);
      delay(1);
      spiWrite2(spi, 0x14, 0x00, 0x0D, 0x000D); //write sim power good bit
      delay(1);
      Serial.print("P0EV status: ");
      Serial.println(spiRead(spi, 0x10), HEX);
      delay(1);
      Serial.print("P0ST status, 3012 if power-good: ");
      Serial.println(spiRead(spi, 0x012), HEX);
      delay(1);
      Serial.print("Write successful = 0x : ");
      Serial.println(spiRead(spi, 0x013), HEX);
      delay(1);
      Serial.println("");
    //cIndex++;
    }
    if (c == 0x65) //if letter is e
    {
      spiWrite2(spi, 0x13, 0x00, 0x02, 0x0002);
      delay(1);
      spiWrite2(spi, 0x14, 0x00, 0x0C, 0x000C); //write sim power good bit
      delay(1);
    //cIndex++;
    }
    if (c == 0x66) //if letter is f
    {
      delay(1);
      Serial.println("f : simulated power on.....");
      spiWrite2(spi, 0x13, 0xA8, 0x27, 0xA827);
      delay(1);
      spiWrite2(spi, 0x14, 0x00, 0x0C, 0x000C); //write sim power good bit
      delay(1);
      Serial.print("P0EV status: ");
      Serial.println(spiRead(spi, 0x10), HEX);
      delay(1);
      Serial.print("P0ST status, 3012 if power-good: ");
      Serial.println(spiRead(spi, 0x012), HEX);
      delay(1);
      Serial.print("Write successful = 0x : ");
      Serial.println(spiRead(spi, 0x013), HEX);
      delay(1);
      Serial.println("");
    //cIndex++;
    }

    if (c == 0x67)  //trigger if g
    {
      init(); //starter reset og sjekker om SCCP svarer med å trekke linja lav
      write_CC_AA(); //sender !0xCC og !0xAA, skal kun utføres når init() får riktig respons, men har ikke implementert det enda
      read_plot();
      Serial.print("\n");
    }

    if (c == 0x68)  //trigger if h, SCCP program
    {
      init(); 
      write_CC_AA(); 
      read_plot();
      if(powerClass[0] == 0 & powerClass[1] == 1 & powerClass[2] == 0 & powerClass[3] == 0 & 
      powerClass[4] == 0 & powerClass[5] == 0 & powerClass[6] == 0 & powerClass[7])
      {
        Serial.println("SCCP classification successful: ");
        Serial.println("d : SCCP power on.....");
        spiWrite2(spi, 0x13, 0x88, 0x27, 0x8827);
        delay(1);
        spiWrite2(spi, 0x14, 0x00, 0x0D, 0x000D); //write sim power good bit
        delay(1);
      }
      else
      {
        Serial.println("SCCP classification unsuccessful: ");
        spiWrite2(spi, 0x13, 0x00, 0x02, 0x0002);
        delay(1);
        spiWrite2(spi, 0x14, 0x00, 0x0C, 0x000C); //write sim power good bit
        delay(1);
      }
      }
      Serial.print("\n");
    }
  digitalWrite(GPIO1, LOW); 
  delay(10);
}
void init (void)
{
      delay(1);
      digitalWrite(GPIO1, HIGH); //skrur av linja i 9.3ms
      delayMicroseconds(9300); //reset init
      digitalWrite(GPIO1, LOW); //reset end
      delay(3);
      while(digitalRead(GPIO0) != 1) //interrupt funksjon, ikke optimal men fungerer til testingen. Sjekker når SCCP er ferdig med å sende
      {
      }
      Serial.println("SCCP pin pulls LOW.....");
}
void write_CC_AA (void)
{
  delayMicroseconds(500);
  //Write broadcast adress
  for (i=0; i<8; i++)
  {
    Serial.print(NCC[i]);
    if(NCC[i] == 1)
    {
      //HIGH write slot pulse
      digitalWrite(GPIO1, HIGH); 
      delayMicroseconds(t_w1l);
      digitalWrite(GPIO1, LOW); 
      delayMicroseconds(t_write1); 
    }
    else
    {
      //LOW write slot pulse
      digitalWrite(GPIO1, HIGH); 
      delayMicroseconds(t_w0l);
      digitalWrite(GPIO1, LOW);  
      delayMicroseconds(t_charge);
    }
  }
  Serial.println("");
  //Write scratchpad command
  for (i=0; i<8; i++)
  {
    Serial.print(NAA[i]);
    if(NAA[i] == 1)
    {
      //HIGH write slot pulse
      digitalWrite(GPIO1, HIGH); 
      delayMicroseconds(t_w1l);
      digitalWrite(GPIO1, LOW); 
      delayMicroseconds(t_write1); 
    }
    else
    {
      //LOW write slot pulse
      digitalWrite(GPIO1, HIGH); 
      delayMicroseconds(t_w0l);
      digitalWrite(GPIO1, LOW);  
      delayMicroseconds(t_charge);
    }
  }
  Serial.println("\n");
}
uint16_t spiRead(SPIClass *spi, byte rAdress)
{
  uint8_t rAdress1 = (rAdress << 1) | 0x01;
  uint8_t PECA = get_pec_byte(rAdress1, 0x41);
  uint16_t datain;
  uint8_t PECD;
  spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(spi->pinSS(), LOW);
  spi->transfer(rAdress1);
  spi->transfer(PECA);
  datain = spi->transfer16(0x0000);
  PECD = spi->transfer(0x00);
  digitalWrite(spi->pinSS(), HIGH);
  spi->endTransaction();
  return datain;
}
uint16_t spiWrite2(SPIClass *spi, byte rAdress, byte data1, byte data0, uint16_t data)
{
  uint8_t rAdress1 = (rAdress << 1) & ~0x01;
  uint8_t PECR = get_pec_byte(rAdress1, 0x41);
  uint8_t intermediate = get_pec_byte(data1, 0x41);
  uint8_t PECD = get_pec_byte(data0, intermediate);
  uint16_t dataOut;
  spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(spi->pinSS(), LOW);
  spi->transfer(rAdress1);
  spi->transfer(PECR);
  spi->transfer16(data);
  spi->transfer(PECD);
  digitalWrite(spi->pinSS(), HIGH);
  spi->endTransaction();
  return dataOut;
}
uint16_t spiWrite(SPIClass *spi, byte rAdress, byte data1, byte data0, uint16_t data)
{
  uint8_t rAdress1 = (rAdress << 1) & ~0x01;
  uint8_t PECR = get_pec_byte(rAdress1, 0x41);
  uint8_t intermediate = get_pec_byte(data1, 0x41);
  uint8_t PECD = get_pec_byte(data0, intermediate);
  uint16_t dataOut;
  spi->beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));
  digitalWrite(spi->pinSS(), LOW);
  spi->transfer(rAdress1);
  spi->transfer(PECR);
  spi->transfer16(data);
  spi->transfer(PECD);
  digitalWrite(spi->pinSS(), HIGH);
  spi->endTransaction();
  return dataOut;
}
void read_plot(void)
{
  Serial.print("Response from LTC9111: ");
  for (i=0;i<8;i++)
  {
    digitalWrite(GPIO1, HIGH);
    delayMicroseconds(t_w1l);
    digitalWrite(GPIO1, LOW);
    delayMicroseconds(200);
    //Serial.print(digitalRead(GPIO0));
    powerClass[i] = digitalRead(GPIO0);
    Serial.print(powerClass[i]);
    delayMicroseconds(t_read-200);
  }
  Serial.println("");
}

uint8_t get_pec_byte(uint8_t data, uint8_t seed) //calculate PEC byte
{
 uint8_t pec = seed;
 uint8_t din, in0, in1, in2;
 int bit;
 for(bit=7; bit>=0; bit--)
 {
 din = (data>>bit) & 0x01;
 in0 = din ^ ( (pec>>7) & 0x01 );
 in1 = in0 ^ ( pec & 0x01);
 in2 = in0 ^ ( (pec>>1) & 0x01 );
 pec = (pec << 1);
 pec &= ~(0x07);
 pec = pec | in0 | (in1<<1) | (in2<<2);
 }
 return pec;
}