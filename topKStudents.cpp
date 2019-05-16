/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/
#include<malloc.h>
#include<stdio.h>
struct student {
	char *name;
	int score;
};
int partition(struct student* stud, int low, int high);
void sort(struct student* stud, int low, int high);
void * scoresDescendingSort(struct student *students, int len)
{
	if (students != NULL && len > 0)
	{
		int high = len - 1;
		int low = 0;
		sort(students, low, high);
	}
	return NULL;
}
void swap(struct student* a, struct student* b)
{
	struct student t = *a;
	*a = *b;
	*b = t;
}
void sort(struct student* stud, int low, int high)
{
	if (low < high)
	{
		int mid = partition(stud, low, high);
		sort(stud, low, mid - 1);
		sort(stud, mid + 1, high);
	}
}
int partition(struct student* stud, int low, int high)
{
	int pivot = stud[high].score;
	int index1 = low - 1;
	for (int index2 = low; index2 <= high - 1; index2++)
	{
		if (stud[index2].score >= pivot)
		{
			index1++;
			swap(&stud[index1], &stud[index2]);
		}
	}
	swap(&stud[index1 + 1], &stud[high]);
	return index1 + 1;
}

struct student ** topKStudents(struct student *students, int len, int K)
{
	if (students != NULL && len > 0 && K > 0 && K <= len)
	{
		scoresDescendingSort(students, len);
		struct student *temp = (struct student*)malloc(K*sizeof(struct student));
		for (int index = 0; index < K; index++)
		{
			*(temp + index) = students[index];

		}
		struct student **temp1 = (struct student**)malloc(K*sizeof(struct student*));
		*temp1 = temp;
		

		return temp1;
	}
	return NULL;
}