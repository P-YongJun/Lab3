#define _XOPEN_SOURCE 200
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	struct sigaction act;
	int i=0;
	act.sa_handler= SIG_IGN;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	printf("SIGINT off\n");
	while(1){
		sleep(1);
		printf("프로세스 정지 시간 : %d sec(s).\n", ++i);
	}
}