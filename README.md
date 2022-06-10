# SMOVEN-by-Mechatronics-AI-UPI-EDU
Repository ini adalah dokumentasi pengerjaan projek UAS mata kuliah sensor dan tranduser.
This repository is the documentation for the final exam project for sensor and transducer course.

I. SMOVEN (Smart Door with Voice Command and Automatic Light Sensor)

II. Kami hidup berdampingan dengan teman - teman penyandang disabilitas. Namun, sangat disayangkan apabila melihat sarana prasarana di tempat umum tidak ramah penyandang disabilitas. Salah satunya adalah pintu, pintu merupakan salah satu bagian terpenting dari suatu bangunan. Beberapa pintu yang ditemui di tempat umum hanya sedikit yang ramah disabiiitas. Melihat masalah yang ada, kami membuat demonstrasi alat sederhana yang bertujuan untuk memudahkan penyandang disabilitas masuk dan keluar suatu ruangan dengan bantuan sensor motor servo. Kami juga menginisiasi dalam pembuatan lampu otomatis yang nyalanya dapat menyesuaikan dengan kondisi penerangan untuk meminimalisir tindak kejahatan sehingga apabila dalam kondisi pagi dan siang, lampu akan mati. Sedangkan dalam kondisi malam, lampu akan menyala.

III. Solusi yang kami buat dari problem yang telah dijelaskan adalah membuat pintu otomatis dengan motor servo dan lampu otomatis dengan sensor cahaya APDS 9960. 

IV. Untuk pintu otomatis, ketika perintah suara "buka" pertama kali diucapkan, data akan bernilai 49. Apabila kondisi ini terpenuhi, maka akan menyebabkan servo bergerak ke posisi 0 derajat. Sedangkan apabila kata "tutup" diucapkan, maka data bernilai 50 dan apabila kondisi tersebut terpenuhi maka servo akan bergerak ke posisi 90 derajat. Sedangkan untuk lampu otomatis, lampu akan menyala apabila indeks cahaya pada data bernilai kurang dari 4500 dan apabila kondisi tersebut tidak dipenuhi (nilainya lebih dari 4500 maka lampu akan padam).

V. Referensi :
- https://youtu.be/A3QRyixnEl8
- 
