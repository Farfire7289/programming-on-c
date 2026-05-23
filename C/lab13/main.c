#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*Íàïèñàòü ïðîãðàììó, îáðàáàòûâàþùóþ ïîëó÷åíèå ñèãíàëîâ 
(SIGABRT, SIGFPE, SIGILL, SIGINT, SIGSEGV, SIGTERM). 
Òàêæå ïðîãðàììà, ìîæåò âîçáóæäàòü ýòè ñèãíàëû ïî óêàçàíèþ ïîëüçîâàòåëÿ. 
Â êà÷åñòâå îáðàáîò÷èêà äîëæíî áûòü ðåàëèçîâàíî ëîãèðîâàíèå (âûâîä íà êîíñîëü).*/

void handler(int sig){
	switch(sig){
		case SIGABRT:
			printf("Signal handler ABRT: %d.\n", sig);
			break;
		case SIGFPE:
			printf("Signal handler FPE: %d.\n", sig);
			break;
		case SIGILL:
			printf("Signal handler ILL: %d.\n", sig);
			break;
		case SIGINT:
			printf("Signal handler INT: %d.\n", sig);
			break;
		case SIGSEGV:
			printf("Signal handler SEGV: %d.\n", sig);
			break;
		case SIGTERM:
			printf("Signal handler TERM: %d.\n", sig);
			break;
		default: 
			printf("Signal handler: %d.\n", sig);
			break;
	}
}
int main(void) {
	
/*	void(*f)(int);
	signal(SIGTERM, handler);*/
	if(signal(SIGABRT, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	if(signal(SIGFPE, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	if(signal(SIGILL, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	if(signal(SIGINT, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	if(signal(SIGSEGV, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	if(signal(SIGTERM, handler) == SIG_ERR){
		printf("Signal set failed.\n");
		return 1;
	}
	
	int choice;
	int x = 24/0;
	printf("%d", x);
	printf("CHOOSE:\n 0-END THE CYCLE OF VIOLENCE\n 1-SIGABRT\n 2-SIGFPE\n 3-SIGILL\n 4-SIGINT\n 5-SIGSEGV\n 6-SIGTERM\n");
	
	while(1){
		printf("Your choice: ");
		scanf("%d", &choice);
		printf("Raising signal.\n");
		
		switch(choice){
			case 0:
				printf("CLOSING... THANKS FOR THE FREEDO-");
				return 0;
			case 1:
				printf("Raising SIGABRT...\n");
				raise(SIGABRT);
				break;
			case 2:
				printf("Raising SIGFPE...\n");
				raise(SIGFPE);
				break;
			case 3:
				printf("Raising SIGILL...\n");
				raise(SIGILL);
				break;
			case 4:
				printf("Raising SIGAINT...\n");
				raise(SIGINT);
				break;
			case 5:
				printf("Raising SIGSEGV...\n");
				raise(SIGSEGV);
				break;
			case 6:
				printf("Raising SIGTERM...\n");
				raise(SIGTERM);
				break;
			default:
				printf("Wrong choice, please be a good human and rechoice from 0-6\n");
				continue;	
		
		printf("Signal is raised, be happy.");
		
	}
	}
	return 0;
}
