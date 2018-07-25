#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}    //스왑 매크로


void BubbleSort(int *base, int n);
int main(void)
{
	int arr[10] = { 9,4,3,10,5,8,7,6,2,1 };
	BubbleSort(arr, 10);
	return 0;
}
void ViewArr(int *arr, int n);
void BubbleSort(int *base, int n)
{
	int i, j;
	ViewArr(base, n);                          //현재 상태 출력
	for (i = n; i>1; i--)                      //정렬할 범위를 점점 줄임. 큰 값을 먼저 뒤로 배치하기 떄문
	{
		for (j = 1; j<i; j++)
		{
			if (base[j - 1]>base[j])           //비교하여 앞 자리의 값이 더 크면
			{
				SWAP(base[j - 1], base[j]);    //스왑
				ViewArr(base, n);              //정렬 결과 출력
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

