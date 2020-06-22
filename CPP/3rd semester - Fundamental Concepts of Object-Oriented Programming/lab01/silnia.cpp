#pragma once
#include "silnia.h"
#include <iostream> 

using namespace std;

int silnia(int i)
{
    if(i<0)
    {
        cout << "brak rozwiazania";
        return 0;
    }
    else
    {
        int wynik=1;
        for(int k=1;k<=i;k++)
        {
            wynik=wynik*k;
        }
        return wynik;
    }
}

int silnia_rec(int i)
{
    if(i<0)
    {
        cout << "brak rozwiazania";
        return 0;
    }
    else
    {
        if(i==0 || i==1)
        {
            return 1;
        }
        else
        {
            return silnia_rec(i-1) * i;
        }
    }
}
