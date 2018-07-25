#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}    //���� ��ũ��

void InsertionSort(int *base, int n);
int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	InsertionSort(arr, 10);
	return 0;
}
void ViewArr(int *arr, int n);
void InsertionSort(int *base, int n)
{
	int i, j;

	ViewArr(base, n);                        //���� ���� ���
	for (i = 1; i<n; i++)                    //������ ������ ���� �÷�����. 
	{
		for (j = i; j>0; j--)
		{
			if (base[j - 1]>base[j])         //���� �ڸ��� ���� �� Ŭ ���
			{
				SWAP(base[j - 1], base[j]);  //���� 
				ViewArr(base, n);            //���� ��� ���
			}
			else
			{
				break;
			}
		}
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