# soal-shift-sisop-modul-2-C05-2021

Repository Praktikum Sisop Modul 2
- 05111940000073_Aji Wahyu Admaja Utama
- 05111940000084_Aldo Yaputra Hartono
- 05111940000204_Muhammad Subhan

## Penyelesaian Soal No.1
Pada suatu masa, hiduplah seorang Steven yang hidupnya pas-pasan. Steven punya pacar, namun sudah putus sebelum pacaran. Ketika dia galau memikirkan mantan, ia selalu menonton https://www.youtube.com/watch?v=568DH_9CMKI untuk menghilangkan kesedihannya. 

Di lain hal Steven anak yang tidak amat sangat super membenci matkul sisop, beberapa jam setelah diputus oleh pacarnya dia menemukan wanita lain bernama Stevany, namun Stevany berkebalikan dengan Steven karena menyukai sisop. Steven ingin terlihat jago matkul sisop demi menarik perhatian Stevany.

Pada hari ulang tahun Stevany, Steven ingin memberikan Stevany zip berisikan hal-hal yang disukai Stevany. Steven ingin isi zipnya menjadi rapi dengan membuat folder masing-masing sesuai extensi. (a) Dikarenakan Stevany sangat menyukai huruf **Y**, Steven ingin nama folder-foldernya adalah **Musyik** untuk mp3, **Fylm** untuk mp4, dan **Pyoto** untuk jpg (b) untuk musik Steven **mendownloadnya** dari link di bawah, film dari link di bawah lagi, dan foto dari link dibawah juga :). (c) Steven tidak ingin isi folder yang dibuatnya berisikan zip, sehingga perlu **meng-extract-nya** setelah didownload serta (d) **memindahkannya** ke dalam folder yang telah dibuat (hanya file yang dimasukkan).

(e) Untuk memudahkan Steven, ia ingin semua hal di atas berjalan **otomatis** 6 jam sebelum waktu ulang tahun Stevany). (f) Setelah itu pada **waktu** ulang tahunnya Stevany, semua folder akan di zip dengan nama **Lopyu_Stevany.zip** dan semua folder akan di **delete**(sehingga hanya menyisakan .zip).
Kemudian Steven meminta bantuanmu yang memang sudah jago sisop untuk membantunya mendapatkan hati Stevany. Bantu Woy!!

**Note:**

● Ulang Tahun Stevany : 09 April Pukul 22.22 WIB

● Semua poin dijalankan oleh **1 script di latar belakang**, termasuk mendownload file zip-nya. Jadi cukup jalankan script 1x serta ubah time dan date untuk check hasilnya.
```text
Preview :
https://drive.google.com/drive/folders/1NzRiPPoVlR_H8P51cxN4jaceeFQGk4un
*tontonnya 720p biar jelas.. ಠ‿ಠ
```

● **Tidak boleh** menggunakan fungsi system(), mkdir(), dan rename() (Yang di bahasa C) .... FORBIDDENNN!!

● **Tidak boleh** pake **cron** !!!

● Menggunakan fork dan exec.

● Link
```text
Foto :
https://drive.google.com/file/d/1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD/view
Musik :
https://drive.google.com/file/d/1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J/view
Film : 
https://drive.google.com/file/d/1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp/view
```

**Tips :**

● Gunakan fungsi wait() dan sleep() untuk memperlancarrr..

● untuk mendownload zip yang dibutuhkan bisa menggunakan command :
```text
wget --no-check-certificate "https://drive.google.com/uc?id=ID-FILE&export=download" -O Nama_untuk_filenya.ext
```

● contoh
```
Wget --no-check-certificate "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download" -O Musik_for_Stevany.zip
```

#
### Jawab 1a
Pada soal 1a diminta untuk membuat folder Musyik untuk mp3, Fylm untuk mp4, dan Pyoto untuk jpg. Dikarenakan Steven ingin menggunakannya pada waktu tertentu, maka kita menggunakan daemon untuk menggantikan crontab.
```c
void daemonstart() {
    pid_t pid, sid;
    pid = fork();
    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if(sid < 0) exit(EXIT_FAILURE);
    if((chdir("/home/aldo/Sisop/Modul2/Soal3")) < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}
```
![s11](https://user-images.githubusercontent.com/31863229/115901113-fb179180-a48a-11eb-91bd-4c2b11d4affa.PNG)

Lalu kita melakukan pembuatan folder sesuai keinginan soal dengan nama Musyik, Fylm, dan Pyoto menggunakan fungsi `execv()` dengan argumen `mkdir`. Gunakan fungsi `fork()` untuk setiap proses pembuatan folder. Kita juga menggunakan `fork()` dan `exec()` agar bisa menjalankan task secara bersamaan.
```c
cid1 = fork();
if(cid1 < 0) exit(0);
if(cid1 == 0) {
	char *arg[] = {"mkdir", "Musyik", NULL};
	execv("/bin/mkdir", arg);
}

cid2 = fork();
if(cid2 < 0) exit(0);
if(cid2 == 0) {
	char *arg[] = {"mkdir", "Fylm", NULL};
	execv("/bin/mkdir", arg);
}

cid3 = fork();
if(cid3 < 0) exit(0);
if(cid3 == 0) {
	char *arg[] = {"mkdir", "Pyoto", NULL};
	execv("/bin/mkdir", arg);
}

//lanjut soal b
```

#
### Jawab 1b
Pada soal kedua kita diminta mendownload file musik, foto, dan film. Link download telah tersedia pada soal. Disini kita bisa menggunakan fungsi `wget()` untuk mendownload file tersebut. Kita juga menggunakan `fork()` dan `execv()` untuk menjalankan task secara bersamaan. Fungsi `execv()` disini digunakan untuk mengeksekusi bagian argumen pada code.
```c
while(wait(&status) > 0);
cid4 = fork();
if(cid4 < 0) exit(0);
if(cid4 == 0) {
	char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", "-o", "/dev/null", NULL};
	execv("/usr/bin/wget", arg);
}

while(wait(&status2) > 0);
cid5 = fork();
if(cid5 < 0) exit(0);
if(cid5 == 0) {
	char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", "-o", "/dev/null", NULL};
	execv("/usr/bin/wget", arg);
}

while(wait(&status3) > 0);
cid6 = fork();
if(cid6 < 0) exit(0);
if(cid6 == 0) {
	char *arg[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", "-o", "/dev/null", NULL};
	execv("/usr/bin/wget", arg);
}
```

Pada saat menjalankan program diatas kita menggunakan fungsi `wait()` untuk menunggu proses yang sebelumnya dijalankan agar selesai terlebih dahulu.
![s12](https://user-images.githubusercontent.com/31863229/115901167-0b2f7100-a48b-11eb-8b28-735900c0df1c.PNG)
![s13](https://user-images.githubusercontent.com/31863229/115901172-0cf93480-a48b-11eb-9d6c-b7a73baaee47.PNG)

#
### Jawab 1c
Pada soal ketiga kita diminta untuk melakukan extract pada file yang telah didownload dengan menggunakan argumen `unzip` pada tiap folder musik, film, dan foto.
```c
while(wait(&status4) > 0);
cid7 = fork();
if(cid7 < 0) exit(0);
if(cid7 == 0) {
	char *arg[] = {"unzip", "-o", "-q", "./Musik_for_Stevany.zip", NULL};
	execv("/usr/bin/unzip", arg);
}

while(wait(&status5) > 0);
cid8 = fork();
if(cid8 < 0) exit(0);
if(cid8 == 0) {
	char *arg[] = {"unzip", "-o", "-q", "./Film_for_Stevany.zip", NULL};
	execv("/usr/bin/unzip", arg);
}

while(wait(&status6) > 0);
cid9 = fork();
if(cid9 < 0) exit(0);
if(cid9 == 0) {
	char *arg[] = {"unzip", "-o", "-q", "./Foto_for_Stevany.zip", NULL};
	execv("/usr/bin/unzip", arg);
}
```

Kita juga menggunakan `fork()` dan `execv()` untuk menjalankan task secara bersamaan. Pada saat menjalankan program diatas kita menggunakan fungsi `wait()` untuk menunggu proses yang sebelumnya dijalankan agar selesai terlebih dahulu.

#
### Jawab 1d
Pada soal ini kita diminta untuk memindahkan file yang sudah kita download ke dalam folder yang sudah ditentukan.
```c
while(wait(&status7) > 0);
DIR *dirp;
struct dirent *entry;
dirp = opendir("./MUSIK");
while((entry = readdir(dirp)) != NULL) {
	if(entry->d_type == DT_REG) {
		pid_t cid;
		cid = fork();
		if(cid < 0) exit(0);
		if(cid == 0) {
			char asal[300], tujuan[300];
			sprintf(asal, "./MUSIK/%s", entry->d_name);
			sprintf(tujuan, "./Musyik");
			char *arg[] = {"cp", "-r", asal, tujuan, NULL};
			execv("/bin/cp", arg);
		}
	}
}
```

Kita harus membuka folder MUSIK terlebih dahulu menggunakan `opendir()` lalu iterasi tiap file di dalamnya dengan fungsi `readdir()`. Gunakan `sprintf()` untuk menulis string yang diformat ke variable. Salin tiap file ke folder tujuan dengan argumen `cp`. Lakukan hal yang sama pada folder FILM dan FOTO.

```c
while(wait(&status8) > 0);
DIR *dirp2;
struct dirent *entry2;
dirp2 = opendir("./FILM");
while((entry2 = readdir(dirp2)) != NULL) {
	if(entry2->d_type == DT_REG) {
		pid_t cid;
		cid = fork();
		if(cid < 0) exit(0);
		if(cid == 0) {
			char asal[300], tujuan[300];
			sprintf(asal, "./FILM/%s", entry2->d_name);
			sprintf(tujuan, "./Fylm");
			char *arg[] = {"cp", "-r", asal, tujuan, NULL};
			execv("/bin/cp", arg);
		}
	}
}

while(wait(&status9) > 0);
DIR *dirp3;
struct dirent *entry3;
dirp3 = opendir("./FOTO");
while((entry3 = readdir(dirp3)) != NULL) {
	if(entry3->d_type == DT_REG) {
		if(strstr(entry3->d_name, ".jpg")) {
			pid_t cid;
			cid = fork();
			if(cid < 0) exit(0);
			if(cid == 0) {
				char asal[300], tujuan[300];
				sprintf(asal, "./FOTO/%s", entry3->d_name);
				sprintf(tujuan, "./Pyoto");
				char *arg[] = {"cp", "-r", asal, tujuan, NULL};
				execv("/bin/cp", arg);
			}
		}
	}
}
```
![s14](https://user-images.githubusercontent.com/31863229/115901143-04a0f980-a48b-11eb-9c64-69c6249d023f.PNG)

#
### Jawab 1e
Pada soal ini kita diminta untuk menjalankan seluruh program di atas secara otomatis pada 6 jam sebelum Stevany ulang tahun, yaitu pada 09 April Pukul 16:22 WIB. Disini kita melakukan pengaturan agar waktu yang digunakan tepat.
```c
time_t now = time(NULL);
struct tm *t = localtime(&now);
if(t->tm_mon == 3 && t->tm_mday == 9 && t->tm_hour == 16 && t->tm_min == 22 && t->tm_sec == 0) {
	cid = fork();
	if(cid < 0) exit(0);
	if(cid == 0) {
		//lanjut soal a hingga d
		
		while(wait(&status10) > 0);
		exit(0);
	}
}
```

Lakukan penggantian waktu dan tanggal pada linux dengan menjalankan command `sudo date --set="2021-04-09 16:21:59"` untuk melihat apakah script telah berjalan dengan benar.

#
### Jawab 1f
Pada soal 1f kita diminta untuk melakukan zip dengan menggunakan argumen `zip` lalu semua folder akan dihapus. Hal ini dilakukan pada saat ulang tahun Stevany, yaitu pada 09 April Pukul 22:22 WIB.

```c
else if(t->tm_mon == 3 && t->tm_mday == 9 && t->tm_hour == 22 && t->tm_min == 22 && t->tm_sec == 0) {
	cid12 = fork();
	if(cid12 < 0) exit(0);
	if(cid12 == 0) {
		cid10 = fork();
		if(cid10 < 0) exit(0);
		if(cid10 == 0) {
			char *arg[] = {"zip", "-q", "-rm", "Lopyu_Stevany.zip", "./Musyik", "./Fylm", "./Pyoto", NULL};
			execv("/usr/bin/zip", arg);
		}

		cid11 = fork();
		if(cid11 < 0) exit(0);
		if(cid11 == 0) {
			char *arg[] = {"rm", "-r", "./MUSIK", "./FILM", "./FOTO", NULL};
			execv("/bin/rm", arg);
		}

		while(wait(&status11) > 0);
		exit(0);
	}
}
```

Lakukan penggantian waktu dan tanggal pada linux dengan menjalankan command `sudo date --set="2021-04-09 22:21:59"` untuk melihat apakah script telah berjalan dengan benar.
![s15](https://user-images.githubusercontent.com/31863229/115901153-08348080-a48b-11eb-8c1d-3b54f11b811c.PNG)
![s16](https://user-images.githubusercontent.com/31863229/115901162-0965ad80-a48b-11eb-8f8f-5e2c49fa2cd0.PNG)

#
### Kendala
1. Agak kesusahan saat mengganti waktu dan tanggal karena ternyata auto synchronize nya masih aktif. Dengan mematikannya sementara maka command untuk mengganti waktu dan tanggal dapat berjalan dengan baik.
2. Sedikit ada trouble saat mendownload file menjadi zip dikarenakan ada kesalahan pada argumen.
3. Sempat mengira program tidak dapat melakukan unzip dikarenakan file yang masuk ke dalam folder hanya sedikit. Ternyata hanya butuh sedikit tambahan waktu hingga proses unzip dapat selesai seluruhnya.

#
## Penyelesaian Soal No.2
Loba bekerja di sebuah petshop terkenal, suatu saat dia mendapatkan zip yang berisi banyak sekali foto peliharaan dan Ia diperintahkan untuk mengkategorikan foto-foto peliharaan tersebut. Loba merasa kesusahan melakukan pekerjaanya secara manual, apalagi ada kemungkinan ia akan diperintahkan untuk melakukan hal yang sama. Kamu adalah teman baik Loba dan Ia meminta bantuanmu untuk membantu pekerjaannya.

a. Pertama-tama program perlu mengextract zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop”. Karena bos Loba teledor, dalam zip tersebut bisa berisi folder-folder yang tidak penting, maka program harus bisa membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan.

b. Foto peliharaan perlu dikategorikan sesuai jenis peliharaan, maka kamu harus membuat folder untuk setiap jenis peliharaan yang ada dalam zip. Karena kamu tidak mungkin memeriksa satu-persatu, maka program harus membuatkan folder-folder yang dibutuhkan sesuai dengan isi zip.

Contoh: Jenis peliharaan kucing akan disimpan dalam “`/petshop/cat`”, jenis peliharaan kura-kura akan disimpan dalam “`/petshop/turtle`”.

c. Setelah folder kategori berhasil dibuat, programmu akan memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.

Contoh: “`/petshop/cat/joni.jpg`”. 

d. Karena dalam satu foto bisa terdapat lebih dari satu peliharaan maka foto harus di pindah ke masing-masing kategori yang sesuai. Contoh: foto dengan nama “`dog;baro;1_cat;joni;2.jpg`” dipindah ke folder “`/petshop/cat/joni.jpg`” dan “`/petshop/dog/baro.jpg`”.

e.Di setiap folder buatlah sebuah file "keterangan.txt" yang berisi nama dan umur semua peliharaan dalam folder tersebut. **Format harus sesuai contoh.**

```text
nama : joni
umur  : 3 tahun

nama : miko
umur  : 2 tahun

```

Loba sangat mengapresiasi bantuanmu, minggu depan ia akan mentraktir makan malam!

**Note:**

● Setiap data peliharaan disimpan sebagai nama foto dengan format [jenis peliharaan]:[nama peliharaan]:[umur peliharaan dalam tahun]. Jika terdapat lebih dari satu peliharaan, data dipisahkan menggunakan *underscore*(_).

● Tidak boleh menggunakan fungsi system(), mkdir(), dan rename().

● Menggunakan fork dan exec.

#
### Jawab 2a
Pada soal ini kita diminta untuk mengekstrak zip yang diberikan ke dalam folder “/home/[user]/modul2/petshop” dengan menggunakan fork dan execv.
```c
pid_t cid;
cid = fork();
if(cid < 0) exit(0);
if(cid == 0) {
    char *arg[] = {"unzip", "-o", "-q", "/home/aldo/modul2/pets.zip", "-d", "/home/aldo/modul2/petshop", NULL};
    execv("/usr/bin/unzip", arg);
}
```

Selanjutnya dengan program berikut ini, kita dapat membedakan file dan folder sehingga dapat memproses file yang seharusnya dikerjakan dan menghapus folder-folder yang tidak dibutuhkan. Juga digunakan fungsi `wait()` untuk menunggu proses unzip hingga selesai terlebih dahulu.
```c
while(wait(&status) > 0);
DIR *dirp;
struct dirent *entry;
dirp = opendir("/home/aldo/modul2/petshop");
while((entry = readdir(dirp)) != NULL) {
    if((entry->d_type == DT_DIR) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
        pid_t cid;
        cid = fork();
        if(cid < 0) exit(0);
        if(cid == 0) {
            char foldername[300];
            sprintf(foldername, "/home/aldo/modul2/petshop/%s", entry->d_name);
            char *arg[] = {"rm", "-r", foldername, NULL};
            execv("/bin/rm", arg);
        }
    }
}
```
![s21](https://user-images.githubusercontent.com/31863229/115901676-b2aca380-a48b-11eb-8710-a7d46612dfe0.PNG)

#
### Jawab 2b
Sebelum membuat folder pengkategorian hewan peliharaan, maka perlu diketahui jenis-jenis peliharaan yang nantinya akan dijadikan nama folder yang akan dibuat. Jenis-jenis peliharaan disimpan dalam array of char 2 dimensi (seperti array of string pada C++) dengan nama variable `foldername[][]` dan integer idx sebagai bantuan indexing pada foldername.
```c
while(wait(&status2) > 0);
DIR *dirp2;
struct dirent *entry2;
dirp2 = opendir("/home/aldo/modul2/petshop");
char foldername[100][300];
int idx = 0;
while((entry2 = readdir(dirp2)) != NULL) {
    if(entry2->d_type == DT_REG) {
        char tmp[300], tmp2[300];
        memset(foldername[idx], 0, sizeof(foldername[idx]));
        memset(tmp2, 0, sizeof(tmp2));
        strcpy(tmp, entry2->d_name);

        int i, found = 0;
        for(i = 0; i < strlen(tmp); i++) {
            if(tmp[i] == ';') break;
            tmp2[i] = tmp[i];
        }

        for(i = 0; i < idx && found == 0; i++)
            if(strcmp(foldername[i], tmp2) == 0)
                found = 1;

        if(found == 0) {
            strcpy(foldername[idx], tmp2);
            idx++;
        }
    }
}
```

Membuat folder sesuai dengan jenis hewan peliharaan.
```c
int i;
for(i = 0; i < idx; i++) {
    pid_t cid;
    cid = fork();
    if(cid < 0) exit(0);
    if(cid == 0) {
        char tmp[300];
        sprintf(tmp, "/home/aldo/modul2/petshop/%s", foldername[i]);
        char *arg[] = {"mkdir", tmp, NULL};
        execv("/bin/mkdir", arg);
    }
}
```

#
### Jawab 2c
Melihat setiap file dalam folder dan inisialisasi variabel yang akan digunakan nanti. `tmp2` untuk hewan pertama dan `tmp3` untuk hewan kedua.
```c
while(wait(&status3) > 0);
DIR *dirp3;
struct dirent *entry3;
dirp3 = opendir("/home/aldo/modul2/petshop");
while((entry3 = readdir(dirp3)) != NULL) {
    if(entry3->d_type == DT_REG) {
        char tmp[300];
        char tmp2_jenis[300], tmp2_nama[300], tmp2_umur[300];
        char tmp3_jenis[300], tmp3_nama[300], tmp3_umur[300];
        memset(tmp2_jenis, 0, sizeof(tmp2_jenis));
        memset(tmp2_nama , 0, sizeof(tmp2_nama));
        memset(tmp2_umur , 0, sizeof(tmp2_umur));
        memset(tmp3_jenis, 0, sizeof(tmp3_jenis));
        memset(tmp3_nama , 0, sizeof(tmp3_nama));
        memset(tmp3_umur , 0, sizeof(tmp3_umur));
        strcpy(tmp, entry3->d_name);
	
	//lanjut penyimpanan data tiap hewan
```

Menyimpan jenis, nama, dan umur hewan peliharaan pertama dalam variabel tmp2.
```c
//penyimpanan data tiap hewan

int i, ii, found = 0, adadua = 0;
for(i = 0; i < strlen(tmp); i++) {
    if(tmp[i] == ';') break;
    tmp2_jenis[i] = tmp[i];
}

i++; ii = i;
for(; i < strlen(tmp); i++) {
    if(tmp[i] == ';') break;
    tmp2_nama[i-ii] = tmp[i];
}

i++; ii = i;
for(; i < strlen(tmp); i++) {
    if(tmp[i] == '_' || (tmp[i] == '.' && tmp[i+1] == 'j')) break;
    tmp2_umur[i-ii] = tmp[i];
}

//lanjut penyalinan foto ke folder
```

Menyalin foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
```c
//penyalinan foto ke folder

int status, status2;
pid_t cid;
cid = fork();
if(cid < 0) exit(0);
if(cid == 0) {
    char asal[300], tujuan[300];
    sprintf(asal, "/home/aldo/modul2/petshop/%s", entry3->d_name);
    sprintf(tujuan, "/home/aldo/modul2/petshop/%s/%s", tmp2_jenis, tmp2_nama);
    char *arg[] = {"cp", "-r", asal, tujuan, NULL};
    execv("/bin/cp", arg);
}

//lanjut soal e
```

#
### Jawab 2d
Mengecek apakah dalam satu foto terdapat 2 jenis hewan peliharaan, jika ada maka akan disimpan jenis, nama, dan umur hewan yang kedua pada tmp3.
```c
if(tmp[i] == '_') {
    i++; ii = i;
    for(; i < strlen(tmp); i++) {
	if(tmp[i] == ';') break;
	tmp3_jenis[i-ii] = tmp[i];
    }

    i++; ii = i;
    for(; i < strlen(tmp); i++) {
	if(tmp[i] == ';') break;
	tmp3_nama[i-ii] = tmp[i];
    }

    i++; ii = i;
    for(; i < strlen(tmp); i++) {
	if(tmp[i] == '.' && tmp[i+1] == 'j') break;
	tmp3_umur[i-ii] = tmp[i];
    }

    adadua = 1;
}

//lanjut penyalinan foto ke folder
```

Memindahkan foto ke folder dengan kategori yang sesuai dan di rename dengan nama peliharaan.
```c
//penyalinan foto ke folder

if(adadua == 1) {
    pid_t cid;
    cid = fork();
    if(cid < 0) exit(0);
    if(cid == 0) {
	char asal[300], tujuan[300];
	sprintf(asal, "/home/aldo/modul2/petshop/%s", entry3->d_name);
	sprintf(tujuan, "/home/aldo/modul2/petshop/%s/%s", tmp3_jenis, tmp3_nama);
	char *arg[] = {"cp", "-r", asal, tujuan, NULL};
	execv("/bin/cp", arg);
    }

    //lanjut soal e
}
```

#
### Jawab 2e
Menambahkan keterangan berupa nama dan umur hewan peliharaan sesuai didalam file "keterangan.txt" yang terdapat dalam setiap folder kategorinya.
```c
while(wait(&status) > 0);
char ket[300];
sprintf(ket, "/home/aldo/modul2/petshop/%s/keterangan.txt", tmp2_jenis);
FILE *filep;
filep = fopen(ket, "a+");
fprintf(filep, "nama : %s\n", tmp2_nama);
fprintf(filep, "umur : %s tahun\n\n", tmp2_umur);
fclose(filep);
```

Hal yang sama juga dilakukan ketika ada dua jenis hewan peliharaan dalam satu foto.
```c
while(wait(&status2) > 0);
char ket[300];
sprintf(ket, "/home/aldo/modul2/petshop/%s/keterangan.txt", tmp3_jenis);
FILE *filep;
filep = fopen(ket, "a+");
fprintf(filep, "nama : %s\n", tmp3_nama);
fprintf(filep, "umur : %s tahun\n\n", tmp3_umur);
fclose(filep);
```

Jangan lupa untuk menghapus semua gambar yang telah disalin ke masing-masing folder sesuai dengan jenisnya.
```c
while(wait(&status4) > 0);
DIR *dirp4;
struct dirent *entry4;
dirp4 = opendir("/home/aldo/modul2/petshop");
while((entry4 = readdir(dirp4)) != NULL) {
	if((entry4->d_type == DT_REG) && strcmp(entry4->d_name, ".") != 0 && strcmp(entry4->d_name, "..") != 0) {
	    pid_t cid;
	    cid = fork();
	    if(cid < 0) exit(0);
	    if(cid == 0) {
		char foldername[300];
		sprintf(foldername, "/home/aldo/modul2/petshop/%s", entry4->d_name);
		char *arg[] = {"rm", "-r", foldername, NULL};
		execv("/bin/rm", arg);
	    }
	}
}
```
![s22](https://user-images.githubusercontent.com/31863229/115901684-b6402a80-a48b-11eb-9363-647e129219b9.PNG)
![s23](https://user-images.githubusercontent.com/31863229/115901690-b809ee00-a48b-11eb-8f3b-86cdc2d3f022.PNG)
![s24](https://user-images.githubusercontent.com/31863229/115901699-b93b1b00-a48b-11eb-8b6a-5105371e2f9b.PNG)

#
### Cek keterangan.txt
https://gist.github.com/segi3/0f90621bb2d118b0b6fadc98d5835b02

#
### Kendala
1. Agak kesulitan dalam menentukan argumen apa saja yang ada dalam arg pada `execv` namun dapat diatasi dengan searching dan tanya teman satu kelompok.
2. Pada saat membuat dan menambah data dalam suatu file sempat berjalan tidak sesuai keinginan karena adanya kesalahan penulisan sintaks.
3. Sedikit ada kendala saat ingin mengerjakan soal e dan akhirnya teratasi dengan mengerjakannya bersamaan dengan soal c dan d. Sehingga saat iterasi menyalin gambar, sekaligus mengisi keterangan.txt.

#
## Penyelesaian Soal No.3
Ranora adalah mahasiswa Teknik Informatika yang saat ini sedang menjalani magang di perusahan ternama yang bernama “FakeKos Corp.”, perusahaan yang bergerak dibidang keamanan data. Karena Ranora masih magang, maka beban tugasnya tidak sebesar beban tugas pekerja tetap perusahaan. Di hari pertama Ranora bekerja, pembimbing magang Ranora memberi tugas pertamanya untuk membuat sebuah program.

a. Ranora harus membuat sebuah program C yang dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].

b. Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang didownload dari https://picsum.photos/, dimana setiap gambar akan didownload setiap 5 detik. Setiap gambar yang didownload akan diberi nama dengan format timestamp [YYYY-mm-dd_HH:ii:ss] dan gambar tersebut berbentuk persegi dengan ukuran (n%1000) + 50 pixel dimana n adalah detik Epoch Unix.

c. Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Caesar Cipher adalah Teknik enkripsi sederhana yang dimana dapat melakukan enkripsi string sesuai dengan shift/key yang kita tentukan. Misal huruf “A” akan dienkripsi dengan shift 4 maka akan menjadi “E”. Karena Ranora orangnya perfeksionis dan rapi, dia ingin setelah file tersebut dibuat, direktori akan di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

d. Untuk mempermudah pengendalian program, pembimbing magang Ranora ingin program tersebut akan men-generate sebuah program “Killer” yang executable, dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Karena Ranora menyukai sesuatu hal yang baru, maka Ranora memiliki ide untuk program “Killer” yang dibuat nantinya harus merupakan **program bash**.

e.Pembimbing magang Ranora juga ingin nantinya program utama yang dibuat Ranora dapat dijalankan di dalam dua mode. Untuk mengaktifkan mode pertama, program harus dijalankan dengan argumen -z, dan Ketika dijalankan dalam mode pertama, program utama akan langsung menghentikan semua operasinya Ketika program Killer dijalankan. Sedangkan untuk mengaktifkan mode kedua, program harus dijalankan dengan argumen -x, dan Ketika dijalankan dalam mode kedua, program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

Ranora meminta bantuanmu untuk membantunya dalam membuat program tersebut. Karena kamu anak baik dan rajin menabung, bantulah Ranora dalam membuat program tersebut!

Note:
- Tidak boleh menggunakan system()
- **Program utama** merupakan **SEBUAH PROGRAM C**
- **Wajib** memuat algoritma Caesar Cipher pada program utama yang dibuat

#
### Jawab 3a
Pada soal ini kita diminta membuat direktori baru setiap 40 detik. Nama dari direktori mengikuti timestamp [YYYY-mm-dd_HH:ii:ss]. Pada mulanya, dapatkan waktu saat ini dan simpan ke array variable.

```c
char curtime[100];
time_t now = time(NULL);
struct tm *t1 = localtime(&now);
strftime(curtime, sizeof(curtime)-1, "%Y-%m-%d_%H:%M:%S", t1);
```

Kemudian buat child karena nantinya akan dibuat menjadi daemon dan parent tidak menunggu child saat ini untuk menjalankan proses berikutnya. Beri `sleep(40)` agar proses berjalan setiap 40 detik.

```c
cid = fork();
if(cid < 0) exit(0);
if(cid == 0) {
    //buat folder
}
sleep(40);
```

Buat child untuk membuat direktori baru lalu jalankan `wait()` untuk menunggu proses selesai sebelum lanjut ke proses berikutnya.

```c
//buat folder

cid2 = fork();
if(cid2 < 0) exit(0);
if(cid2 == 0) {
    char *arg[] = {"mkdir", curtime, NULL};
    execv("/bin/mkdir", arg);
}

while(wait(&status) > 0);

//lanjut soal b 
```

#
### Jawab 3b
Pindah ke direktori sesuai timestamp, lalu lakukan iterasi download 10 gambar dan beri `sleep(5)` untuk jeda 5 detik setiap download. Jalankan `wait()` untuk menunggu proses download selesai sebelum lanjut ke proses berikutnya.

```c
chdir(curtime);
int i = 0;
char link[100], curtime2[100];
while(i < 10) {
    //download gambar

    i++;
    sleep(5);
}

while(wait(&status2) > 0);

//lanjut soal c
```

Tambahkan ukuran gambar pada akhir alamat untuk mendownload gambar dikarenakan setiap gambar harus berukuran (n % 1000) + 50 pixel dimana n adalah detik Epoch Unix. Lalu untuk setiap gambar yang akan didownload akan dilakukan rename dengan timestamp saat ini.

```c
//download gambar

time_t now2 = time(NULL);
struct tm *t2 = localtime(&now2);
strftime(curtime2, sizeof(curtime2)-1, "%Y-%m-%d_%H:%M:%S", t2);
sprintf(link, "https://picsum.photos/%ld", (now2 % 1000) + 50);

cid3 = fork();
if(cid3 < 0) exit(0);
if(cid3 == 0) {
    char *arg[] = {"wget", link, "-O", curtime2, "-o", "/dev/null", NULL};
    execv("/usr/bin/wget", arg);
}
```

#
### Jawab 3c
Setelah direktori telah terisi dengan 10 gambar, program tersebut akan membuat sebuah file “status.txt”, dimana didalamnya berisi pesan “Download Success” yang terenkripsi dengan teknik Caesar Cipher dan dengan shift 5. Algoritma Caesar Cipher dilakukan dengan mengiterasi tiap huruf dari `Download Success` dan ditampung ke array variable yang baru. Penggeseran 5 karakter dengan memperhatikan huruf kecil dan huruf besar serta terdapat modulo 26 sehingga setelah `z / Z` kembali ke `a / A`.

```c
char text[] = "Download Success";
char text2[100];
memset(text2, 0, sizeof(text2));
int key = 5;
for(i = 0; i < strlen(text); i++){
    if((int)islower(text[i])) text2[i] = (text[i]-'a'+key)%26 + 'a';
    else if((int)isupper(text[i])) text2[i] = (text[i]-'A'+key)%26 + 'A';
    else text2[i] = text[i];
}
```

Setelah Caesar Cipher selesai dilakukan, masukkan hasil enkripsi ke file status.txt lalu keluar dari folder tersebut. Direktori kemudian di zip dan direktori akan didelete, sehingga menyisakan hanya file zip saja.

```c
FILE *filep;
filep = fopen("status.txt", "w");
fprintf(filep, "%s", text2);
fclose(filep);

chdir("..");
char curtime3[100];
sprintf(curtime3, "%s.zip", curtime);
char *arg[] = {"zip", "-rm", curtime3, curtime, NULL};
execv("/usr/bin/zip", arg);
```

#
### Jawab 3d
Kita diminta untuk membuat `Killer.sh` dimana program tersebut akan menterminasi semua proses program yang sedang berjalan dan akan menghapus dirinya sendiri setelah program dijalankan. Pada awalnya cek argumen yang diterima. Jika jumlah argumen dan isi argumen yang diinput tidak sesuai, maka keluarkan pesan `Mode hanya ada -z atau -x` agar user mengetahui argumen yang seharusnya diinputkan. Jalankan daemon karena kita ingin program utama ini berjalan di latar belakang. Buat program bash killer yang penjelasannya terdapat pada soal e.

```c
int main(int argc, char* argv[]) {
    if(argc != 2 || (argv[1][1] != 'z' && argv[1][1] != 'x')) {
        printf("Mode hanya ada -z atau -x\n");
        exit(0);
    }
    
    daemonstart();
    generatekiller(argv[1]);
    int status, status2;
    
    //lanjut soal a
}
```

Berikut isi dari fungsi `daemonstart()`.

```c
void daemonstart() {
    pid_t pid, sid;
    pid = fork();
    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if(sid < 0) exit(EXIT_FAILURE);
    if((chdir("/home/aldo/Sisop/Modul2/Soal3")) < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}
```

#
### Jawab 3e
Buat program killer sesuai mode yang diinputkan. Terdapat 2 mode:

- Mode `-z`. Ketika program killer dijalankan, maka program utama akan langsung menghentikan semua operasinya.

```bash
!/bin/bash

killall -9 soal3
echo 'Program killed successfully.'
rm $0
```

`killall -9 soal3` berguna untuk menghentikan semua proses yang berjalan dari soal3.

- Mode `-x`. Ketika program killer dijalankan, maka program utama akan berhenti namun membiarkan proses di setiap direktori yang masih berjalan hingga selesai (Direktori yang sudah dibuat akan mendownload gambar sampai selesai dan membuat file txt, lalu zip dan delete direktori).

```bash
!/bin/bash

kill %d
echo 'Program killed successfully.'
rm $0
```

`kill %d` berguna untuk menghentikan proses dari program utama saja. `%d` akan diisi oleh pid program utama.

Setelah program bash selesai dibuat, maka jalankan child untuk mengubah status file `Killer.sh` agar dapat dijalankan user.

```c
void generatekiller(char mode[]){
    FILE *filep;
    filep = fopen("Killer.sh", "w");
    
    if(strcmp(mode, "-z") == 0)
        fprintf(filep, "#!/bin/bash \n killall -9 soal3 \n echo \'Program killed successfully.\' \n rm \"$0\"");
    else if(strcmp(mode, "-x") == 0)
        fprintf(filep, "#!/bin/bash \n kill %d \n echo \'Program killed successfully.\' \n rm \"$0\"", getpid());

    fclose(filep);

    pid_t pid;
    pid = fork();
    if(pid == 0){
        char *arg[] = {"chmod", "+x", "Killer.sh", NULL};
        execv("/bin/chmod", arg);
    }
}
```

#
### Mode -z
![s31](https://user-images.githubusercontent.com/31863229/115901858-f30c2180-a48b-11eb-9843-08c5417265ac.PNG)
![s32](https://user-images.githubusercontent.com/31863229/115901869-f6071200-a48b-11eb-83d2-200d207116a8.PNG)
![s33](https://user-images.githubusercontent.com/31863229/115901873-f7383f00-a48b-11eb-847e-db92f88a0e9a.PNG)
![s34](https://user-images.githubusercontent.com/31863229/115901881-f99a9900-a48b-11eb-9363-a45882c5af11.PNG)
![s35](https://user-images.githubusercontent.com/31863229/115901891-fb645c80-a48b-11eb-83dc-e39999bc2c52.PNG)
![s36](https://user-images.githubusercontent.com/31863229/115901894-fc958980-a48b-11eb-9d21-282f44e5c600.PNG)

#
### Mode -x
![s37](https://user-images.githubusercontent.com/31863229/115901901-fe5f4d00-a48b-11eb-9396-50862aeb4325.PNG)
![s38](https://user-images.githubusercontent.com/31863229/115901911-00c1a700-a48c-11eb-831c-d8530f01acfc.PNG)

#
### Kendala
1. Saat ingin mendownload gambar dari `https://picsum.photos/` awalnya tidak tau bagaimana cara set ukurannya, ternyata tinggal tambahin angka pixelnya pada akhir link tersebut.
2. Bingung untuk membuat killer mode -x, ternyata kill saja parentnya sehingga child masih dapat berjalan dan nantinya berhenti sendiri terkena `execv`.
3. Sempat salah membuat `fork()` dimana child tidak saya beri `execv` sehingga child nya menggenerate child lagi dan linux saya sampai lag. Solusinya saya restart dan sudah kembali seperti semula.
