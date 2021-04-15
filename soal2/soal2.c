#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<syslog.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<wait.h>
#include<dirent.h>

int main() {
    int status, status2, status3;
    
    //soal a
    pid_t cid;
    cid = fork();
    if(cid < 0) exit(0);
    if(cid == 0) {
        char *arg[] = {"unzip", "-o", "-q", "/home/aldo/modul2/pets.zip", "-d", "/home/aldo/modul2/petshop", NULL};
        execv("/usr/bin/unzip", arg);
    }
    
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
    
    //soal b
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
    
    //soal c
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
            
            //soal d
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
            //akhir soal d
            
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
            
            
            //soal e
            while(wait(&status) > 0);
            char ket[300];
            sprintf(ket, "/home/aldo/modul2/petshop/%s/keterangan.txt", tmp2_jenis);
            FILE *filep;
            filep = fopen(ket, "a+");
            fprintf(filep, "nama : %s\n", tmp2_nama);
            fprintf(filep, "umur : %s tahun\n\n", tmp2_umur);
            fclose(filep);
            //akhir soal e
            
            //soal d
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
                
                //soal e
                while(wait(&status2) > 0);
                char ket[300];
                sprintf(ket, "/home/aldo/modul2/petshop/%s/keterangan.txt", tmp3_jenis);
                FILE *filep;
                filep = fopen(ket, "a+");
                fprintf(filep, "nama : %s\n", tmp3_nama);
                fprintf(filep, "umur : %s tahun\n\n", tmp3_umur);
                fclose(filep);
                //akhir soal e
            }
            //akhir soal d
        }
    }
}
