#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	//char meno[50];
	char pohlavie;
	int rok_narodenia;
	char spz[7];
	bool typ_priestupku;
	int vyska_pokuty;
	int datum_priestupku;
} PRIESTUPKY;

void k(FILE *subor) {
	fclose(subor);
	//free(arr);
	exit(EXIT_SUCCESS);
}

void o(PRIESTUPKY *p) {
	FILE *subor;
	int riadky = 0; // celkovy pocet (riadky/2+1)
	subor = fopen("priestupky.txt", "r");  // otvorenie suboru
	char temp;
	while (fscanf(subor, "%c", &temp) != EOF) {
		if (temp == '\n') {
			riadky++;
		}
	}
	p =  (PRIESTUPKY*)calloc((riadky/2+1), sizeof(PRIESTUPKY));
	rewind(subor);
	char sp[8];
	for (int i = 0, j = 0; i < riadky; i++) {
		/*if (i % 2 == 1) {
			while (fscanf(subor, "%c", &temp)) {
				if (temp == '\n') continue;
			}
		}*/
		fscanf(subor, " %c %d %s %d %d %d", &p[i].pohlavie, &p[i].rok_narodenia, &sp, &p[i].typ_priestupku, &p[i].vyska_pokuty, &p[i].datum_priestupku);
		strcpy(p[i].spz, sp);
		printf("%c %d %s %d %d %d\n", p[i].pohlavie, p[i].rok_narodenia, p[i].spz, p[i].typ_priestupku, p[i].vyska_pokuty, p[i].datum_priestupku);
	}
};

int main()
{
	PRIESTUPKY ludia, *p;
	p = &ludia;
	
	//FILE *subor;
	char vstup;
	while (scanf("%c", &vstup)) {
		switch (vstup) {
		case 'k':
			return 0;
			break;
		case 'o':
			o(p);
			break;
		case 'v':
			printf("%c\n", p[0].pohlavie);
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
