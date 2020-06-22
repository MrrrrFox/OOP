#include "students.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

char* addNewName(char const * imie1, char const * imie2) {

	char* name1 = new char[strlen(imie1) + 1];
	char* name2 = new char[strlen(imie2) + 1];
	
	strcpy(name1, imie1);
	strcpy(name2, imie2);

	strcat(name1, (char *) " ");
	strcat(name1, name2);
	delete[] name2;

	return name1;
}

char* addNewSurname(char const *nazwisko) {

	char* surname = new char[strlen(nazwisko) + 1];
	
	strcpy(surname, nazwisko);

	return surname;
}


void NowaListaChar(int n, char **nameList, char ***newNameList) {
	for (int i = 0; i < n; i++) {
		(*newNameList)[i] = nameList[i];
	}
}


void NowaListaInt(int n, int *semList, int **newSemList) {
	for (int i = 0; i < n; i++) {
		(*newSemList)[i] = semList[i];
	}
}

void NowaListaChar(int n, char **nameList, char ***newNameList, int indeks) {
	int j=0;
	for (int i = 0; i < n; i++) 
	{
		if(i!=indeks)
		{
			(*newNameList)[j] = nameList[i];
			j++;
		}
	}
}


void NowaListaInt(int n, int *semList, int **newSemList, int indeks) {
	int j=0;
	for (int i = 0; i < n; i++) 
	{
		if(i!=indeks)
		{
			(*newSemList)[j] = semList[i];
			j++;
		}
	}
}

void AddStudent(int* numberOfStudents, char*** nameList, char*** surnamesList, int** semesterList, char const * imie, char const * imie2, char const * nazwisko, int semestr)
{
	char *name = addNewName(imie, imie2);
	char *surname = addNewSurname(nazwisko);
	char **newNameList = new char*[*numberOfStudents + 1];
	char **newSurnameList = new char*[*numberOfStudents + 1];
	int *newSemesterList = new int[*numberOfStudents + 1];

	NowaListaChar(*numberOfStudents, *nameList, &newNameList);
	NowaListaChar(*numberOfStudents, *surnamesList, &newSurnameList);
	NowaListaInt(*numberOfStudents, *semesterList, &newSemesterList);

	newNameList[*numberOfStudents] = name;
	newSurnameList[*numberOfStudents] = surname;
	newSemesterList[*numberOfStudents] = semestr;

	*numberOfStudents += 1;
	*nameList = newNameList;
	*surnamesList = newSurnameList;
	*semesterList = newSemesterList;
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
	// najpierw usuwam imiona i nazwiska (wewnętrzne)
	int i;
	for (i = 0; i < *numberOfStudents; i++) {
		delete[] (*namesList)[i];
		delete[] (*surnamesList)[i];
	}
	// teraz usuwam wskaźniki na główne tablice (zewnetrzne)
	delete[] (*namesList);
	delete[] (*surnamesList);
	delete[] (*semesterList);
}

void deleteStudent (int* numberOfStudents, char*** namesList, char*** surnamesList, int** semesterList, int indeks)
{
/*	// usuwa poprawnie studenta o konkretnym indeksie, ale potem nie działa ClearStudents()
	
	// tworze tablice o jeden mniejsze
	char **newNameList = new char*[*numberOfStudents - 1];
	char **newSurnameList = new char*[*numberOfStudents - 1];
	int *newSemesterList = new int[*numberOfStudents - 1];
	
	// przepisuje wartości poza tą, o indeksie do usuniecia	
	NowaListaChar(*numberOfStudents, *namesList, &newNameList, indeks);
	NowaListaChar(*numberOfStudents, *surnamesList, &newSurnameList, indeks);
	NowaListaInt(*numberOfStudents, *semesterList, &newSemesterList, indeks);

	*numberOfStudents -= 1;
	*namesList = newNameList;
	*surnamesList = newSurnameList;
	*semesterList = newSemesterList;

*/
}
