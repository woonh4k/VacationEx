#include <stdio.h>

int main(void)
{
	int i = 0;
	int j, temp;
	int arr[10] = { 0 };

	while (i < 10)
	{
		printf("���� �Է�%d >", i);
		scanf("%d", &arr[i]);
		for (j = 0; j < i; j++) {                     
			if (arr[i] == arr[j]) {                   //�Էµ� ������ �������� ����� ������ ���� ���� ������ ���ý�
				i--;                                  //����� �迭 �ڸ����� �ٽ� �ǵ�����
				printf("�ߺ��Դϴ�.\n");              //�ߺ��� �˸��� ���� ���
			}
		}
		i++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);                        //�ߺ�ó���� �迭�� ����� ���� ���
	}
	for (i = 0; i < 10; i++)
	{
		for (j = i; j < 10; j++) {
			if (arr[i] > arr[j]) {                    //�迭�� ����� ���� ���Ͽ� �տ� ����� ������ �ڿ� ����� �������� Ŭ��� ��������.
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);                       //�ߺ�ó�� + ������������ ���ĵ� �迭 ���.
	}
}

