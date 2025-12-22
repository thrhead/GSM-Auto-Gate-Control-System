# Proje İş Akışı

## Temel İlkeler

1. **Plan Gerçeğin Kaynağıdır:** Tüm çalışmalar `plan.md` üzerinden takip edilmelidir.
2. **Teknoloji Yığını Kasıtlıdır:** Teknoloji yığınındaki değişiklikler, uygulamadan *önce* `tech-stack.md` dosyasına kaydedilmelidir.
3. **Test Odaklı Geliştirme (TDD):** İşlevselliği uygulamadan önce birim testlerini yazın.
4. **Yüksek Kod Kapsama Oranı:** Tüm modüller için >%80 kod test kapsamı hedefleyin.
5. **Önce Kullanıcı Deneyimi:** Her karar kullanıcı deneyimine öncelik vermelidir.
6. **Etkileşimsiz & CI-Farkındalığı:** Etkileşimsiz komutları tercih edin. Tek seferlik yürütme sağlamak için izleme modu (watch-mode) araçlarında (testler, linterlar) `CI=true` kullanın.

## Görev İş Akışı

Tüm görevler sıkı bir yaşam döngüsünü takip eder:

### Standart Görev İş Akışı

1. **Görevi Seç:** `plan.md` dosyasından sıradaki müsait görevi seçin.

2. **Devam Ediyor Olarak İşaretle:** Çalışmaya başlamadan önce `plan.md` dosyasını düzenleyin ve görevi `[ ]` durumundan `[~]` durumuna getirin.

3. **Başarısız Testler Yaz (Kırmızı Aşama):**
   - Özellik veya hata düzeltmesi için yeni bir test dosyası oluşturun.
   - Görev için beklenen davranışı ve kabul kriterlerini açıkça tanımlayan bir veya daha fazla birim testi yazın.
   - **KRİTİK:** Testleri çalıştırın ve beklendiği gibi başarısız olduklarını doğrulayın. Bu, TDD'nin "Kırmızı" aşamasıdır. Başarısız testleriniz olmadan devam etmeyin.

4. **Testleri Geçmek İçin Uygula (Yeşil Aşama):**
   - Başarısız testleri geçmek için gereken minimum uygulama kodunu yazın.
   - Test paketini tekrar çalıştırın ve tüm testlerin geçtiğini doğrulayın. Bu "Yeşil" aşamadır.

5. **Yeniden Düzenle (İsteğe Bağlı ama Önerilen):**
   - Geçen testlerin güvenliğiyle, uygulama kodunu ve test kodunu netliği artırmak, tekrarları kaldırmak ve dış davranışı değiştirmeden performansı iyileştirmek için yeniden düzenleyin.
   - Yeniden düzenlemeden sonra testlerin hala geçtiğinden emin olmak için testleri tekrar çalıştırın.

6. **Kapsamı Doğrula:** Projenin seçilen araçlarını kullanarak kapsam raporlarını çalıştırın. Örneğin, bir Python projesinde bu şöyle görünebilir:
   ```bash
   pytest --cov=app --cov-report=html
   ```
   Hedef: Yeni kod için >%80 kapsam. Belirli araçlar ve komutlar dile ve çerçeveye göre değişecektir.

7. **Sapmaları Belgele:** Uygulama teknoloji yığınından farklıysa:
   - Uygulamayı **DURDURUN**
   - `tech-stack.md` dosyasını yeni tasarımla güncelleyin
   - Değişikliği açıklayan tarihli bir not ekleyin
   - Uygulamaya devam edin

8. **Kod Değişikliklerini İşle (Commit):**
   - Görevle ilgili tüm kod değişikliklerini sahneleyin (stage).
   - Açık, özlü bir işlem mesajı önerin örn. `feat(ui): Hesap makinesi için temel HTML yapısını oluştur`.
   - İşlemi (commit) gerçekleştirin.

9. **Git Notları ile Görev Özeti Ekle:**
   - **Adım 9.1: İşlem Hash'ini Al:** *Az önce tamamlanan işlemin* hash'ini alın (`git log -1 --format="%H"`).
   - **Adım 9.2: Not İçeriği Hazırla:** Tamamlanan görev için ayrıntılı bir özet oluşturun. Bu, görev adını, değişikliklerin özetini, oluşturulan/değiştirilen tüm dosyaların listesini ve değişikliğin temel "nedenini" içermelidir.
   - **Adım 9.3: Notu Ekle:** Özeti işleme eklemek için `git notes` komutunu kullanın.
     ```bash
     # Önceki adımdaki not içeriği -m bayrağı ile iletilir.
     git notes add -m "<not içeriği>" <commit_hash>
     ```

10. **Görev İşlem SHA'sını Al ve Kaydet:**
    - **Adım 10.1: Planı Güncelle:** `plan.md` dosyasını okuyun, tamamlanan görev satırını bulun, durumunu `[~]`'dan `[x]`'e güncelleyin ve *az önce tamamlanan işlemin* hash'inin ilk 7 karakterini ekleyin.
    - **Adım 10.2: Planı Yaz:** Güncellenen içeriği `plan.md` dosyasına geri yazın.

11. **Plan Güncellemesini İşle:**
    - **Eylem:** Değiştirilen `plan.md` dosyasını sahneleyin.
    - **Eylem:** Bu değişikliği açıklayıcı bir mesajla işleyin (örn., `conductor(plan): 'Kullanıcı modeli oluştur' görevini tamamlandı olarak işaretle`).

### Aşama Tamamlama Doğrulama ve Kontrol Noktası Protokolü

**Tetikleyici:** Bu protokol, `plan.md` dosyasında bir aşamayı da sonlandıran bir görev tamamlandıktan hemen sonra yürütülür.

1.  **Protokol Başlangıcını Duyur:** Kullanıcıya aşamanın tamamlandığını ve doğrulama ve kontrol noktası protokolünün başladığını bildirin.

2.  **Aşama Değişiklikleri İçin Test Kapsamını Sağla:**
    -   **Adım 2.1: Aşama Kapsamını Belirle:** Bu aşamada değiştirilen dosyaları belirlemek için önce başlangıç noktasını bulmalısınız. *Önceki* aşamanın kontrol noktasının Git işlem SHA'sını bulmak için `plan.md` dosyasını okuyun. Önceki bir kontrol noktası yoksa, kapsam ilk işlemden bu yana yapılan tüm değişikliklerdir.
    -   **Adım 2.2: Değiştirilen Dosyaları Listele:** Bu aşamada değiştirilen tüm dosyaların kesin listesini almak için `git diff --name-only <previous_checkpoint_sha> HEAD` komutunu çalıştırın.
    -   **Adım 2.3: Doğrula ve Testler Oluştur:** Listedeki her dosya için:
        -   **KRİTİK:** Önce uzantısını kontrol edin. Kod olmayan dosyaları (örn. `.json`, `.md`, `.yaml`) hariç tutun.
        -   Kalan her kod dosyası için karşılık gelen bir test dosyasının var olduğunu doğrulayın.
        -   Bir test dosyası eksikse, bir tane oluşturmak **zorundasınız**. Testi yazmadan önce, **doğru adlandırma kuralını ve test stilini belirlemek için depodaki diğer test dosyalarını analiz edin.** Yeni testler, bu aşamanın görevlerinde (`plan.md`) açıklanan işlevselliği **doğrulamalıdır**.

3.  **Otomatik Testleri Proaktif Hata Ayıklama ile Yürüt:**
    -   Yürütmeden önce, testleri çalıştırmak için kullanacağınız tam kabuk komutunu **duyurmalısınız**.
    -   **Örnek Duyuru:** "Aşamayı doğrulamak için şimdi otomatik test paketini çalıştıracağım. **Komut:** `CI=true npm test`"
    -   Duyurulan komutu çalıştırın.
    -   Testler başarısız olursa, kullanıcıyı bilgilendirmek ve hata ayıklamaya başlamak **zorundasınız**. Bir düzeltme önermeyi **en fazla iki kez** deneyebilirsiniz. İkinci önerilen düzeltmenizden sonra testler hala başarısız olursa, **durmalı**, kalıcı hatayı bildirmeli ve kullanıcıdan rehberlik istemelisiniz.

4.  **Ayrıntılı, Uygulanabilir Manuel Doğrulama Planı Öner:**
    -   **KRİTİK:** Planı oluşturmak için önce `product.md`, `product-guidelines.md` ve `plan.md` dosyalarını analiz ederek tamamlanan aşamanın kullanıcıya dönük hedeflerini belirleyin.
    -   Kullanıcıyı doğrulama sürecinde yönlendiren, gerekli komutları ve belirli, beklenen sonuçları içeren adım adım bir plan **oluşturmalısınız**.
    -   Kullanıcıya sunduğunuz plan şu formatı **takip etmelidir**:

        **Bir Frontend Değişikliği İçin:**
        ```
        Otomatik testler geçti. Manuel doğrulama için lütfen şu adımları izleyin:

        **Manuel Doğrulama Adımları:**
        1.  **Geliştirme sunucusunu şu komutla başlatın:** `npm run dev`
        2.  **Tarayıcınızı şuraya açın:** `http://localhost:3000`
        3.  **Şunu gördüğünüzü doğrulayın:** Kullanıcının adı ve e-postasının doğru görüntülendiği yeni kullanıcı profil sayfası.
        ```

        **Bir Backend Değişikliği İçin:**
        ```
        Otomatik testler geçti. Manuel doğrulama için lütfen şu adımları izleyin:

        **Manuel Doğrulama Adımları:**
        1.  **Sunucunun çalıştığından emin olun.**
        2.  **Terminalinizde şu komutu çalıştırın:** `curl -X POST http://localhost:8080/api/v1/users -d '{"name": "test"}'`
        3.  **Şunu aldığınızı doğrulayın:** `201 Created` durumlu bir JSON yanıtı.
        ```

5.  **Açık Kullanıcı Geri Bildirimi Bekle:**
    -   Ayrıntılı planı sunduktan sonra, kullanıcıdan onay isteyin: "**Bu beklentilerinizi karşılıyor mu? Lütfen evet ile onaylayın veya neyin değiştirilmesi gerektiği konusunda geri bildirimde bulunun.**"
    -   **DURAKLAYIN** ve kullanıcının yanıtını bekleyin. Açık bir evet veya onay olmadan devam etmeyin.

6.  **Kontrol Noktası İşlemi (Checkpoint Commit) Oluştur:**
    -   Tüm değişiklikleri sahneleyin. Bu adımda hiçbir değişiklik olmadıysa, boş bir işlemle devam edin.
    -   Açık ve özlü bir mesajla işlemi gerçekleştirin (örn., `conductor(checkpoint): Aşama X sonu kontrol noktası`).

7.  **Git Notları Kullanarak Denetlenebilir Doğrulama Raporu Ekle:**
    -   **Adım 8.1: Not İçeriği Hazırla:** Otomatik test komutunu, manuel doğrulama adımlarını ve kullanıcının onayını içeren ayrıntılı bir doğrulama raporu oluşturun.
    -   **Adım 8.2: Notu Ekle:** Tam raporu kontrol noktası işlemine eklemek için `git notes` komutunu ve önceki adımdaki tam işlem hash'ini kullanın.

8.  **Aşama Kontrol Noktası SHA'sını Al ve Kaydet:**
    -   **Adım 7.1: İşlem Hash'ini Al:** *Az önce oluşturulan kontrol noktası işleminin* hash'ini alın (`git log -1 --format="%H"`).
    -   **Adım 7.2: Planı Güncelle:** `plan.md` dosyasını okuyun, tamamlanan aşamanın başlığını bulun ve `[checkpoint: <sha>]` formatında işlem hash'inin ilk 7 karakterini ekleyin.
    -   **Adım 7.3: Planı Yaz:** Güncellenen içeriği `plan.md` dosyasına geri yazın.

9. **Plan Güncellemesini İşle:**
    - **Eylem:** Değiştirilen `plan.md` dosyasını sahneleyin.
    - **Eylem:** Bu değişikliği `conductor(plan): '<AŞAMA ADI>' aşamasını tamamlandı olarak işaretle` formatını izleyen açıklayıcı bir mesajla işleyin.

10.  **Tamamlamayı Duyur:** Kullanıcıya aşamanın tamamlandığını ve kontrol noktasının oluşturulduğunu, ayrıntılı doğrulama raporunun bir git notu olarak eklendiğini bildirin.

### Kalite Kapıları

Herhangi bir görevi tamamlandı olarak işaretlemeden önce şunları doğrulayın:

- [ ] Tüm testler geçiyor
- [ ] Kod kapsamı gereksinimleri karşılıyor (>%80)
- [ ] Kod, projenin kod stili yönergelerine uyuyor (`code_styleguides/` içinde tanımlandığı gibi)
- [ ] Tüm genel fonksiyonlar/metotlar belgelenmiş (örn. docstrings, JSDoc, GoDoc)
- [ ] Tip güvenliği sağlanmış (örn. type hints, TypeScript tipleri, Go tipleri)
- [ ] Tiftikleme (linting) veya statik analiz hatası yok (projenin yapılandırılmış araçları kullanılarak)
- [ ] Mobilde doğru çalışıyor (varsa)
- [ ] Gerekirse belgeler güncellendi
- [ ] Güvenlik açığı oluşturulmadı

## Geliştirme Komutları

**YAPAY ZEKA AJANI TALİMATI: Bu bölüm projenin belirli diline, çerçevesine ve derleme araçlarına uyarlanmalıdır.**

### Kurulum
```bash
# Örnek: Geliştirme ortamını kurma komutları (örn. bağımlılıkları yükle, veritabanını yapılandır)
# örn. bir Node.js projesi için: npm install
# örn. bir Go projesi için: go mod tidy
```

### Günlük Geliştirme
```bash
# Örnek: Yaygın günlük görevler için komutlar (örn. geliştirme sunucusunu başlat, testleri çalıştır, lint, formatla)
# örn. bir Node.js projesi için: npm run dev, npm test, npm run lint
# örn. bir Go projesi için: go run main.go, go test ./..., go fmt ./...
```

### İşlemeden (Commit) Önce
```bash
# Örnek: Tüm ön işlem kontrollerini çalıştırma komutları (örn. formatla, lint, tip kontrolü, testleri çalıştır)
# örn. bir Node.js projesi için: npm run check
# örn. bir Go projesi için: make check (bir Makefile varsa)
```

## Test Gereksinimleri

### Birim Testi
- Her modülün karşılık gelen testleri olmalıdır.
- Uygun test kurulum/söküm mekanizmalarını kullanın (örn. fixtures, beforeEach/afterEach).
- Harici bağımlılıkları taklit edin (Mock).
- Hem başarı hem de başarısızlık durumlarını test edin.

### Entegrasyon Testi
- Tam kullanıcı akışlarını test edin
- Veritabanı işlemlerini doğrulayın
- Kimlik doğrulama ve yetkilendirmeyi test edin
- Form gönderimlerini kontrol edin

### Mobil Testi
- Mümkünse gerçek iPhone üzerinde test edin
- Safari geliştirici araçlarını kullanın
- Dokunmatik etkileşimleri test edin
- Duyarlı düzenleri doğrulayın
- 3G/4G üzerinde performansı kontrol edin

## Kod İnceleme Süreci

### Kendi Kendine İnceleme Kontrol Listesi
İnceleme talep etmeden önce:

1. **İşlevsellik**
   - Özellik belirtildiği gibi çalışıyor
   - Uç durumlar ele alınmış
   - Hata mesajları kullanıcı dostu

2. **Kod Kalitesi**
   - Stil rehberine uyuyor
   - DRY prensibi uygulanmış
   - Net değişken/fonksiyon adları
   - Uygun yorumlar

3. **Test Etme**
   - Birim testleri kapsamlı
   - Entegrasyon testleri geçiyor
   - Kapsam yeterli (>%80)

4. **Güvenlik**
   - Kodlanmış sır (secret) yok
   - Girdi doğrulama mevcut
   - SQL enjeksiyonu engellenmiş
   - XSS koruması mevcut

5. **Performans**
   - Veritabanı sorguları optimize edilmiş
   - Görseller optimize edilmiş
   - Gereken yerlerde önbellekleme uygulanmış

6. **Mobil Deneyimi**
   - Dokunma hedefleri yeterli (44x44px)
   - Metin yakınlaştırmadan okunabilir
   - Mobilde performans kabul edilebilir
   - Etkileşimler doğal hissediliyor

## İşleme (Commit) Yönergeleri

### Mesaj Formatı
```
<tür>(<kapsam>): <açıklama>

[isteğe bağlı gövde]

[isteğe bağlı alt bilgi]
```

### Türler
- `feat`: Yeni özellik
- `fix`: Hata düzeltmesi
- `docs`: Sadece dokümantasyon
- `style`: Biçimlendirme, eksik noktalı virgüller vb.
- `refactor`: Ne hata düzelten ne de özellik ekleyen kod değişikliği
- `test`: Eksik testleri ekleme
- `chore`: Bakım görevleri

### Örnekler
```bash
git commit -m "feat(auth): Beni hatırla işlevselliği ekle"
git commit -m "fix(posts): Kısa gönderiler için alıntı oluşturmayı düzelt"
git commit -m "test(comments): Emoji tepki sınırları için testler ekle"
git commit -m "style(mobile): Buton dokunma hedeflerini iyileştir"
```

## Bitti Tanımı (Definition of Done)

Bir görev şu durumlarda tamamlanmış sayılır:

1. Tüm kod şartnameye göre uygulanmış
2. Birim testleri yazılmış ve geçiyor
3. Kod kapsamı proje gereksinimlerini karşılıyor
4. Dokümantasyon tamamlanmış (varsa)
5. Kod, yapılandırılmış tüm tiftikleme (linting) ve statik analiz kontrollerini geçiyor
6. Mobilde güzel çalışıyor (varsa)
7. Uygulama notları `plan.md` dosyasına eklenmiş
8. Değişiklikler uygun mesajla işlenmiş (committed)
9. Görev özeti içeren Git notu işleme (commit) eklenmiş

## Acil Durum Prosedürleri

### Üretimde Kritik Hata
1. Main'den hotfix dalı oluştur
2. Hata için başarısız test yaz
3. Minimal düzeltmeyi uygula
4. Mobil dahil kapsamlı test et
5. Hemen dağıt (deploy)
6. plan.md içinde belgele

### Veri Kaybı
1. Tüm yazma işlemlerini durdur
2. En son yedekten geri yükle
3. Veri bütünlüğünü doğrula
4. Olayı belgele
5. Yedekleme prosedürlerini güncelle

### Güvenlik İhlali
1. Tüm sırları (secrets) hemen döndür (rotate)
2. Erişim günlüklerini incele
3. Güvenlik açığını yamala
4. Etkilenen kullanıcıları bildir (varsa)
5. Güvenlik prosedürlerini belgele ve güncelle

## Dağıtım İş Akışı

### Dağıtım Öncesi Kontrol Listesi
- [ ] Tüm testler geçiyor
- [ ] Kapsam >%80
- [ ] Tiftikleme (linting) hatası yok
- [ ] Mobil testi tamamlandı
- [ ] Ortam değişkenleri yapılandırıldı
- [ ] Veritabanı geçişleri (migrations) hazır
- [ ] Yedek oluşturuldu

### Dağıtım Adımları
1. Özellik dalını (feature branch) main ile birleştir (merge)
2. Sürümü versiyonla etiketle
3. Dağıtım servisine it (push)
4. Veritabanı geçişlerini çalıştır
5. Dağıtımı doğrula
6. Kritik yolları test et
7. Hataları izle (monitor)

### Dağıtım Sonrası
1. Analitikleri izle
2. Hata günlüklerini kontrol et
3. Kullanıcı geri bildirimi topla
4. Bir sonraki yinelemeyi planla

## Sürekli İyileştirme

- İş akışını haftalık gözden geçir
- Sorunlu noktalara göre güncelle
- Öğrenilen dersleri belgele
- Kullanıcı mutluluğu için optimize et
- İşleri basit ve sürdürülebilir tut