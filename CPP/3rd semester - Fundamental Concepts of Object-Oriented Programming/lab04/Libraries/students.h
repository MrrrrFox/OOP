#pragma once

#include <iostream>

void AddStudent(int*, char***, char***, int**, char const *, char const *, char const *, int);
char* addNewName(char const *, char const *);
char* addNewSurname(char const *);
void NowaListaChar(int, char **, char ***);
void NowaListaInt(int, int *, int **);
void NowaListaChar(int, char **, char ***, int);
void NowaListaInt(int, int *, int **, int);
void PrintListContent (int, char**);
void PrintListContent (int, int*);
void PrintListContent (int, char**, char**, int*);
void ClearStudents (int*, char***, char***, int**);
void deleteStudent (int*, char***, char***, int**, int);
