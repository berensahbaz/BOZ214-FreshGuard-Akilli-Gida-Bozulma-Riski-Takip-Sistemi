# FreshGuard – Akıllı Gıda Bozulma Riski Takip Sistemi

Ders: BOZ214 – Fiziksel Programlama  
Proje Türü: Final Projesi  
Geliştirici: Beren Şahbaz  
Üniversite: Ankara Üniversitesi  
Durum: Tamamlandı (v1.0)

---

# 📖 Proje Hakkında

FreshGuard, Arduino Uno tabanlı akıllı bir gıda takip ve bozulma riski analiz sistemidir. Bu proje; sıcaklık, nem, kapak durumu ve ürün algılama verilerini kullanarak kullanıcıyı olası bozulma risklerine karşı uyarmak amacıyla geliştirilmiştir.

Sistem; DHT11 sıcaklık/nem sensörü, HX711 load cell modülü, buzzer, LED sistemi, reed switch kapak sensörü ve 16x2 LCD ekran kullanarak fiziksel dünyadan veri alır ve kullanıcıya anlık geri bildirim verir.

FreshGuard yalnızca sıcaklık ölçmekle kalmaz; ürünün kutu içerisinde bulunup bulunmadığını da kontrol eder. Bu sayede sistem hem çevresel koşulları hem de ürün durumunu birlikte değerlendirebilir.

Proje fiziksel programlama, sensör entegrasyonu, kullanıcı geri bildirimi ve gerçek zamanlı durum kontrolü konularını bir araya getiren bütünleşik bir Arduino projesidir.

---

# 🎯 Projenin Amacı

Bu projenin amacı Arduino platformu kullanılarak gerçek dünyadan veri alan, kullanıcıyı olası gıda bozulma risklerine karşı uyaran ve fiziksel ortamı akıllı şekilde takip eden işlevsel bir sistem geliştirmektir.

FreshGuard ile hedeflenenler:

- Sıcaklık ve nem değerlerinin takip edilmesi
- Ürün var/yok durumunun algılanması
- Kapak açık/kapalı bilgisinin kontrol edilmesi
- Kullanıcıya LCD ekran üzerinden durum mesajları verilmesi
- LED sistemi ile görsel geri bildirim sağlanması
- Buzzer ile sesli uyarı verilmesi
- Gıda bozulma riskinin erken tespit edilmesi
- Fiziksel programlama bileşenlerinin birlikte çalıştırılması

---

# 🧩 Temel Özellikler

- Sıcaklık ve nem ölçümü
- Ürün algılama sistemi
- Kapak açık/kapalı kontrolü
- 16x2 LCD ekran bilgilendirmesi
- Sesli uyarı sistemi
- Çoklu LED durum sistemi
- Gerçek zamanlı sensör kontrolü
- Akıllı durum analizi
- Gıda bozulma riski uyarısı
- Fiziksel kutu tasarımı
- Arduino tabanlı gömülü sistem kontrolü

---

# 🛠 Kullanılan Donanımlar

| Donanım | Kullanım Amacı |
|---|---|
| Arduino Uno | Sistemin ana kontrol kartı |
| DHT11 Sensörü | Sıcaklık ve nem ölçümü |
| HX711 Modülü | Load cell veri okuma |
| Load Cell | Ürün algılama |
| 16x2 LCD Ekran | Kullanıcı bilgilendirme |
| Reed Switch | Kapak açık/kapalı algılama |
| Buzzer | Sesli uyarı |
| Yeşil LED | Normal durum bildirimi |
| Sarı LED | Ürün algılama bildirimi |
| Kırmızı LED | Risk/uyarı bildirimi |
| Jumper Kablolar | Devre bağlantıları |
| Ahşap Kutu | Projenin fiziksel gövdesi |

---

# ⚙ Kullanılan Kütüphaneler

Projede aşağıdaki Arduino kütüphaneleri kullanılmıştır:

| Kütüphane | Kullanım Amacı |
|---|---|
| LiquidCrystal_I2C.h | LCD ekran kontrolü |
| HX711.h | Load cell veri okuma |
| DHT.h | DHT11 sıcaklık/nem sensörü |

---

# 📁 Proje Dosya Yapısı

```txt
BOZ214-FreshGuard-Akilli-Gida-Bozulma-Riski-Takip-Sistemi/

│
├── FreshGuard.ino
│     └── Arduino IDE üzerinde çalışan final proje kodu
│
└── README.md
      └── Proje açıklaması, sistem yapısı ve kullanım bilgileri
🔌 Final Pin Bağlantıları
Arduino Pin	Bağlantı
D2	HX711 DOUT
D3	HX711 SCK
D4	DHT11 sensörü
D9	Yeşil LED
D10	Kırmızı LED
D11	Sarı LED
D12	Buzzer
A0	Reed switch
I2C	16x2 LCD ekran

⚠️ LCD ekran I2C bağlantısı ile çalışmaktadır.
⚠️ Tüm modüllerin GND bağlantıları ortak yapılmıştır.

▶️ Çalışma Mantığı

FreshGuard sistem durumlarına göre çalışan bir akış yapısına sahiptir.

1. Bekleme Durumu

Sistem açıldığında LCD ekranda açılış mesajı gösterilir.

İşlem sırasında:

FreshGuard açılış ekranı görünür.
Sensörler aktif hale gelir.
Sistem sıcaklık ve nem verilerini okumaya başlar.
Ürün durumu kontrol edilir.
Sistem sürekli takip modunda çalışır.
2. Ürün Algılama Senaryosu

Kutunun içerisine ürün yerleştirildiğinde sistem ürün algılar.

İşlem sırası:

Load cell ağırlık değişimini algılar.
Sistem ürün bulunduğunu doğrular.
Sarı LED yanar.
LCD ekranda “Ürün Algılandı” mesajı görünür.
Takip sistemi aktif hale gelir.
3. Kapak Açık Senaryosu

Kapak açıldığında sistem kullanıcıyı uyarır.

İşlem sırası:

Reed switch kapak durumunu algılar.
Sistem kapağın açıldığını belirler.
LCD ekranda “Kapak Açık” mesajı görünür.
Kullanıcıya kısa sesli uyarı verilir.
Yeşil LED durum bildirimi sağlar.
4. Risk Senaryosu

Sıcaklık kritik seviyeye ulaştığında sistem alarm verir.

İşlem sırası:

DHT11 sıcaklığı ölçer.
Sistem sıcaklığın eşik değeri geçtiğini algılar.
Kırmızı LED yanar.
Buzzer alarm verir.
LCD ekranda uyarı mesajı görünür.
🚨 Hata Senaryoları

Sistem yalnızca normal durumları değil, hatalı durumları da algılar.

Hata Durumu	Sistem Tepkisi
Yüksek sıcaklık	Kırmızı LED + buzzer alarmı
Kapak açık kaldı	LCD uyarısı
Ürün yok	Sistem takip başlatmaz
Sensör hatası	Veri okunamazsa uyarı verir
Ani ağırlık değişimi	Sistem tekrar kontrol yapar
⚖️ Load Cell Eşik Değerleri

Final testlerinde load cell için aşağıdaki mantık kullanılmıştır:

Durum	Sistem Kararı
Düşük değer	Ürün yok
Orta değer	Ürün var
Ani büyük değer	Hata kontrolü

Final eşikleri:

Belirlenen eşik altı  -> Ürün yok
Belirlenen eşik üstü -> Ürün var
🖥 LCD Ekran Arayüzü

16x2 LCD ekranda kullanıcıya kısa durum mesajları gösterilir.

Örnek LCD mesajları:

FreshGuard
Akıllı Gıda
Sicaklik:
Nem:
Urun Algilandi
Takip Basladi
Kapak Acik
Lutfen Kapat
Risk Algilandi
Sistem Aktif
🧠 Sistem Mimarisi
DHT11 + Load Cell + Reed Switch
                ↓
           Arduino Uno
                ↓
      Sensör Veri Analizi
                ↓
        Risk Kontrol Sistemi
                ↓
 LCD + LED + Buzzer Bildirimi

Sistem; giriş birimleri, işlem birimi ve çıkış birimleri olarak üç ana bölümde düşünülebilir.

Giriş Birimleri
DHT11 sensörü
Load cell
Reed switch
İşlem Birimi
Arduino Uno
Çıkış Birimleri
LCD ekran
LED sistemi
Buzzer
🧪 Test Edilen Senaryolar

Final aşamada aşağıdaki senaryolar test edilmiştir:

Test	Sonuç
LCD ekran testi	Başarılı
DHT11 sensör testi	Başarılı
Load cell testi	Başarılı
Reed switch testi	Başarılı
Buzzer testi	Başarılı
LED testi	Başarılı
Ürün algılama testi	Başarılı
Kapak kontrol testi	Başarılı
Risk alarm testi	Başarılı
🏗 Fiziksel Tasarım

Proje ahşap bir kutu üzerine kurulmuştur.

Ön yüzde LCD ekran bulunur.
LED ve buzzer ön panele yerleştirilmiştir.
Kapak sistemi reed switch ile kontrol edilir.
İç bölümde Arduino Uno ve sensörler bulunur.
Ürün algılama alanında load cell sistemi kullanılmıştır.
Sensör kablolamaları kutu içerisine gizlenmiştir.
⚙ Kurulum ve Kullanım

Bu proje fiziksel donanım üzerinde çalışmaktadır. Kodun çalıştırılması için Arduino IDE kullanılmalıdır.

1. Arduino IDE ile Açma

Arduino IDE üzerinden aşağıdaki .ino dosyası açılır:

proje_v5.ino
2. Gerekli Kütüphaneleri Kurma

Arduino IDE Library Manager üzerinden aşağıdaki kütüphaneler kurulmalıdır:

LiquidCrystal_I2C
HX711
DHT sensor library
3. Kart Seçimi

Arduino IDE içerisinde:

Tools > Board > Arduino Uno

seçilir.

4. Port Seçimi

Arduino bağlandıktan sonra uygun COM portu seçilir.

Tools > Port
5. Kodu Yükleme

Arduino IDE üzerinden Upload butonuna basılarak kod Arduino Uno kartına yüklenir.

📌 Arduino Konuları ile İlişki

Bu proje BOZ214 Fiziksel Programlama dersi kapsamında birçok Arduino konusunu içermektedir:

Temel Arduino programlama
Sensör okuma
Dijital giriş/çıkış kullanımı
LCD ekran kontrolü
Buzzer kontrolü
LED kontrolü
Analog veri işleme
Sensör entegrasyonu
Gerçek zamanlı takip sistemi
Fiziksel programlama uygulamaları
🧠 Pair Programming ve Yapay Zeka Asistanı Kullanımı

Bu proje geliştirilirken pair programming yaklaşımı kullanılmıştır. Geliştirme sürecinde öğrenci ve yapay zeka asistanı birlikte çalışmıştır.

Bu süreçte:

Proje fikri geliştirilmiştir.
Sistem akışı planlanmıştır.
Sensör entegrasyonları yapılmıştır.
Arduino kodları geliştirilmiştir.
Modüller test edilmiştir.
LCD arayüzü düzenlenmiştir.
Hata senaryoları oluşturulmuştur.
Fiziksel tasarım planlanmıştır.
Final testleri gerçekleştirilmiştir.
README, rapor ve proje dökümanları hazırlanmıştır.
📄 Lisans ve Telif Hakkı

Bu projede Tüm Haklar Saklıdır.

Kaynak kodları yalnızca eğitim ve proje inceleme amacıyla paylaşılmıştır. İzinsiz ticari kullanım, kopyalama veya dağıtım yasaktır.

Copyright © 2026 Beren Şahbaz

Not: Bu proje Ankara Üniversitesi BOZ214 Fiziksel Programlama dersi kapsamında geliştirilmiştir.
