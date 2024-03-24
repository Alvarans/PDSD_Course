#pragma once
#include <iostream>

struct SetCl {
	int value;
	SetCl* next;
};


class SetList {
public:
	SetCl* root; 
public:
	SetList(){																			//f1
		root = nullptr;
	}

	bool isEmptyCl(SetCl* set);														//f2

	bool inSetListCl(SetCl* set, int value);											//f3

	SetCl* addElemCl(SetCl*& first, int value);									//f4

	SetCl* createSetCl(int num, int min, int max, int k);							//f5

	int setPowerCl(SetCl* first);													//f6

	void showSetCl(SetCl* first, char splitter);										//f7

	bool isSubSetCl(SetCl* first, SetCl* second);									//f9

	bool setsIsEqualCl(SetCl* first, SetCl* second);								//f10

	SetCl* combineTwoSetsCl(SetCl* first, SetCl* second);						//f11

	SetCl* intersectionofSetsCl(SetCl* first, SetCl* second);					//f12

	SetCl* setDifferenceCl(SetCl* first, SetCl* second);						//f13

	SetCl* symmetricalDifferenceCl(SetCl* first, SetCl* second);				//f14

	~SetList() {																		//f8
		SetCl* current = root;
		while (current != nullptr) {
			SetCl* temp = current;
			current = current->next;
			delete temp;
		}
		root = nullptr;
	}
};
