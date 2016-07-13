#include <stdio.h>

int main (int argc, char** argv){
	execve("/bin/sh");
	return 0;
} 
