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
jawab 1a

#
### Jawab 1b
jawab 1b

#
### Jawab 1c
jawab 1c

#
### Jawab 1d
jawab 1d

#
### Jawab 1e
jawab 1e

#
### Jawab 1f
jawab 1f

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
jawab 2a

#
### Jawab 2b
jawab 2b

#
### Jawab 2c
jawab 2c

#
### Jawab 2d
jawab 2d

#
### Jawab 2e
jawab 2e

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
jawab 3c

#
### Jawab 3d
jawab 3d

#
### Jawab 3e
jawab 3e
