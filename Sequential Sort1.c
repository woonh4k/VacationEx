#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a = b; b = t;}   //���� ��ũ��


void SequenceSort(int *base, int n);
int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	SequenceSort(arr, 10);
	return 0;
}
void ViewArray(int *arr, int n);
void SequenceSort(int *base, int n)
{
	int i, j;
	ViewArray(base, n);                            //���� ���� ���
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (base[i] > base[j])                //���� �ڸ� ���Ұ� �� �ڸ��� ���Һ��� Ŭ ��
			{
				SWAP(base[i], base[j]);           //����
				ViewArray(base, n);               //���� ��� ���
			}
		}
	}
}

void ViewArray(int *arr, int n)                   //����� ���� �Լ�
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

