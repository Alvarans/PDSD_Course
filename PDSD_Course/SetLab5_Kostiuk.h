#pragma once
#include <iostream>
#include <set> 
#include <String>
#include <ctime> 

using namespace std;

class SetClass {
public:
	set <int> sets;
public:

	bool isEmptyCl();																//f2

	bool inSetListCl(int value);													//f3

	void addElemCl(int value);												//f4

	void createSetCl(int num, int min, int max, int k);								//f5

	int setPowerCl();																//f6

	string showSetCl(char splitter);													//f7

	void deleteSetCl();																//f8

	bool isSubSetCl(SetClass first, SetClass second);								//f9

	bool setsIsEqualCl(SetClass first, SetClass second);							//f10

	SetClass comnineTwoSetsCl(SetClass first, SetClass second);						//f11
	
	SetClass intersectionofSetsCl(SetClass first, SetClass second);						//f12

	SetClass setDifferenceCl(SetClass first, SetClass second);							//f13

	SetClass symmetricalDifferenceCl(SetClass first, SetClass second);					//f14

};
