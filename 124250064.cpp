#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
	struct Barang{
		char nama[50];
		int harga;
		int stok;
		};
	struct Karyawan{
		int id;
		char nama[50];
		};
	Barang barang[100];
	Karyawan karyawan [100];
	int jumlahBarang = 0;
	int jumlahKaryawan = 0;
	struct menu{
		int input;
		string next;
		}menuu;
	struct log{
		string username ;
		int password ;
		} loginAdmin;
void tungguLanjut() {
    cout << "Tekan Enter untuk Melanjutkan . . . ";
    cin.ignore();
    cin.get();
}
bool login(){ // LOGIN ADMIN
    while(true){
        cout << "\n----------------------------------------\n";
		cout << "              LOGIN ADMIN\n";
		cout << "----------------------------------------\n";
        cout << "Username : ";
        cin >> loginAdmin.username;
        cout << "Password : ";
        cin >> loginAdmin.password;
        if(loginAdmin.username == "admin" && loginAdmin.password == 123){
            cout << "------------ Login Berhasil ------------\n";
            return true;
        }
        cout << "Username atau Password Anda salah\n";
        char ulang;
        cout << "Coba lagi? (y/n) : ";
        cin >> ulang;
        if(ulang == 'n' || ulang == 'N'){
            return false;  
        }
        tungguLanjut();
    }
}
void simpanBarang(){ //MENYIMPAN DATA BARANG
	FILE *fp;
	fp = fopen("barang.txt","w");
	for(int i = 0; i < jumlahBarang; i++){
		fprintf(fp,"%s\n", barang[i].nama); fprintf(fp,"%d\n", barang[i].harga); fprintf(fp,"%d\n", barang[i].stok);
	}fclose(fp);
}
void bacaBarang(){
	FILE *fp;
	fp = fopen("barang.txt","r");
	if(fp == NULL){
		return;
	}jumlahBarang = 0;
	while(fscanf(fp," %[^\n]\n%d\n%d", barang[jumlahBarang].nama, &barang[jumlahBarang].harga, &barang[jumlahBarang].stok) == 3){
		jumlahBarang++;
	}fclose(fp);
}
void simpanKaryawan(){ // MENYIMPAN SEMUA DATA KARYAWAN
    FILE *fp;
    fp = fopen("karyawan.txt","w");
    for(int i = 0; i < jumlahKaryawan; i++){
        fprintf(fp,"%d %s\n", karyawan[i].id, karyawan[i].nama);
    }fclose(fp);
}
void bacaKaryawan(){  //MEMBACA DATA KARYAWAN DARI FILE KARYAWAN.TXT
    FILE *fp;
    fp = fopen("karyawan.txt","r");
    if(fp == NULL){
		return; 
		} jumlahKaryawan = 0;
		while(fscanf(fp,"%d %[^\n]\n", &karyawan[jumlahKaryawan].id, karyawan[jumlahKaryawan].nama) != EOF){
        jumlahKaryawan++;
		} fclose(fp);
	}
void tambahKaryawan(){ // MENAMBAH DATA KARYAWAN
	int n;
    cout << "Masukkan Jumlah Karyawan : ";
    cin >> n;
    for(int i = 0; i < n; i++){
		cout << "\nData karyawan ke - " << i+1 << endl;
		cout << "Masukkan ID Karyawan     : ";
        cin >> karyawan[jumlahKaryawan].id;
        cout << "Masukkan Nama Karyawan   : ";
        cin.ignore();
        cin.getline(karyawan[jumlahKaryawan].nama, 50);
        jumlahKaryawan++;
        cout << endl;
		} cout << "-------- Data Berhasil Ditambah --------\n";
		 simpanKaryawan(); 
	}
void dataKaryawan(){ // MENAMPILKAN DATA KARYAWAN
	bacaKaryawan();
	if(jumlahKaryawan == 0){
        cout << "Data Kosong\n";
        return;
    }
		cout << "\n---------------------------------------\n";
		cout << "             DATA KARYAWAN\n";
		cout << "---------------------------------------\n";
		cout << left << setw(5) << "No"
		<< setw(10) << "ID"
		<< setw(30) << "Nama" << endl;
		cout << "---------------------------------------\n";
		for(int i = 0; i < jumlahKaryawan; i++){
			cout << left << setw(5) << i+1 << setw(10) << karyawan[i].id
			<< setw(30) << karyawan[i].nama << endl; }
	}
void cariKaryawan(){ // MENCARI DATA KARYAWAN 
    bacaKaryawan();
    int pilihan;
    cout << "\nCari berdasarkan :\n";
    cout << "1. ID\n";
    cout << "2. Nama\n";
    cout << "Pilih Menu : ";
    cin >> pilihan;
    if(pilihan == 1){
        int id;
        bool ditemukan = false;
        int nomor = 1;
        cout << "Masukkan ID karyawan : ";
        cin >> id;
        for(int i = 0; i < jumlahKaryawan; i++){
            if(karyawan[i].id == id){
            if(!ditemukan){
            cout << "\n------------ Data Ditemukan ------------\n"; }
            cout << "Data ke-" << nomor << endl;
            cout << "ID   : " << karyawan[i].id << endl;
            cout << "Nama : " << karyawan[i].nama << endl << endl;
            ditemukan = true;
            nomor++;
			}
		}if(!ditemukan){
			cout << "\n------- Karyawan Tidak Ditemukan -------\n";
		}
	}else if(pilihan == 2){
        char nama[50];
        int nomor = 1;
        bool ditemukan = false;
        cout<<"Masukkan Nama Karyawan : ";
        cin.ignore();
        cin.getline(nama, 50);
        for(int i = 0; i < jumlahKaryawan; i++){
			if(strcmp(karyawan[i].nama,nama) == 0){
			if(!ditemukan){
            cout << "\n------------ Data Ditemukan ------------\n"; }
            cout << "Data ke-" << nomor << endl;
            cout << "ID   : " << karyawan[i].id << endl;
            cout << "Nama : " << karyawan[i].nama << endl << endl;
            ditemukan = true;
            nomor++;
			}
		}if(!ditemukan){
			cout << "Karyawan Tidak Ditemukan\n";
			}
	}else{
		cout << "-------- Pilihan Menu Tidak Ada --------\n"; }
	}
void bubbleSortID(){ //BUBBLE SORT ID KARYAWAN ASC
    for(int i = 0; i < jumlahKaryawan - 1; i++){
        for(int j = 0; j < jumlahKaryawan - i - 1; j++){
            if(karyawan[j].id > karyawan[j+1].id){
                Karyawan temp = karyawan[j];
                karyawan[j] = karyawan[j+1];
                karyawan[j + 1] = temp;
            }
        }
    }
}
void bubbleSortNamaKaryawan(){ //BUBBLE SORT ID KARYAWAN DESC
    for(int i = 0; i < jumlahKaryawan - 1; i++){
        for(int j = 0; j < jumlahKaryawan - i - 1; j++){
            if(strcmp(karyawan[j].nama,karyawan[j + 1].nama) > 0){
                Karyawan temp = karyawan[j];
                karyawan[j] = karyawan[j + 1];
                karyawan[j + 1] = temp;
            }
        }
    }
}
int partitionID(int low, int high){ //PARTISION ID KARYAWAN
    int pivot = karyawan[high].id;
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(karyawan[j].id > pivot){
            i++;
            Karyawan temp = karyawan[i];
            karyawan[i] = karyawan[j];
            karyawan[j] = temp;
        }
    }
    Karyawan temp = karyawan[i + 1];
    karyawan[i + 1] = karyawan[high];
    karyawan[high] = temp;
    return i + 1;
}
void quickSortID(int low, int high){ // QUICK SORT ID KARYAWAN
    if(low < high){
        int pi = partitionID(low,high);
        quickSortID(low,pi - 1);
        quickSortID(pi + 1,high);
    }
}
int partitionNama(int low, int high){ //PARTISI NAMA KARYAWAN
    char pivot[50];
    strcpy(pivot,karyawan[high].nama);
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(strcmp(karyawan[j].nama,pivot) > 0){
            i++;
            Karyawan temp = karyawan[i];
            karyawan[i] = karyawan[j];
            karyawan[j] = temp;
        }
    }
    Karyawan temp = karyawan[i + 1];
    karyawan[i + 1] = karyawan[high];
    karyawan[high] = temp;
    return i + 1;
}	
void quickSortNama(int low, int high){
    if(low < high){
        int pi = partitionNama(low, high);
        quickSortNama(low,pi - 1);
        quickSortNama(pi + 1, high);
    }
}
void urutKaryawan(){ // MENGURUTKAN KARYAWAN
    bacaKaryawan();
    int berdasarkan, metode;
    cout << "\nUrutkan berdasarkan:\n";
    cout << "1. ID\n";
    cout << "2. Nama\n";
    cout << "Pilih : ";
    cin >> berdasarkan;
    cout << "\nMetode urut:\n";
    cout << "1. Ascending (Bubble Sort)\n";
    cout << "2. Descending (Quick Sort)\n";
    cout << "Pilih : ";
    cin >> metode;
    if(berdasarkan == 1 && metode == 1){
        bubbleSortID(); }
    else if(berdasarkan == 2 && metode == 1){
        bubbleSortNamaKaryawan(); }
    else if(berdasarkan == 1 && metode == 2){
        quickSortID(0, jumlahKaryawan - 1); }
    else if(berdasarkan == 2 && metode == 2){
        quickSortNama(0, jumlahKaryawan - 1); }
    else{
        cout << "-------- Pilihan Menu Tidak Ada --------\n";
        return; }
		cout << "\n--- Data Karyawan Setelah Diurutkan ---";
		cout << "\n---------------------------------------\n";
		cout << "           DATA KARYAWAN\n";
		cout << "---------------------------------------\n";
		cout << left << setw(5) << "No"
		<< setw(10) << "ID"
		<< setw(30) << "Nama" << endl;
		cout << "---------------------------------------\n";
		for(int i = 0; i < jumlahKaryawan; i++){
			cout << left << setw(5) << i+1 << setw(10) << karyawan[i].id
			<< setw(30) << karyawan[i].nama << endl; 
	}
}
void tambahBarang(){ // MENAMBAH DATA BARANG
    bacaBarang();
    int n;
    cout << "Masukkan Jumlah Barang : ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
		cout << "\nBarang ke - " << i+1 << endl;
        cout << "Nama : ";
		cin.getline(barang[jumlahBarang].nama,50);
        cout << "Harga : ";
        cin >> barang[jumlahBarang].harga;
        cout << "Stok : ";
        cin >> barang[jumlahBarang].stok;
        cin.ignore();
        jumlahBarang++;
    } cout << "-------- Data Berhasil Ditambah --------\n";
    simpanBarang();
}
void bubbleSort(){ //BUBLE SORT BARANG ASC
    for(int i = 0; i < jumlahBarang - 1; i++){
        for(int j = 0; j < jumlahBarang - i - 1; j++){
            if(barang[j].harga > barang[j+1].harga){
                Barang temp = barang[j];
                barang[j] = barang[j+1];
                barang[j+1] = temp;
            }
        }
    }
}
int partition(int low, int high){ //PARTISI DATA BARANG BERDASARKAN HARGA
    int pivot = barang[high].harga;
    int i = low - 1;
    for(int j= low; j < high; j++){
        if(barang[j].harga > pivot){
            i++;
            Barang temp = barang[i];
            barang[i] = barang[j];
            barang[j] = temp;
        }
    }
    Barang temp = barang[i+1];
    barang[i+1] = barang[high];
    barang[high] = temp;
    return i+1;
}
void quickSort(int low, int high){ // QUICK SORT BARANG DESC
    if(low < high){
        int pi = partition(low,high);
        quickSort(low,pi - 1);
        quickSort(pi + 1, high);
    }
}
void bubbleSortNama(){
    for(int i = 0; i < jumlahBarang - 1; i++){
        for(int j = 0; j < jumlahBarang - i - 1; j++){
            if(strcmp(barang[j].nama, barang[j+1].nama) > 0){
                Barang temp = barang[j];
                barang[j] = barang[j+1];
                barang[j+1] = temp;
            }
        }
    }
}
void lihatBarang(){ // MELIHAT DATA BARANG 
    bacaBarang();
    if(jumlahBarang == 0){
        cout << "Data Kosong\n";
        return;
    }
    int pilih;
    cout << "\nLihat Menu Berdasarkan : \n";
    cout << "1. Ascending (Bubble Sort)\n";
    cout << "2. Descending (Quick Sort)\n";
    cout << "Pilih menu : ";
    cin >> pilih;
     if (pilih < 1 || pilih > 2) {
		cout << "-------- Pilihan Menu Tidak Ada --------\n";
		return ; }
    if(pilih == 1) { bubbleSort();
    }else{ quickSort(0, jumlahBarang - 1);}
    cout << "\n----------------------------------------\n";
    cout << "             DATA BARANG\n";
    cout << "----------------------------------------\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama"
     << setw(10) << "Harga"
     << setw(10) << "Stok" << endl;
     cout << "----------------------------------------\n";
     for(int i = 0; i < jumlahBarang; i++){
     cout << left << setw(5) << i + 1 << setw(20) << barang[i].nama
         << setw(10) << barang[i].harga
         << setw(10) << barang[i].stok << endl;
	}
}
void sequentialSearch(){ // SEQUENTIAL SEARCH DATA BARANG
	bacaBarang();
    char cari[50];
    bool ditemukan = false;
    cin.ignore();
    cout << "\nMasukkan Nama Barang : ";
    cin.getline(cari,50);
    cout << "\n----------------------------------------\n";
    cout << "            HASIL PENCARIAN\n";
    cout << "----------------------------------------\n";
    cout << left << setw(20) << "Nama"
         << setw(10) << "Harga"
         << setw(10) << "Stok" << endl;
    cout << "----------------------------------------\n";
    for(int i = 0; i < jumlahBarang; i++){
        if(strcmp(barang[i].nama,cari) == 0){
            cout << left << setw(20) << barang[i].nama
                 << setw(10) << barang[i].harga
                 << setw(10) << barang[i].stok << endl;
            ditemukan = true;
        }
    }
    if(ditemukan){
		cout << "----------------------------------------\n";
        cout << "----------- Barang Ditemukan -----------\n";
    }else{
        cout << "-------- Barang Tidak Ditemukan --------\n";
    }
}
int binarySearch(char cari[]){
    int kiri = 0;
    int kanan = jumlahBarang - 1;
    while(kiri <= kanan){
        int tengah = (kiri + kanan)/2;
        int hasil = strcmp(barang[tengah].nama,cari);
        if(hasil == 0){
            return tengah;
        }else if(hasil < 0){
            kiri = tengah + 1;
        }else{
            kanan = tengah - 1;
        }
    } return -1;
}
void binarySearchBarang(){ // BINARY SEARCH DATA BARANG
    bacaBarang();
    bubbleSortNama(); 
    char cari[50];
    cin.ignore();
    cout << "\nMasukkan Nama Barang : ";
    cin.getline(cari,50);
    int index = binarySearch(cari);
    cout << "\n----------------------------------------\n";
    cout << "            HASIL PENCARIAN\n";
    cout << "----------------------------------------\n";
    cout << "Nama                Harga     Stok\n";
    cout << "----------------------------------------\n";
    if(index != -1){
        int i = index;  // cek ke kiri
        while(i >= 0 && strcmp(barang[i].nama,cari) == 0){
            cout << left << setw(20) << barang[i].nama
                << setw(10) << barang[i].harga
                << setw(10) << barang[i].stok << endl;
            i--;
              cout << "----------------------------------------\n";
             cout << "----------- Barang Ditemukan -----------\n";
        } 
        i = index + 1; // cek ke kanan
        while(i < jumlahBarang && strcmp(barang[i].nama,cari) == 0){
            cout << left << setw(20) << barang[i].nama
                << setw(10) << barang[i].harga
                << setw(10) << barang[i].stok<<endl;
            i++;
            cout <<"----------------------------------------\n";
            cout << "----------- Barang Ditemukan -----------\n";
        }
    }else{
        cout << "-------- Barang Tidak Ditemukan --------\n";
    }
}
void editBarang(){ // EDIT DATA BARANG
    bacaBarang();
    char cari[50];
    cin.ignore();
    cout << "Nama barang yang ingin diedit : ";
    cin.getline(cari,50);
    for(int i = 0; i < jumlahBarang;i++){
        if(strcmp(barang[i].nama,cari) == 0){
            cout << "\n----------------------------------------\n";
            cout << "              DATA LAMA\n";
            cout << "----------------------------------------\n";
            cout << left << setw(20) << "Nama"
                 << setw(10) << "Harga"
                 << setw(10) << "Stok" << endl;
            cout << "----------------------------------------\n";
            cout << left << setw(20) << barang[i].nama
                 << setw(10) << barang[i].harga
                 << setw(10) << barang[i].stok << endl;
            cout << "\nNama baru  : ";
            cin.getline(barang[i].nama,50);
            cout << "Harga baru : ";
            cin >> barang[i].harga;
            cout << "Stok baru  : ";
            cin >> barang[i].stok;
            simpanBarang();
            cout << "\n--------- Data Berhasil Diubah ---------\n";
            return;
        }
    }
    cout << "\n-------- Barang Tidak Ditemukan --------\n";
}
void cariBarang(){ // MENCARI DATA BARANG
    bacaBarang();
    int metode;
    cout << "\nPilih Metode Pencarian : \n"; 
    cout << "1. Sequential\n";
    cout << "2. Binary\n";
    cout << "Pilih Metode : ";
    cin >> metode;
    if(metode == 1){
        sequentialSearch();
    }else if(metode == 2){
		binarySearchBarang();
		}else{
            cout << "\n-------- Pilihan Menu Tidak Ada --------\n";
        }
    }
void menuAdmin(){ //MENU ADMIN
	int pilihkaryawan;
	do{
	 cout << "\n----------------------------------------\n";
	 cout << "               HALO ADMIN\n";
	 cout << "----------------------------------------\n";
	 cout << "1. Tambah Data Karyawan\n";
	 cout << "2. Lihat Data Karyawan\n";
	 cout << "3. Searching Data Karyawan\n";
	 cout << "4. Sorting Data Karyawan\n";
	 cout << "5. Logout\n";
	 cout << "----------------------------------------\n";
	 cout << "Pilih Menu : ";
	 cin >> pilihkaryawan;
	 if(pilihkaryawan >= 1 && pilihkaryawan <= 5){
			if (pilihkaryawan == 1){
				tambahKaryawan();
			}if(pilihkaryawan == 2){
				dataKaryawan();
			}if(pilihkaryawan == 3){
				cariKaryawan();
			}if(pilihkaryawan == 4){
				urutKaryawan();
			}if(pilihkaryawan == 5){
				cout << "Terimakasih, Kembali ke Menu Utama\n\n";
			}
		}else{
				cout << "-------- Pilihan Menu Tidak Ada --------\n";
				}
	}while (pilihkaryawan != 5);
}
void menuKaryawan(){ //MENU KARYAWAN
	 int pilihkaryawan;
	 do{
	 cout << "\n----------------------------------------\n";
	 cout << "             HALO KARYAWAN\n";
	 cout << "----------------------------------------\n";
	 cout << "1. Tambah Data Barang\n";
	 cout << "2. Lihat Data Barang\n";
	 cout << "3. Edit Data Barang\n";
	 cout << "4. Cari Data Barang\n";
	 cout << "5. Logout\n";
	 cout << "----------------------------------------\n";
	 cout << "Pilih Menu : ";
	 cin >> pilihkaryawan;
	 if(pilihkaryawan >= 1 && pilihkaryawan <= 5){
			if (pilihkaryawan == 1){
				tambahBarang();
			}if(pilihkaryawan == 2){
				lihatBarang();
			}if(pilihkaryawan == 3){
				editBarang();
			}if(pilihkaryawan == 4){
				cariBarang();
			}if(pilihkaryawan == 5){
				cout << "Terimakasih, Kembali ke Menu Utama\n\n";
			}
		}else {
				cout << "-------- Pilihan Menu Tidak Ada --------\n";
				}
	 }while(pilihkaryawan != 5);
}
void keluar(){ // MENU KELUAR
	cout << "Terima Kasih Selamat Datang Kembali\n";
}
int main(){
	do { // MENU UTAMA
		cout << "========================================\n";
		cout << "        WELCOME TO COCOA HEAVEN\n";
		cout << "========================================\n";
		cout << "1. Login Admin \n";
		cout << "2. Karyawan \n";
		cout << "3. Keluar  \n";
		cout << "========================================\n";
		cout << "Pilih Menu : ";
		cin >> menuu.input;
		if(menuu.input >= 1 && menuu.input <= 3){
			if (menuu.input == 1){
				if(login()){ 
					menuAdmin();} 
			}if(menuu.input == 2){
				menuKaryawan();
			}if(menuu.input == 3){
				keluar(); }
		}else{
			cout << "\n-------- Pilihan Menu Tidak Ada --------\n\n";
		    }
		}while(menuu.input != 3);
	}
