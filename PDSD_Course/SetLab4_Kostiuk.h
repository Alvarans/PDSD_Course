#pragma once
#include <iostream>
#include <list>

using namespace std;

class ListClass {
public:
	list <int> sets;
public:

	bool isEmptyCl();																//f2

	bool inSetListCl(int value);													//f3

	void addEleminStartCl(int value);												//f4
	
	void addEleminEndCl(int value);													//f4

	void createSetCl(int num, int min, int max, int k);								//f5

	int setPowerCl();																//f6

	void showSetCl(char splitter);													//f7

	void deleteSetCl();																//f8

	bool isSubSetCl(ListClass first, ListClass second);								//f9

	bool setsIsEqualCl(ListClass first, ListClass second);							//f10

	void combineTwoSetsCl(ListClass first, ListClass second);							//f11

	void intersectionofSetsCl(ListClass first, ListClass second);						//f12

	void setDifferenceCl(ListClass first, ListClass second);							//f13

	void symmetricalDifferenceCl(ListClass first, ListClass second);					//f14

};
