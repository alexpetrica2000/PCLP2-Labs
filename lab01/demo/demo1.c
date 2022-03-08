#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin(char c)
{
    unsigned i;
    for (i = 1 << 7; i > 0; i = i / 2)
        (c & i) ? printf("1") : printf("0");
    printf("\n");
}
void binVar2(unsigned n)
{
    unsigned i;
    for (i = 1 << 15; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}

int main() {

	printf("----Shift Operations----\n");
	int n = 1 + 1 << 4;
	printf("n = %d\n", n);

	int n2 = 1 + (1 << 4);
	printf("n_ok = %d\n", n2);

	int n_shift = 1 << 32;
	printf("n_shift = %d\n", n_shift);

	long long n_ll_shift = 1 << 32;
	printf("n_ll_shift = %lld\n", n_ll_shift);

	long long n_ll_shift_ok = 1LL << 32;
	printf("n_ll_shift_ok = %lld\n", n_ll_shift_ok);

	char c = 0b11111111;

	printf("\n");
	// %x - hex int (4)
	// %hx - hex short (2)
	// %hhx - hex char (1)

	printf("See the diff\n");
	printf("%hhd\n",c);
	printf("%hhu\n\n",c);

	printf("----Inv----\n");
	bin(~c);
	printf("\n");


	char a = 0b00001111;
	char b = ~a;

	printf("----AND----\n");
	printf("first is "); bin(a);
	printf("second is "); bin(b);
	printf("first & second is ");
	bin(a & b);
	printf("\n");

	printf("----OR----\n");
	printf("first is "); bin(a);
	printf("second is "); bin(b);
	printf("first & second is ");
	bin(a | b);
	printf("\n");

	a = 0b11001100;
	printf("----XOR----\n");
	printf("first is "); bin(a);
	printf("second is "); bin(b);
	printf("first & second is ");
	bin(a ^ b);
	printf("\n");

	printf("----SHIFT LEFT---\n");
	bin(a << 1);
	printf("\n");

	printf("----SHIFT RIGHT---\n");
	bin(a >> 1);
	printf("\n");

	int var = 0xD9B1;

	printf("Number is %d\n\n", var);

	binVar2(var);
	printf("\n");

	printf("Size of data Types bits + bytes\n");
	printf("char : %u bits %u bytes\n", 8 * sizeof(char), sizeof(char));
	printf("short : %u bits %u bytes\n", 8 * sizeof(short), sizeof(short));
	printf("int : %u bits %u bytes\n", 8 * sizeof(int), sizeof(int));
	printf("long : %u bits %u bytes\n", 8 * sizeof(long), sizeof(long));
	printf("long long : %u bits %u bytes\n", 8 * sizeof(long long), sizeof(long long));
	printf("pointer : %u bits %u bytes\n", 8 * sizeof(int*), sizeof(int*));

	printf("\n----Arrays---- \n");

	int arr[] = {0xABCDEFF0, 0xCAFEBABE, 0x6A8BF3B1, 0x3DA49FA3};

	printf("%x\n", *(arr+ 3));

	printf("%x\n", *(arr) + 1);

	printf("%p\n", arr);

	printf("%p\n", arr + 1);

	printf("%p\n", arr + 2);

	printf("Why are they the same? %p %p", &arr[0], arr);

	printf("\n----Little or Big Endian----\n");

	c = *(arr + 1);

	printf("%hhx\n", c);

	unsigned char *p = (unsigned char*) (arr + 2);

	printf("%hhx == b1 -> Little Endian \n", *p);

	printf("\nWhy void pointer?\n");

	void *pointer;

	pointer = &c;

	printf("c == pointer? %x == %x\n", c, *(char*) pointer);

	pointer = arr;

	printf("arr[0] == pointer? %x == %x\n", arr[0], *(int*) pointer);



	return 0;
}

