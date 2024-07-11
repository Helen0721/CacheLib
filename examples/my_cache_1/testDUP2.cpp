#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <fcntl.h>              
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv){

	std::cout << "Starting in STDOUT " << STDOUT_FILENO << std::endl;
	int old_stdout;
        if((old_stdout = dup(STDOUT_FILENO)) < 0){
	       	perror("dup error");
		exit(errno);
	}

	int f1;
	int mode_flag = 066;		/*rw for all*/
	
	int open_flag;
	if (argc > 1) open_flag = O_CREAT|O_RDWR|O_TRUNC;
	else open_flag = O_CREAT|O_RDWR|O_APPEND;

        if( (f1 = open("test1",open_flag,mode_flag)) < 0){
		perror("open error");
		exit(errno);
	}
	
	std::cout << "f1: " << f1 <<std::endl;

	int d1;
	//int dup2(int oldfd, int newfd);
	//The file descriptor newfd refers to the same open file description as oldfd.	
	if ( (d1 = dup2(f1,STDOUT_FILENO)) < 0){
		perror("dup2 error in changing stdout");
		exit(errno);
	}
	
	std::cout << "dup2 to test1\n";
	std::cout << "new STDOUT: " << STDOUT_FILENO << std::endl;
	std::cout << "test test" << std::endl;
	
	int d2;
	if ( (d2 = dup2(old_stdout,STDOUT_FILENO)) < 0){
		perror("dup2 error in changing back stdout");
		exit(errno);
	}

	close(f1);
	close(old_stdout);
	std::cout << "this msg should be in old stdout" << std::endl;

	return 0;
}
