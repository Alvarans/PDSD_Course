#pragma once
#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

class MapClass {
public:
	map <int, int>  sets;
	map <int, int> ::iterator it = sets.begin();
public:
	bool isEmptyMap();																//f2

	bool inSetListMap(int value);													//f3

	void addElemMap(int value);												        //f4

	void createSetMap(int num, int min, int max, int k);								//f5

	int setPowerMap();																//f6

	string showSetMap(char splitter);													//f7

	void deleteSetMap();																//f8

	bool isSubSetMap(MapClass first, MapClass second);								//f9

	bool setsIsEqualMap(MapClass first, MapClass second);							//f10

	MapClass comnineTwoSetsMap(MapClass first, MapClass second);						//f11

	MapClass intersectionofSetsMap(MapClass first, MapClass second);						//f12

	MapClass setDifferenceMap(MapClass first, MapClass second);							//f13

	MapClass symmetricalDifferenceMap(MapClass first, MapClass second);					//f14
};
