#include "Set_Map.h"

using namespace std;

bool MapClass::isEmptyMap() {
	return sets.begin() == sets.end();
}

bool MapClass::inSetListMap(int value) {
	return sets.find(value) != sets.end();
}

void MapClass::addElemMap(int value) {
	sets[value] = value;
}

void MapClass::createSetMap(int num, int min, int max, int k) {
	if (num * k > max - min + 1) {
		cout << "Данные неверны" << endl;
	}
	for (int i = 0; i < num; i++) {														//Для каждого i до числа элементов в множестве
		int candidate = 0;																//СОздаём кандидата на добавление
		//srand(time(NULL));
		candidate = rand() % max - min + 1;											//Присваиваем кандидату рандомное значение от min до max включительно
		while (candidate == 0 || candidate % k != 0 || inSetListMap(candidate)) {				//Проверяяем кандидата на кратность и наличие в создаваемом множестве
			candidate = rand() % max - min + 1;										//Если какое то из условий не выполнено, то повторяем рандомизацию
		}
		addElemMap(candidate);													//Если элемент соответствует всем требованиям, то он добавляется
	}

}

int MapClass::setPowerMap() {
	return sets.size();
}

string MapClass::showSetMap(char splitter) {
	it = sets.begin();
	string showSet = "";
	if (sets.empty()) {																//Если множество пустое, то отображать нечего
		return showSet += "Set is empty\n";
	}
	for (; it != sets.end(); it++ ) {
		showSet += to_string(it->first);
		showSet += splitter;
	}
	showSet += "\n";
	return showSet;
}

void MapClass::deleteSetMap() {
	sets.clear();
}

bool MapClass::isSubSetMap(MapClass first, MapClass second) {
	first.it = first.sets.begin();
	if (first.isEmptyMap())																//Если первое множество является пустым, то возвращаем true
		return true;
	if (second.isEmptyMap())
		return false;
	for (; first.it != first.sets.end(); first.it++) {															//Пока не дошли до конца множества 
		if (!second.inSetListMap(first.it->first))														//Проверяем на наличие элемента first множества в second
			return false;																//Если элемент не найден - возвращаем false
	}
	return true;
}

bool MapClass::setsIsEqualMap(MapClass first, MapClass second) {
	return isSubSetMap(first, second) && isSubSetMap(second, first);
}

MapClass MapClass::comnineTwoSetsMap(MapClass first, MapClass second) {
	MapClass combine;
	first.it = first.sets.begin();
	second.it = second.sets.begin();
	if (first.isEmptyMap() && second.isEmptyMap())										//Если оба множества пустые, возвращаем указатель на пустое объединённое 
		return combine;
	for (; first.it != first.sets.end(); first.it++)
		combine.addElemMap(first.it->first);
	for (; second.it != second.sets.end(); second.it++) 														//Пока не дошли до конца второго множества
		combine.addElemMap(second.it->first);
	return combine;
}

MapClass MapClass::intersectionofSetsMap(MapClass first, MapClass second) {
	MapClass intersection;
	first.it = first.sets.begin();
	if (first.isEmptyMap() || second.isEmptyMap())											//Если 1 из множеств пустое, возвращаем указатель на пустое пересечение 
		return intersection;
	for (; first.it != first.sets.end(); first.it++) {															//Пока не дошли до конца первого множества 
		if (second.inSetListMap(first.it->first))													//Если элемент первого множества найден во втором множестве
			intersection.addElemMap(first.it->first);																	//, то добавляем элемент в множество пересечения
	}
	return intersection;
}

MapClass MapClass::setDifferenceMap(MapClass first, MapClass second) {
	MapClass difference;
	first.it = first.sets.begin();
	if (first.isEmptyMap() && second.isEmptyMap())											//Если оба множества пустые, возвращаем указатель на пустую разность
		return difference;
	for (; first.it != first.sets.end(); first.it++) {															//Пока не дошли до конца первого множества
		if (!second.inSetListMap(first.it->first))														//Если элемент не найден первого множества отсутствует во втором множестве
			difference.addElemMap(first.it->first);																	//, добавляем этот элемент в множество разности
	}
	return difference;
}

MapClass MapClass::symmetricalDifferenceMap(MapClass combine, MapClass intersection) {
	return setDifferenceMap(combine, intersection);
}
