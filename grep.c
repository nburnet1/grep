//Noah Burnette
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc < 2){
		fprintf(stderr,"Usage: <char*> <input file>\n");
		exit(1);
	}
	FILE *fp = fopen(argv[2],"r");
	if(fp == NULL){
		fprintf(stderr,"File: <%s> not found\n",argv[2]);
		exit(1);
	}
	int c = getc(fp);
	if(c == EOF){
		fprintf(stderr,"File: <%s> is empty\n",argv[2]);
		exit(1);
	}
	char *str = argv[1];
	int length = strlen(str);
	int count = 0;
	while(c !=  EOF){
		if(str[count] == c){
			count ++;
		}
		else if(str[count] != c){
			count = 0;
		}
		if(count == length){
			printf("File: <%s> contains \"%s\"\n",argv[2],argv[1]);
			exit(0);
		}
		c = getc(fp);
	}
	printf("File: <%s> does not contain \"%s\"\n",argv[2],argv[1]);
	fclose(fp);
	exit(1);
}
