#include <stdio.h>
#include <string.h>

/* Aplikasi CRUD sederhana 
   Version 0.1
*/
void menu();
void tambahMahasiswa();
void tampilkanData();
void editData();
void deleteData();
void cariMahasiswa();
void selesaiProses();
void close();

struct DATA
{
    int id;
    int nim;
    char nama[50];
    char jurusan[30];
}tambah,cek,hapus;


int main(){
    
    menu();
    return 0;
}

void menu(){
    int input;
    system("cls");
    printf("=================================\n");
    printf("[1]. Tambah data mahasiswa\n");
    printf("[2]. Tampilkan data mahasiswa\n");
    printf("[3]. Ubah data mahasiswa\n");
    printf("[4]. Hapus data mahasiswa\n");
    printf("[5]. Cari data mahasiswa\n");
    printf("[6]. Keluar\n");
    printf("=================================\n\n");
    
    label_error:
    printf("Masukan pilihan[1-5] : ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        tambahMahasiswa();
        break;
    case 2:
        //read data
        tampilkanData();
        break;
    case 3:
        editData();
        break;
    case 4:
        deleteData();
        break;
    case 5:
        cariMahasiswa();
        break;
    case 6:
        printf("Aplikasi ditutup");
        break;
    default:
        printf("Error(operasi tidak ditemukan).\n");
        goto label_error;
        break;
    }
}
void tambahMahasiswa(){    
    FILE *ptr,*ptr1;
	int count;
	ptr = fopen("mahasiswa.txt","a");
		system("cls");
		ptr1 =fopen("mahasiswa.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%d;%[^;];\n",&tambah.id,tambah.nama,tambah.jurusan,&tambah.nim)!=EOF)
		{
			tambah.id++;	
		}
		count = tambah.id;
		fclose(ptr1);
		printf ("masukan nama mahasiswa : ");fflush(stdin);
		scanf ("%[^\n]",tambah.nama);
		printf ("masukan NIM mahasiswa : ");fflush(stdin);
		scanf ("%d",&tambah.nim); 
		printf ("masukan Jurusan mahasiswa : ");fflush(stdin);
		scanf ("%[^\n]",tambah.jurusan);
		fprintf(ptr,"%d;%s;%d;%s;\n", count,tambah.nama,tambah.nim,tambah.jurusan);
		fclose(ptr);
	
		printf("\nData Mahasiswa Sudah Disimpan !\n");

        selesaiProses();
}
void tampilkanData(){
    //TODO later
    FILE *show;
    int test=0;

    system("cls");
    printf("NO   NAMA\t\tNIM\t  JURUSAN\n");
    printf("-----------------------------------------\n");
    show = fopen("mahasiswa.txt", "r");
    while (fscanf(show, "%d;%[^;];%d;%[^;];\n", &cek.id, &cek.nama, &cek.nim, &cek.jurusan)!= EOF)
    {
        printf("%d.   %s\t\t%d\t  %s\n", cek.id,cek.nama, cek.nim,cek.jurusan);
        test++;
    }
    printf("\n========Jumlah data %d========\n\n", test);
    fclose(show);
    
    selesaiProses();
    
}
void editData(){
    int pilih, input;
    FILE *lama, *baru;

    lama = fopen("mahasiswa.txt", "r");
    baru = fopen("textbaru.txt", "w");
    printf("Cari data berdasarkan : \n");
    printf("[1]. Nama\n");
    printf("[2]. NIM\n");
    error_handling:
    printf("\nMasukan pilihan[1/2] :");
    scanf("%d", &pilih);

    ulangi:
    switch (pilih)
    {
    case 1:
        printf("Masukan nama mahasiswa : ");fflush(stdin);
        scanf("%[^\n]", cek.nama);
        goto data_changer;
        break;
    case 2:
        printf("Masukan NIM mahasiswa :");fflush(stdin); 
        scanf("%d", &cek.nim);
        goto data_changer;
        break;
    default:
        printf("Error.\n");
        goto error_handling;
        break;
    }
    data_changer:
    while (fscanf(lama, "%d;%[^;];%d;%[^;];\n", &tambah.id, &tambah.nama, &tambah.nim, &tambah.jurusan) !=EOF)
    {
        if (tambah.nama == cek.nama || tambah.nim == cek.nim)
        {   
            system("cls");
            printf("=====================\n");
            printf("NAMA\t: %s\nNIM\t: %d\nJURUSAN\t: %s\n", tambah.nama,tambah.nim,tambah.jurusan);
            printf("data yg ingin diubah? ");
            scanf("%d", &input);

            if (input == 1)
            {
                printf("Masukan nama baru : ");fflush(stdin);
                scanf("%[^\n]", cek.nama);
                strcpy(tambah.nama, cek.nama);
                fprintf(baru, "%d;%s;%d;%s;", tambah.id, tambah.nama,tambah.nim, tambah.jurusan);
                printf("data berhasil diubah\n");
            }else if (input == 2)
            {
                printf("Masukan NIM baru : ");fflush(stdin);
                scanf("%d", &cek.nim);
                tambah.nim = cek.nim;
                fprintf(baru, "%d;%s;%d;%s;", tambah.id, tambah.nama,tambah.nim, tambah.jurusan);
                printf("\ndata berhasil diubah!\n");
            }else
            {   
                printf("data tidak ditemukan");
                goto ulangi;
            }
        
        }else
        {
            fprintf(baru, "%d;%s;%d;%s;\n", tambah.id, tambah.nama, tambah.nim, tambah.jurusan);
        }
    }
    fclose(lama);
    fclose(baru);
    remove("mahasiswa.txt");
    rename("textbaru.txt", "mahasiswa.txt");

    selesaiProses();
}
void deleteData(){
    int validation;
    FILE *baru, *lama;

    printf("masukan id yg ingin dihapus : ");fflush(stdin);
    scanf("%d", &hapus.id);
    lama =fopen("mahasiswa.txt", "r");
    baru =fopen("textbaru.txt", "w");
    while (fscanf(lama, "%d;%[^;];%d;%[^;];\n", &tambah.id, &tambah.nama, &tambah.nim, &tambah.jurusan) !=EOF)
    {
        if (tambah.id != hapus.id)
        {
            
            fprintf(baru, "%d;%s;%d;%s;\n", tambah.id, tambah.nama, tambah.nim, tambah.jurusan);
        }
        else
        {
            validation++;
            printf("data berhasil dihapus!\n");
        }
        
    }
    
    fclose(lama);
    fclose(baru);
    remove("mahasiswa.txt");
    rename("textbaru.txt", "mahasiswa.txt");

    if (validation == 0)
    {
        printf("data tidak ditemukan!\n");
    }
    selesaiProses();
    
}
void cariMahasiswa(){
    printf("maaf fitur belum tersedia");
    close();
}

void close(){
    printf("\n\nAplikasi ditutup");
}

void selesaiProses(){
    tes:
    printf("0 menu, 1 exit : ");
    switch (getch())
    {
    case '0':
        menu();
        break;
    case '1':
        close();
        break;
    default:
        printf("yg bener masukinnya!\n");
        goto tes;
    }
}
