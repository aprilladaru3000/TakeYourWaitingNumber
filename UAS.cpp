#include <iostream>
#include <iomanip>
using namespace std;

struct antrian {
    int nomorAntrian;
    string nama;
    int alasan;
    string nim;
    antrian* next;
} * head, * temporaryNode, * currentnode, * tail;

void antrianbaru(int);
void enqueue(antrian*);
void dequeue();
void cetakAntrian();
void cetakAntrianByNIM();
void sortAntrianByTujuan();
bool isEmpty();
void clear();

int main() {
    head = tail = nullptr;
    char pilihan;
    bool ongoing = true;
    int nomorAntrian = 1;

    const int MAX_ADMINS = 3;
    string admins[MAX_ADMINS] = {"AdminDaru", "admin2", "admin3"};
    string password = "darutampan";

    string inputAdmin, inputPassword;
    cout << "Username Admin: ";
    cin >> inputAdmin;
    cout << "Password: ";
    cin >> inputPassword;

    bool isAdmin = false;
    for (int i = 0; i < MAX_ADMINS; i++) {
        if (inputAdmin == admins[i] && inputPassword == password) {
            isAdmin = true;
            break;
        }
    }

    if (isAdmin) {
        while (ongoing) {
            cout << endl;
            cout << "===================================" << endl;
            cout << "||     Program Antrian DAAK      ||" << endl;
            cout << "|| UNIVERSITAS AMIKOM YOGYAKARTA ||      " << endl;
            cout << "===================================" << endl;
            cout << "|| 1. Tambahkan Antrian Baru     ||" << endl;
            cout << "|| 2. Panggil Antrian            ||" << endl;
            cout << "|| 3. Tampilkan Antrian          ||" << endl;
            cout << "|| 4. Pencarian Data Antrian     ||" << endl;
            cout << "|| 5. Hapus & Reset Antrian      ||" << endl;
            cout << "|| 6. Keluar                     ||" << endl;
            cout << "===================================" << endl;
            cout << "Pilihan [1-6] : ";
            cin >> pilihan;
            cout << "===================================\n" << endl;
            switch (pilihan) {
                case '1':
                    antrianbaru(nomorAntrian); 
                    nomorAntrian++;
                    break;
                case '2':
                    dequeue(); 
                    break;
                case '3':
                    cout << "===================================" << endl;
                    cout << "||     Tampilkan Antrian         ||" << endl;
                    cout << "|| 1. Tampilkan Daftar Antrian   ||" << endl;
                    cout << "|| 2. Tampilkan Antrian Terurut  ||" << endl;
                    cout << "===================================" << endl;
                    cout << "Pilihan [1-2] : ";
                    char subpilihan;
                    cin >> subpilihan;
                    cout << "===================================\n" << endl;
                    switch (subpilihan) {
                        case '1':
                            cetakAntrian();
                            break;
                        case '2':
                            sortAntrianByTujuan();
                            cetakAntrian();
                            break;
                        default:
                            cout << "Input Salah." << endl;
                            break;
                    }
                    break;
                case '4':
                    cetakAntrianByNIM(); 
                    break;
                case '5':
                    clear(); 
                    nomorAntrian = 1;
                    break;
                case '6':
                    cout << "Program selesai." << endl;
                    ongoing = false;
                    break;
                default:
                    cout << "Input Salah." << endl;
                    break;
            }
        } 
    } else {
        cout << "Login gagal. Program selesai." << endl;
    }

    return 0;
} 

void antrianbaru(int nomorAntrian) {
    string inputNama;
    int inputAlasan;
    string inputNim;

    cout << "\n===================================" << endl;
    cout << "Masukkan Nama Mahasiswa : ";
    cin.ignore();
    getline(cin, inputNama);
    cout << "Masukkan NIM             : ";
    getline(cin, inputNim);
    cout << "===================================" << endl;
    cout << "|| Pilih Tujuan :                ||" << endl;
    cout << "|| 1. Pembayaran SPP             ||" << endl;
    cout << "|| 2. Pengajuan Surat            ||" << endl;
    cout << "|| 3. Permasalahan Pada Dashboard    ||" << endl;
    cout << "===================================" << endl;
    cout << "Pilihan [1-3]: ";
    cin >> inputAlasan;
    cout << "===================================\n" << endl;

    antrian* newNode = new antrian();
    newNode->nomorAntrian = nomorAntrian;
    newNode->nama = inputNama;
    newNode->nim = inputNim;
    newNode->alasan = inputAlasan;
    newNode->next = nullptr;

    enqueue(newNode);
}

bool isEmpty() {
    return !head;
}

void enqueue(antrian* newNode) {
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Nomor antrian 0" << newNode->nomorAntrian;
    cout << " atas nama " << newNode->nama << " NIM " << newNode->nim << " dengan tujuan untuk ";
    switch (newNode->alasan) {
        case 1:
            cout << "Pembayaran SPP";
            break;
        case 2:
            cout << "Pengajuan Surat";
            break;
        case 3:
            cout << "Permasalahan Pada Dashboard";
            break;
        default:
            cout << "Tidak Valid";
            break;
    }
    cout << " berhasil ditambahkan." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    }
    else {
        currentnode = head;
        cout << "Nomor antrian 0" << currentnode->nomorAntrian;
        cout << " atas nama " << currentnode->nama;
        cout << " nim " << currentnode->nim;
        cout << " dengan tujuan untuk ";
        switch (currentnode->alasan) {
            case 1:
                cout << "Pembayaran SPP";
                break;
            case 2:
                cout << "Pengajuan Surat";
                break;
            case 3:
                cout << "Permasalahan Pada Dashboard";
                break;
            default:
                cout << "Tidak Valid";
                break;
        }
        cout << " telah dipanggil." << endl;
        head = head->next;
        delete currentnode;
    }
}

void cetakAntrian() {
    cout << "============================================================================" << endl;
    cout << "                                  Antrian                                   " << endl;
    cout << "============================================================================" << endl;
    if (isEmpty()) {
        cout << "\nAntrian Kosong" << endl;
    }
    else {
        currentnode = head;
        cout << "NO  | Nama                        | NIM           | Tujuan                   " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        while (currentnode != nullptr) {
            cout << setw(3) << right << currentnode->nomorAntrian << " | ";
            cout << setw(28) << left << currentnode->nama << " | ";
            cout << setw(13) << left << currentnode->nim << " | ";
            switch (currentnode->alasan) {
                case 1:
                    cout << "Pembayaran SPP";
                    break;
                case 2:
                    cout << "Pengajuan Surat";
                    break;
                case 3:
                    cout << "Permasalahan Pada Dashboard";
                    break;
                default:
                    cout << "Tidak Valid";
                    break;
            }
            cout << endl;
            currentnode = currentnode->next;
        }
        cout << "============================================================================" << endl;
    }
}

void cetakAntrianByNIM() {
    if (isEmpty()) {
        cout << "\nAntrian Kosong" << endl;
    }
    else {
        string searchNIM;
        cout << "Masukkan NIM yang ingin dicari: ";
        cin.ignore();
        getline(cin, searchNIM);
        currentnode = head;
        bool found = false;
        while (currentnode != nullptr) {
            if (currentnode->nim == searchNIM) {
                found = true;
                break;
            }
            currentnode = currentnode->next;
        }
        if (found) {
            cout << "============================================================================" << endl;
            cout << "                         Data Antrian Berdasarkan NIM                        " << endl;
            cout << "============================================================================" << endl;
            cout << "NO  | Nama                        | NIM           | Tujuan                   " << endl;
            cout << "----------------------------------------------------------------------------" << endl;
            cout << setw(3) << right << currentnode->nomorAntrian << " | ";
            cout << setw(28) << left << currentnode->nama << " | ";
            cout << setw(13) << left << currentnode->nim << " | ";
            switch (currentnode->alasan) {
                case 1:
                    cout << "Pembayaran SPP";
                    break;
                case 2:
                    cout << "Pengajuan Surat";
                    break;
                case 3:
                    cout << "Permasalahan Pada Dashboard";
                    break;
                default:
                    cout << "Tidak Valid";
                    break;
            }
            cout << endl;
            cout << "============================================================================" << endl;
        }
        else {
            cout << "Data tidak ditemukan." << endl;
        }
    }
}

void sortAntrianByTujuan() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    bool swapped;
    antrian* ptr;
    antrian* lptr = nullptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->alasan > ptr->next->alasan) {
                int tempNomorAntrian = ptr->nomorAntrian;
                string tempNama = ptr->nama;
                int tempAlasan = ptr->alasan;
                string tempNIM = ptr->nim;

                ptr->nomorAntrian = ptr->next->nomorAntrian;
                ptr->nama = ptr->next->nama;
                ptr->alasan = ptr->next->alasan;
                ptr->nim = ptr->next->nim;

                ptr->next->nomorAntrian = tempNomorAntrian;
                ptr->next->nama = tempNama;
                ptr->next->alasan = tempAlasan;
                ptr->next->nim = tempNIM;

                swapped = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}

void clear() {
    if (isEmpty()) {
        cout << "Antrian Kosong" << endl;
    }
    else {
        currentnode = head;
        while (currentnode != nullptr) {
            temporaryNode = currentnode->next;
            delete currentnode;
            currentnode = temporaryNode;
        }
        head = tail = nullptr;
        cout << "Antrian berhasil dihapus dan direset." << endl;
    }
}