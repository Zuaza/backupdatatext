#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<iomanip>
#include<conio.h>
using namespace std;

class item{
    //Data members
private:
    int nis;
    char jenis[20];
	char akun[60];
	char password[80];
    //member function
public:
    void put_item(void);
    void get_item(void);
    int get_nis (void){
        return nis;
    };

    void inputCode(){
    while (!(cin >> nis))
        {
            cout << "\n\t\t\t\t!!!! ERROR !!!!";
            cin.clear();
            cin.ignore(132, '\n');
        }
}

};

//Member fungtion class item di luar class

void item::get_item(void){
	    cout<<"\n\n\n\t\t\t\t\t\t+++ TAMBAH ITEM +++"<<endl;
		cout << "\n\t\t\t\t\tNo\t   :  ";
        inputCode();
        //fflush(stdin);
        cout<<"\t\t\t\t\tJenis Akun :  "; cin>>jenis;
        cout << "\t\t\t\t\tAkun\t   :  "; cin>>akun;
        cout << "\t\t\t\t\tPassword   :  "; cin>>password;
    }

void item::put_item(void){
    cout<<"\t\t\t "<<nis<<"     "<<jenis<<"\t    "<<akun<<"   "<<password<<endl; //setup dengan lebar field membutuhkan library iomanip
}

//Fuction Prototype
void addRecord(void);
void showAll(void);
void showRecord(void);
void deleteRecord(void);
void modifRecord(void);
void sourceCode(void);

//Global Declaration
item it;        //membuat object item
fstream file;   //membuat object fstream

void loading_compled(){
	//loading
	   for(int w=0;w<=100;w++){
        cout<<endl<<"\n\n\t\t\t\t\t         Loading . . . . "<<w<<"%"<<endl;
        system("cls");
        }
        cout<<"\n\n\t\t\t\t\tLOADING COMPLETE"<<endl;
}

int main() {    
   int i;  
   string pass_input, user_input;  
   
   cout << "\n\n\t\t\t\t\t==================================\n";    
   cout << "\t\t\t\t\t|\t    L O G I N        \t |\n";    
   cout << "\t\t\t\t\t==================================\n\n";  
   
   string username ="user";    
   string password = "user123";    
   string login = "block";    
   i = 1;    
   
   do {        
       //login
       cout << "\t\t\t\t\tUsername = "; cin>>user_input;        
       cout << "\t\t\t\t\tPassword = "; cin>>pass_input;   
	        
       if (user_input == username && pass_input == password) {  
	   
	       //start 
	       loading_compled();   
		    
		int option;
        while(1){
        system("cls");
        
        cout<<"\n\t\t\t\t-----------------------------------------------"<<endl;
        cout<<"\t\t\t\t|\t\t     MENU\t              |"<<endl;
        cout<<"\t\t\t\t-----------------------------------------------"<<endl;
        cout<<"\t\t\t\t|\t     1. Tambah Record Data\t      |"<<endl;
        cout<<"\t\t\t\t|\t     2. Tampil Semua Data\t      |"<<endl;
        cout<<"\t\t\t\t|\t     3. Cari Data Tertentu  \t      |"<<endl;
        cout<<"\t\t\t\t|\t     4. Hapus Akun  \t\t      |"<<endl;
        cout<<"\t\t\t\t|\t     5. Keluar\t\t\t      |"<<endl;
        cout<<"\t\t\t\t|\t-----\t\t\t-----\t      |"<<endl;
        cout<<"\t\t\t\t|\t        00Surce Code00\t\t      |"<<endl;
        cout<<"\t\t\t\t|\t-----\t\t\t-----\t      |"<<endl;
		cout<<"\t\t\t\t-----------------------------------------------"<<endl;
        cout<<"\n\t\t\t\tMasukkan nomor opsi: "; cin>>option;
        switch(option){
            case 1:{
                addRecord();
                cout<<"\n\n\t\t\t\tTekan sembarang untuk kembali ke menu ...";
                getch(); //butuh library conio.h
                break;
            }
            case 2:{
                cout<<"\n\t\t       -----------------------------------------------------------------"<<endl;
                cout<<"\t\t     "<<setw(6)<<"  | No "<<"| Jenis Akun  |"<<"            Akun               "<<"|  Password  |"<<endl;
                cout<<"\t\t       -----------------------------------------------------------------"<<endl;
                showAll();
                cout<<"\n\n\t\t\t\tTekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 3:{
                showRecord();
                cout<<"\n\n\t\t\t\tTekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 4:{
                deleteRecord();
                cout<<"\n\n\t\t\t\tTekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
            case 5:{
                exit(0);
            }
            case 00:{
            	sourceCode();
            	getch();
				break;
			}
            default:{
                cout<<"\t\t\tOpsi pilihan tidak ada, Tekan sembarang untuk kembali ke menu ...";
                getch();
                break;
            }
        }
    }
		    
		       
           i = 4;
           login = "berhasil";        }  
       //login gagal
       else {
	               
       for(int w=0;w<20;w++){
        cout<<endl<<"\n\n\t\t\t\t\t         Loading . . . . "<<w<<"%"<<endl;
        system("cls");
        }
        
       system("cls");
       cout << "\n\t\t\t\t\t==================================\n";    
       cout << "\t\t\t\t\t|    Username / Password salah   |\n";    
       cout << "\t\t\t\t\t==================================\n";
	   cout << "\t\t\t\t\t      silahkan ulangi lagi... \n\n";
           i = i +1;
       }   
    } while (i <= 3);
	
    if(login != "berhasil"){
       cout<<"\t\t\t\t\tAnda telah 3x salah login.\n";       
       cout<<"\t\t\t\t\tSilahkan coba beberapa saat lagi. Terima Kasih..\n\n";      
	}   
   return 0;


}

void addRecord(){
    char ch = 'y';
    file.open("database.dat",ios::app|ios::binary);
    while(ch=='y'||ch=='Y'){
        it.get_item();
        //write object into file
        file.write((char*)&it, sizeof(it));
        cout<<"\n\t\t\t\t\tTambah lagi ... (y/n)?";
        cin>>ch;
    }
    file.close();
}

void showAll(){
    file.open("database.dat", ios::in|ios::binary);
    if(!file)
    {
        cout<<"\n\t\t\t\t\t      file tidak ditemukan";
        exit(0);
    }else{
        file.read((char*)&it, sizeof(it));
        while (!file.eof()){
            it.put_item();
            file.read((char*)&it, sizeof(it));
        }
    }
    file.close();
}

void showRecord(void){
    int no, flag = 0;
    file.open("database.dat", ios::in|ios::binary);
    if (!file){ //Jika file tidak bisa dibuka
        cout<<"\n\t\t\t\t\t      file tidak ditemukan";
        exit(0);
    }else{
        cout<<"\n\t\t\t\tMasukkan no : ";
        cin>>no;
        //Baca record dari file dan dimasukkan ke object
        while(!file.eof()){ //ketika akhir dari file
            if(no==it.get_nis()){
                flag=1;
                cout<<"\n\t\t       -----------------------------------------------------------------"<<endl;
                cout<<"\t\t     "<<setw(6)<<"  | No "<<"| Jenis Akun  |"<<"            Akun               "<<"|  Password  |"<<endl;
                cout<<"\t\t       -----------------------------------------------------------------"<<endl;
                it.put_item();
                break;
            }
            file.read((char*)&it, sizeof(it));
        }
        if (flag==0){
            cout<<"\t\t\t\tAkun tidak ditemukan ....";
        }
    }
    file.close();
}

void deleteRecord(void){
    int no;
    cout<<"\n\t\t\t\tMasukkan kode item untuk dihapus: "  ;
    cin>>no;
    ofstream file2;  //stream object
    //open new.dat file for write operation
    file2.open("cache.dat",ios::binary);
    file.open("database.dat", ios::in|ios::binary);
    if(!file)    //if open file fails
    {
        cout<<"\n\t\t\t\t\t      Data tidak ada";
        exit(0);
    }else{
        //read record form stock.dat file into object
        file.read((char*)&it, sizeof(it));
        while(!file.eof()){
            if(no != it.get_nis()){
                file2.write((char*)&it, sizeof(it));
            }
            file.read((char*)&it, sizeof(it));
        }
    }
    file2.close();
    file.close();
    remove("database.dat");
    rename("cache.dat","database.dat");
}

void sourceCode(void){
	system("cls");
	
	for(int w=0;w<=60;w++){
        cout<<endl<<"\n\t\t\t\t\t\tMencari DATA . . . "<<w<<"%"<<endl;
        system("cls");
        }
        cout<<"\n\n\t\t\t\t\t\tDATA Ditemukan ..."<<endl;
        cout<<"\n\t\t\t\t\tgithub.com/Zuaza/backupdatatext"<<endl;
        
}
