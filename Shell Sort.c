#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}                //ġȯ ��ũ��

int *origin;
int on;

void ShellSort(int *base, int n);
int main(void)
{
	int arr[10] = { 10,7,5,8,1,3,2,4,6,9 };
	origin = arr;
	on = 10;
	ShellSort(arr, 10);
	return 0;
}
void InsertionSort(int *base, int size, int step);
void ViewArr(int *arr, int n);
void ShellSort(int *base, int size)
{
	int i, step;

	for (step = size / 2 ; step > 0 ; step /= 2)              //step�� ���� 1/2�� ���� ���δ�
	{
		printf("step:%d\n", step);
		for (i = 0; i<step; i++)                          
		{
			InsertionSort(base + i, size - i, step);    //step ���ݿ� �ִ� ������ ���������Ѵ�.
		}
	}
}

void InsertionSort(int *base, int size, int step)
{
	int i, j;
	for (i = step; i<size; i += step)                  //���� ��� ���� step �������� �̵�
	{

		for (j = i; j>0; j -= step)                   //step �������� ������ �̵�
		{
			if (base[j - step]>base[j])               //������ ���� �� ū ���
			{
				SWAP(base[j - step], base[j]);       //ġȯ ����
				ViewArr(origin, on);
			}
			else
			{
				break;
			}
		}
	}
}
void ViewArr(int *arr, int n)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}
