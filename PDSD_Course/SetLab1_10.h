#pragma once
#include <iostream>
//Элемент списка
struct Set {
	int value;//Числовое значение
	Set* next;//Указатель на следующий элемент
};

	Set* createEmptySet();												//f1

	bool isEmpty(Set* set);												//f2

	bool inSetList(Set* first, int value);								//f3

	Set* addElem(Set*& first, int value);								//f4

	Set* createSet(int num, int min, int max, int k);					//f5

	int setPower(Set* first);											//f6

	void showSet(Set* first, char splitter);							//f7

	Set* deleteSet(Set*& first);										//f8

	bool isSubSet(Set* first, Set* second);								//f9

	bool setsIsEqual(Set* first, Set* second);							//f10

	Set* combineTwoSets(Set* first, Set* second);						//f11

	Set* intersectionofSets(Set* first, Set* second);					//f12

	Set* setDifference(Set* first, Set* second);						//f13

	Set* symmetricalDifference(Set* first, Set* second);				//f14
