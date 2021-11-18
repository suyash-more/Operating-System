#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(){
    char str1[100], str2[100];

    //will take in the path and the permission level to be provided
    mkfifo("myfifo", 0777);
    while(1){
        int fd = open("myfifo", O_RDONLY);
        read(fd, str1, 100);
        printf("User 1 : %s\n", str1);
        close(fd);

        fd = open("myfifo", O_WRONLY);
        fgets(str2, 100, stdin);
        write(fd, str2, strlen(str2)+1);
        close(fd);
    }
    return 0;
}