#include <stdio.h>

#define MAXSIZE 10  

int queue[MAXSIZE];
int front, rear;

void init_queue(void) {
	front = rear = 0;
}

void clear_queue(void) {
	front = rear;
}

int put(int value) {

	if ((rear + 1) % MAXSIZE == front) {   
		printf("Queue Overflow! \n");
		return -1;
	}

	queue[rear] = value;                    
	rear = ++rear % MAXSIZE;             
	return value;
}

int get(void) {
	int i;

	if (front == rear) {                
		printf(" Queue Underflow!\n");
		return (-1);
	}

	i = queue[front];  
	front = ++front%MAXSIZE;  
	return i;
}

void print_queue(void) {
	int i;
	printf("\n QueueÀÇ ¹æÇâ Front------> To Rear \n");
	for (i = front; i != rear; i = ++i%MAXSIZE)
		printf("%-6d", queue[i]);
}

void main(void)
{
	int i;

	init_queue();

	printf(" Put 5, 4, 7, 8, 2, 1\n");
	put(5);
	put(4);
	put(7);
	put(8);
	put(2);
	put(1);
	print_queue();

	printf(" \nGet");
	i = get();
	print_queue();
	printf("\nget value is %d", i);

	printf(" Put 3, 2, 5, 7 \n");
	put(3);
	put(2);
	put(5);
	put(7);
	print_queue();

	printf("\n Now queue is full, \n put 3 \n");
	put(3);
	print_queue();

	printf(" \nInitialize Queue");
	clear_queue();
	print_queue();

	printf(" Now queue is empty,\n get\n");
	i = get();
	print_queue();
	printf("get value is %d\n", i);
}
