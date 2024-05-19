#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void Wait()
{
    cout << endl;
    cout << "Tekan Enter untuk melanjutkan..." << endl;
    cin.ignore();
    cin.get();
}

void printData(int resi, const string &penerima, const string &alamat, int nomertelepon)
{
    system("cls");
    cout << "-> Resi: " << resi << "\n";
    cout << "Nama Penerima: " << penerima << "\n";
    cout << "Alamat: " << alamat << "\n";
    cout << "No Telepon: " << nomertelepon << "\n\n";
}

struct paket
{
    int resi;
    string penerima;
    string alamat;
    int nomertelepon;
};
typedef struct paket paket;

struct node
{
    paket data;
    node *next;
    node *prev;
};
typedef struct node node;

// queue
struct antriandata
{
    node *head;
    node *tail;
    int count;
};
typedef struct antriandata antriandata;

// stack
struct mobil
{
    node *top;
    int count;
};
typedef struct mobil mobil;

// doublelinkedlist
struct kurir
{
    node *head;
    node *tail;
    int count;
};
typedef struct kurir kurir;

int hitungPaketDiMobil(mobil *mobil)
{
    return mobil->count;
}

int hitungpaketdiantriandata(antriandata *antrian)
{
    return antrian->count;
}

void paketMasuk(antriandata *antrian, int resi, string penerima, string alamat, int nomertelepon)
{
    system("cls");
    node *temp = new node;
    temp->data.resi = resi;
    temp->data.penerima = penerima;
    temp->data.alamat = alamat;
    temp->data.nomertelepon = nomertelepon;
    temp->next = NULL;
    if (antrian->head == NULL)
    {
        antrian->head = temp;
        antrian->tail = temp;
    }
    else
    {
        antrian->tail->next = temp;
        antrian->tail = temp;
    }
    antrian->count++;
    cout << "Paket telah dimasukkan ke dalam antrian" << endl;
}

void paketKeMobil(antriandata *antrian, mobil *mobil)
{
    system("cls");
    if (antrian->head == NULL)
    {
        cout << "Tidak ada paket yang harus diproses" << endl;
        getch();
        return;
    }
    node *temp = antrian->head;
    antrian->head = antrian->head->next;
    temp->next = mobil->top; // Perbarui 'next' dari paket baru
    mobil->top = temp;
    // paket dipindahkan ke dalam mobil
    temp->next = NULL;
    if (antrian->head == NULL)
    {
        antrian->tail = NULL;
    }
    antrian->count--;
    mobil->count++;
    cout << "Paket dengan nomor resi " << temp->data.resi << " telah dipindahkan ke mobil" << endl;
    getch();
}

void mobilKeKurir(antriandata *antrian, mobil **mobil, kurir **kurir)
{
    system("cls");
    if ((*mobil)->top == NULL)
    {
        cout << "Tidak ada paket yang harus diproses" << endl;
        getch();
        return;
    }
    node *temp = (*mobil)->top;
    (*mobil)->top = (*mobil)->top->next;
    temp->next = (*kurir)->head; // Perbarui 'next' dari paket baru
    if ((*kurir)->head != NULL)
    {
        (*kurir)->head->prev = temp;
    }
    (*kurir)->head = temp;
    // paket dipindahkan ke dalam kurir
    temp->prev = NULL;
    if ((*mobil)->top == NULL)
    {
        (*mobil)->top = NULL;
    }
    (*mobil)->count--;
    (*kurir)->count++;
    cout << "Paket dengan nomor resi " << temp->data.resi << " telah dipindahkan ke kurir" << endl;
    getch();
}


void kurirKeCustomer(kurir *kurir)
{
    system("cls");
    if (kurir->head == NULL)
    {
        cout << "Tidak ada paket yang harus diproses" << endl;
        getch();
        return;
    }
    node *temp = kurir->head;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". Paket dengan nomor resi " << temp->data.resi << endl;
        temp = temp->next;
        i++;
    }
    cout << "Masukkan resi paket yang akan diantarkan: ";
    int resi;
    cin >> resi;
    temp = kurir->head;
    while (temp != NULL && temp->data.resi != resi)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Paket dengan resi " << resi << " tidak ditemukan" << endl;
    }
    else
    {
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            kurir->head = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            kurir->tail = temp->prev;
        }
        cout << "Paket dengan nomor resi " << temp->data.resi << " telah dikirim ke customer" << endl;
        delete temp;
    }
    cin.get();
}

void displayPaketMasuk(antriandata *antrian)
{
    system("cls");
    if (antrian->head == NULL)
    {
        cout << "Antrian masih kosong" << endl;
    }
    else
    {
        node *temp = antrian->head;
        cout << ("Paket dalam antrian: \n");
        while (temp != NULL)
        {
            printData(temp->data.resi, temp->data.penerima, temp->data.alamat, temp->data.nomertelepon);
            temp = temp->next;
        }
    }
}

void displayMobilKeKurir(mobil *mobil)
{
    system("cls");
    node *temp;
    temp = top;
    printf("Paket dalam mobil: \n");
    while (temp != NULL)
    {
        printData(temp->data.resi, temp->data.penerima, temp->data.alamat, temp->data.nomertelepon);
        temp = temp->next;
    }
}

void displayKurirKeCustomer(kurir *kurir)
{
    system("cls");
    node *temp = kurir->head;
    printf("Paket dalam kurir: \n");
    while (temp != NULL)
    {
        printData(temp->data.resi, temp->data.penerima, temp->data.alamat, temp->data.nomertelepon);
        temp = temp->next;
    }
}
int main()
{
    antriandata antrian;
    antrian.head = NULL;
    antrian.tail = NULL;
    antrian.count = 0;

    mobil mobil;
    mobil.top = NULL;

    kurir kurir;
    kurir.head = NULL;
    kurir.tail = NULL;

    int choice;
    do
    {
        system("cls");
        cout << "1. Tambah paket ke antrian\n";
        cout << "2. Pindahkan paket dari antrian ke mobil\n";
        cout << "3. Pindahkan paket dari mobil ke kurir\n";
        cout << "4. Kurir ke Customer\n";
        cout << "5. Tampilkan paket dalam antrian\n";
        cout << "6. Tampilkan paket dalam mobil\n";
        cout << "7. Tampilkan paket dalam kurir\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int resi, nomertelepon;
            string penerima, alamat;
            cout << "Masukkan nomor resi: ";
            cin >> resi;
            cout << "Masukkan nama penerima: ";
            cin >> penerima;
            cout << "Masukkan alamat: ";
            cin >> alamat;
            cout << "Masukkan nomor telepon: ";
            cin >> nomertelepon;
            paketMasuk(&antrian, resi, penerima, alamat, nomertelepon);
            break;
        }
        case 2:
            paketKeMobil(&antrian, &mobil);
            break;
        case 3:
            mobilKeKurir(&antrian, &mobil, &kurir);
            break;
        case 4:
            kurirKeCustomer(&kurir);
            break;
        case 5:
            displayPaketMasuk(&antrian);
            Wait();
            break;
        case 6:
            displayMobilKeKurir(mobil);
            Wait();
            break;
        case 7:
            displayKurirKeCustomer(&kurir);
            Wait();
            break;
        }
    } while (choice != 0);

    return 0;
}
