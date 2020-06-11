#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
	int i, num, pid;
	double sum = 0, j, step;
	
	if(argc < 2)
		num = 1; //default value
	else
		num = atoi(argv[1]); //from command line
	if (num < 0 || num > 20)
		num = 2;
	
	if (argc < 3)
		step = 0.1;
	else
		step = atoi(argv[2]); //from command line		

	sum = 0;
	pid = 0;
	for(i = 0; i < num; i++){
		pid = fork();
		if(pid < 0){
			printf(1, "%d failed in fork!\n",getpid());
					
		}
		else if(pid > 0){
			printf(1, "Parent %d creating child %d\n", getpid(), pid);
			chngpr(getpid(), 3);
			wait();
		}
		else{
			printf(1, "Child %d created\n", getpid());
			chngpr(getpid(), 3);
			for(j = 0; j < 9000000.0; j += step)
				sum = sum + 3.14 * 97.689;
			break;		
		}
		
	}
	exit();
}
