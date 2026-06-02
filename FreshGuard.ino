// =====================================================
// FRESHGUARD - AKILLI GIDA TAKIP SISTEMI
// BOZ214 Fiziksel Programlama Final Projesi
// Gelistirici: Beren Sahbaz
// =====================================================


// ================= LCD KUTUPHANESI =================
// I2C destekli 16x2 LCD ekran kutuphanesi
#include <LiquidCrystal_I2C.h>

// LCD adresi: 0x27
// 16 sutun, 2 satir
LiquidCrystal_I2C lcd(0x27,16,2);


// ================= HX711 LOAD CELL =================
// HX711 kutuphanesi
#include "HX711.h"

// HX711 pin tanimlari
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// HX711 nesnesi
HX711 scale;


// ================= DHT11 SENSOR =================
// DHT kutuphanesi
#include "DHT.h"

// DHT11 veri pini
#define DHTPIN 4

// Sensor tipi
#define DHTTYPE DHT11

// DHT nesnesi
DHT dht(DHTPIN, DHTTYPE);


// ================= LED VE BUZZER =================

// Yesil LED pini
int yes = 9;

// Kirmizi LED pini
int kir = 10;

// Sari LED pini
int sar = 11;

// Buzzer pini
int buz = 12;


// ================= DIGER PINLER =================

// Buton pini (aktif degil)
int but1  = A1;

// Reed switch kapak sensoru pini
int read = A0;

// Sayac degiskeni
int say = 0;


// ================= SISTEM DEGISKENLERI =================

// Sistem hazir yazisinin tekrar tekrar cikmamasi icin
bool sistemHazirGosterildi = false;

// Onceki kapak durumu
bool oncekiKapakKapali = false;

// Onceki urun durumu
bool oncekiUrunVar = false;


// Takip suresi baslangici
unsigned long takipBaslamaZamani = 0;



// =====================================================
// SETUP FONKSIYONU
// Sistem ilk acildiginda bir kez calisir
// =====================================================
void setup() {

  // Serial monitor baslatma
  Serial.begin(9600);

  // HX711 baslatma
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // DHT11 sensor baslatma
  dht.begin();

  // Pin modlari
  pinMode(but1, INPUT);
  pinMode(read , INPUT);

  pinMode(yes, OUTPUT);
  pinMode(kir, OUTPUT);
  pinMode(sar, OUTPUT);
  pinMode(buz, OUTPUT);

  // Tum LED ve buzzer baslangicta kapali
  digitalWrite(yes,LOW);
  digitalWrite(kir,LOW);
  digitalWrite(sar,LOW);
  digitalWrite(buz,LOW);

  // LCD baslatma
  lcd.init();

  // LCD arka isik aktif
  lcd.backlight();


  // ================= ACILIS EKRANI =================

  lcd.setCursor(2,0);
  lcd.print("FreshGuard");

  lcd.setCursor(0,1);
  lcd.print("Takip Sistemi");

  // 3 saniye bekleme
  delay(3000);

  // LCD temizleme
  lcd.clear();
}



// =====================================================
// LOOP FONKSIYONU
// Sistem surekli bu dongu icinde calisir
// =====================================================
void loop() {


  // ================= DHT11 VERI OKUMA =================

  // Nem verisi okuma
  float h = dht.readHumidity();

  // Sicaklik verisi okuma
  float t = dht.readTemperature();


  // Sensor verisi okunamazsa hata ver
  if (isnan(h) || isnan(t)) {

    Serial.println(F("DHT sensor okunamadi!"));

    return;
  }


  // Serial monitor ekranina verileri yazdir
  Serial.print(F("Nem: "));
  Serial.print(h);

  Serial.print(F("  Sicaklik: "));
  Serial.println(t);



  // ================= KAPAK KONTROL =================

  // Reed switch ile kapak kontrolu
  bool kapakKapali = !digitalRead(read);


  // Kapak kapaliysa yesil LED yanar
  if(kapakKapali) {

    digitalWrite(yes, HIGH);
  }

  // Kapak aciksa yesil LED kapanir
  else {

    digitalWrite(yes, LOW);

    sistemHazirGosterildi = false;
  }



  // ================= SICAKLIK KONTROL =================

  bool sicaklikYuksek = false;

  // Sicaklik 26 derecenin ustundeyse riskli kabul edilir
  if(t > 26) {

    sicaklikYuksek = true;
  }

  else {

    sicaklikYuksek = false;
  }



  // =====================================================
  // KAPAK ACIK SENARYOSU
  // =====================================================
  if(!kapakKapali) {

    lcd.clear();

    lcd.setCursor(2,0);
    lcd.print("KAPAK ACIK!");

    lcd.setCursor(1,1);
    lcd.print("Lutfen Kapat");


    // Buzzer kisa araliklarla uyarir
    digitalWrite(buz, HIGH);
    delay(150);

    digitalWrite(buz, LOW);
    delay(850);

    oncekiKapakKapali = false;
  }



  // =====================================================
  // KAPAK KAPALI SENARYOSU
  // =====================================================
  else {


    // ================= SISTEM HAZIR EKRANI =================

    if(sistemHazirGosterildi == false) {

      lcd.clear();

      lcd.setCursor(1,0);
      lcd.print("Sistem Hazir");

      lcd.setCursor(0,1);
      lcd.print("Takip Bekleniyor");

      delay(1500);

      lcd.clear();

      sistemHazirGosterildi = true;
    }



    // ================= URUN ALGILAMA SISTEMI =================

    bool urunVar = false;


    // HX711 baglantisi hazirsa veri oku
    if (scale.is_ready()) {

      // Ham sensor verisi
      long reading = scale.read();

      Serial.print("HX711 reading: ");
      Serial.println(reading);


      // Esik degeri
      long bak = -340000.0;


      // Sensor degeri esikten buyukse urun var
      if(reading > bak) {

        urunVar = true;

        // Sari LED aktif
        digitalWrite(sar, HIGH);
      }

      // Sensor degeri dusukse urun yok
      else {

        urunVar = false;

        digitalWrite(sar, LOW);
      }

    }

    else {

      Serial.println("HX711 bulunamadi.");

      digitalWrite(sar, LOW);
    }



    // =====================================================
    // URUN YENI ALGILANDI
    // =====================================================
    if(urunVar == true && oncekiUrunVar == false) {

      // Takip baslangic zamani kaydedilir
      takipBaslamaZamani = millis();

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Urun Algilandi");

      lcd.setCursor(1,1);
      lcd.print("Takip Basladi");

      delay(1500);

      lcd.clear();
    }



    // Urun yoksa sure sifirlanir
    if(urunVar == false) {

      takipBaslamaZamani = 0;
    }



    // ================= TAKIP SURESI =================

    unsigned long toplamSaniye = 0;

    unsigned long dakika = 0;

    unsigned long saniye = 0;

    int demoGun = 0;



    // Urun varsa sure hesaplanir
    if(urunVar == true && takipBaslamaZamani > 0) {

      // Gecen sure hesaplama
      unsigned long gecenSure = millis() - takipBaslamaZamani;

      toplamSaniye = gecenSure / 1000;

      dakika = toplamSaniye / 60;

      saniye = toplamSaniye % 60;


      // Demo gun sistemi
      if(toplamSaniye < 20) {

        demoGun = 1;
      }

      else if(toplamSaniye < 40) {

        demoGun = 2;
      }

      else {

        demoGun = 3;
      }
    }



    // ================= SURE RISK ANALIZI =================

    bool sureRiskli = false;


    // Demo gun 3 ve ustu riskli kabul edilir
    if(urunVar == true && demoGun >= 3) {

      sureRiskli = true;
    }

    else {

      sureRiskli = false;
    }



    // ================= URUN DURUM EKRANI =================

    if(urunVar == true) {

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Urun:VAR");

      lcd.setCursor(0,1);
      lcd.print("Takip Aktif");

      delay(1500);

    }

    else {

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Urun:YOK");

      lcd.setCursor(0,1);
      lcd.print("Takip Bekliyor");

      delay(1500);
    }



    // ================= SICAKLIK VE NEM EKRANI =================

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Sic:");
    lcd.print(t);
    lcd.print("C");

    lcd.setCursor(0,1);
    lcd.print("Nem:%");
    lcd.print(h);

    delay(1500);



    // =====================================================
    // TAKIP AKTIFSE EK BILGILER GOSTER
    // =====================================================
    if(urunVar == true) {

      // ================= TAKIP SURESI EKRANI =================

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Sure:");

      lcd.print(dakika);
      lcd.print("dk ");

      lcd.print(saniye);
      lcd.print("sn");

      lcd.setCursor(0,1);
      lcd.print("Takip Ediliyor");

      delay(1500);


      // ================= DURUM ANALIZI =================

      lcd.clear();


      // Sicaklik yuksekse riskli durum
      if(sicaklikYuksek) {

        lcd.setCursor(0,0);
        lcd.print("Durum:RISKLI");

        lcd.setCursor(0,1);
        lcd.print("Sicaklik Yuksek");

      }


      // Demo gun 1 = normal
      else if(demoGun == 1) {

        lcd.setCursor(0,0);
        lcd.print("Demo Gun:1");

        lcd.setCursor(0,1);
        lcd.print("Durum:NORMAL");

      }


      // Demo gun 2 = dikkat
      else if(demoGun == 2) {

        lcd.setCursor(0,0);
        lcd.print("Demo Gun:2");

        lcd.setCursor(0,1);
        lcd.print("Durum:DIKKAT");

      }


      // Demo gun 3 = riskli
      else {

        lcd.setCursor(0,0);
        lcd.print("Demo Gun:3");

        lcd.setCursor(0,1);
        lcd.print("Durum:RISKLI");
      }

      delay(1500);
    }



    // ================= ALARM SISTEMI =================

    // Sicaklik yuksek veya sure riskliyse alarm aktif
    if(sicaklikYuksek || sureRiskli) {

      digitalWrite(kir, HIGH);

      digitalWrite(buz, HIGH);
    }

    else {

      digitalWrite(kir, LOW);

      digitalWrite(buz, LOW);
    }



    // Onceki durumlari kaydet
    oncekiUrunVar = urunVar;

    oncekiKapakKapali = true;
  }
}
