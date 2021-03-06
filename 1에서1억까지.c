//이 소스는 1에서 1억의 범위에서 1을 찾아 카운트해서 출력하는 프로그램이다. 단 실행시간은 2초를 초과해선 안된다.

#include<stdio.h>


int main(void) { 
	int count = 0;                           //숫자 1을 카운트 하기위한 변수
	int b = 0;                               //중간 값을 저장해 두기 위한 변수

	for (int i = 1; i <= 100000000; i++) {   //1부터 1억까지의 범위 지정
		int a = 100000000;                   //이중 포문에서 a를 나눠서 자릿수 연산을 위한 값인데 초기화 해줘야 하므로 여기서 선언.
		for (int j = 1; a != 0; j++) {       //나눈 a값이 0이되어 더이상 나누지 못할 때 for문 탈출
			b = i / a;                       //자릿수의 값을 찾기 위한 중간 연산
			if (b % 10 == 1) {               //찾은 자릿수의 값을 10으로 나눈 나머지값이 1이면 1이므로 카운트 값 1 상승.
				count++;
				a /= 10;                     //자릿수를 찾기위한 나눔연산
			}
			else
				a /= 10;                    //다음 조건으로 넘어가기 위한 자릿수를 찾기위한 나눔연산

		}
	}

	printf("1의 개수 : %d\n", count);       //연산이 다 끝난 후 찾은 1의 카운트 값 출력.

	return 0;
}
