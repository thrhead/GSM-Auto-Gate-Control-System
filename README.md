# GSM Otomatik Garaj Kapısı Kontrol Sistemi

Bu proje, ESP32 mikrodenetleyici ve SIM800L GSM modülü kullanılarak geliştirilmiş, güvenli ve uzaktan yönetilebilir bir garaj kapısı kontrol sistemidir. Sisteme tanımlı yetkili numaralar, cihazı arayarak garaj kapısını **ücretsiz** bir şekilde (arama reddedilerek) açabilirler.

## 🌟 Özellikler

*   **📞 Arama ile Kontrol:** Yetkili numaradan gelen aramayı algılar, meşgule atar ve kapıyı tetikler. Ücret yansımaz.
*   **🛡️ Güvenli Erişim (Beyaz Liste):** Sadece cihazın hafızasında kayıtlı numaralar işlem yapabilir. Yabancı numaralar reddedilir.
*   **📲 SMS ile Uzaktan Yönetim:** Yönetici numaraları, SMS komutları göndererek kullanıcı ekleyebilir, silebilir veya sistem durumunu sorgulayabilir.
*   **🔔 Başlangıç Bildirimi:** Sistem elektrik kesintisi vb. durumlardan sonra yeniden başladığında yöneticilere SMS ile bilgi verir.
*   **💾 Kalıcı Hafıza:** Yetkili numaralar ESP32'nin kalıcı hafızasında (Preferences) saklanır, elektrik kesintisinde silinmez.
*   **⚡ Donanım Koruması:** SIM800L modülü kilitlenirse otomatik olarak resetlenir (Self-healing).

## 🛠️ Donanım Gereksinimleri

*   **Mikrodenetleyici:** ESP32 Development Board (örn. ESP32-WROOM-32)
*   **GSM Modülü:** SIM800L (Mikro SIM kart ile çalışır)
*   **Röle:** 5V Röle Modülü (Garaj motorunu tetiklemek için)
*   **Güç Kaynağı:**
    *   ESP32 için USB veya 5V.
    *   SIM800L için **kaliteli** bir güç kaynağı (Anlık 2A akım çekebilir, harici bir DC-DC dönüştürücü önerilir).

### Bağlantı Şeması (Varsayılan Pinler)

| SIM800L Pin | ESP32 Pin | Açıklama |
| :--- | :--- | :--- |
| RX | GPIO 17 | TX2 |
| TX | GPIO 16 | RX2 |
| RST | GPIO 5 | Reset Kontrolü |
| VCC | Harici 4V-4.2V | (ESP32 5V pininden beslemeyin!) |
| GND | GND | (ESP32 GND ile birleştirilmeli) |

| Röle Modülü | ESP32 Pin |
| :--- | :--- |
| IN | GPIO 23 |
| VCC | 5V |
| GND | GND |

## 🚀 Kurulum

1.  Proje **PlatformIO** (VS Code eklentisi) kullanılarak geliştirilmiştir.
2.  Depoyu klonlayın:
    ```bash
    git clone https://github.com/thrhead/GSM-Auto-Gate-Control-System.git
    ```
3.  VS Code ile klasörü açın.
4.  Gerekli kütüphaneler (`TinyGSM`) `platformio.ini` dosyasında tanımlıdır, otomatik yüklenecektir.
5.  `src/main.cpp` dosyasını açın.
6.  İlk kurulum için kendi numaranızı yönetici olarak eklemek isterseniz `setup()` fonksiyonu içine şu satırı geçici olarak ekleyin:
    ```cpp
    storageService.addAdmin("+905XXXXXXXXX");
    ```
7.  Kodu ESP32'ye yükleyin.

## 📱 SMS Komutları

Sadece tanımlı **Yönetici** numaraları bu komutları kullanabilir.

| Komut | Örnek | Açıklama |
| :--- | :--- | :--- |
| **EKLE** | `EKLE:+905551234567` | Belirtilen numarayı beyaz listeye ekler. |
| **SIL** | `SIL:+905551234567` | Belirtilen numarayı listeden siler. |
| **DURUM** | `DURUM` | Sistem durumunu, sinyal kalitesini ve kayıtlı kullanıcı sayısını döner. |

## 📂 Proje Yapısı

*   `src/` - Kaynak kodlar (`main.cpp`, servis sınıfları)
*   `include/` - Başlık dosyaları (`.h`)
*   `test/` - Birim testleri
*   `conductor/` - Proje planlama ve dokümantasyon dosyaları (Conductor framework)

## 🤝 Katkıda Bulunma

1.  Bu depoyu Fork'layın.
2.  Yeni bir özellik dalı (branch) oluşturun (`git checkout -b feature/yeni-ozellik`).
3.  Değişikliklerinizi yapın ve commit'leyin.
4.  Dalınızı Push'layın (`git push origin feature/yeni-ozellik`).
5.  Bir Pull Request (PR) oluşturun.

---
*Geliştirme Süreci Conductor Framework ile yönetilmiştir.*
