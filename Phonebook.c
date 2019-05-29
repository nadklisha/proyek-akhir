#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

void mulai();
void add_contact();
void search_contact();
void delete_contact();
void contact_list();
void data();
void how_to_use();
void htu_add_contact();
void htu_contact_list();
void htu_delete_contact();
void htu_contact_search();

int main(){
	system("Color 30");
	mulai();
	return 0;
}

void mulai(){
		printf("\t\t\t-----------Phonebook-----------\n");
		printf("\t\t\t      TUGAS PROYEK AKHIR\n");
		printf("\t\t\t    Pengantar Teknik Komputer\n");
		menu();
}

void menu(){
	int option,exit=0;	
	while (1){
		system("cls");
		printf("\t\t\t-----------Phonebook-----------\n");
		printf("\t\t\t      TUGAS PROYEK AKHIR\n");
		printf("\t\t\t    Pengantar Teknik Komputer\n");
		printf("\n\n\n\t 1. Add Contact		2. Contact List		3. Delete Contact\n");
		printf("\t 4. How To Use		5. Search Contact	6. Exit");
		printf("\n\n\n Enter Number: \n");
		scanf("%d", &option);
		system("cls");
		switch(option){
			case 1:
				add_contact();
			break;
			case 2:
				contact_list();
			break;
			case 3:
				delete_contact();
			break;
			case 4:
				how_to_use();
			break;	
			case 5:
				search_contact();
			break;
			case 6:
				printf("Thank You");
				exit=1;
			break;
			default:
	            printf("\nEnter 1 to 6 only\n\n");
	            system("pause");
	            system("cls");
	        break;
		}
		if(exit==1) break;
	}
	return;
}

struct phonebook{
	char full_name[50];
	char first_name[25];
	char last_name[25];
	char nickname[25];
	char mobile_number[12];
	char worknumber[12];
	char address[50];
	char birthday[20];
	char email[25];
};

void data(char *name){
	int k=0;
	int l;
	char c, ch;
	do{
		 c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+k)=c;
                        putch(c);
                        k++;
                }
                if(c==8)
                {
                    if(k>0)
                    {
                        k--;
                    }
                    system("cls");
                    for(l=0;l<k;l++)
                    {
                        ch=*(name+l);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+k)='\0';
}

void add_contact(){
	FILE *f;
	system("cls");
	struct phonebook p;
    f=fopen("Last Project","a+");
    system("cls");
    printf("         Add Contact\n\n\n");
    printf("\nAdd Full Name : ");
    data(p.full_name);
    printf("\nAdd First Name : ");
    data(p.first_name);
    printf("\nAdd Last Name : ");
    data(p.last_name);
    printf("\nAdd Nickname : ");
    data(p.nickname);
    printf("\nAdd Mobile Number : ");
    data(p.mobile_number);
    printf("\nAdd Work Number : ");
    data(p.worknumber);
    printf("\nAdd Address : ");
    data(p.address);
    printf("\nAdd Birthday : ");
    data(p.birthday);
    printf("\nAdd Email : ");
    data(p.email);
    fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
	printf("\n\nrecord saved\n\n");
	
fclose(f);

system("pause");
system("cls");
return;
}

void contact_list(){
	system("cls");
	struct phonebook p;
	FILE *f;
	f=fopen("Last Project","r+");
	if(f==0){
		printf("Data Not Found/Data Has Not Been Imputted");
		exit(1);
	}
	while(fread(&p,sizeof(p),1,f)==1){
		printf("Data is recorded\n");
		printf("\nYour Contact List\n");
		printf("\nFull Name : %s", p.full_name);
		printf("\nFirst Name : %s", p.first_name);
		printf("\nLast Name : %s", p.last_name );
		printf("\nNickname : %s", p.nickname);
    	printf("\n Mobile Number : %s", p.mobile_number);
    	printf("\nWork Number : %s", p.worknumber);
    	printf("\nAddress : %s", p.address);
    	printf("\nBirthday : %s", p.birthday);
    	printf("\nEmail : %s\n\n\n", p.email);
    	
    	system("pause");
    	system("cls");
	}
	fclose(f);
	system("cls");
	return;
}

void delete_contact()
{
	FILE *f;
	FILE *fp;
	struct phonebook p;
 int nama;
 char full_name[100],op;
do{
 system("cls");
 f=fopen("Last Project","r");
if(f==0)
{
 printf("tidak dapat di hapus");
 exit(1);
} else{
	fp=fopen("Hapus Kontak", "wb");
	if(fp==0)
		printf("File Opening Error");
	else{
		printf("Menghapus Data dengan Nama : ");
		data(full_name);
		fflush(stdin);
		
		while(fread(&p,sizeof(p),1, f)==1)
		{
			if(strcmp(p.full_name,full_name)!=0)
				fwrite(&p, sizeof(p), 1, fp);
			if(strcmp(p.full_name,full_name)!=0)
			nama=1;
		}
		fclose(f);
		fclose(fp);
		if(nama!=1)
	{
		printf("\nNO CONTACT'S RECORD TO DELETE.");
		remove("Hapus Kontak");
	}
		else
		{
			remove("Last Project");
			rename("Hapus Kontak","Last Project");
			printf("\nRECORD DELETED SUCCESSFULLY.");
		}
	}
	} 
printf("\n\nhapus lagi  = %s", full_name);
 op=getch();
		
}while(op=='Y'||op=='y');
 puts("\n");
 system("pause");
    system("cls");
return;
}

void how_to_use(){
	int options;
		system("cls");
		printf("Help Center of This Phonebook\n");
		printf("Choose one of these options which can help you run this phonebook\n");
	while(1){
		printf("\n\n1. Add Contact");
		printf("\n2. Contact List");
		printf("\n3. Delete Contact");
		printf("\n4. Search Contact");
		printf("\n5. Back to main menu");
		printf("\n\n\nEnter Number : ");
		scanf("%d", &options);
		system("cls");
		switch(options){
			case 1:
				htu_add_contact();
			break;
			case 2:
				htu_contact_list();
			break;
			case 3:
				htu_delete_contact();
			break;
			case 4:
				htu_contact_search();
			break;
			case 5:
				return;
			break;
			default:
				printf("\nEnter 1 to 5 only\n\n");
				system("pause");
		        system("cls");
		    break;
		}
	}
}

void option_menu(){
	printf("Help Center of This Phonebook\n");
	printf("Choose one of these options which can help you run this phonebook\n");
}

void htu_add_contact(){
		printf("Petunjuk Menggunakan Add Contact pada Phonebook\n\n\n");
		printf("Add Full Name sesuai nama panjang\n");
		printf("Add First Name sesuai nama pertama\n");
		printf("Add Last Name sesuai nama akhir ataupun nama keluarga\n");
		printf("Add Nickname sesuai nama panggilan yang dipunyai (tidak lebih dari 25 character)\n");
		printf("Add Mobile Number sesuai nomor handphone\n");
		printf("Add Work Number sesuai dengan nomor yang digunakan pada saat penting\n");
		printf("Add Birthday sesuai dengan tanggal ulang tahun\n");
		printf("Add Email sesuai email yang dipunyai\n\n");
		system("Pause");
		system("cls");
	option_menu();
}

void htu_delete_contact(){
		printf("Petunjuk Menggunakan Delete pada Phonebook\n\n\n");
		printf("Menginput angka 3 untuk mencari kontak\n");
		printf("Menghapus sesuai Full Name yang sudah terinput sebelumnya\n");
		printf("Sebagai catatan, untuk mennghapus kontak, nama yang diinput haruslah sama seperti yang berada di contact list (termasuk huruf kapital dan spasi)\n");
		system("Pause");
		system("cls");
option_menu();
}

void htu_contact_list(){
		printf("Petunjuk Menggunakan Contact List pada Phonebook\n\n\n");
		printf("Menginput angka 2 pada main menu\n");
		printf("Contact list akan terbuka\n");
		printf("Menggunakan enter untuk melihat kontak berikutnya yang tersimpan\n\n");
		system("Pause");
		system("cls");
option_menu();
}

void htu_contact_search(){
		printf("Petunjuk Menggunakan Contact Search pada Phonebook\n\n\n");
		printf("Menginput angka 5 untuk mencari kontak\n");
		printf("Mencari sesuai Full Name yang sudah terinput sebelumnya\n");
		printf("Sebagai catatan, untuk mencari kontak, nama yang diinput haruslah sama seperti yang berada di contact list (termasuk huruf kapital dan spasi)\n");
		system("pause");
		system("cls");
option_menu();
}

void search_contact(){
	system("cls");
	struct phonebook p;
	char full_name[100];
	FILE *f;
	f=fopen("Last Project","r");

	printf("\nType Full Name to search information contact : ");
	data(full_name);
	
	while(fread(&p,sizeof(p),1,f)==1){
	system("cls");
    if(strcmp(p.full_name, full_name)==0){
    	printf("Information about : %s", full_name);
 		printf("Data is recorded\n");
		printf("\nYour Contact List\n");
		printf("\nFull Name : %s", p.full_name);
		printf("\nFirst Name : %s", p.first_name);
		printf("\nLast Name : %s", p.last_name );
		printf("\nNickname : %s", p.nickname);
    	printf("\n Mobile Number : %s", p.mobile_number);
    	printf("\nWork Number : %s", p.worknumber);
    	printf("\nAddress : %s", p.address);
    	printf("\nBirthday : %s", p.birthday);
    	printf("\nEmail : %s\n\n\n", p.email);
	}
	else
		printf("Data not found");
}
	fclose(f);
	system("pause");
	system("cls");
	return;

}



