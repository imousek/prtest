#include <stdio.h>
#include <stdlib.h>

void k(FILE *subor, int *arr) {
	fclose(subor);
	free(arr);
	exit(EXIT_SUCCESS);
}

int main()
{
	FILE *subor;
	char vstup;
	int *arr = (int*)malloc(10*sizeof(int));
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	subor = fopen("priestupky.txt", "r");  // otvorenie suboru
	while (scanf("%c", &vstup)) {
		switch (vstup) {
		case 'k':
			k(subor, arr);
			break;
		case 'o':
			break;
		case 'v':
			break;
		case 'x':
			break;
		case 'r':
			break;
		case 'p':
			break;
		case 'a':
			break;
		}
	}
}
