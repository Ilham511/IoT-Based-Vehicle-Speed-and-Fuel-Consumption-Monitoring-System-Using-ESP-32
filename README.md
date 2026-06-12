Prototype Sistem Monitoring Kecepatan (RPM) dan Bahan Bakar Berbasis IoT
​Proyek ini adalah sistem pemantauan kondisi kendaraan secara real-time yang dirancang untuk efisiensi operasional dengan memanfaatkan mikrokontroler ESP32 dan platform Blynk IoT.
​📋 Deskripsi Proyek
​Sistem ini memantau dua parameter utama kendaraan:
​Kecepatan (RPM) menggunakan sensor Hall Effect KY-024.
​Level Bahan Bakar (BBM) menggunakan potensiometer sebagai simulasi.
​Data diproses oleh ESP32 dan ditampilkan secara lokal melalui LCD I2C 16x2, serta dikirimkan ke aplikasi Blynk untuk pemantauan jarak jauh via smartphone.
​🛠️ Komponen Utama
​Mikrokontroler: ESP32 DevKit V1
​Sensor: Hall Effect KY-024 & Potensiometer
​Display: LCD I2C 16x2
​Platform: Blynk IoT
​Pendukung: Breadboard, Kabel Jumper, Dinamo, Magnet, Adaptor
​🚀 Cara Kerja
​Sistem membaca data kecepatan dan bahan bakar melalui sensor yang terhubung ke ESP32. Data tersebut diolah dan dikirim melalui WiFi ke platform Blynk untuk ditampilkan secara real-time. Sistem ini mempermudah pengguna memantau kondisi kendaraan baik secara langsung maupun jarak jauh.
​📊 Hasil Pengujian
​Sistem menunjukkan tingkat konsistensi yang tinggi dengan selisih data yang relatif kecil antara pembacaan pada LCD lokal dan aplikasi Blynk. Detail lengkap hasil pengujian dapat dilihat pada file panduan yang tersedia di folder Panduan-Prototype.
​📸 Dokumentasi
​<img src="https://raw.githubusercontent.com/Ilham511/IoT-Based-Vehicle-Speed-and-Fuel-Consumption-Monitoring-System-Using-ESP-32/refs/heads/main/Foto%20Hasil%20Proyek%20IoT-Based%20Vehicle%20Speed%20and%20Fuel%20Consumption%20Monitoring%20System%20Using%20ESP%2032.jpeg" width="500">
