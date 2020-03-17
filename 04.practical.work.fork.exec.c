#include <stdio.h>
#include <unistd.h>

void main(){
	int pid1 = fork();
	int pid2 = fork();

	if (pid1==0 && pid2==0) return;
	else if (pid1==0){
		printf("I'm launching ps -ef\n");
		execl("/bin/ps","ps","-ef",NULL);
	}
	else if (pid2==0){
		printf("I'm launching free -h\n");
		execl("/usr/bin/free","free","-h",NULL);
	} 
	else printf("I'm parent, child is %d and %d\n",pid1,pid2);

	return;
}
