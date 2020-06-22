#pragma once

void AddStudent(int*, char***, char***, int**, char const *, char const *, char const *, int);
char* newName(char const *, char const *);
char* newSurname(char const *);
void rewriteList(int, char **, char ***);
void rewriteList(int, int *, int **);
void PrintListContent (int, char**);
void PrintListContent (int, int*);
void PrintListContent (int, char**, char**, int*);
void ClearStudents (int*, char***, char***, int**);
