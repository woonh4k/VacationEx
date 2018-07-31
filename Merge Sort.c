#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ

int *origin;

int on;

void MergeSort(int *base, int n);

void ViewArr(int *arr, int n);

int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	origin = arr;
	on = 10;
	ViewArr(origin, on);
	MergeSort(arr, 10);
	ViewArr(origin, on);
	return 0;
}

void PrintSpace(int n);

void MergeSort(int *base, int n)
{  
	int ahalf = n / 2;                    //�迭�� ���� ����
	int bhalf = n - ahalf;                //�迭�� ���� ����
	int ai = 0, bi = ahalf;
	int i = 0;
	int *tbase = 0;

	if (n <= 1)                           //�迭�� ũ�Ⱑ 1���� �۰ų� ���� ��
	{
		return;
	}
	MergeSort(base, ahalf);                //���� �迭 ���ȣ��� ����
	PrintSpace(base - origin);
	ViewArr(base, ahalf);
	MergeSort(base + ahalf, bhalf);        //���� �迭 ���ȣ��� ����
	PrintSpace(base + ahalf - origin);
	ViewArr(base + ahalf, bhalf);
	tbase = (int *)malloc(sizeof(int)*n);  //�迭 ũ���� �ӽ� ������ �Ҵ�
	memcpy(tbase, base, sizeof(int)*n);    //�ӽ� ������ �迭 �޸� ����

	while ((ai<ahalf) && (bi<n))
	{
		if (tbase[ai] <= tbase[bi])        //������ ũ�ų� ���� ��
		{
			base[i] = tbase[ai];           //���� �迭�� ���Ҹ� ����
			ai++;
		}
		else
		{
			base[i] = tbase[bi];           //���� �迭�� ���Ҹ� ����
			bi++;
		}
		i++;
	}
	while (ai<ahalf)                      //���� �迭�� ���� �͵��� ����
	{
		base[i] = tbase[ai];
		i++;
		ai++;
	}
	while (bi<n)                         //���� �迭�� ���� �͵��� ����
	{
		base[i] = tbase[bi];
		i++;
		bi++;
	}
	free(tbase);                        //�ӽ� ���ۿ� �Ҵ��� �޸� ����       
}

void PrintSpace(int n)
{
	int i = 0;

	for (i = 0; i<n; i++)
	{
		printf("   ");
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