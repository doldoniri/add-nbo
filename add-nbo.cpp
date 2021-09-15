#include <stdio.h>
#include <stdint.h> // uint32_t
#include <netinet/in.h> // htons, ntohl

int main(int argc, char *argv[]){
	
	if(argc <= 2){
		printf("syntax : add-nbo <file1> <file2>\n");
		printf("sample : add-nbo a.bin b.bin\n");
	
		return 0;
	}

	uint32_t a1, a2;
	uint32_t sum;

	FILE * file1 = fopen(argv[1], "r");
	FILE * file2 = fopen(argv[2], "r");

	fread(&a1, sizeof(a1), 1, file1);
	fread(&a2, sizeof(a2), 1, file2);

	fclose(file1);
	fclose(file2);

	a1 = ntohl(a1);
	a2 = ntohl(a2);
	
	sum = a1+a2;

	printf(("%d(0x%x) + %d(0x%x) = %d(0x%x)\n"), a1, a1, a2, a2, sum, sum);
	
}

