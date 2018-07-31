#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환


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
	int pivot = 0;                          // 피벗의 위치 기억하는 변수
	int left = 0, right = 0;                // 피벗보다 큰 값과 작은 값의 위치를 찾기위한 변수

	if (n <= 1)
	{
		return;
	}

	left = 0;
	right = n;

	while (1)
	{
		for (left++; (left<n) && (base[0] >= base[left]); left++);     //앞쪽에 피벗(인덱스 0에 있는 원소)보다 큰 값을 만날 때까지 left를 이동합니다.
		for (right--; (right>0) && (base[0]<base[right]); right--);    //뒤쪽에 피벗(인덱스 0에 있는 원소)보다 작은 값을 만날 때까지 right를 이동한다.

		
		if (left<right)                                        //만약 left가 right보다 작다면 피벗과 비교했을 때 작은 값이 큰 값보다 뒤에 있으니 교환한다.
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
	SWAP(base[0], base[right]);         //피벗을 작은값과 큰값 사이로 보낸다.
	PrintSpace(base - origin);
	ViewArr(base, n);

	QuickSort(base, right);             //피벗보다 작은 값들이 있는 앞쪽을 재귀 호출로 정렬합니다.
	QuickSort(base + left, n - left);  	//피벗보다 큰 값들이 있는 뒤쪽을 재귀 호출로 정렬합니다.
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
