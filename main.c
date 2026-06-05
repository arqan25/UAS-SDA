#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "linkedlist.h"
#include "queue.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void tungguEnter() {
    printf("\nTekan [ENTER] untuk kembali ke menu utama...");
    getchar();
}

int getHargaPerKg(char jenis[]) {
    if (strcasecmp(jenis, "Plastik") == 0) return 3000;
    if (strcasecmp(jenis, "Kertas") == 0) return 2000;
    if (strcasecmp(jenis, "Logam") == 0) return 6000;
    return 1000;
}

int main() {
    NodeNasabah* rootNasabah = NULL;
    NodeTransaksi* listTransaksi = NULL;
    Queue antrian;
    initQueue(&antrian);

    int pilihan;
    int counterIdNasabah = 101;  
    int counterIdTransaksi = 1;  

    while (1) {
        clearScreen();
        printf("=================================================\n");
        printf("           SISTEM BANK SAMPAH DIGITAL            \n");
        printf("=================================================\n");
        printf(" [1] Pendaftaran Nasabah Baru\n");
        printf(" [2] Masuk Antrian Setor Sampah\n");
        printf(" [3] Proses Setor Sampah (Petugas)\n");
        printf(" [4] Lihat Semua Riwayat Transaksi\n");
        printf(" [5] Keluar Aplikasi\n");
        printf("=================================================\n");
        printf("Pilih menu (1-5): ");
        
        if (scanf("%d", &pilihan) != 1) {
            printf("Input harus berupa angka!\n");
            getchar(); getchar();
            continue;
        }
        getchar(); 

        switch (pilihan) {
            case 1: {
                clearScreen();
                char nama[50];
                printf("=== PENDAFTARAN NASABAH ===\n");
                printf("Masukkan Nama Nasabah Baru : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; 

                rootNasabah = insertNasabah(rootNasabah, counterIdNasabah, nama);
                
                printf("\n-------------------------------------------------\n");
                printf(" [SUKSES] Data Berhasil Tersimpan!\n");
                printf(" ID Nasabah Baru Anda : %d\n", counterIdNasabah);
                printf("-------------------------------------------------\n");
                
                counterIdNasabah++;
                tungguEnter();
                break;
            }
            case 2: {
                clearScreen();
                int id;
                printf("=== MASUK ANTRIAN SETOR SAMPAH ===\n");
                printf("Masukkan ID Nasabah : ");
                scanf("%d", &id);
                getchar(); 
                
                NodeNasabah* nasabah = searchNasabah(rootNasabah, id);
                if (nasabah != NULL) {
                    enqueue(&antrian, id);
                    printf("\n[SUKSES] Nasabah %s masuk ke antrian.\n", nasabah->nama);
                } else {
                    printf("\n[ERROR] ID %d tidak ditemukan!\n", id);
                }
                tungguEnter();
                break;
            }
            case 3: {
                clearScreen();
                printf("=== PROSES SETOR SAMPAH (PETUGAS) ===\n");

                if (isEmpty(&antrian)) {
                    printf("\n[INFO] Antrian kosong.\n");
                    tungguEnter();
                    break;
                }

                int idNasabahAktif = dequeue(&antrian);
                NodeNasabah* nasabah = searchNasabah(rootNasabah, idNasabahAktif);

                printf("Melayani Nasabah: %s (ID: %d)\n\n", nasabah->nama, nasabah->idNasabah);
                
                char jenis[30];
                float berat;
                printf("Input Jenis Sampah (Plastik/Kertas/Logam): ");
                fgets(jenis, sizeof(jenis), stdin);
                jenis[strcspn(jenis, "\n")] = 0;

                printf("Input Berat Sampah (kg): ");
                scanf("%f", &berat);
                getchar(); 

                int hargaPerKg = getHargaPerKg(jenis);
                int totalHarga = (int)(berat * hargaPerKg);
                
                nasabah->saldo += totalHarga;

                insertTransaksi(&listTransaksi, counterIdTransaksi, idNasabahAktif, jenis, berat, totalHarga);
                
                printf("\n=== STRUK BUKTI TRANSAKSI ===\n");
                printf(" ID Transaksi  : TX%03d\n", counterIdTransaksi);
                printf(" ID / Nama     : %d / %s\n", nasabah->idNasabah, nasabah->nama);
                printf(" Jenis Sampah  : %s (Rp%d/kg)\n", jenis, hargaPerKg);
                printf(" Berat Sampah  : %.2f kg\n", berat);
                printf("-------------------------------------------------\n");
                printf(" Total Hasil   : Rp%d\n", totalHarga);
                printf(" Total Saldo   : Rp%d\n", nasabah->saldo);
                printf("==============================\n");

                counterIdTransaksi++;
                tungguEnter();
                break;
            }
            case 4: {
                clearScreen();
                printf("=== REKAP SELURUH RIWAYAT TRANSAKSI ===\n\n");
                tampilkanTransaksi(listTransaksi);
                tungguEnter();
                break;
            }
            case 5:
                clearScreen();
                printf("\nTerima kasih telah menggunakan Bank Sampah!\n\n");
                exit(0);
            default:
                printf("\n[Peringatan] Pilihan tidak valid!\n");
                tungguEnter();
        }
    }
    return 0;
}
