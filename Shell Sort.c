#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}                //치환 매크로

int *origin;
int on;

void ShellSort(int *base, int n);
int main(void)
{
	int arr[10] = { 10,7,5,8,1,3,2,4,6,9 };
	origin = arr;
	on = 10;
	ShellSort(arr, 10);
	return 0;
}
void InsertionSort(int *base, int size, int step);
void ViewArr(int *arr, int n);
void ShellSort(int *base, int size)
{
	int i, step;

	for (step = size / 2 ; step > 0 ; step /= 2)              //step의 폭을 1/2로 점점 줄인다
	{
		printf("step:%d\n", step);
		for (i = 0; i<step; i++)                          
		{
			InsertionSort(base + i, size - i, step);    //step 간격에 있는 값들을 삽입정렬한다.
		}
	}
}

void InsertionSort(int *base, int size, int step)
{
	int i, j;
	for (i = step; i<size; i += step)                  //정렬 대상 값은 step 간격으로 이동
	{

		for (j = i; j>0; j -= step)                   //step 간격으로 앞으로 이동
		{
			if (base[j - step]>base[j])               //앞쪽의 값이 더 큰 경우
			{
				SWAP(base[j - step], base[j]);       //치환 실행
				ViewArr(origin, on);
			}
			else
			{
				break;
			}
		}
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
