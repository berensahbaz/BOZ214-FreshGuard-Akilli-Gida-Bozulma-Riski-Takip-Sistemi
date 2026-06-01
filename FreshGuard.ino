#include <LiquidCrystal_I2C.h>

// LCD ekran tanımlama
LiquidCrystal_I2C lcd(0x27,16,2);

#include "HX711.h"

// HX711 pinleri
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

// HX711 nesnesi oluşturma
HX711 scale;

#include "DHT.h"

// DHT11 sıcaklık sensörü pini
#define DHTPIN 4

// Sensör tipi
#define DHTTYPE DHT11

// DHT sensör nesnesi
DHT dht(DHTPIN, DHTTYPE);

// LED ve buzzer pinleri
int yes = 9;   // Yeşil LED
int kir = 10;  // Kırmızı LED
int sar = 11;  // Sarı LED
int buz = 12;  // Buzzer

// Reed switch pini
int read = A0;

// Ürün takip başlangıç zamanı
unsigned long urunBaslangic = 0;

// Ürün var mı kontrol değişkeni
bool urunVar = false;

void setup() {

  // Seri haberleşmeyi başlat
  Serial.begin(9600);

  // HX711 başlat
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

  // DHT11 başlat
  dht.begin();

  // Reed switch giriş pini
  pinMode(read , INPUT);

  // LED ve buzzer çıkış pinleri
  pinMode(yes, OUTPUT);
  pinMode(kir, OUTPUT);
  pinMode(sar, OUTPUT);
  pinMode(buz, OUTPUT);

  // Başlangıçta tüm LED ve buzzer kapalı
  digitalWrite(yes,LOW);
  digitalWrite(kir,LOW);
  digitalWrite(sar,LOW);
  digitalWrite(buz,LOW);

  // LCD başlat
  lcd.init();

  // LCD ışığını aç
  lcd.backlight();

  // Açılış ekranı
  lcd.setCursor(0,0);
  lcd.print("FreshGuard");

  lcd.setCursor(0,1);
  lcd.print("Takip Sistemi");

  delay(3000);

  // LCD temizle
  lcd.clear();
}

void loop() {

  // Nem değerini oku
  float h = dht.readHumidity();

  // Sıcaklık değerini oku
  float t = dht.readTemperature();

  // Sıcaklık kontrol değişkeni
  bool sicaklikYuksek = false;

  // Sıcaklık 26 dereceden büyükse riskli kabul et
  if(t > 26) {
    sicaklikYuksek = true;
  }
  else {
    sicaklikYuksek = false;
  }

  // Kapak durumu kontrol değişkeni
  bool kapakKapali = false;

  // Reed switch ile kapağın kapalı olup olmadığını kontrol et
  if(!digitalRead(read)) {

    kapakKapali = true;

    // Kapak kapalıysa yeşil LED yanar
    digitalWrite(yes,HIGH);
  }
  else {

    kapakKapali = false;

    // Kapak açıksa yeşil LED söner
    digitalWrite(yes,LOW);
  }

  // Ürün algılama değişkeni
  bool urunAlgilandi = false;

  // HX711 sensörü çalışıyorsa
  if(scale.is_ready()) {

    // Sensör değerini oku
    long reading = scale.read();

    // Ürün algılama eşik değeri
    long esik = -340000;

    // Eğer eşik değerinden büyükse ürün var
    if(reading > esik) {

      urunAlgilandi = true;

      // Sarı LED yanar
      digitalWrite(sar,HIGH);
    }
    else {

      urunAlgilandi = false;

      // Sarı LED söner
      digitalWrite(sar,LOW);
    }
  }

  // Ürün yeni algılandıysa
  if(urunAlgilandi && !urunVar) {

    urunVar = true;

    // Takip başlangıç zamanını kaydet
    urunBaslangic = millis();

    // LCD mesajı
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Urun Algilandi");

    lcd.setCursor(0,1);
    lcd.print("Takip Basladi");

    delay(2000);
  }

  // Ürün çıkarıldıysa
  if(!urunAlgilandi && urunVar) {

    urunVar = false;

    // LCD mesajı
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Urun Yok");

    lcd.setCursor(0,1);
    lcd.print("Takip Bekliyor");

    delay(2000);
  }

  // Kapak açıksa uyarı ver
  if(!kapakKapali) {

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("KAPAK ACIK!");

    lcd.setCursor(0,1);
    lcd.print("Lutfen Kapat");

    // Buzzer kısa aralıklarla öter
    digitalWrite(buz,HIGH);
    delay(200);

    digitalWrite(buz,LOW);
    delay(200);

    return;
  }

  // Kapak kapalı ama ürün yoksa
  if(kapakKapali && !urunVar) {

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Sistem Hazir");

    lcd.setCursor(0,1);
    lcd.print("Takip Bekliyor");

    delay(2000);
  }

  // Sıcaklık ve nem ekranı
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Sic:");
  lcd.print(t);

  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("Nem:");
  lcd.print(h);

  lcd.print("%");

  delay(2000);

  // Eğer ürün varsa takip süresini hesapla
  if(urunVar) {

    // Geçen süre hesabı
    unsigned long gecenSure = millis() - urunBaslangic;

    // Saniyeye çevir
    unsigned long saniye = gecenSure / 1000;

    // Demo gün hesabı
    unsigned long demoGun = saniye / 20;

    // Süre ekranı
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Sure:");
    lcd.print(saniye);

    lcd.print(" sn");

    lcd.setCursor(0,1);
    lcd.print("Takip Ediliyor");

    delay(2000);

    // Risk analizi ekranı
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Demo Gun:");
    lcd.print(demoGun);

    // Riskli durum kontrolü
    if(sicaklikYuksek || demoGun >= 3) {

      lcd.setCursor(0,1);
      lcd.print("Durum:RISKLI");

      // Kırmızı LED ve buzzer aktif
      digitalWrite(kir,HIGH);
      digitalWrite(buz,HIGH);

      delay(500);

      digitalWrite(buz,LOW);

      delay(500);
    }

    // Dikkat durumu
    else if(demoGun >= 2) {

      lcd.setCursor(0,1);
      lcd.print("Durum:DIKKAT");

      digitalWrite(kir,LOW);
      digitalWrite(buz,LOW);

      delay(1000);
    }

    // Normal durum
    else {

      lcd.setCursor(0,1);
      lcd.print("Durum:NORMAL");

      digitalWrite(kir,LOW);
      digitalWrite(buz,LOW);

      delay(1000);
    }
  }

  // Ürün yoksa kırmızı LED ve buzzer kapalı
  else {

    digitalWrite(kir,LOW);
    digitalWrite(buz,LOW);
  }
}