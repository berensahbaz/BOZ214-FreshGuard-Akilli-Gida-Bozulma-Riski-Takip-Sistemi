BOZ214-FreshGuard-Akilli-Gida-Bozulma-Riski-Takip-Sistemi

Arduino tabanlı akıllı gıda bozulma riski takip ve uyarı sistemi

📘 Proje Hakkında

FreshGuard, sıcaklık, nem, kapak durumu ve ürün takibi yapabilen Arduino tabanlı akıllı bir gıda takip sistemidir. Sistem; gıda ürünlerinin uygun koşullarda saklanıp saklanmadığını kontrol etmek ve oluşabilecek bozulma risklerini kullanıcıya bildirmek amacıyla geliştirilmiştir.

Projede DHT11 sıcaklık ve nem sensörü, HX711 yük hücresi modülü, reed switch kapak sensörü, LCD ekran, buzzer ve LED uyarı sistemi birlikte kullanılmıştır.

FreshGuard sistemi yalnızca sıcaklık ölçümü yapmaz. Aynı zamanda kutu kapağını kontrol eder, ürün algılaması yapar ve riskli durumlarda kullanıcıya sesli ve görsel uyarı verir.

Bu proje BOZ214 Fiziksel Programlama dersi kapsamında geliştirilmiştir.

🎯 Projenin Amacı

Bu projenin amacı; gıda ürünlerinin uzun süre uygun olmayan sıcaklıkta beklemesi sonucu oluşabilecek bozulma risklerini takip etmek ve kullanıcıyı erken aşamada uyarmaktır.

FreshGuard sistemi ile:

Sıcaklık takibi yapılır
Nem takibi yapılır
Kapak kontrolü sağlanır
Ürün algılama işlemi gerçekleştirilir
LCD ekran üzerinden kullanıcı bilgilendirilir
LED ve buzzer ile risk uyarısı verilir
Gerçek zamanlı çalışan düşük maliyetli bir takip sistemi oluşturulur
🧩 Temel Özellikler
Sıcaklık ölçümü
Nem ölçümü
Kapak açık/kapalı kontrolü
Ürün algılama sistemi
LCD ekran bilgilendirmesi
LED durum göstergeleri
Buzzer ile sesli uyarı
Risk analizi sistemi
Takip süresi mantığı
Gerçek zamanlı sensör kontrolü
🛠️ Kullanılan Donanımlar
Donanım	Kullanım Amacı
Arduino Uno	Ana kontrol kartı
DHT11 Sensörü	Sıcaklık ve nem ölçümü
HX711 Modülü	Load cell veri okuma
Load Cell	Ürün algılama
Reed Switch	Kapak kontrolü
16x2 LCD Ekran	Kullanıcı bilgilendirme
Kırmızı LED	Risk uyarısı
Sarı LED	Ürün algılama durumu
Yeşil LED	Kapak durumu
Buzzer	Sesli uyarı sistemi
Jumper Kablolar	Devre bağlantıları
Ahşap Kutu	Fiziksel tasarım
⚙️ Kullanılan Kütüphaneler
Kütüphane	Kullanım Amacı
Wire.h	I2C haberleşmesi
LiquidCrystal_I2C.h	LCD ekran kontrolü
DHT.h	DHT11 işlemleri
HX711.h	Load cell veri okuma
📂 Proje Dosya Yapısı
BOZ214-FreshGuard-Akilli-Gida-Bozulma-Riski-Takip-Sistemi/

├── FreshGuard.ino
├── README.md

🔌 Final Pin Bağlantıları
Arduino Pin	Bağlantı
D2	Reed Switch
D3	Buzzer
D4	Kırmızı LED
D5	Sarı LED
D6	Yeşil LED
D7	DHT11 Veri Pini
A0	HX711 DT
A1	HX711 SCK
SDA	LCD SDA
SCL	LCD SCL

Tüm modüllerin GND bağlantıları ortak yapılmıştır.

▶️ Çalışma Mantığı

FreshGuard sistem açıldığında LCD ekran aktif olur ve başlangıç ekranı görüntülenir. Sistem daha sonra sensörlerden veri okumaya başlar.

DHT11 sensörü ortam sıcaklığı ve nem değerlerini ölçmektedir.

Reed switch sensörü kutu kapağının açık veya kapalı olduğunu kontrol etmektedir.

HX711 modülü ve load cell sistemi kullanılarak ürün algılama işlemi gerçekleştirilmektedir.

Sistem içerisinde ürün algılandığında sarı LED aktif olur ve LCD ekran üzerinde takip başladığı bilgisi görüntülenir.

Kapak açık olduğunda kullanıcı LCD ekran üzerinden uyarılır ve buzzer kısa sesli uyarı verir.

Sıcaklık değeri 26°C üzerine çıktığında sistem risk durumuna geçer. Bu durumda kırmızı LED aktif olur ve buzzer alarm verir.

LCD ekran üzerinde sistem durumuna göre farklı mesajlar gösterilmektedir.

🖥️ LCD Ekran Mesajları

Sistem üzerinde kullanılan bazı LCD ekran mesajları:

FreshGuard Takip Sistemi
Sistem Hazır
Takip Bekleniyor
Ürün Algılandı
Takip Başladı
Kapak Açık
Lütfen Kapat
Risk Algılandı
Sıcaklık Yüksek
Demo Gün 1
Durum Dikkat
Demo Gün 3
Durum Riskli
🚨 Hata Senaryoları
Durum	Sistem Tepkisi
Kapak açık kaldı	LCD uyarısı + buzzer
Yüksek sıcaklık	Kırmızı LED + alarm
Sensör veri hatası	Sistem yeniden veri okumayı dener
Ürün algılanmadı	Takip sistemi başlamaz
🌡️ Risk Analizi
Durum	Sistem Kararı
26°C altı	Normal durum
26°C ve üzeri	Risk durumu
Kapak açık	Kullanıcı uyarısı
Ürün algılandı	Takip başlatılır
🧠 Sistem Mimarisi
DHT11 + Reed Switch + HX711
                ↓
           Arduino Uno
                ↓
        Risk Analizi Sistemi
                ↓
 LCD + LED + Buzzer Uyarıları
🧪 Test Edilen Senaryolar
Test	Sonuç
LCD ekran testi	Başarılı
DHT11 sıcaklık testi	Başarılı
DHT11 nem testi	Başarılı
Reed switch testi	Başarılı
LED kontrol testi	Başarılı
Buzzer testi	Başarılı
HX711 veri testi	Başarılı
Ürün algılama testi	Başarılı
Risk alarm testi	Başarılı
🪵 Fiziksel Tasarım

Proje ahşap kutu üzerine kurulmuştur.

LCD ekran ön panelde bulunmaktadır
LED göstergeleri ön bölümde yer almaktadır
Reed switch kapak bölümüne yerleştirilmiştir
Arduino ve sensör bağlantıları kutu içerisine yerleştirilmiştir
Sistem taşınabilir yapıdadır
Kablo düzeni kutu içerisinde gizlenmiştir
⚙️ Kurulum ve Kullanım

Arduino IDE üzerinden proje_v5.ino dosyası açılır.

Gerekli kütüphaneler Arduino IDE Library Manager üzerinden kurulmalıdır:

LiquidCrystal_I2C
DHT sensor library
HX711

Arduino IDE içerisinde:

Tools > Board > Arduino Uno

seçilir.

Daha sonra uygun COM port seçilir:

Tools > Port

Kod Arduino Uno kartına yüklenir ve sistem çalıştırılır.

📌 Arduino Konuları ile İlişki

Bu proje aşağıdaki fiziksel programlama konularını içermektedir:

Sensör kullanımı
LCD ekran kontrolü
LED kontrolü
Buzzer kontrolü
Dijital giriş/çıkış işlemleri
Sensör entegrasyonu
Gerçek zamanlı takip sistemi
Risk analizi mantığı
Fiziksel programlama uygulamaları
🧠 Pair Programming ve Yapay Zeka Asistanı Kullanımı

Bu proje geliştirilirken pair programming yaklaşımı kullanılmıştır. Geliştirme sürecinde öğrenci ve yapay zeka asistanı birlikte çalışmıştır.

Bu süreçte:

Proje fikri geliştirilmiştir
Sistem akışı planlanmıştır
Sensör entegrasyonları yapılmıştır
Arduino kodları geliştirilmiştir
Modüller test edilmiştir
LCD arayüzü düzenlenmiştir
Risk senaryoları oluşturulmuştur
Fiziksel tasarım planlanmıştır
Final testleri gerçekleştirilmiştir
README ve proje dokümanları hazırlanmıştır
📄 Lisans ve Telif Hakkı

Bu projede tüm haklar saklıdır.

Kaynak kodlarının izinsiz şekilde ticari amaçla kullanılması, dağıtılması veya kopyalanması yasaktır.

Copyright © 2026 Beren Şahbaz

 Not:BOZ214 Ankara Üniversitesi Fiziksel Programlama Dersi Final Projesidir.
