#include "print.h"
#include <iostream>

using namespace std;

void print(int * wektor, int n)
{
	int l1;
	for(l1=0;l1<n;l1++)
	{
		cout<<*(wektor+l1)<<", ";
	}
	cout<<endl;
}
