#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "linkedlist.h"
#include "queue.h"

// Simulasi harga sampah per kg
int getHargaPerKg(char jenis[]) {
    if (strcasecmp(jenis, "Plastik") == 0) return 3000;
    if (strcasecmp(jenis, "Kertas") == 0) return 2000;
    if (strcasecmp(jenis, "Logam") == 0) return 6000;
    return 1000; // Harga default untuk jenis lainnya
}

int main() {
    NodeNasabah* rootNasabah = NULL;
    NodeTransaksi* listTransaksi = NULL;
    Queue antrian;
    initQueue(&antrian);

    int pilihan;
    int counterIdNasabah = 101;  // ID Nasabah otomatis mulai dari 101
    int counterIdTransaksi = 1;  // ID Transaksi otomatis mulai dari 1

    while (1) {
        printf("------- SISTEM BANK SAMPAH DIGITAL -------\n");
        printf("1. Pendaftaran Nasabah Baru\n");
        printf("2. Masuk Antrian Setor Sampah\n");
        printf("3. Proses Setor Sampah (Petugas)\n");
        printf("4. Lihat Semua Riwayat Transaksi\n");
        printf("5. Keluar Aplikasi\n");
        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);
        getchar(); // Membersihkan buffer newline

        switch (pilihan) {
            case 1: {
                char nama[50];
                printf("\n--- Pendaftaran Nasabah ---\n");
                printf("Masukkan Nama Nasabah: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // Menghapus newline di akhir string

                rootNasabah = insertNasabah(rootNasabah, counterIdNasabah, nama);
                printf("[SUKSES] Data Tersimpan!\n");
                printf("ID Nasabah Anda: %d\n", counterIdNasabah);
                counterIdNasabah++;
                break;
            }
            case 2: {
                // Fitur pendukung untuk memasukkan nasabah ke antrian fisik sebelum dilayani
                int id;
                printf("\n--- Masuk Antrian ---\n");
                printf("Masukkan ID Nasabah: ");
                scanf("%d", &id);
                
                NodeNasabah* nasabah = searchNasabah(rootNasabah, id);
                if (nasabah != NULL) {
                    enqueue(&antrian, id);
                    printf("[SUKSES] Nasabah %s masuk ke dalam antrian.\n", nasabah->nama);
                } else {
                    printf("[ERROR] ID Nasabah tidak ditemukan! Silahkan daftar terlebih dahulu.\n");
                }
                break;
            }
            case 3: {
                if (isEmpty(&antrian)) {
                    printf("\n[INFO] Antrian kosong. Tidak ada nasabah yang menyetor sampah.\n");
                    break;
                }

                // Ambil nasabah terdepan dari antrian
                int idNasabahAktif = dequeue(&antrian);
                NodeNasabah* nasabah = searchNasabah(rootNasabah, idNasabahAktif);

                printf("\n--- Melayani Nasabah: %s (ID: %d) ---\n", nasabah->nama, nasabah->idNasabah);
                
                char jenis[30];
                float berat;
                printf("Input Jenis Sampah (Plastik/Kertas/Logam): ");
                fgets(jenis, sizeof(jenis), stdin);
                jenis[strcspn(jenis, "\n")] = 0;

                printf("Input Berat Sampah (kg): ");
                scanf("%f", &berat);

                // Hitung Nilai Sampah
                int hargaPerKg = getHargaPerKg(jenis);
                int totalHarga = (int)(berat * hargaPerKg);
                printf("-> Hitung Nilai Sampah: %.2f kg x Rp%d = Rp%d\n", berat, hargaPerKg, totalHarga);

                // Tambah Saldo Nasabah
                nasabah->saldo += totalHarga;
                printf("-> Saldo Nasabah berhasil ditambah. Saldo sekarang: Rp%d\n", nasabah->saldo);

                // Simpan Riwayat Transaksi (Linked List)
                insertTransaksi(&listTransaksi, counterIdTransaksi, idNasabahAktif, jenis, berat, totalHarga);
                
                // Tampilkan Bukti Transaksi
                printf("\n===================================\n");
                printf("       BUKTI TRANSAKSI DIGITAL     \n");
                printf("===================================\n");
                printf("ID Transaksi  : TX%03d\n", counterIdTransaksi);
                printf("ID/Nama       : %d / %s\n", nasabah->idNasabah, nasabah->nama);
                printf("Jenis Sampah  : %s\n", jenis);
                printf("Berat Sampah  : %.2f kg\n", berat);
                printf("Total Pendapatan: Rp%d\n", totalHarga);
                printf("===================================\n");
                counterIdTransaksi++;
                break;
            }
            case 4: {
                printf("\n--- Seluruh Riwayat Transaksi Bank Sampah ---\n");
                tampilkanTransaksi(listTransaksi);
                break;
            }
            case 5:
                printf("\nProgram selesai. Terima kasih!\n");
                exit(0);
            default:
                printf("\nPilihan tidak valid!\n");
        }
    }
    return 0;
}
