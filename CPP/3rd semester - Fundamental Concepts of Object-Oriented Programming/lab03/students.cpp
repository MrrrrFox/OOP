#include "students.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void AddStudent(int* numberOfStudents, char*** nameList, char*** surnamesList, int** semesterList, char* imie, char* imie2, char* nazwisko, int semestr)
{
	char *name = newName(imie, imie2);
	char *surname = newSurname(nazwisko);
		
	char **newNameList = (char **) malloc((*numberOfStudents + 1)*sizeof(char *));
	char **newSurnameList = (char **) malloc((*numberOfStudents + 1)*sizeof(char *));
	int *newSemesterList = (int *) malloc((*numberOfStudents + 1)*sizeof(int *));

	rewriteList(*numberOfStudents, *nameList, &newNameList);
	rewriteList(*numberOfStudents, *surnamesList, &newSurnameList);
	rewriteList(*numberOfStudents, *semesterList, &newSemesterList);

	newNameList[*numberOfStudents] = name;
	newSurnameList[*numberOfStudents] = surname;
	newSemesterList[*numberOfStudents] = semestr;

	*nameList = newNameList;
	*surnamesList = newSurnameList;
	*semesterList = newSemesterList;

	*numberOfStudents = *numberOfStudents + 1;

}

char *newName(char const *imie1, char const *imie2) {

	char *firstName = (char *) malloc((strlen(imie1) + strlen(imie2) + 1)*sizeof(char));
	char *secondName = (char *) malloc(strlen(imie2)*sizeof(char));

	strcpy(firstName, imie1);
	strcpy(secondName, imie2);

	strcat(firstName, (char *) " ");
	strcat(firstName, secondName);

	return firstName;
}

char *newSurname(char const *nazwisko) {

	char *surname = (char *) malloc(strlen(nazwisko)*sizeof(char));

	strcpy(surname, nazwisko);

	return surname;
}


void rewriteList(int n, char **nameList, char ***newNameList) {
	for (int i = 0; i < n; i++) {
		(*newNameList)[i] = nameList[i];
	}
}


void rewriteList(int n, int *semList, int **newSemList) {
	for (int i = 0; i < n; i++) {
		(*newSemList)[i] = semList[i];
	}
}

void AddCharList(int numberOfStudents, char*** listChar, char* wyraz)
{
	
}

void AddIntList(int numberOfStudents, int** listInt, int numer)
{
	
}

void PrintListContent (int numberOfStudents, char** charList)
{
	int i;
	for(i=0; i<numberOfStudents; i++)
	{
		cout << charList[i] << endl; 
	}
}

void PrintListContent (int numberOfStudents, int* semesterList)
{
	int i;
	for(i=0; i<numberOfStudents; i++)
	{
		cout << semesterList[i] << endl; 
	}
}

void PrintListContent (int numberOfStudents, char** namesList, char** surnamesList, int* semesterList)
{
	int i;
	for(i=0; i<numberOfStudents; i++)
	{
		cout << surnamesList[i] << ", " << namesList[i] << " - semestr " << semesterList[i] << endl; 
	}
}

void ClearStudents (int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList)
{
	
}
