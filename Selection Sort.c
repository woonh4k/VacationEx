#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}    //���� ��ũ��


void SelectionSort(int *base, int n);
int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	SelectionSort(arr, 10);
	return 0;
}
void ViewArr(int *arr, int n);
void SelectionSort(int *base, int n)
{
	int i, j;
	int maxi;
	ViewArr(base, n);                           //���� ���� ���
	for (i = n; i>1; i--)                       //������ ������ ����
	{ 
		maxi = 0;
		for (j = 1; j<i; j++)
		{
			if (base[maxi]<base[j])             //���� �� �ڸ��� ������ �� ū ���� ������ �Ǹ�
			{
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);          //����
		ViewArr(base, n);                       //���� ��� ���
	}
}

void ViewArr(int *arr, int n)                  //����� ���� �Լ�
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}