#include <stdio.h>

int main(void)
{
	int i = 0;
	int j, temp;
	int arr[10] = { 0 };

	while (i < 10)
	{
		printf("정수 입력%d >", i);
		scanf("%d", &arr[i]);
		for (j = 0; j < i; j++) {                     
			if (arr[i] == arr[j]) {                   //입력된 정수를 이전까지 저장된 정수를 비교해 같은 조건이 나올시
				i--;                                  //저장될 배열 자릿값을 다시 되돌리고
				printf("중복입니다.\n");              //중복을 알리는 문구 출력
			}
		}
		i++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);                        //중복처리된 배열에 저장된 정수 출력
	}
	for (i = 0; i < 10; i++)
	{
		for (j = i; j < 10; j++) {
			if (arr[i] > arr[j]) {                    //배열에 저장된 수를 비교하여 앞에 저장된 정수가 뒤에 저장된 정수보다 클경우 스왑해줌.
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);                       //중복처리 + 오름차순으로 정렬된 배열 출력.
	}
}

