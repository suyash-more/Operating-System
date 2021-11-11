#include <stdio.h>
#include <unistd.h>

int main(){

	int pipefds[2];
	int returnstatus;
	char writemessage[2][20]={"hi ","hello"};
	char readmessage[20];
	returnstatus = pipe(pipefds);

	if(returnstatus==-1)
	{
		printf("Unable to create pipe\n");
		return 1;
	}

	printf("Writing to pipe message 1 is - %s\n",writemessage[0]);

	write(pipefds[1],writemessage[0],sizeof(writemessage[0]));
	read(pipefds[0],readmessage,sizeof(readmessage));
	printf("reading from pipe message 1 is - %s\n",readmessage);


	printf("Writing to pipe message 2 is - %s\n",writemessage[1]);
	write(pipefds[1],writemessage[1],sizeof(writemessage[1]));
	read(pipefds[0],readmessage,sizeof(readmessage));
	printf("reading from pipe message 2 is - %s\n",readmessage);
	return 0;

}
