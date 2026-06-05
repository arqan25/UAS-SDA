KELOMPOK 1

BANK SAMPAH DIGITAL

DESKRIPSI PROGRAM

Bank Sampah Digital merupakan aplikasi berbasis bahasa C yang digunakan untuk mengelola proses penyetoran sampah oleh nasabah secara terstruktur. Program ini menerapkan beberapa konsep Struktur Data dan Algoritma seperti Binary Search Tree (BST), Linked List, dan Queue untuk mengelola data nasabah, transaksi, serta antrian penyetoran sampah.

Program dibuat sebagai proyek Ujian Akhir Semester (UAS) mata kuliah Struktur Data dan Algoritma.

FITUR UTAMA PROGRAM

1. Pendaftaran Nasabah Baru
Nasabah dapat mendaftar dan akan memperoleh ID nasabah secara otomatis.
2. Antrian Setor Sampah
Nasabah yang ingin menyetor sampah akan masuk ke dalam antrian pelayanan menggunakan struktur data Queue (FIFO).
3. Proses Setor Sampah
Petugas melayani nasabah sesuai urutan antrian dan melakukan pencatatan:
* Jenis sampah
* Berat sampah
* Harga per kilogram
* Total hasil setoran
Saldo nasabah akan bertambah secara otomatis berdasarkan hasil transaksi.
4. Riwayat Transaksi
Seluruh transaksi yang telah dilakukan dapat ditampilkan kembali sebagai laporan transaksi.
-Struktur Data yang Digunakan
-Binary Search Tree (BST)
Digunakan untuk menyimpan data nasabah sehingga proses pencarian nasabah berdasarkan ID menjadi lebih efisien.
-Queue
Digunakan untuk mengatur antrian penyetoran sampah berdasarkan prinsip First In First Out (FIFO).
-Linked List
Digunakan untuk menyimpan riwayat transaksi yang terus bertambah selama program berjalan.
-Menu Program
1. Pendaftaran Nasabah Baru
2. Masuk Antrian Setor Sampah
3. Proses Setor Sampah
4. Lihat Semua Riwayat Transaksi
5. Keluar Aplikasi
Cara Menjalankan Program
Compile
```bash
gcc main.c bst.c linkedlist.c queue.c -o banksampah
```
Jalankan Program
```bash
./banksampah
```
Untuk pengguna Windows:
```bash
banksampah.exe
```

 Contoh Alur Penggunaan
1. Daftarkan nasabah baru
2. Sistem memberikan ID nasabah
3. Nasabah masuk ke antrian penyetoran
4. Petugas memproses setoran sampah
5. Sistem menghitung nilai transaksi
6. Saldo nasabah diperbarui
7. Riwayat transaksi tersimpan dan dapat ditampilkan kembali

Konsep Struktur Data yang Diimplementasikan
* Binary Search Tree (BST)
* Linked List
* Queue (FIFO)
* Dynamic Memory Allocation
* Searching
* Data Management menggunakan Struct

 Teknologi
* Bahasa C
* GCC Compiler
* Visual Studio Code
* Git & GitHub

Tujuan Proyek
* Mengimplementasikan konsep Struktur Data dan Algoritma dalam studi kasus nyata
* Memahami penggunaan BST, Queue, dan Linked List
* Melatih kemampuan pemrograman modular menggunakan bahasa C
* Mengembangkan sistem pengelolaan bank sampah sederhana

Anggota Kelompok
-Farhan Syafiq (250810701100039)
-Arqan Syahputra (250810701100057)
-Nur Asysyifa Nadhira (250810701100060)
-M Yogi Kafrawi (250810701100114)

Mata Kuliah
Struktur Data dan Algoritma

