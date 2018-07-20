#include <stdio.h>

int main(void)
{
	int i, j = 0;
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int result[20] = { 0 };

	for (i = 0; i<10; i++) {
		j++;
		arr1[i] = j;
	}
	j = 0;
	for (i = 0; i<10; i++) {
		j++;
		arr2[i] = j;
	}
	for (i = 0; i < 10; i++) {
		result[i * 2] = arr1[i];
		result[i * 2 + 1] = arr2[i];
	}

	for (i = 0; i<20; i++)
		printf("%d ", result[i]);

}