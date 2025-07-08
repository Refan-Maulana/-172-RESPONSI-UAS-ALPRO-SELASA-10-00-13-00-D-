#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct tiketPesawat {
	string kode,maskapai,bandara_asal,bandara_tujuan,tanggal,jam_kedatanggan,jam_keberangkatan,harga;
};

vector<tiketPesawat>daftartiket;

void muatData() {
    ifstream file("dataTiket.txt");
    if (!file) return;

    string kode,maskapai,bandara_asal,bandara_tujuan,tanggal,jam_kedatanggan,jam_keberangkatan,harga;
    while (getline(file, kode)) {
        getline(file, maskapai);
		getline(file, harga);
		getline(file,bandara_asal);
		getline(file,bandara_tujuan);
		getline(file,jam_kedatanggan);
		getline(file,jam_keberangkatan);
		getline(file,tanggal);
        daftartiket.push_back({kode, maskapai, harga, bandara_asal, bandara_tujuan, jam_kedatanggan, jam_keberangkatan, tanggal});
    }
    file.close();
}

void simpanData() {
    ofstream file("dataTiket.txt");
    for (auto t : daftartiket){
    	file << t.kode <<endl;
    	file << t.maskapai <<endl;
    	file << t.harga <<endl;
    	file << t.bandara_asal <<endl;
    	file << t.bandara_tujuan <<endl;
    	file << t.jam_kedatanggan <<endl;
    	file << t.jam_keberangkatan <<endl;
    	file << t.tanggal <<endl;
	}
}

void tampilkanData() {
    if (daftartiket.empty()) {
        cout << "Tidak ada data Tiket.\n";
        return;
    }

    cout << "\n=== Data Tiket ===\n";
    for (int i = 0; i < daftartiket.size(); ++i) {
        cout << i + 1 << " Kode penerbangan : " << daftartiket[i].kode << endl; 
        cout << " Nama maskapai : " << daftartiket[i].maskapai << endl;
        cout << " Harga Tiket : " << daftartiket[i].harga << endl;
        cout << " Bandara asal : " << daftartiket[i].bandara_asal <<endl;
        cout << " Bandara tujuan : " << daftartiket[i].bandara_tujuan <<endl;
        cout << " Jam keberangkataan : " << daftartiket[i].jam_keberangkatan <<endl;
        cout << " Jam kedatanggan  : " << daftartiket[i].jam_kedatanggan <<endl;
        cout << " tanggal Keberangkatan : " << daftartiket[i].tanggal <<endl;
    }
}


void tambahData() {
	tiketPesawat t;
    cout << "Masukkan kode penerbangan: ";
    cin >> t.kode;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan Nama Maskapai: ";
    getline(cin, t.maskapai);
    cout<<"Masukan Harga : ";
    cin.ignore();
    getline(cin,t.harga);
    cout<<"Masukan Bandara awal : ";
    cin.ignore();
    getline(cin, t.bandara_asal);
    cout<<"Masukan Bandara Akhir : ";
    cin.ignore();
    getline(cin, t.bandara_tujuan);
    cout<<"Masukan jam Keberangkatan : ";
    cin.ignore();
    getline(cin, t.jam_keberangkatan);
    cout<<"Masuakn jam kedatanggan : ";
    cin.ignore();
    getline(cin, t.jam_kedatanggan);
    cout<<"Masukan tanggal penerbangan : ";
    cin.ignore();
    getline(cin, t.tanggal);
	daftartiket.push_back(t);
    simpanData();
	
    cout << "Data berhasil ditambahkan!\n";
}

void editData() {
    tampilkanData();
    int index;
    int pil;
    cout << "Pilih nomor data yang ingin diedit: ";
    cin >> index;
    if (index < 1 || index > daftartiket.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Masukan nomor brapa yang ingin anda edit : ";
	cin >> pil;
	switch(pil){
		case 1: 
		 cout << "Masukkan kode penerbangan baru: ";
		 cin.ignore();
    	getline(cin, daftartiket[index - 1].kode);
    	//simpanData();
    	break;
    	
    	case 2: 
		cout << "Masukkan Nama Maskapai baru: ";
		cin.ignore();
    	getline(cin, daftartiket[index - 1].maskapai);
    	//simpanData();
    	break;
    	
    	case 3:
    		cout<<"Masukan Harga baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].harga);
    		//simpanData();
    		break;
    		
    	case 4:
    		cout<<"Masukan bandara awal baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].bandara_asal);
    		break;
    		
    	case 5:
    		cout<<"Masukan bandara tujuan baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].bandara_tujuan);
    		break;
    		
    	case 6:
    		cout<<"Masukan jam keberangkatan baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].jam_keberangkatan);
    		break;
    	
    	case 7:
    		cout<<"Masukan jam kedatanggan baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].jam_kedatanggan);
    		break;
    		
    	case 8:
    		cout<<"Masukan tanggal tiket baru : ";
    		cin.ignore();
    		getline(cin, daftartiket[index - 1].tanggal);
    		break;
    		
    	default:
    		cout<<"Pilihan tidak valit ";
	}
   
   
   
    simpanData();
    cout << "Data berhasil diubah!\n";
}

void hapusData() {
    tampilkanData();
    int index;
    cout << "Pilih nomor data yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > daftartiket.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    daftartiket.erase(daftartiket.begin() + index - 1);
    simpanData();
    cout << "Data berhasil dihapus!\n";
}

void cari_tiket(){
	string tujuan;
	cout<<"Masukan tujuan penerbangan anda dari? :";
	cin>>tujuan;	
		
	
}

void urut_kecil(){
	
}

void urut_besar(){
	
}


int main() {
    muatData();

    int pilihan;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Data Tiket\n";
        cout << "2. Edit Data Tiket\n";
        cout << "3. Hapus Data Tiket\n";
        cout << "4. Tampilkan Data Tiket\n";
        cout << "5. urutkan data\n";
        cout << "6. cari tiket berdasarkan rute\n";
		cout << "7. cari tiket berdasarkan maskapai\n";
		cout << "8. cari tiket berdasarkan harga\n";   
        cout << "9. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                editData();
                break;
            case 3:
                hapusData();
                break;
            case 4:
                tampilkanData();
                break;
            case 5:
                break;
            case 6:
            	break;
            case 7:
            	break;
            case 8:
            	break;
            case 9:
            	cout << "Keluar dari program...\n";
            	break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 9);

    return 0;
}
