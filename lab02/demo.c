#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct angajat {
    char *nume;
    int id;
    double salariu;
    char keyCode;
} Angajat;


void dosomething() {

	printf("Nothing\n");
}

int add(int a, int b) {
    return a + b;
}
 
int substract(int a, int b) {
    return a - b;
}
 
int operation(int x, int y, int (*func) (int, int)) {
    return func(x, y);
}

void special_printf(void *p, int size) {

	if (size == sizeof(int)) {
		int *nr = (int*) p;
		printf("%d\n", *nr);
	}

	if (size == sizeof(char)) {
		char *nr = (char*) p;
		printf("%c\n", *nr);
	}

	if (size == sizeof(short)) {
		short *nr = (short*) p;
		printf("%hd\n", *nr);
	}

	if (size == sizeof(double)) {
		double *nr = (double*) p;
		printf("%.2lf\n", *nr);
	}

}

int main() {


	int nr = 2;

	int *p = &nr;


	// pointerii pot retine adresa unor date de un anumit tip
	printf("%p - %p\n", p, &nr);

	void *t = &dosomething;
	// pointerii pot retine adresa unor functii
	printf("%p - %p\n", t, &dosomething);

	p = (int*) calloc(1, sizeof(int));

	// pointerii pot reprezenta adresa unei zone de memorie
	printf("%p\n", p);


	// dimensiunea pointerilor 
	printf("%d\n\n", sizeof(void *));

	int intnr = 4;
	double doublenr = 2.893;
	short shortnr = 2;
	char charnr = 'c';

	special_printf(&charnr, sizeof(char));
	special_printf(&doublenr, sizeof(double));
	special_printf(&shortnr, sizeof(short));
	special_printf(&intnr, sizeof(int));

	printf("\n\n");

	int v[10] = {89, 7, 9 , 3, 2};

	printf("%d\n", sizeof(v));
	printf("%d\n", v[5]);

	int arr[] = {5, 7, 9 , 3, 2, -9};
	printf("%d\n", sizeof(arr));
	printf("%d\n", arr[5]);

	printf("%p - %p\n", v, arr);

	printf("%d\n", v - arr);

	char *s1 = "Lab2 PCLP2";
	char *s2 = s1;

	for (; *s2 != '\0'; s2++);

	printf("%d\n", s2 - s1);
	int *v2 = v;
	printf("%p\n", v);
	printf("%p\n", ++v2);
	//printf("%p\n", ++v);


	// partea a 2a
	printf("%d\n", *v2++);
	printf("%d\n", *v2);
	printf("%d\n", ++*v2);
	printf("%d\n", *++v2);
	printf("%d\n", (*v2)++);
	printf("%d\n", *v2);
	printf("\n\n");


	int n = 0xCAFEBABE;
	unsigned char first_byte = *((unsigned char*) &n); /* Se extrage primul byte al lui n */
	unsigned char second_byte = *((unsigned char*) &n + 1); /* Se extrage al doilea byte al lui n */
	printf("0x%x, 0x%x\n", first_byte, second_byte);

	printf("\n\n");
	int nrows = 5, ncolumns = 5;
	int **array1 = (int **) malloc(nrows * sizeof(*array1));
	for(int i = 0; i < nrows; ++i)
    	array1[i] = (int*) malloc(ncolumns * sizeof(**array1));
    printf("%p - %p\n", &array1[0][ncolumns - 1], &array1[1][0]);

	int **array2 = malloc(nrows * sizeof(*array2));
	array2[0] = malloc(nrows * ncolumns * sizeof(**array2));
	for(int i = 1; i < nrows; ++i)
	    array2[i] = array2[0] + i * ncolumns;
	printf("%p - %p\n", &array2[0][ncolumns - 1], &array2[1][0]);

	Angajat ang;
	ang.id = 1;
	ang.nume = strdup("Ionescu Gigel");
	ang.salariu = 1400;
	ang.keyCode = 'A';
	printf("Angajat nume : %s, id = %d, salariu = %.2lf, keyCode = %c \n", ang.nume, ang.id, ang.salariu, ang.keyCode);

	Angajat *ang2 = (Angajat *) malloc(sizeof(Angajat));
	ang2->id = 2;
	ang2->nume = strdup("Popescu Dorel");
	ang2->salariu = 2500;
	ang2->keyCode = 'B';
	printf("Angajat nume : %s, id = %d, salariu = %.2lf keycode = %c \n", ang2->nume, ang2->id, ang2->salariu, ang2->keyCode);

	Angajat *ang3 = &ang;
	ang3->salariu = 3000;
	ang3->keyCode = 'C';
	printf("Angajat nume : %s, id = %d, salariu = %.2lf, keyCode = %c \n", ang.nume, ang.id, ang.salariu, ang.keyCode);
	
	printf("Size = %d\n", sizeof(Angajat));


	int (*minus)(int, int) = substract;
	printf("%d\n", operation(10, 5, minus));
	minus = add;
	printf("%d\n", operation(10, 5, minus));
	return 0;

}