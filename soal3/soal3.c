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

void generatekiller(char mode[]){
    FILE *filep;
    filep = fopen("Killer.sh", "w");

    //soal e
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

int main(int argc, char* argv[]) {
    if(argc != 2 || (argv[1][1] != 'z' && argv[1][1] != 'x')) {
        printf("Mode hanya ada -z atau -x\n");
        exit(0);
    }

    //soal d
    daemonstart();
    generatekiller(argv[1]);
    int status, status2;

    while(1) {
        char curtime[100];
    	pid_t cid, cid2, cid3, cid4, cid5;
        
        //soal a
        time_t now = time(NULL);
        struct tm *t1 = localtime(&now);
        strftime(curtime, sizeof(curtime)-1, "%Y-%m-%d_%H:%M:%S", t1);

        cid = fork();
        if(cid < 0) exit(0);
        if(cid == 0) {
            cid2 = fork();
            if(cid2 < 0) exit(0);
            if(cid2 == 0) {
                char *arg[] = {"mkdir", curtime, NULL};
                execv("/bin/mkdir", arg);
            }
            
            while(wait(&status) > 0);
            
            //soal b
            chdir(curtime);
            int i = 0;
            char link[100], curtime2[100];
            while(i < 10) {
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

                i++;
                sleep(5);
            }
            
            while(wait(&status2) > 0);

            //soal c
            char text[] = "Download Success";
            char text2[100];
            memset(text2, 0, sizeof(text2));
            int key = 5;
            for(i = 0; i < strlen(text); i++){
                if((int)islower(text[i])) text2[i] = (text[i]-'a'+key)%26 + 'a';
                else if((int)isupper(text[i])) text2[i] = (text[i]-'A'+key)%26 + 'A';
                else text2[i] = text[i];
            }
            
            FILE *filep;
            filep = fopen("status.txt", "w");
            fprintf(filep, "%s", text2);
            fclose(filep);

            chdir("..");
            char curtime3[100];
            sprintf(curtime3, "%s.zip", curtime);
            char *arg[] = {"zip", "-rm", curtime3, curtime, NULL};
            execv("/usr/bin/zip", arg);
        }
        
        sleep(40);
    }
}
