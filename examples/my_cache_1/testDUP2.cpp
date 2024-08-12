#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <iostream>
#include <fcntl.h>              
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void test1(){
	
	std::cout << "Starting in STDOUT " << STDOUT_FILENO << std::endl;
	int old_stdout;
        if((old_stdout = dup(STDOUT_FILENO)) < 0){
	       	perror("dup error");
		exit(errno);
	}
	
	int f1;
	int mode_flag = 0666;		/*rw for all*/
	
	int open_flag;
	open_flag = O_CREAT|O_RDWR|O_TRUNC;

        if( (f1 = open("test1",open_flag,mode_flag)) < 0){
		perror("open error");
		exit(errno);
	}
	const char *buf = "hello";
	if (write(f1,(void *)buf,strlen(buf)) < 0) {
		perror("write error");
		exit(errno);
	}
	
	system("ls -l test1");

	
	std::cout << "redirecting to f1 " << f1 <<std::endl;

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
	
	if (close(f1)!=0) {perror("close error in closing output file"); exit(errno); }
	if (close(old_stdout)!=0) {perror("close error in old stdout file"); exit(errno); }

	std::cout << "this msg should be in old stdout" << std::endl;
	system("ls -l test1");
}

void test2(){
	std::cout << "Starting in STDOUT " << STDOUT_FILENO << std::endl;
	int old_stdout;
        if((old_stdout = dup(STDOUT_FILENO)) < 0){
	       	perror("dup error");
		exit(errno);
	}

	int f1;
	int mode_flag = 0666;		/*rw for all*/
	
	std::cout << "trying again" << std::endl;
	
	if( (f1 = open("test1",O_CREAT|O_RDWR|O_APPEND,mode_flag)) < 0){
		perror("open error in test2");
		exit(errno);
	}
	
	std::cout << "f1 again: " << f1 <<std::endl;

	system("ls -l test1");
	//int dup2(int oldfd, int newfd);
	//The file descriptor newfd refers to the same open file description as oldfd.	
	int d1;
	if ( (d1 = dup2(f1,STDOUT_FILENO)) < 0){
		perror("dup2 error in test2 when changing stdout");
		exit(errno);
	}
	
	std::cout << "dup2 to test1\n";
	std::cout << "new STDOUT: " << STDOUT_FILENO << std::endl;
	std::cout << "test2 test2" << std::endl;
	
	int d2;
	if ( (d2 = dup2(old_stdout,STDOUT_FILENO)) < 0){
		perror("dup2 error in test2 when changing back stdout");
		exit(errno);
	}

	if (close(f1)!=0) {perror("close error in test2 in closing output file"); exit(errno); }
	if (close(old_stdout)!=0) {perror("close error in test2 in old stdout file"); exit(errno); }

	std::cout << "this msg should be in old stdout" << std::endl;
	system("ls -l test1");
}




int main(int argc, char** argv){
	test1();
	if (argc > 1) test2();
	return 0;
}
