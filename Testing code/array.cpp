#include <bits/stdc++.h>

using namespace std;

void fillUp(int array[], const int NUM)
{
	printf("fillUp %d\n", sizeof(array));
	for(int i = 0; i < NUM; i++)
		array[i] = i;
}

void fillUp(int array[][3], const int NUM)
{
	printf("fillUp 2d %d\n", sizeof(array));
	int cnt = 0;
	for(int i = 0; i < NUM; i++)
		for(int j = 0; j < NUM; j++)
			array[i][j] = cnt++;
}

void print(int array[], const int NUM)
{
	for(int i = 0; i < NUM; i++)
		printf("%d %d\n", i, array[i]);
}

void print(int array[][3], const int NUM)
{
	for(int i = 0; i < NUM; i++)
		for(int j = 0; j < NUM; j++)
			printf("%d %d %d\n", i, j, array[i][j]);
}

int main()
{	
	int person[3];

	const int NUM_STUDENTS = 3;
	int score[NUM_STUDENTS];

	printf("%d\n", sizeof(score));

	fillUp(score, NUM_STUDENTS);
	print(score, NUM_STUDENTS);
	
	/*
	int numStudent = 5;
	int score1[numStudent]; // -pedantic will throw warning
	*/

	int score2d[NUM_STUDENTS][NUM_STUDENTS];
	fillUp(score2d, NUM_STUDENTS);
	print(score2d, NUM_STUDENTS);
	

	return 0;
}
