#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}    //스왑 매크로


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
	ViewArr(base, n);                           //현재 상태 출력
	for (i = n; i>1; i--)                       //정렬할 범위를 줄임
	{ 
		maxi = 0;
		for (j = 1; j<i; j++)
		{
			if (base[maxi]<base[j])             //제일 뒷 자리의 값보다 더 큰 값을 만나게 되면
			{
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);          //스왑
		ViewArr(base, n);                       //정렬 결과 출력
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