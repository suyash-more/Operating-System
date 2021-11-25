#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int buffer_len = 0, line_count = 0,j=0;
    char c;
    FILE *fptr;
    //will take in the path and the permission level to be provided
    mkfifo("myfifo", 0777);
    while (1)
    {
        line_count = 0;
        int fd = open("myfifo", O_RDONLY);
        read(fd, str1, 100);
        printf("User 1 : %s\n", str1);
        close(fd);

        fd = open("myfifo", O_WRONLY);
        fgets(str2, 100, stdin);
        
        buffer_len = strlen(str2);
        while(c!=EOF){
            c = str1[j];
            if (c == '\n') 
                line_count = line_count + 1;
            j++;
        }
        fptr = fopen("./pipe_buffer.txt", "a");
        fprintf(fptr, "Buffer len - %d  No. of lines - %d \n", buffer_len, line_count);
        fclose(fptr);
        write(fd, str2, strlen(str2) + 1);
        close(fd);
    }
    return 0;
}