# Teknik Şartname - Garaj Kontrol MVP

## Genel Bakış
Bu aşama, Otomatik Garaj Kapısı Sisteminin temel işlevselliğini gerçekleştirir. Sistem, gelen aramaları algılamak, arayanı beyaz listeye göre doğrulamak ve garaj kapısını açmak için bir röleyi tetiklemek üzere SIM800L GSM modülü ile arayüz oluşturan bir ESP32 kullanacaktır.

## Fonksiyonel Gereksinimler
- **Arama Algılama:** Gelen aramalar için SIM800L modülünü izleme.
- **Otomatik Reddetme (Auto-Hangup):** Ücret yansımaması için gelen aramaları hemen reddetme (meşgule atma).
- **Yetkilendirme:** Arayan kimliğini (Caller ID), kalıcı hafızada (Preferences) saklanan beyaz liste ile kontrol etme.
- **Röle Kontrolü:** Garaj motorunu tetiklemek için bir GPIO pinine 1 saniyelik darbe (pulse) gönderme.
- **Yönetici (Admin) Yönetimi:** Beyaz listeye kullanıcı eklemek/çıkarmak için belirlenen Yönetici numaralarından gelen SMS komutlarını destekleme.
- **Başlangıç Bildirimi:** Sistem açıldığında Yöneticilere bir SMS gönderme.

## Teknik Kısıtlamalar
- **Donanım:** ESP32, SIM800L (UART), 5V Röle Modülü.
- **Dil:** C++ (Arduino Framework).
- **Kütüphane:** SIM800L iletişimi için TinyGSM.
- **Depolama:** Kalıcı depolama için ESP32 `Preferences` kütüphanesi.

## Güvenlik
- Sadece beyaz listedeki numaralar erişebilir.
- SMS komutları sadece Yönetici numaralarıyla sınırlandırılmıştır.