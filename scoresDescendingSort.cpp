/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SD
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};
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