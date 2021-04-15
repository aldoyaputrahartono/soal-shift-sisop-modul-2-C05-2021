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

void daemonstart() {
    pid_t pid, sid;
    pid = fork();
    if(pid < 0) exit(EXIT_FAILURE);
    if(pid > 0) exit(EXIT_SUCCESS);
    umask(0);
    sid = setsid();
    if(sid < 0) exit(EXIT_FAILURE);
    if((chdir("/home/aldo/Sisop/Modul2/Soal1")) < 0) exit(EXIT_FAILURE);
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    daemonstart();
    int status, status2, status3, status4, status5, status6, status7, status8, status9, status10, status11, status12;
    
    while(1) {
        pid_t cid, cid1, cid2, cid3, cid4, cid5, cid6, cid7, cid8, cid9, cid10, cid11, cid12;
        
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        
		//soal e
		if(t->tm_mon == 3 && t->tm_mday == 9 && t->tm_hour == 16 && t->tm_min == 22 && t->tm_sec == 0) {
			cid = fork();
			if(cid < 0) exit(0);
			if(cid == 0) {
				//soal a
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

				//soal b
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

				//soal c
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

				//soal d
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
				
				while(wait(&status10) > 0);
				exit(0);
			}
		}
		
		//soal f
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
        
        //sudo date --set="2021-04-09 16:21:59"
        //sudo date --set="2021-04-09 22:21:59"
        
        while(wait(&status12) > 0);
        sleep(1);
    }
}
