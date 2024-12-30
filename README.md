Penjelasan Kode:
Inisialisasi GPS dan LCD:

TinyGPSPlus gps: Membuat objek GPS untuk membaca data GPS.
SoftwareSerial ss(4, 3): Membuat komunikasi serial dengan modul GPS pada pin 4 (RX) dan 3 (TX).
LiquidCrystal_I2C lcd(0x27, 16, 2): Membuat objek LCD dengan alamat I2C 0x27, lebar 16 karakter dan tinggi 2 baris.
Setup:

Serial.begin(9600): Memulai komunikasi serial dengan baud rate 9600.
ss.begin(9600): Memulai komunikasi serial dengan modul GPS.
lcd.begin(): Memulai LCD.
lcd.backlight(): Mengaktifkan backlight LCD.
lcd.print("Initializing..."): Menampilkan teks "Initializing..." pada LCD.
Loop:

Membaca data dari modul GPS dan meng-encode-nya dengan gps.encode(ss.read()).
Mengecek apakah data lokasi dan kecepatan valid dengan gps.location.isValid() dan gps.speed.isValid().
Jika data valid, menampilkan kecepatan dalam km/h pada LCD dan Serial Monitor.
Jika data tidak valid, menampilkan pesan "Waiting for GPS signal..." pada LCD dan Serial Monitor.
Program ini akan mengambil data dari modul GPS dan menampilkan kecepatan kendaraan dalam km/h pada LCD. Pastikan modul GPS memiliki pandangan yang jelas ke langit untuk menerima sinyal satelit dengan baik.
