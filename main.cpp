#include <iostream>
#include <fstream>

#define garis "#=============================================================#"

using namespace std;

//-------------------------------tempat variabel
struct pesanan {
//	masih ada rencana untuk merubah nama variabel supaya lebih mudah dipahami
	
//	int input pilihan
//	merubah variabel type menjadi tipe utk konsistensi
	int pil, tipe, jam ;
//	pil = pilihan tujuan---------------
//	tipe = pilihan kelas penerbangan------
//	jam = pilihan jam
	
//	int input jumlah
	int tikets, jk, jta;
//	tikets = jlh tiket dibeli==========
//	jk = jumlah koper yang diangkut
//	jta = jumlah tambahan angkutan
	
//	int tampilan
	int h;
//	h = tampilan harga tiket================
	
//	int total
	int hrg[3];
//  hrg = harga total
	
	//string input
	string nama, umur;
//	nama = nama pelanggan
//	alamat = alamat pelanggan
//	umur = umur pelanggan
	
	//string tampilan
//	jika ingin otak-atik datanya silahkan asalkan masih masuk akal
	
	const string tk[2][2] = {
		{"Economy Biasa", "1.900.000"},
		{"Economy Premium", "3.000.000"}
	}, 
	
	tt[5] = {
	"Batam - Jakarta", 
	"Batam - Jambi", 
	"Batam - Medan", 
	"Batam - Surabaya", 
	"Batam - Bali"
	},
	
	tj[5] = {
	"10.30 - 12.30", 
	"12.45 - 14.45", 
	"15.00 - 17.00", 
	"17.15 - 19.15", 
	"19.30 - 21.30"
	},
	
	e = "Salah Input";
//	tk = tampilan kelas-----------
//	tt = tampilan tujuan-------
//	tj = tampilan jam------------
//	e = tampilan error
	
	//char input
	char ja, ta;
//	ja = jasa angkut (y/t)
//	ta = tambahan angkutan (y/t)
};





//-------------------------------operasi
//========total pembayaran
int totalawal(int a, int b, int c) {
	pesanan tiket;
	long total;
	int tax;
	total = a + b + c; 
	return total;
}

int pajak (int a,int b,int c) {
	pesanan tiket;
	int tax;
	tax = totalawal(a, b, c)*0.05;
	return tax;
}

int total (int a,int b,int c) {
	pesanan tiket;
	long hargatotal;
	int tax;
	
	hargatotal = totalawal(a, b, c) + pajak(a, b, c);
	return hargatotal;
}

//========tipe kelas
string kelas(int tipe) {
	pesanan tiket;
	string tk;
	switch (tipe){
		case 1: tk = tiket.tk[0][0]; break;
		case 2: tk = tiket.tk[1][0]; break;
		default : tk = tiket.e;
	}
	return tk;
}

//========tipe tujuan
string tujuan(int pil){
	pesanan tiket;
	string tt;
	switch (pil){
		case 1: tt = tiket.tt[0]; break;
		case 2: tt = tiket.tt[1]; break;
		case 3: tt = tiket.tt[2]; break;
		case 4: tt = tiket.tt[3]; break;
		case 5: tt = tiket.tt[4]; break;
		default : tt = tiket.e; 
	}
	return tt;
}

//========tipe harga
int harga(int tipe) {
	pesanan tiket;
	int h;
	switch (tipe) {
		case 1: h=1900000; break;
		case 2: h=3000000; break;
		default: h = 0;
	}
	return h;
}

//========tipe jam penerbangan
string jam_terbang(int jam) {
	pesanan tiket;
	string tj;
	switch (jam){
		
//		bagian jam baru diubah
		case 1: tj = tiket.tj[0]; break;
		case 2: tj = tiket.tj[1]; break;
		case 3: tj = tiket.tj[2]; break;
		case 4: tj = tiket.tj[3]; break;
		case 5: tj = tiket.tj[4]; break;
		default : tj = tiket.e; 
	}
	
	return tj;
}




//rencananya ingin menggunakan fungsi public dan private tapi masih belum dipelajari di algo sem 1
//-------------------------------tampilan & fungsi2 dari aplikasi
//========menu beranda
void menu() {
	pesanan tiket;
	
	system ("cls");
	cout<<garis<<endl;
	cout<<"Form Pemesanan"<<endl;
	cout<<garis<<endl;
	cout<<"Daftar Tujuan"<<endl;
	
//	perulangan daftar tiket
	for (int i=0; i<5; i++) {
		cout<<"|"<<i+1<<". "<<tiket.tt[i]<<" |" <<endl;
	}
	
	cout<<garis<<endl;
	cout<<"Masukkan Nama Anda : "; cin>>tiket.nama;
	cout<<"Masukkan Pilihan Tujuan Anda (1-5): "; cin>>tiket.pil;
	cout<<garis<<endl;
	cout<<"Tipe  : " <<endl;
	
	cout<<"1. "<<tiket.tk[0][0]<<" ("<<tiket.tk[0][1]<<"/org)" <<endl;
	cout<<"2. "<<tiket.tk[1][0]<<" ("<<tiket.tk[1][1]<<"/org)" <<endl;
	cout<<"Masukkan Pilihan Kelas Penerbangan Anda: "; cin>>tiket.tipe;
	
	cout<<"Jumlah Tiket yang ingin dibeli: "; cin>>tiket.tikets;
	
	pesanan customer[tiket.tikets];
	
	for (int i=0; i<tiket.tikets; i++){
		cout<<"\nNama : "; cin>>customer[i].nama;
		cout<<"Umur : "; cin>>customer[i].umur;
	}
	
	system ("cls");
	
	cout<<garis<<endl;
	cout<<"|Jam Penerbangan : |" <<endl; 
	
//	perulangan daftar jam penerbangan
	for (int i=0; i<5; i++) {
		cout<<"|"<<i+1<<". "<<tiket.tj[i]<<" |" <<endl;
	}
	
	cout<<garis<<endl;
	cout<<"Masukkan Pilihan Jam Penerbangan Anda (1-5): "; cin>>tiket.jam;
	
	cout<<garis<<endl;
	cout<<"Butuh Jasa Angkut Barang ? (y/t): "; cin>>tiket.ja;
	
//	menambahkan nilai 'Y' utk kemudahan
	if (tiket.ja == 'y' || tiket.ja == 'Y'){
		cout<<"Koper/50rb : "; cin>>tiket.jk;
	} else {
		tiket.jk=0;
	}
	
	cout<<"Ada Tambahan Angkutan Lagi ? (y/t): "; cin>>tiket.ta;
	
//	menambahkan nilai 'Y' utk kemudahan
	if (tiket.ta == 'y' || tiket.ta == 'Y'){
		cout<<"Tambah berapa barang? : "; cin>>tiket.jta;
	} else {
		tiket.jta=0;
	}
	
	system ("cls");
	cout<<garis<<endl;
	cout<<"Terima Kasih " << tiket.nama << " telah memilih Penerbangan dengan Ironman 3000"<<endl;
	
//	menjalankan fungsi tujuan berdasarkan input pil
	cout<<"Tujuan Keberangkatan adalah: " << tujuan(tiket.pil) << " dengan total " <<
	
//	menjalankan fungsi kelas berdasarkan input tipe
	tiket.tikets << " tiket "<< kelas(tiket.tipe) <<endl;
	
//	menjalankan fungsi jam_terbang berdasarkan input jam
	cout<<"Jam Penerbangan anda: " << jam_terbang(tiket.jam)<<endl;
	
	cout<<"\n____________________ DAFTAR PEMESAN  _____________________\n";
    cout<<garis<<endl;
    for (int i=0; i<tiket.tikets; i++){
		cout<<"Nama : "<<customer[i].nama<<"	";
		cout<<"Umur : "<<customer[i].umur<<endl;
		cout<<endl;
	}
	
//	menjalankan fungsi harga berdasarkan input tipe
	tiket.hrg [0]= harga(tiket.tipe) * tiket.tikets;
	tiket.hrg [1]= tiket.jk * 50000;
	tiket.hrg [2]= tiket.jta * 50000;
	
//	menjalankan fungsi total
	cout<<"Total Awal	: Rp "<<totalawal(tiket.hrg[0], tiket.hrg[1], tiket.hrg[2])<< endl;
	cout<< "Pajak		: Rp "<<pajak(tiket.hrg[0], tiket.hrg[1], tiket.hrg[2])<< endl;
	cout<<"Total Akhir	: Rp "<< total(tiket.hrg[0],tiket.hrg[1],tiket.hrg[2]) << endl; 
	cout<<garis<<endl;
	
//	ofstream myfile ("example.txt");
//	
//	if (myfile.is_open())
//	{
//	    myfile << "Tujuan Keberangkatan adalah: " << tujuan(tiket.pil) << " dengan total "<<  tiket.tikets << " tiket "<< kelas(tiket.tipe) <<endl;
//	    myfile << "Jam Penerbangan anda: " << jam_terbang(tiket.jam) <<endl;
//	    
//	    myfile <<"Total Biaya Keseluruhan: " << total(tiket.hrg[0],tiket.hrg[1],tiket.hrg[2]) << "setelah kena pajak "<<pajak(tiket.hrg[0], tiket.hrg[1], tiket.hrg[2])<<"."<< endl;
//		myfile <<garis<<endl;
//	    myfile.close();
//	    
//	    
//	}
//	else cout << "Unable to open file";
}

void aplikasi() {
	menu();
	
}







//-------------------------------bagian utama aplikasi
int main(){
	int pilmenu, rating;
	pesanan tiket;
	char tanya, ulang;
	
	awal:
		system("cls");
		cout<<"Selamat Datang di Ironman 3000 2022!" <<endl;
		cout<<garis<<endl;
		cout<<"1. Pembelian Tiket Pesawat."<<endl;
		cout<<"2. Tutup Aplikasi."<<endl;
		cout<<"Pilih Apa Yang Akan Anda Gunakan : ";cin>>pilmenu;
		
		switch(pilmenu) {
			case 1:
				atas:
					
				aplikasi();
				cout<<"Apakah Anda Ingin Memesan Tiket Lagi (y/t)? ";cin>>tanya;
				
				if(tanya=='y' || tanya == 'Y'){
					goto atas;
				} else {
					
					cout<<"Berikan Rating Anda Untuk Aplikasi Ini(1-5): ";cin>>rating;
					if (rating <=3){
						cout<<garis<<endl;
						cout<<"Kami Minta Maaf Atas Ketidaknyamanan Anda"<<endl;
						cout<<"Kami akan Terus Mengembangkan Aplikasi Ini"<<endl;
						cout<<"Terima Kasih Atas Feedback anda dan Silahkan Datang Kembali";
					}
					else if (rating <=5){
						cout<<garis<<endl;
						cout<<"Terima Kasih Sudah Menggunakan Aplikasi Ini"<<endl;
						cout<<"Kedepannya Tolong Terus Menggunakan Aplikasi Ini"<<endl;
						cout<<"Terima Kasih Atas Feedback Anda dan Silahkan Datang Kembali";
				}
//				tidak ada else if karena masih bug
				break;
				
			case 2:
				exit(0);
				break;
				
			default:
				cout<<"Tidak Ada Pilihan Tersebut"<<endl;
				cout<<"Apakah Anda Ingin Mengulang(Y/T)?: "; cin>>ulang;
				if (ulang == 'y'|| ulang == 'Y'){
					goto awal;
				} else {
					cout<<"Terima Kasih Sudah Menggunakan Aplikasi Ini."<<endl;
					exit(0);
				}
//				tidak ada else if karena masih bug
				break;
		}
	}
}
