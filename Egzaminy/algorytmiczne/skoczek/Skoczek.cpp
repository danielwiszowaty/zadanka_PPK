// Skoczek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct index
{
	int x = 65;
	int y = 65;
};

index znajdz(int pole[8][8], int wartosc)
{
	index zwrot;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (pole[i][j] == wartosc)
			{
				zwrot.x = j;
				zwrot.y = i;
				return zwrot;
			}
		}
	}
	return zwrot;
}
int main()
{
	const int rozmiar = 8;
	int pole[rozmiar][rozmiar] = {{0},{0}};
	fstream plik;
	string Nplik="C:/Users/SL/Documents/aeirepo/Tomasz-Skowron-gr07-repo/student/Skoczek/Debug/plik.txt";
	plik.open(Nplik, ios::in|| ios::out);
	if (plik)
	{
		string linia;
		int nr = 0;
		while (getline(plik, linia))
		{
			stringstream ss(linia);
			for (int i = 0; i < 9; i++)
			{
				ss >> pole[nr][i];
			}
			nr++;
		}
		for (int i = 1; i < 65; i++)
		{
			index poleA;
			index poleB;
			poleA = znajdz(pole, i);
			poleB = znajdz(pole, i + 1);
			if ((poleA.x - poleB.x == 1 && poleA.y-poleB.y==2)|| (poleA.x - poleB.x == -1 && poleA.y - poleB.y == 2) || (poleA.x - poleB.x == -2 && poleA.y - poleB.y == -1) || (poleA.x - poleB.x == -2 && poleA.y - poleB.y == 1) || (poleA.x - poleB.x == -1 && poleA.y - poleB.y == -2) || (poleA.x - poleB.x == 1 && poleA.y - poleB.y == -2) || (poleA.x - poleB.x == 2 && poleA.y - poleB.y == 1) || (poleA.x - poleB.x == 2 && poleA.y - poleB.y == -1))
			{
				continue;
			}
			else
			{
				cout << "false";
			}
		}
		cout << "true";
	}

	plik.close();
    return 0;
}

