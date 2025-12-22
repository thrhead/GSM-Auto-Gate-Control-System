# Product Guidelines

## Core Principles

### 1. Reliability First
- **Watchdog Timers:** Sistem kilitlenmelerine karşı donanımsal ve yazılımsal watchdog zamanlayıcıları aktif olarak kullanılmalıdır.
- **Error Handling:** GSM bağlantı kopmaları ve SIM kart hataları otomatik olarak tespit edilmeli ve kurtarma senaryoları (yeniden bağlanma, modül resetleme) uygulanmalıdır.

### 2. Security
- **Whitelist Verification:** Gelen aramaların numaraları, yetkili numara listesiyle (EEPROM veya SPIFFS üzerinde saklanan) kesin olarak eşleşmelidir.
- **Input Validation:** SMS ile gelen komutlar sıkı bir şekilde doğrulanmalı, hatalı veya kötü niyetli girdiler reddedilmelidir.

### 3. Maintainability & Modularity
- **Component Separation:** GSM yönetimi, röle kontrolü ve numara yönetimi (whitelist) ayrı modüller veya sınıflar halinde kodlanmalıdır.
- **Configurability:** Kritik parametreler (röle tetikleme süresi, operatör ayarları) kodun içine gömülmek yerine yapılandırma dosyalarından veya tanımlı sabitlerden yönetilmelidir.

### 4. Hardware Safety
- **Fail-Safe State:** Sistem açılışında veya hata durumunda röleler her zaman "Kapalı" (Güvenli) konumda kalmalıdır.
- **Debouncing:** Fiziksel girişler (varsa butonlar) için kararlı okuma (debounce) algoritmaları uygulanmalıdır.
