#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//========STRUCT QUEUE ========
struct paket
{
    int resi;
    char penerima[50];
    char alamat[50];
    char nomertelepon[12];
    char status[50];
    int hari;
    struct paket *next;
};
typedef struct paket paket;

struct antrianPaket
{
    paket *head;
    paket *tail;
    int count;
    int total;
};

//========STRUCT STACK ========
struct node
{
    paket data;
    node *next;
};
typedef struct node node;

struct mobil
{
    node *top;
    int count;
};
typedef struct mobil mobil;

//========STRUCT LINKEDLIST ========
struct kurir
{
    node *head;
    node *tail;
    int count;
};
typedef struct kurir kurir;

// function queue
void paketMasuk(antrianPaket **head, antrianPaket *pPre, antrianPaket *pCur);
{
    antrianPaket *pNew = (antrianPaket *)malloc(sizeof(antrianPaket));
    printf("Masukkan nomor resi: ");
    scanf("%d", &pNew->data.resi);
    printf("Masukkan nama penerima: ");
    scanf("%s", &pNew->data.penerima);
    printf("Masukkan alamat penerima: ");
    scanf("%s", &pNew->data.alamat);
    printf("Masukkan nomor telepon penerima: ");
    scanf("%s", &pNew->data.nomertelepon);
    printf("Masukkan status paket: ");
    scanf("%s", &pNew->data.status);
    printf("Masukkan hari: ");
    scanf("%d", &pNew->data.hari);
    pNew->next = NULL;
    if (*head == NULL)
    {
        *head = pNew;
    }
    else
    {
        pPre = NULL;
        pCur = *head;
        while (pCur != NULL && pNew->data.resi > pCur->data.resi)
        {
            pPre = pCur;
            pCur = pCur->next;
        }
        if (pPre == NULL)
        {
            pNew->next = *head;
            *head = pNew;
        }
        else
        {
            pNew->next = pCur;
            pPre->next = pNew;
        }
    }
}
void paketKeluar(antrianPaket **head, antrianPaket *pPre, antrianPaket *pCur);
void paketKeMobil(antrianPaket **head, mobil **top);
void mobilKeKurir(mobil **top, kurir **head);
void kurirKeTujuan(kurir **head, kurir *pPre, kurir *pCur);
void displayPaketMasuk(antrianPaket *head);
void displayMobilKeKurir(mobil *top);
void displayKurirKeTujuan(kurir *head);
