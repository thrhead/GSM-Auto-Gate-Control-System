# Plan - Garaj Kontrol MVP

## Aşama 1: Donanım Entegrasyonu ve Temel İletişim [checkpoint: 77af010]
- [x] Görev: Proje İskeleti - PlatformIO projesini başlat ve TinyGSM kütüphanesini kur. [5034b31]
- [x] Görev: Temel UART İletişimi - SIM800L ile AT komutları üzerinden iletişim kuracak kodu uygula. [95d0bcd]
- [x] Görev: Ağ Kaydı - GSM ağ kaydını bekleme ve sinyal gücü kontrol mantığını uygula. [ac18094]
- [x] Görev: Conductor - Kullanıcı Manuel Doğrulama 'Aşama 1' (Protokol workflow.md dosyasında)

## Aşama 2: Arama Yönetimi ve Röle Kontrolü [checkpoint: 1d8d1e5]
- [x] Görev: Gelen Arama Algılama - Seri portu RING uyarıları için izle ve Arayan Kimliğini (Caller ID) ayıkla. [ea3e887]
- [x] Görev: Otomatik Reddetme Mantığı - Zil algılandığında hemen kapatma işlemini uygula. [cde5ae8]
- [x] Görev: Röle Tetikleme - 1 saniyelik darbe için GPIO kontrol mantığını uygula. [c698917]
- [x] Görev: Conductor - Kullanıcı Manuel Doğrulama 'Aşama 2' (Protokol workflow.md dosyasında)

## Aşama 3: Beyaz Liste ve SMS Yönetimi
- [x] Görev: Kalıcı Depolama - Preferences tabanlı beyaz liste yönetimini uygula. [69dd8db]
- [x] Görev: SMS Komut Ayrıştırma - Yöneticilerden gelen "EKLE", "SIL" ve "DURUM" komutlarını işleyecek mantığı uygula. [60c478c]
- [ ] Görev: Başlangıç Bildirimi - Sistem açılışında SMS uyarısı göndermeyi uygula.
- [ ] Görev: Conductor - Kullanıcı Manuel Doğrulama 'Aşama 3' (Protokol workflow.md dosyasında)

## Aşama 4: Son Entegrasyon ve Test
- [ ] Görev: Entegrasyon - Arama algılamayı, beyaz liste doğrulamayı ve röle tetiklemeyi birleştir.
- [ ] Görev: Stres Testi - Tekrarlanan aramalar ve ağ kopma senaryoları altında sistem kararlılığını doğrula.
- [ ] Görev: Conductor - Kullanıcı Manuel Doğrulama 'Aşama 4' (Protokol workflow.md dosyasında)