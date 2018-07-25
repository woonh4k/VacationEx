#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a = b; b = t;}   //스왑 매크로


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
	ViewArray(base, n);                            //현재 상태 출력
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (base[i] > base[j])                //앞의 자리 윈소가 뒷 자리의 원소보다 클 때
			{
				SWAP(base[i], base[j]);           //스왑
				ViewArray(base, n);               //스왑 결과 출력
			}
		}
	}
}

void ViewArray(int *arr, int n)                   //출력을 위한 함수
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

