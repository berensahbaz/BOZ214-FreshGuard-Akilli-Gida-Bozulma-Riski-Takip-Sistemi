# FreshGuard – Akıllı Gıda Bozulma Riski Takip Sistemi
Arduino tabanlı akıllı gıda bozulma riski takip sistemi.

📚 Ders: BOZ214 – Fiziksel Programlama  
🛠️ Proje Türü: Final Projesi  
👩‍💻 Geliştirici: Beren Şahbaz  
🏫 Üniversite: Ankara Üniversitesi  
✅ Durum: Tamamlandı (v1.0)

---

## 📖 Proje Hakkında

FreshGuard, Arduino Uno tabanlı akıllı gıda takip ve bozulma riski uyarı sistemidir. Bu proje, bir gıda ürününün kutu içerisinde bulunup bulunmadığını algılamak, ortam sıcaklığı ve nemini takip etmek, kapağın açık veya kapalı olduğunu kontrol etmek ve riskli durumlarda kullanıcıyı uyarmak amacıyla geliştirilmiştir.

Sistem; DHT11 sıcaklık-nem sensörü, HX711 modülü ve load cell ile ürün algılama sistemi, kapak kontrolü için reed switch, LCD ekran ile kullanıcı bilgilendirme, kırmızı-sarı-yeşil LED sistemi ve buzzer ile sesli uyarı bileşenlerini bir araya getirir.

FreshGuard yalnızca sıcaklık ve nem değerlerini göstermemektedir. Aynı zamanda ürünün kutuya konulup konulmadığını algılar, ürün algılandığında takip sürecini başlatır, kapağın açık kalması durumunda uyarı verir ve sıcaklık ya da takip süresi riskli seviyeye ulaştığında kullanıcıya alarm üretir.

Bu yönüyle FreshGuard; sensörlerden veri alan, bu verileri Arduino üzerinde işleyen, LCD ekran üzerinden kullanıcıya bilgi veren ve LED/buzzer ile geri bildirim sağlayan bütünleşik bir fiziksel programlama projesidir.

---

## 🎯 Projenin Amacı

Bu projenin amacı, Arduino platformu kullanılarak gerçek dünyadan veri alan, bu verileri değerlendiren ve kullanıcıya anlık geri bildirim sağlayan işlevsel bir akıllı gıda takip sistemi geliştirmektir.

FreshGuard ile hedeflenenler:

* Gıda ürünlerinin saklama koşullarını takip etmek
* Ortam sıcaklığı ve nem değerlerini ölçmek
* Kapağın açık veya kapalı olduğunu algılamak
* Kutuda ürün olup olmadığını load cell ile belirlemek
* Ürün algılandığında takip sürecini otomatik başlatmak
* Takip süresini LCD ekranda göstermek
* Demo gün sistemi ile zaman geçişini simüle etmek
* Sıcaklık veya süreye bağlı risk durumlarını belirlemek
* Kullanıcıya LCD ekran üzerinden anlaşılır durum mesajları göstermek
* LED ve buzzer ile görsel/sesli geri bildirim vermek
* Gıda bozulma riskine yönelik düşük maliyetli bir prototip oluşturmak

---

## 🧩 Temel Özellikler

* Sıcaklık ölçümü
* Nem ölçümü
* Ürün var/yok algılama
* Kapak açık/kapalı kontrolü
* LCD ekran üzerinden kullanıcı bilgilendirmesi
* Kırmızı, sarı ve yeşil LED ile durum gösterimi
* Buzzer ile sesli uyarı
* Ürün algılandığında otomatik takip başlatma
* Ürün çıkarıldığında takip bekleme moduna geçme
* Takip süresi gösterimi
* Demo gün sistemi
* Normal, dikkat ve riskli durum değerlendirmesi
* Sıcaklık 26°C üstüne çıktığında alarm verme
* Kapak açıkken kullanıcıyı uyarma
* Gerçek zamanlı sensör okuma
* Arduino tabanlı çoklu modül entegrasyonu

---

## 🛠️ Kullanılan Donanımlar

| Donanım         | Kullanım Amacı                                                   |
| --------------- | ---------------------------------------------------------------- |
| Arduino Uno     | Sistemin ana kontrol kartı                                       |
| DHT11 Sensörü   | Sıcaklık ve nem ölçümü                                           |
| HX711 Modülü    | Load cell verisini Arduino’ya aktarma                            |
| Load Cell       | Kutuda ürün olup olmadığını algılama                             |
| Reed Switch     | Kapak açık/kapalı durumunu algılama                              |
| 16x2 LCD Ekran  | Kullanıcıya sistem durumlarını gösterme                          |
| Kırmızı LED     | Riskli sıcaklık veya riskli takip durumu uyarısı                 |
| Sarı LED        | Ürün algılandığını gösterme                                      |
| Yeşil LED       | Kapak kapalı olduğunda sistemin izlemeye hazır olduğunu gösterme |
| Buzzer          | Kapak açık ve riskli durumlarda sesli uyarı verme                |
| Jumper Kablolar | Modül bağlantılarını sağlama                                     |
| Ahşap/MDF Kutu  | Projenin fiziksel gövdesi                                        |

---

## ⚙️ Kullanılan Kütüphaneler

Projede aşağıdaki Arduino kütüphaneleri kullanılmıştır:

| Kütüphane           | Kullanım Amacı                                 |
| ------------------- | ---------------------------------------------- |
| LiquidCrystal_I2C.h | I2C bağlantılı 16x2 LCD ekranı kontrol etme    |
| HX711.h             | HX711 modülünden load cell verisi okuma        |
| DHT.h               | DHT11 sensöründen sıcaklık ve nem verisi okuma |

---

## 📁 Proje Dosya Yapısı

FreshGuard-Akilli-Gida-Bozulma-Riski-Takip-Sistemi/

│

├── FreshGuard.ino

│   └── Arduino IDE üzerinde çalışan final proje kodu

│

├── README.md

│   └── Proje açıklaması, kullanılan donanımlar, çalışma mantığı ve test bilgileri

---

## 🔌 Final Pin Bağlantıları

| Arduino Pin | Bağlantı                  |
| ----------- | ------------------------- |
| D2          | HX711 DOUT                |
| D3          | HX711 SCK                 |
| D4          | DHT11 veri pini           |
| D9          | Yeşil LED                 |
| D10         | Kırmızı LED               |
| D11         | Sarı LED                  |
| D12         | Buzzer                    |
| A0          | Reed switch kapak sensörü |
| A4          | LCD SDA                   |
| A5          | LCD SCL                   |

⚠️ Tüm modüllerin GND bağlantıları ortak yapılmıştır.

⚠️ LCD ekran I2C modül ile kullanılmıştır. Bu nedenle LCD için çok sayıda dijital pin kullanılmamış, yalnızca SDA ve SCL hatları üzerinden haberleşme sağlanmıştır.

---

## ▶️ Çalışma Mantığı

FreshGuard, sistem durumlarına göre çalışan bir akış yapısına sahiptir.

### 1. Başlangıç Durumu

Sistem açıldığında LCD ekranda FreshGuard başlangıç ekranı görüntülenir.

Açılışta LCD ekranda:

FreshGuard
Takip Sistemi

mesajı gösterilir.

Bu ekran yaklaşık 3 saniye görüntülenir. Daha sonra sistem sensörlerden veri okumaya ve takip moduna geçmeye başlar.

---

### 2. Kapak Kontrol Senaryosu

Sistemde reed switch kullanılarak kapağın açık veya kapalı olduğu kontrol edilir.

Kapak kapalıysa:

* Yeşil LED yanar
* Sistem izlemeye hazır hale gelir
* LCD ekranda sistem hazır veya takip bilgileri gösterilir

Kapak açıksa:

* Yeşil LED söner
* LCD ekranda kapak uyarısı görünür
* Buzzer kısa aralıklarla uyarı verir
* Sistem kullanıcıdan kapağı kapatmasını bekler

Kapak açıkken LCD ekranda:

KAPAK ACIK!
Lutfen Kapat

mesajı gösterilir.

---

### 3. Ürün Algılama Senaryosu

Kutunun içerisine ürün yerleştirildiğinde load cell ve HX711 modülü üzerinden ham sensör verisi okunur.

Kodda belirlenen eşik değeri ile sensörden gelen değer karşılaştırılır.

Eğer sensör değeri ürün var olarak yorumlanırsa:

* Sarı LED yanar
* Ürün algılandı mesajı gösterilir
* Takip süresi başlatılır
* Sistem ürün takip moduna geçer

LCD ekranda:

Urun Algilandi
Takip Basladi

mesajı görüntülenir.

Ürün kutudan çıkarıldığında:

* Sarı LED söner
* Takip aktif durumdan çıkar
* LCD ekranda ürün yok mesajı görünür

LCD ekranda:

Urun Yok
Takip Bekliyor

mesajı görüntülenir.

---

### 4. Sıcaklık ve Nem Takibi

DHT11 sensörü ortam sıcaklığı ve nem değerlerini ölçer.

Sistem bu değerleri LCD ekranda gösterir.

Örnek LCD ekran çıktısı:

Sic: 24.00C
Nem: 42.00%

Sıcaklık değeri 26°C üstüne çıktığında sistem bunu riskli sıcaklık durumu olarak kabul eder.

Bu durumda:

* Kırmızı LED yanar
* Buzzer uyarı verir
* LCD ekranda riskli durum bilgisi gösterilir

---

### 5. Takip Süresi Senaryosu

Ürün algılandığında sistem takip başlangıç zamanını millis() fonksiyonu ile kaydeder.

Ürün kutuda kaldığı sürece geçen süre hesaplanır.

LCD ekranda:

Sure: 20 sn
Takip Ediliyor

şeklinde takip süresi görüntülenir.

Bu özellik sayesinde ürünün kutuda ne kadar süredir takip edildiği kullanıcıya gösterilir.

---

### 6. Demo Gün Sistemi

Projenin sunum ve test aşamasında gerçek günler beklenemeyeceği için demo gün sistemi oluşturulmuştur.

Kodda geçen süre saniye cinsinden hesaplanır ve belirli aralıklarla demo gün değerine dönüştürülür.

Sistemde:

* Demo gün 0 veya 1 ise durum normal kabul edilir
* Demo gün 2 ise durum dikkat olarak gösterilir
* Demo gün 3 ve üzeri ise durum riskli kabul edilir

LCD ekranda:

Demo Gun: 2
Durum: DIKKAT

veya

Demo Gun: 3
Durum: RISKLI

mesajları gösterilebilir.

Bu sayede proje, gıdanın zaman içinde bozulma riskinin artmasını kısa sürede gösterebilecek şekilde simüle edilmiştir.

---

## 🚨 Hata Senaryoları

Sistem yalnızca normal çalışma durumlarını değil, uyarı gerektiren durumları da algılar.

| Hata Durumu                          | Sistem Tepkisi                                          |
| ------------------------------------ | ------------------------------------------------------- |
| Kapak açık kaldı                     | LCD uyarısı verir, buzzer kısa aralıklarla öter         |
| Ürün algılanmadı                     | Sarı LED yanmaz, takip başlatılmaz                      |
| Ürün çıkarıldı                       | Sarı LED söner, takip bekleme moduna geçilir            |
| Sıcaklık 26°C üstüne çıktı           | Kırmızı LED yanar, buzzer uyarı verir                   |
| Demo gün 2 oldu                      | Durum dikkat olarak gösterilir                          |
| Demo gün 3 ve üzeri oldu             | Durum riskli olarak gösterilir                          |
| HX711 hazır değil                    | Ürün verisi okunamaz, sistem yeniden okumaya devam eder |
| Kapak açıkken işlem yapılmak istenir | LCD kapak uyarısı verir                                 |

---

## ⚖️ Load Cell Eşik Değerleri

Final testlerde load cell gram ölçümü yerine ürün var/yok algılama amacıyla kullanılmıştır.

Başlangıçta sensör gram cinsinden net değer üretmediği için ürün ağırlığını doğrudan 300 gram gibi göstermek yerine, sensörün ham değerine göre ürün algılama sistemi tercih edilmiştir.

Bu karar sayesinde sistem daha kararlı ve sunum için daha anlaşılır hale getirilmiştir.

Kodda kullanılan eşik değeri:

* Eşik değer: -340000
* Sensör değeri bu eşikten büyükse: Ürün var
* Sensör değeri bu eşikten küçükse: Ürün yok

Final karar mantığı:

reading > -340000  -> Ürün var
reading <= -340000 -> Ürün yok

Bu yöntemle load cell sistemi, hassas gram ölçümü yapmak yerine ürünün kutuda olup olmadığını belirleyen bir sensör olarak kullanılmıştır.

---

## 🖥️ LCD Ekran Arayüzü

LCD ekranda kullanıcıya kısa ve anlaşılır durum mesajları gösterilir.

Sistemde kullanılan temel LCD mesajları:

FreshGuard
Takip Sistemi

Sistem Hazir
Takip Bekliyor

KAPAK ACIK!
Lutfen Kapat

Urun Algilandi
Takip Basladi

Urun Yok
Takip Bekliyor

Sic: ... C
Nem: ... %

Sure: ... sn
Takip Ediliyor

Demo Gun: ...
Durum: NORMAL

Demo Gun: ...
Durum: DIKKAT

Demo Gun: ...
Durum: RISKLI

LCD ekran 16x2 karakter yapısında olduğu için mesajlar kısa tutulmuştur. Böylece kullanıcı sistemin durumunu hızlı şekilde anlayabilmektedir.

---

## 📝 Serial Monitor Kayıtları

Bu projenin final sürümünde kullanıcı bilgilendirmesi ağırlıklı olarak LCD ekran üzerinden yapılmaktadır.

Serial Monitor ise geliştirme ve test aşamalarında sensörlerin çalışıp çalışmadığını kontrol etmek amacıyla kullanılabilir.

Test aşamasında Serial Monitor üzerinden kontrol edilebilecek bilgiler:

* DHT11 sıcaklık verisi
* DHT11 nem verisi
* HX711 ham sensör değeri
* Ürün algılama durumu
* Kapak durumu
* Sistem başlangıç kontrolü

Final kullanıcı deneyiminde asıl çıktı birimi LCD ekran, LED sistemi ve buzzer olarak tasarlanmıştır.

---

## 🧠 Sistem Mimarisi

FreshGuard çoklu sensör entegrasyonu ile çalışır.

DHT11 Sıcaklık/Nem Sensörü
↓
Arduino Uno
↓
Sıcaklık ve Nem Değerlendirmesi
↓
LCD Ekran + Kırmızı LED + Buzzer

Load Cell + HX711
↓
Arduino Uno
↓
Ürün Var/Yok Kontrolü
↓
LCD Ekran + Sarı LED

Reed Switch
↓
Arduino Uno
↓
Kapak Açık/Kapalı Kontrolü
↓
LCD Ekran + Yeşil LED + Buzzer

Sistem; giriş birimleri, işlem birimi ve çıkış birimleri olarak üç ana bölümde düşünülebilir.

### Giriş Birimleri

* DHT11 sıcaklık ve nem sensörü
* Load cell
* HX711 modülü
* Reed switch kapak sensörü

### İşlem Birimi

* Arduino Uno

### Çıkış Birimleri

* 16x2 LCD ekran
* Kırmızı LED
* Sarı LED
* Yeşil LED
* Buzzer

---

## 🧪 Test Edilen Senaryolar

Final aşamada aşağıdaki senaryolar test edilmiştir:

| Test                             | Sonuç    |
| -------------------------------- | -------- |
| LCD ekran başlangıç testi        | Başarılı |
| LCD mesaj geçişleri testi        | Başarılı |
| DHT11 sıcaklık testi             | Başarılı |
| DHT11 nem testi                  | Başarılı |
| HX711 veri okuma testi           | Başarılı |
| Load cell ürün algılama testi    | Başarılı |
| Ürün var/yok testi               | Başarılı |
| Sarı LED ürün algılama testi     | Başarılı |
| Reed switch kapak testi          | Başarılı |
| Yeşil LED kapak testi            | Başarılı |
| Kapak açık uyarısı testi         | Başarılı |
| Buzzer kapak uyarısı testi       | Başarılı |
| Kırmızı LED risk testi           | Başarılı |
| Buzzer sıcaklık alarm testi      | Başarılı |
| Takip süresi testi               | Başarılı |
| Demo gün sistemi testi           | Başarılı |
| Normal/dikkat/riskli durum testi | Başarılı |

---

## 🏗️ Fiziksel Tasarım

Proje ahşap/MDF bir kutu üzerine kurulmuştur.

Ön yüzde LCD ekran ve LED göstergeleri bulunmaktadır. LCD ekran sistemin anlık durumunu kullanıcıya gösterir. LED’ler ise ürün durumu, kapak durumu ve risk durumunu hızlı şekilde göstermek için kullanılmıştır.

Kutunun iç bölümünde Arduino Uno, bağlantı kabloları, sensörler ve HX711 modülü yer almaktadır. Load cell sistemi ürün algılama amacıyla kutu içinde konumlandırılmıştır.

Kapak kontrolü için reed switch kullanılmıştır. Kapak kapalı olduğunda sistem bunu algılar ve yeşil LED aktif olur. Kapak açık kaldığında ise LCD ekran ve buzzer ile kullanıcı uyarılır.

Bu fiziksel tasarım sayesinde sistem yalnızca yazılım olarak değil, gerçek bir kutu prototipi üzerinde çalışan donanımsal bir ürün haline getirilmiştir.

---

## ⚙️ Kurulum ve Kullanım

Bu proje fiziksel donanım üzerinde çalışmaktadır. Kodun çalıştırılması için Arduino IDE kullanılmalıdır.

### 1. Arduino IDE ile Açma

Arduino IDE üzerinden aşağıdaki .ino dosyası açılır:

FreshGuard.ino

### 2. Gerekli Kütüphaneleri Kurma

Arduino IDE Library Manager üzerinden aşağıdaki kütüphaneler kurulmalıdır:

* LiquidCrystal_I2C
* HX711
* DHT sensor library

### 3. Kart Seçimi

Arduino IDE içinde:

Tools > Board > Arduino Uno

seçilir.

### 4. Port Seçimi

Arduino bağlıyken uygun COM portu seçilir.

Tools > Port

### 5. Kodu Yükleme

Arduino IDE üzerinden Upload butonuna basılarak kod Arduino Uno’ya yüklenir.

### 6. Sistemi Çalıştırma

Kod yüklendikten sonra sistem otomatik olarak çalışmaya başlar.

Kullanım sırası:

1. Sistem açılır.
2. LCD ekranda FreshGuard başlangıç mesajı görünür.
3. Kapak açık ise sistem uyarı verir.
4. Kapak kapatıldığında sistem hazır hale gelir.
5. Kutuya ürün yerleştirilirse ürün algılanır.
6. Takip süresi başlatılır.
7. Sıcaklık ve nem değerleri LCD ekranda gösterilir.
8. Süre ve demo gün bilgisi görüntülenir.
9. Riskli durumda kırmızı LED ve buzzer aktif olur.

---

## 📌 Arduino Konuları ile İlişki

Bu proje BOZ214 Fiziksel Programlama dersi kapsamında birçok Arduino konusunu içermektedir:

* Temel Arduino programlama
* Dijital giriş/çıkış kullanımı
* Sensör okuma
* LED kontrolü
* Buzzer kontrolü
* LCD ekran kullanımı
* I2C haberleşmesi
* DHT11 sensörü kullanımı
* HX711 modülü kullanımı
* Load cell ile veri okuma
* Reed switch ile kapak kontrolü
* millis() fonksiyonu ile süre takibi
* delay() ile zamanlama
* Çoklu modül entegrasyonu
* Durum tabanlı programlama
* Hata ve risk senaryoları oluşturma
* Gerçek zamanlı takip sistemi geliştirme

---

## 🧠 Pair Programming ve Yapay Zeka Asistanı Kullanımı

Bu proje geliştirilirken pair programming yaklaşımı kullanılmıştır. Geliştirme sürecinde öğrenci ve yapay zeka asistanı birlikte çalışmıştır.

Bu süreçte:

* Proje fikri ve sistem akışı planlanmıştır.
* Kullanılacak donanımlar belirlenmiştir.
* OLED ekran yerine 16x2 LCD ekran kullanılmasına karar verilmiştir.
* Tek RGB LED yerine üç ayrı LED kullanılmıştır.
* Kırmızı, sarı ve yeşil LED görevleri belirlenmiştir.
* Load cell’in gram ölçümü yerine ürün var/yok algılaması için kullanılmasına karar verilmiştir.
* Arduino kodu aşama aşama geliştirilmiştir.
* LCD başlangıç ekranı düzenlenmiştir.
* Kapak açık uyarısı eklenmiştir.
* Ürün algılandı ve takip başladı ekranları oluşturulmuştur.
* Sıcaklık ve nem ekranı düzenlenmiştir.
* Takip süresi özelliği eklenmiştir.
* Demo gün sistemi oluşturulmuştur.
* Normal, dikkat ve riskli durum ekranları geliştirilmiştir.
* Sıcaklık eşiği test edilerek 26°C olarak belirlenmiştir.
* LED ve buzzer davranışları test edilmiştir.
* Final proje raporu ve README hazırlıkları yapılmıştır.

---

## 📄 Lisans ve Telif Hakkı

Bu projede Tüm Haklar Saklıdır.

Kaynak kodları yalnızca inceleme ve eğitim amaçlı erişime sahiptir. İzin alınmadan ticari amaçla kullanılması, kopyalanması veya dağıtılması yasaktır.

Copyright © 2026 Beren Şahbaz

Not: Bu proje Ankara Üniversitesi BOZ214 Fiziksel Programlama dersi kapsamında geliştirilmiştir.
