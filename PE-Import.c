#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	char* target = "I want to learn PE file format!";
	char buf[1024];
	FILE* fstream = fopen("PE-1.txt", "a+");
	int flag = 0;
	// read from fstream to buf by row
	while (fgets(buf, sizeof(buf), fstream)) {
		// target found
		if (strstr(buf, target)) {
			flag = 1;
			break;
		}
	}
	
	if (!flag) { // target not found
		fputs(target, fstream);
		fclose(fstream);
	}
	else { // target found
		rewind(fstream);
		while (fgets(buf, sizeof(buf), fstream)) {
			printf(buf, "\n");
		}
		fclose(fstream);
	}
}
