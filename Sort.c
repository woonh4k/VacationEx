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
		printf(" %d ��° ������ �Է��Ͻÿ� : ", i + 1);
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				printf("�ߺ��Դϴ�!\n");
			}
		}
		
	}
	printf("�Է��Ͻ� ������ ");
	for (i = 0; i < 10; i++) {
		printf(" %d ", arr[i]);
	}
	printf(" �Դϴ�. ");
	showmenu();
	printf("\n | ���Ͻô� ������ �����ϼ��� => ");
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
	printf("\n\n | ******** ���� ���α׷� ******** |");
	printf("\n | (1) ���� ���� - Sequential Sort |");
	printf("\n | (2) ���� ���� - Bubble Sort     |");
	printf("\n | (3) ���� ���� - Selection Sort  |");
	printf("\n | (4) ���� ���� - Insertion Sort  |");
	printf("\n | (5)  ��  ���� - Shell Sort      |");
	printf("\n | (6)  ��  ���� - Quick Sort      |");
	printf("\n | (7) ���� ���� - Merge Sort      |");
	printf("\n | (8)  ��  ���� - Heap Sort       |");
	printf("\n | (9)      ��  ��  ��  ��         |");

}

void SequentialSort(int *base, int n)
{
	int i, j;
	ViewArr(base, n);                            //���� ���� ���
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (base[i] > base[j])                //���� �ڸ� ���Ұ� �� �ڸ��� ���Һ��� Ŭ ��
			{
				SWAP(base[i], base[j]);           //����
				ViewArr(base, n);               //���� ��� ���
			}
		}
	}
}
 
void BubbleSort(int *base, int n)
{
	int i, j;
	ViewArr(base, n);                          //���� ���� ���
	for (i = n; i>1; i--)                      //������ ������ ���� ����. ū ���� ���� �ڷ� ��ġ�ϱ� ����
	{
		for (j = 1; j<i; j++)
		{
			if (base[j - 1]>base[j])           //���Ͽ� �� �ڸ��� ���� �� ũ��
			{
				SWAP(base[j - 1], base[j]);    //����
				ViewArr(base, n);              //���� ��� ���
			}
		}
	}
}

void SelectionSort(int *base, int n)
{
	int i, j;
	int maxi;
	ViewArr(base, n);                           //���� ���� ���
	for (i = n; i>1; i--)                       //������ ������ ����
	{
		maxi = 0;
		for (j = 1; j<i; j++)
		{
			if (base[maxi]<base[j])             //���� �� �ڸ��� ������ �� ū ���� ������ �Ǹ�
			{
				maxi = j;
			}
		}
		SWAP(base[maxi], base[i - 1]);          //����
		ViewArr(base, n);                       //���� ��� ���
	}
}

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

void ShellSort(int *base, int size)
{
	int i, step;

	for (step = size / 2; step > 0; step /= 2)              //step�� ���� 1/2�� ���� ���δ�
	{
		printf("step:%d\n", step);
		for (i = 0; i<step; i++)
		{
			InsertionSort1(base + i, size - i, step);    //step ���ݿ� �ִ� ������ ���������Ѵ�.
		}
	}
}

void InsertionSort1(int *base, int size, int step)
{
	int i, j;
	for (i = step; i<size; i += step)                  //���� ��� ���� step �������� �̵�
	{

		for (j = i; j>0; j -= step)                   //step �������� ������ �̵�
		{
			if (base[j - step]>base[j])               //������ ���� �� ū ���
			{
				SWAP(base[j - step], base[j]);       //ġȯ ����
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

void MergeSort(int *base, int n)
{
	int ahalf = n / 2;                    //�迭�� ���� ����
	int bhalf = n - ahalf;                //�迭�� ���� ����
	int ai = 0, bi = ahalf;
	int i = 0;
	int *tbase = 0;

	if (n <= 1)                           //�迭�� ũ�Ⱑ 1���� �۰ų� ���� ��
	{
		return;
	}
	MergeSort(base, ahalf);                //���� �迭 ���ȣ��� ����
	PrintSpace(base - origin);
	ViewArr(base, ahalf);
	MergeSort(base + ahalf, bhalf);        //���� �迭 ���ȣ��� ����
	PrintSpace(base + ahalf - origin);
	ViewArr(base + ahalf, bhalf);
	tbase = (int *)malloc(sizeof(int)*n);  //�迭 ũ���� �ӽ� ������ �Ҵ�
	memcpy(tbase, base, sizeof(int)*n);    //�ӽ� ������ �迭 �޸� ����

	while ((ai<ahalf) && (bi<n))
	{
		if (tbase[ai] <= tbase[bi])        //������ ũ�ų� ���� ��
		{
			base[i] = tbase[ai];           //���� �迭�� ���Ҹ� ����
			ai++;
		}
		else
		{
			base[i] = tbase[bi];           //���� �迭�� ���Ҹ� ����
			bi++;
		}
		i++;
	}
	while (ai<ahalf)                      //���� �迭�� ���� �͵��� ����
	{
		base[i] = tbase[ai];
		i++;
		ai++;
	}
	while (bi<n)                         //���� �迭�� ���� �͵��� ����
	{
		base[i] = tbase[bi];
		i++;
		bi++;
	}
	free(tbase);                        //�ӽ� ���ۿ� �Ҵ��� �޸� ����       
}

void HeapSort(int *base, int n)
{
	int on = n;
	while (n>1)
		printf("�ʱ� �� ���� ����\n");
	InitHeap(base, n);
	n--;
	SWAP(base[0], base[n]);
	printf("���� ����\n");
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
	for (i = 1; i<n; i++)                         //���������� ���� ����
	{
		now = i;
		while (now>0)                            //now�� �ε����� 0�� �ƴϸ� - ���� ��Ʈ�� �ƴ� ��
		{
			pa = PARENT(now);                    //�θ� �ε��� ����
			if (base[now]>base[pa])              //�θ𺸴� �� ũ��
			{
				SWAP(base[now], base[pa]);       //�θ�� ��ȯ
				now = pa;                        //�ε����� �θ�� ����
			}
			else                                 //�ƴϸ� �ڸ��� ã�� ����
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
	//��Ʈ�� �ִ� ��Ҹ� �� Ʈ���� �°� �ڸ��� ã�� ����
	while (LEFT_CHILD(now) < n)                   //���� �ڽ��� �ִٸ�
	{
		int mp = FindMaxIndex(base, n, now);      //now�� ����, ������ �ڽ� �߿� ū ���� ��ġ ã��
		if (mp == now)                            //mp�� now�� ������
		{
			break;                                //�ڸ��� ã�� ����
		}
		SWAP(base[mp], base[now]);                //now�� ū ���� �ڸ� ��ȯ
		now = mp;                                 //ū ���� ��ġ�� now�� ����
	}
}


int FindMaxIndex(int *base, int n, int now)
{
	int lc = LEFT_CHILD(now);                     //���� �ڽ�
	int rc = RIGHT_CHILD(now);                    //������ �ڽ�

	if (rc >= n)                                  //������ �ڽ��� ���� ��
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