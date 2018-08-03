#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}
#define LEFT_CHILD(x)    (2*x + 1)
#define RIGHT_CHILD(x) (2*x + 2)
#define PARENT(x)        ((x-1)/2)

int *origin;
int on;

void SequentialSort(int * base, int n);
void BubbleSort(int *base, int n);
void SelectionSort(int *base, int n);
void InsertionSort(int *base, int n);
void ShellSort(int *base, int size);
void QuickSort(int *base, int n); 
void InsertionSort1(int *base, int size, int step);
void MergeSort(int *base, int n);
void HeapSort(int *base, int n);
void InitHeap(int *base, int n);
void MakeHeap(int *base, int n);
int FindMaxIndex(int *base, int n, int now);
void PrintSpace(int n);
void ViewArr(int *arr, int n);
void showmenu();

int main(void) {
	int arr[10] = { 0 };
	int a, i;
	int select;

	for (i = 0; i < 10; i++) {
		printf(" %d 번째 정수를 입력하시오 : ", i + 1);
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				printf("중복입니다!\n");
			}
		}
		
	}
	printf("입력하신 정수는 ");
	for (i = 0; i < 10; i++) {
		printf(" %d ", arr[i]);
	}
	printf(" 입니다. ");
	showmenu();
	printf("\n | 원하시는 정렬을 선택하세요 => ");
	scanf("%d", &select);
	switch (select) {
		case 1 :  
			SequentialSort(arr, 10);
			break;
		case 2 :
			BubbleSort(arr, 10);
			break;
		case 3 :
			SelectionSort(arr, 10);
			break;
		case 4 :
			InsertionSort(arr, 10);
			break;
		case 5 : 
			ShellSort(arr, 10);
			break;
		case 6 :
			QuickSort(arr, 10);
			break;
		case 7 :
			MergeSort(arr, 10);
			break;
		case 8 :
			HeapSort(arr, 10);
			break;
		case 9 :
			exit(0);
	}
	return 0;
}
void showmenu() {
	printf("\n\n | ******** 정렬 프로그램 ******** |");
	printf("\n | (1) 순차 정렬 - Sequential Sort |");
	printf("\n | (2) 버블 정렬 - Bubble Sort     |");
	printf("\n | (3) 선택 정렬 - Selection Sort  |");
	printf("\n | (4) 삽입 정렬 - Insertion Sort  |");
	printf("\n | (5)  쉘  정렬 - Shell Sort      |");
	printf("\n | (6)  퀵  정렬 - Quick Sort      |");
	printf("\n | (7) 병합 정렬 - Merge Sort      |");
	printf("\n | (8)  힙  정렬 - Heap Sort       |");
	printf("\n | (9)      실  행  종  료         |");

}

void SequentialSort(int *base, int n)
{
	int i, j;
	ViewArr(base, n);                            //현재 상태 출력
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (base[i] > base[j])                //앞의 자리 윈소가 뒷 자리의 원소보다 클 때
			{
				SWAP(base[i], base[j]);           //스왑
				ViewArr(base, n);               //스왑 결과 출력
			}
		}
	}
}
 
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

void ShellSort(int *base, int size)
{
	int i, step;

	for (step = size / 2; step > 0; step /= 2)              //step의 폭을 1/2로 점점 줄인다
	{
		printf("step:%d\n", step);
		for (i = 0; i<step; i++)
		{
			InsertionSort1(base + i, size - i, step);    //step 간격에 있는 값들을 삽입정렬한다.
		}
	}
}

void InsertionSort1(int *base, int size, int step)
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

void MergeSort(int *base, int n)
{
	int ahalf = n / 2;                    //배열의 앞쪽 개수
	int bhalf = n - ahalf;                //배열의 뒤쪽 개수
	int ai = 0, bi = ahalf;
	int i = 0;
	int *tbase = 0;

	if (n <= 1)                           //배열의 크기가 1보다 작거나 같을 때
	{
		return;
	}
	MergeSort(base, ahalf);                //앞쪽 배열 재귀호출로 정렬
	PrintSpace(base - origin);
	ViewArr(base, ahalf);
	MergeSort(base + ahalf, bhalf);        //뒤쪽 배열 재귀호출로 정렬
	PrintSpace(base + ahalf - origin);
	ViewArr(base + ahalf, bhalf);
	tbase = (int *)malloc(sizeof(int)*n);  //배열 크기의 임시 공간을 할당
	memcpy(tbase, base, sizeof(int)*n);    //임시 공간에 배열 메모리 복사

	while ((ai<ahalf) && (bi<n))
	{
		if (tbase[ai] <= tbase[bi])        //뒤쪽이 크거나 같을 때
		{
			base[i] = tbase[ai];           //앞쪽 배열의 원소를 대입
			ai++;
		}
		else
		{
			base[i] = tbase[bi];           //뒤쪽 배열의 원소를 대입
			bi++;
		}
		i++;
	}
	while (ai<ahalf)                      //앞쪽 배열의 남은 것들을 대입
	{
		base[i] = tbase[ai];
		i++;
		ai++;
	}
	while (bi<n)                         //뒤쪽 배열의 남은 것들을 대입
	{
		base[i] = tbase[bi];
		i++;
		bi++;
	}
	free(tbase);                        //임시 버퍼에 할당한 메모리 해제       
}

void HeapSort(int *base, int n)
{
	int on = n;
	while (n>1)
		printf("초기 힙 생성 과정\n");
	InitHeap(base, n);
	n--;
	SWAP(base[0], base[n]);
	printf("정렬 과정\n");
	{

		MakeHeap(base, n);
		ViewArr(base, n + 1);
		n--;
		SWAP(base[0], base[n]);
	}
	ViewArr(base, n + 1);
}

void InitHeap(int *base, int n)
{
	int pa = 0;
	int now;
	int i;
	for (i = 1; i<n; i++)                         //순차적으로 힙에 구성
	{
		now = i;
		while (now>0)                            //now의 인덱스가 0이 아니면 - 힙의 루트가 아닐 시
		{
			pa = PARENT(now);                    //부모 인덱스 구함
			if (base[now]>base[pa])              //부모보다 더 크면
			{
				SWAP(base[now], base[pa]);       //부모와 교환
				now = pa;                        //인덱스를 부모로 설정
			}
			else                                 //아니면 자리를 찾은 것임
			{
				break;
			}
		}
		ViewArr(base, i + 1);
	}
}

void MakeHeap(int *base, int n)
{
	int now = 0;
	int mp = 0;
	//루트에 있는 요소를 힙 트리에 맞게 자리를 찾는 과정
	while (LEFT_CHILD(now) < n)                   //왼쪽 자식이 있다면
	{
		int mp = FindMaxIndex(base, n, now);      //now와 왼쪽, 오른쪽 자식 중에 큰 값의 위치 찾음
		if (mp == now)                            //mp와 now가 같으면
		{
			break;                                //자리를 찾은 것임
		}
		SWAP(base[mp], base[now]);                //now와 큰 값의 자리 교환
		now = mp;                                 //큰 값의 위치를 now로 설정
	}
}


int FindMaxIndex(int *base, int n, int now)
{
	int lc = LEFT_CHILD(now);                     //왼쪽 자식
	int rc = RIGHT_CHILD(now);                    //오른쪽 자식

	if (rc >= n)                                  //오른쪽 자식이 없을 때
	{
		if (base[now]<base[lc])
		{
			return lc;
		}
		return now;
	}
	if (base[lc]<base[rc])
	{
		return rc;
	}
	return lc;

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