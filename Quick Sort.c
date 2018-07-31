#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a�� b�� ��ȯ


int *origin;
int on;

void QuickSort(int *base, int n);
void ViewArr(int *arr, int n);
int main(void)
{
	int arr[10] = {6,1,7,5,4,10,8,3,9,2};
	origin = arr;
	on = 10;
	ViewArr(arr, 10);
	QuickSort(arr, 10);
	ViewArr(arr, 10);
	return 0;
}

void PrintSpace(int n);
void QuickSort(int *base, int n)
{
	int pivot = 0;                          // �ǹ��� ��ġ ����ϴ� ����
	int left = 0, right = 0;                // �ǹ����� ū ���� ���� ���� ��ġ�� ã������ ����

	if (n <= 1)
	{
		return;
	}

	left = 0;
	right = n;

	while (1)
	{
		for (left++; (left<n) && (base[0] >= base[left]); left++);     //���ʿ� �ǹ�(�ε��� 0�� �ִ� ����)���� ū ���� ���� ������ left�� �̵��մϴ�.
		for (right--; (right>0) && (base[0]<base[right]); right--);    //���ʿ� �ǹ�(�ε��� 0�� �ִ� ����)���� ���� ���� ���� ������ right�� �̵��Ѵ�.

		
		if (left<right)                                        //���� left�� right���� �۴ٸ� �ǹ��� ������ �� ���� ���� ū ������ �ڿ� ������ ��ȯ�Ѵ�.
		{
			SWAP(base[left], base[right]);
			PrintSpace(base - origin);
			ViewArr(base, n);
		}
		else
		{
			break;
		}
	}
	SWAP(base[0], base[right]);         //�ǹ��� �������� ū�� ���̷� ������.
	PrintSpace(base - origin);
	ViewArr(base, n);

	QuickSort(base, right);             //�ǹ����� ���� ������ �ִ� ������ ��� ȣ��� �����մϴ�.
	QuickSort(base + left, n - left);  	//�ǹ����� ū ������ �ִ� ������ ��� ȣ��� �����մϴ�.
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
