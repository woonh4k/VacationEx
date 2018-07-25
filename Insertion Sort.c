#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}    //스왑 매크로

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

	ViewArr(base, n);                        //현재 상태 출력
	for (i = 1; i<n; i++)                    //정렬할 범위를 점점 늘려간다. 
	{
		for (j = i; j>0; j--)
		{
			if (base[j - 1]>base[j])         //앞쪽 자리의 값이 더 클 경우
			{
				SWAP(base[j - 1], base[j]);  //스왑 
				ViewArr(base, n);            //정렬 결과 출력
			}
			else
			{
				break;
			}
		}
	}
}

void ViewArr(int *arr, int n)                  //출력을 위한 함수
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}