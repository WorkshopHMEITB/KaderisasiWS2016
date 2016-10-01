
#Kalkulator ***WSCalc 20160***

1. ***Cara Kerja Kalkulator WSCalc 20160 (Spesifikasi Tugas, mandatory)***
  1.	**Saat pertama dinyalakan, LCD kalkulator akan menampilkan running text** bertuliskan “WSCalc 20160 Calculator” pada baris pertama, dan "Made by Kelompok X" pada baris kedua
  2.	**Mulai komputasi** dengan menekan *button 1* (*button submit*) (saat *button 1* (*button submit*) ditekan, LED 1 menyala, sedangkan LED lainnya mati)
  3.	**Masukan bilangan A** (dengan menekan *button 2* (*button input*) sebanyak n kali) </br  >
  Contoh: Jika *button 2* (*button input*) ditekan sebanyak 2016 kali maka A = 2016
  4.	**Submit bilangan A** dengan menekan *button 1* (*button submit*) ( saat *button 1* (*button submit*) ditekan, LED2 menyala, sedangkan LED lainnya mati )
  5.	**Masukan bilangan B** (dengan menekan *button 2* (*button input*) sebanyak m kali) </br  >
  Contoh: Jika *button 2* (*button input*) di tekan sebanyak 1437 kali maka B = 1437
  6.	**Submit bilangan B** dengan menekan *button 1* (*button submit*) (saat *button 1* (*button submit*) ditekan, LED 3 menyala, sedangkan LED lainnya mati)
  7.	**Tentukan operasi yang akan dilakukan terhadap bilangan A dan B** dengan menekan *button 2* (*button input*) sebanyak x kali
  (jika x == 1 => A+B , x == 2 => A-B, x == 3 => A*B, x == 4 => A/B)
  8.	**Submit pilihan operasi** dengan menekan *button 1* (*button submit*)
  9.	**Ketiga LED melakukan animasi waving** seperti *exercise 3* saat day 1 minimal 3 kali putaran (ceritanya lagi loading *biar lucu)
  10.	**LCD menampilkan hasil kalkulasi** (yeay)
  11. Tekan *button 1* (*button submit*), **kalkulator kembali ke keadaan semula**

2. ***Fitur Premium Kalkulator WSCalc 20160 (Spesifikasi Bonus, supplementory)***</br  >
  * **Buat board rangkaian sedemikian rupa sehingga rangkaian dapat dijadikan shield Arduino.** (*Shields are boards that can be plugged on top of the Arduino PCB extending its capabilities.* -https://www.arduino.cc/en/Main/ArduinoShields)
  * **Menambah satu button lagi, yaitu *button undo input* (button 3) untuk mengurangi nilai bilangan input. (maksimal hingga nol)** Contoh: Misal pengguna sedang menginput bilangan A. Pertama-tama button input ditekan 5 kali. Kemudian, button undo input ditekan 2 kali. Kemudian button input ditekan satu kali lagi. Terakhir, button submit ditekan. Maka bilangan A menjadi bernilai 4. 
  * **Ketika memasukkan bilangan A atau B, tulisan di LCD akan terupdate (sesuai nilai dari bilangan A dan B saat itu) tiap kali tombol input ditekan.**
  * **Merubah metode penginputan nilai agar lebih efisien (tanpa keypad)**. Berikut caranya:
    * setiap kali menekan button 2 (button input), nilai dari bilangan yang dimasukkan bertambah satu. Namun, jika sudah ditekan 9 kali, menekan sekali lagi membuat nilai dari bilangan kembali ke 0. (Button undo input bekerja seperti itu pula. Setiap menekan button undo input, nilai bilangan berkurang sebesar 1, jika sudah nol, maka menekan kembali membuat nilainya menjadi 9)
    * Untuk menaikkan orde dari bilangan, pengguna harus menekan sebuah tombol baru, tombol *order left*. Contohnya seperti ini: Misal pengguna sedang menginput bilangan A. Pertama-tama button input ditekan 2 kali. Lalu button *order left* ditekan sekali. Kemudian, button input ditekan kembali sebanyak 3 kali. Lalu button *order left* ditekan lagi. Kemudian, button input ditekan 1 kali lagi. Terakhir, button submit ditekan. Maka nilai bilangan A menjadi bernilai 132.
  
3. ***Rangkaian Kalkulator WSCalc 20160***</br  >
  * **Rangkaian push button**</br  >
  ![push](https://github.com/WorkshopHMEITB/KaderisasiWS2016/blob/master/assets/images/push.PNG)
  * **Rangakain LED** </br  >
  ![LED](https://github.com/WorkshopHMEITB/KaderisasiWS2016/blob/master/assets/images/LED.PNG)
  * **Salah satu kemungkinan rangkaian untuk menghubungkan LCD dengan Arduino** (Jangan lupa untuk menyesuaikan parameter pada insialisasi LCD sebelum *setup loop*. Jika ingin menggunakan rangkaian yang dibawah ini dengan persis, maka tuliskan *LiquidCrystal lcd(12, 13, 5, 4, 3, 2);* sebelum *setup loop*)</br  ></br  >
  ![lcdarduino](https://github.com/WorkshopHMEITB/KaderisasiWS2016/blob/master/assets/images/lcdarduino.jpg)

6. ***Detail Tugas***
  1.	Membuat kode Arduino kalkulator ***WSCalc 20160***
  2.	Membuat rangkaian kalkulator ***WSCalc 20160*** (Diperbolehkan menggunakan dot matrix saja. Tidak akan ada penambahan
  nilai meskipun menggunakan PCB cetak. Cetaklah PCB jika itu dikarenakan keinginan pribadi (misal ingin kalkulatornya lebih *cantik* dan *memorable*))
  5.	Membuat dan mengupload file dokumentasi ke folder yang sesuai di repository KaderisasiWS2016 (caranya dapat dilihat pada file README.md pada root directory repository)
  6.	File yang harus di upload : Kode Kalkulator
  
7. ***Parameter Penilaian*** </br  >
Comming soon...

8. ***Deadline*** </br>
Selasa, 3 Oktober 2016

9. ***Informasi Tambahan***
  * Setiap anggota kelompok harus membuat kode Arduino untuk tugas kalkulator ini.
  * Rangkaian boleh dibuat menggunakan dot matriks ataupun dengan mencetak PCB (setiap kelompok hanya 1 dot matrix/PCB)
  * *Learning source comming soon*
