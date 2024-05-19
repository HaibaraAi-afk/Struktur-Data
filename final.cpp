#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

static int resi = 1;
//===================== STRUCT LL =========================
struct node1
{
	int resi;
	string nama_pengirim1, asal1;
	string nama_penerima1, tujuan1;
	string telp_pengirim1, telp_penerima1;
	string kode_asal1, kode_tujuan1;
	int lama_pengiriman1;
	struct node1 *next;
};
typedef struct node1 node1;
//================ STRUCT CIRCULAR LL =====================
struct node2
{
	int resi;
	string nama_pengirim2, asal2;
	string nama_penerima2, tujuan2;
	string telp_pengirim2, telp_penerima2;
	string kode_asal2, kode_tujuan2;
	int lama_pengiriman2;
	struct node2 *next;
};
typedef struct node2 node2;
//=================== STRUCT QUEUE =======================
struct node3
{
	int no_resi;
	string nama_pengirim3, asal3;
	string nama_penerima3, tujuan3;
	string telp_pengirim3, telp_penerima3;
	string kode_asal3, kode_tujuan3;
	int lama_pengiriman3;
	int no_antri;
	struct node3 *next;
};
typedef struct node3 node3;
struct queue
{
	int count;
	int jumlah;
	int no_resi;
	node3 *front;
	node3 *rear;
};
typedef struct queue queue;
//==================== FUNCTION LL =======================
node1 *createNode(void);
void insertNode(node1 **head, node1 *pPre, node1 *pNew);
void deleteNode(node1 **head, node1 *pPre, node1 *pCur);
void tambah_paket1(node1 **head);
void tampilkan_paket1(node1 *head);
void hapus_paket1(node1 **head, node2 **phead);
//============== FUNCTION CIRCULAR LL ====================
void tambah_paket2(node2 **phead, node2 *pPre, node2 *pNew);
void tampilkan_paket2(node2 *phead);
void hapus_paket2(node2 **phead, queue *myQueue);
//================== FUNCTION QUEUE ======================
queue createQueue(void);
void hapus_paket3(queue *myQueue);
void destroy(queue *myQueue);
void tampilkan_paket3(queue myQueue);
void barangterkirim(queue *myQueue);
//========================================================

//================== MAIN FUNCTION =======================
int main()
{
	node1 *head = NULL;
	node2 *phead = NULL;
	int pilih;
	queue myQueue;
	myQueue = createQueue();

	do
	{
		system("cls");
		cout << "==============================================================" << endl;
		cout << "|                                                            |" << endl;
		cout << "|                 SELAMAT DATANG DI                          |" << endl;
		cout << "|                     BnK EKSPEDISI                          |" << endl;
		cout << "|                                                            |" << endl;
		cout << "|============================ MENU ==========================|" << endl;
		cout << "|1. Input Paket                                              |" << endl;
		cout << "|2. Tampilkan Paket                                          |" << endl;
		cout << "|3. Proses Paket ke BnK                                      |" << endl;
		cout << "|4. Tampilkan Paket di BnK                                   |" << endl;
		cout << "|5. Proses Paket ke Kurir                                    |" << endl;
		cout << "|6. Tampilkan Paket yang dibawa Oleh Kurir                   |" << endl;
		cout << "|7. Proses Paket dikirim ke Customer                         |" << endl;
		cout << "|8. Cek Paket yang Berhasil dikirim ke Customer              |" << endl;
		cout << "|9. Exit                                                     |" << endl;
		cout << "==============================================================" << endl;
		fflush(stdin);
		cout << "Masukkan Pilihan : ";
		scanf("%d", &pilih);
		if (pilih == 1)
		{
			tambah_paket1(&head);
			getch();
		}
		else if (pilih == 2)
		{
			tampilkan_paket1(head);
			getch();
		}
		else if (pilih == 3)
		{
			hapus_paket1(&head, &phead);
			getch();
		}
		else if (pilih == 4)
		{
			tampilkan_paket2(phead);
			getch();
		}
		else if (pilih == 5)
		{
			hapus_paket2(&phead, &myQueue);
			getch();
		}
		else if (pilih == 6)
		{
			tampilkan_paket3(myQueue);
			getch();
		}
		else if (pilih == 7)
		{
			hapus_paket3(&myQueue);
			getch();
		}
		else if (pilih == 8)
		{
			barangterkirim(&myQueue);
			getch();
		}
	} while (pilih != 9);
	exit(0);
}
//========================================================
node1 *createNode(void)
{
	node1 *ptr = new node1;
	return (ptr);
}
//========================================================

//========================================================
queue createQueue(void)
{
	queue myQueue;

	myQueue.jumlah = 0;
	myQueue.no_resi = 1;
	myQueue.count = 0;
	myQueue.front = NULL;
	myQueue.rear = NULL;
	return (myQueue);
}
//==================== FUNCTION ==========================
void deleteNode(node1 **head, node1 *pPre, node1 *pCur)
{
	if (pPre == NULL)
		*head = pCur->next;
	else
		pPre->next = pCur->next;
	delete (pCur);
}
//------------------- INPUT PAKET ------------------------
void tambah_paket1(node1 **head)
{
	node1 *pTemp = new node1;
	string nama_pengirim1, asal1;
	string nama_penerima1, tujuan1;
	string telp_pengirim1, telp_penerima1;
	string kode_asal1, kode_tujuan1;
	int lama_pengiriman1;

	system("cls");
	cout << "============================= PENGIRIM =============================" << endl;
	pTemp->resi = resi;
	cout << "No Resi : " << resi << endl;
	resi++;
	cout << "Nama: ";
	cin >> nama_pengirim1;
	fflush(stdin);
	cout << "Alamat: ";
	cin >> asal1;
	fflush(stdin);
	cout << "No Telp: ";
	cin >> telp_pengirim1;
	fflush(stdin);
	cout << "============================= PENERIMA =============================" << endl;
	cout << "Nama: ";
	cin >> nama_penerima1;
	fflush(stdin);
	cout << "Alamat: ";
	cin >> tujuan1;
	fflush(stdin);
	cout << "No Telp: ";
	cin >> telp_penerima1;
	fflush(stdin);
	cout << "=============================== RUTE ===============================" << endl;
	cout << "Kode Asal: ";
	cin >> kode_asal1;
	fflush(stdin);
	cout << "Kode Tujuan: ";
	cin >> kode_tujuan1;
	fflush(stdin);
	cout << "Lama Pengiriman: ";
	cin >> lama_pengiriman1;
	fflush(stdin);
	cout << "====================================================================";

	if (pTemp != NULL)
	{
		int index = 0;
		pTemp->nama_pengirim1 = nama_pengirim1;
		pTemp->asal1 = asal1;
		pTemp->telp_pengirim1 = telp_pengirim1;
		pTemp->nama_penerima1 = nama_penerima1;
		pTemp->tujuan1 = tujuan1;
		pTemp->telp_penerima1 = telp_penerima1;
		pTemp->kode_asal1 = kode_asal1;
		pTemp->kode_tujuan1 = kode_tujuan1;
		pTemp->lama_pengiriman1 = lama_pengiriman1;
		index++;
		pTemp->next = *head;
		*head = pTemp;
	}
	else
	{
		cout << "Paket Gagal Ditambahkan";
		getch();
	}
}
//----------------- DELETE PACKAGE -----------------------
void hapus_paket1(node1 **head, node2 **phead)
{
	int pos;
	node1 *pCur, *pPre;
	node2 *pNew = new node2;
	string nama_pengirim2, asal2;
	string nama_penerima2, tujuan2;
	string telp_pengirim2, telp_penerima2;
	string kode_asal2, kode_tujuan2;
	int lama_pengiriman2, resi;

	system("cls");

	tampilkan_paket1(*head);
	cout << "Masukkan No Resi Paket Yang Ingin Diproses : ";
	fflush(stdin);
	cin >> pos;

	pPre = NULL;
	pCur = *head;

	while (pCur != NULL && pCur->resi != pos)
	{
		pPre = pCur;
		pCur = pCur->next;
	}

	if (pCur == NULL)
	{
		cout << "Paket dengan " << pos << " Tidak Ditemukan !!!" << endl;
		return;
	}
	else
	{
		pNew->resi = pCur->resi;
		pNew->nama_pengirim2 = pCur->nama_pengirim1;
		pNew->telp_pengirim2 = pCur->telp_pengirim1;
		pNew->nama_penerima2 = pCur->nama_penerima1;
		pNew->telp_penerima2 = pCur->telp_penerima1;
		pNew->tujuan2 = pCur->tujuan1;
		pNew->kode_asal2 = pCur->kode_asal1;
		pNew->kode_tujuan2 = pCur->kode_tujuan1;
		pNew->asal2 = pCur->asal1;
		pNew->lama_pengiriman2 = pCur->lama_pengiriman1;
		tambah_paket2(phead, NULL, pNew);
		deleteNode(head, pPre, pCur);
		cout << "Paket dengan No Resi " << pos << " Berhasil Diproses ke BnK !!!" << endl;
		getch();
	}
}
//------------------ SHOW PACKAGE ------------------------
void tampilkan_paket1(node1 *head)
{
	node1 *pWalker;
	pWalker = head;

	system("cls");
	if (pWalker == NULL)
	{
		cout << "Tidak ada Paket" << endl;
		return;
	}
	else
		while (pWalker != NULL)
		{
			cout << "============================= Paket No Resi -  " << pWalker->resi << " =============================" << endl;
			cout << "Nama Pengirim        : " << pWalker->nama_pengirim1 << endl;
			cout << "No Telp. Pengirim    : " << pWalker->telp_pengirim1 << endl;
			cout << "Alamat Pengirim      : " << pWalker->asal1 << endl;
			cout << "Nama Penerima        : " << pWalker->nama_penerima1 << endl;
			cout << "No Telp. Penerima    : " << pWalker->telp_penerima1 << endl;
			cout << "Alamat Penerima      : " << pWalker->tujuan1 << endl;
			cout << "Rute Paket           : " << pWalker->kode_asal1 << " -> " << pWalker->kode_tujuan1 << endl;
			cout << "Perkiraan Pengiriman : " << pWalker->lama_pengiriman1 << " Hari" << endl;
			cout << "==============================================================================" << endl;
			pWalker = pWalker->next;
		}
}
//----------------- SORTING -----------------------
void tambah_paket2(node2 **phead, node2 *pPre, node2 *pNew)
{
	node2 *pCur = *phead;
	if (pPre == NULL)
	{
		if (*phead == NULL)
		{
			pNew->next = pNew;
			(*phead) = pNew;
		}
		else if (pCur->lama_pengiriman2 < pNew->lama_pengiriman2)
		{
			while (pCur->next != (*phead))
			{
				pCur = pCur->next;
			}
			pCur->next = pNew;
			pNew->next = (*phead);
			(*phead) = pNew;
		}
		else
		{
			while (pCur->next != (*phead) && pCur->next->lama_pengiriman2 >= pNew->lama_pengiriman2)
			{
				pCur = pCur->next;
			}
			pNew->next = pCur->next;
			pCur->next = pNew;
		}
	}
	else
	{
		pNew->next = pPre->next;
		pPre->next = pNew;
	}
}
//----------------- VIEW SORTING -----------------------
void tampilkan_paket2(node2 *phead)
{
	node2 *pWalker = phead;
	system("cls");
	if (pWalker == NULL)
	{
		cout << "Paket Masih Kosong di BnK" << endl;
		return;
	}
	else
		cout << "============================= Paket yang Sedang Berada di BnK =============================" << endl;
	while (pWalker->next != phead)
	{
		cout << "Paket No Resi - " << pWalker->resi << endl;
		cout << "Nama Pengirim        : " << pWalker->nama_pengirim2 << endl;
		cout << "No Telp. Pengirim    : " << pWalker->telp_pengirim2 << endl;
		cout << "Alamat Pengirim      : " << pWalker->asal2 << endl;
		cout << "Nama Penerima        : " << pWalker->nama_penerima2 << endl;
		cout << "No Telp. Penerima    : " << pWalker->telp_penerima2 << endl;
		cout << "Alamat Penerima      : " << pWalker->tujuan2 << endl;
		cout << "Rute Paket           : " << pWalker->kode_asal2 << " -> " << pWalker->kode_tujuan2 << endl;
		cout << "Perkiraan Pengiriman : " << pWalker->lama_pengiriman2 << " Hari" << endl;
		cout << "============================================================================================" << endl;
		pWalker = pWalker->next;
	}
	cout << "Paket No Resi - " << pWalker->resi << endl;
	cout << "Nama Pengirim        : " << pWalker->nama_pengirim2 << endl;
	cout << "No Telp. Pengirim    : " << pWalker->telp_pengirim2 << endl;
	cout << "Alamat Pengirim      : " << pWalker->asal2 << endl;
	cout << "Nama Penerima        : " << pWalker->nama_penerima2 << endl;
	cout << "No Telp. Penerima    : " << pWalker->telp_penerima2 << endl;
	cout << "Alamat Penerima      : " << pWalker->tujuan2 << endl;
	cout << "Rute Paket           : " << pWalker->kode_asal2 << " -> " << pWalker->kode_tujuan2 << endl;
	cout << "Perkiraan Pengiriman : " << pWalker->lama_pengiriman2 << " Hari" << endl;
	cout << "============================================================================================" << endl;
}
//----------------- DELETE SORTING -----------------------
void hapus_paket2(node2 **phead, queue *myQueue)
{
	node2 *pCur, *pPre;
	node3 *new_node = new node3;
	string nama_pengirim3, asal3;
	string nama_penerima3, tujuan3;
	string telp_pengirim3, telp_penerima3;
	string kode_asal3, kode_tujuan3;
	int lama_pengiriman3, resi;

	system("cls");
	tampilkan_paket2(*phead);
	pCur = *phead;
	pPre = NULL;
	fflush(stdin);

	if (pCur == NULL)
	{
		cout << "Kurir tidak Membawa Paket" << endl;
		getch();
		return;
	}
	else
	{
		pCur = *phead;
		pPre = NULL;
		while (pCur->next != *phead)
		{
			pPre = pCur;
			pCur = pCur->next;
		}
		if (pPre == NULL)
		{
			*phead = NULL;
		}
		else if (pPre != NULL)
			pPre->next = pCur->next;
		cout << "Paket dengan No Resi " << pCur->resi << " Berhasil Dibawa ke Kurir !!!" << endl;
		{
			myQueue->count++;
			int index = 0;
			int i = 0;
			new_node->no_resi = pCur->resi;
			new_node->no_antri = myQueue->count;
			new_node->nama_penerima3 = pCur->nama_penerima2;
			new_node->nama_pengirim3 = pCur->nama_pengirim2;
			new_node->asal3 = pCur->asal2;
			new_node->tujuan3 = pCur->tujuan2;
			new_node->telp_pengirim3 = pCur->telp_pengirim2;
			new_node->telp_penerima3 = pCur->telp_penerima2;
			new_node->kode_asal3 = pCur->kode_asal2;
			new_node->kode_tujuan3 = pCur->kode_tujuan2;
			new_node->lama_pengiriman3 = pCur->lama_pengiriman2;
			new_node->next = NULL;
			index++;
			i++;
			if (myQueue->front == NULL)
			{
				myQueue->front = new_node;
				myQueue->rear = new_node;
			}
			else
			{
				myQueue->rear->next = new_node;
				myQueue->rear = new_node;
			}
		}
		delete (pCur);
	}
}
//----------------- DEQUEUE -----------------------
void hapus_paket3(queue *myQueue)
{
	system("cls");

	if (myQueue->count == 0)
	{
		cout << "Tidak Ada Paket yang Perlu dikirim" << endl;
	}
	else
	{
		node3 *pFirst;
		pFirst = myQueue->front;
		myQueue->front = myQueue->front->next;
		cout << "Paket dengan No Resi " << pFirst->no_resi << " Berhasil diterima Oleh Customer !!!" << endl;
		delete (pFirst);
		myQueue->jumlah++;
		myQueue->count--;
	}
}
//----------------- VIEW QUEUE -----------------------
void tampilkan_paket3(queue myQueue)
{
	node3 *temp;
	int no_urut;
	temp = myQueue.front;
	system("cls");

	if (temp != NULL)
	{
		cout << "============================= Paket yang Sedang Dikirim Oleh Kurir =============================" << endl;
		while (temp != NULL)
		{
			for (no_urut = 1; temp != NULL; no_urut++)
			{
				cout << "No Urut : " << no_urut << endl;
				cout << "No Resi : " << temp->no_resi << endl;
				cout << "Nama Pengirim : " << temp->nama_pengirim3 << endl;
				cout << "No Telp Pengirim : " << temp->telp_pengirim3 << endl;
				cout << "Alamat Pengirim : " << temp->asal3 << endl;
				cout << "Nama Penerima : " << temp->nama_penerima3 << endl;
				cout << "No Telp Penerima : " << temp->telp_penerima3 << endl;
				cout << "Alamat Penerima : " << temp->tujuan3 << endl;
				cout << "Rute Pengiriman : " << temp->kode_asal3 << " -> " << temp->kode_tujuan3 << endl;
				cout << "Lama Pengiriman : " << temp->lama_pengiriman3 << " Hari" << endl;
				cout << "================================================================================================" << endl;
				temp = temp->next;
			}
		}
	}
	else
	{
		cout << "Kurir tidak Membawa Paket" << endl;
	}
}
//----------------- STATUS -----------------------
void barangterkirim(queue *myQueue)
{
	system("cls");
	cout << "Jumlah Paket yang Sudah Terkirim : " << myQueue->jumlah << " Paket" << endl;
}
