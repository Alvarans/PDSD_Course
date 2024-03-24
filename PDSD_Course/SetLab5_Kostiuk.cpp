#include "SetLab5_Kostiuk.h"

using namespace std;

//Функция проверки множества на пустоту
bool SetClass::isEmptyCl() {
	return sets.empty();
}

//Функция проверки на наличие элемента в множестве
bool SetClass::inSetListCl(int value) {
	return sets.find(value) == sets.end() ? false : true;
}

//Функция добавления элемента в множество
void SetClass::addElemCl(int value) {
	//Добавление элемента в множество
	sets.insert(value);
}


//Функция создания множества 
void SetClass::createSetCl(int num, int min, int max, int k) {														//Создание пустого множества
	if (num * k > max - min + 1) {
		cout << "Данные неверны" << endl;
	}
	for (int i = 0; i < num; i++) {														//Для каждого i до числа элементов в множестве
		int candidate = 0;																//СОздаём кандидата на добавление
		//srand(time(NULL));
		candidate = rand() % max - min + 1;											//Присваиваем кандидату рандомное значение от min до max включительно
		while (candidate == 0 || candidate % k != 0 || inSetListCl(candidate)) {				//Проверяяем кандидата на кратность и наличие в создаваемом множестве
			candidate = rand() % max - min + 1;										//Если какое то из условий не выполнено, то повторяем рандомизацию
		}
		addElemCl(candidate);													//Если элемент соответствует всем требованиям, то он добавляется
	}

}

//Функция определения мощности множества
int SetClass::setPowerCl() {
	return sets.size();																	//Возвращаем мощность множества
}

//Функция отображения множества на экране
string SetClass::showSetCl(char splitter) {
	string showSet = "";
	if (sets.empty()) {																//Если множество пустое, то отображать нечего
		return showSet+="Set is empty\n";
	}
	for (int n : sets) {
		showSet += to_string(n);
		showSet += splitter;
	}
	showSet += "\n";
	return showSet;
}

//Функция удаления множества
void SetClass::deleteSetCl() {
	sets.clear();
	cout << "Delete is complete " << endl;
}
//Функция проверки на подмножество множества
bool SetClass::isSubSetCl(SetClass first, SetClass second) {
	if (first.isEmptyCl())																//Если первое множество является пустым, то возвращаем true
		return true;
	if (second.isEmptyCl())
		return false;
	for (int n : first.sets) {															//Пока не дошли до конца множества 
		if (!second.inSetListCl(n))														//Проверяем на наличие элемента first множества в second
			return false;																//Если элемент не найден - возвращаем false
	}
	return true;																		//Возвращаем true, т.к. все элементы first найдены в second
}

//Функция проверки равенства множеств
bool SetClass::setsIsEqualCl(SetClass first, SetClass second) {
	return isSubSetCl(first, second) && isSubSetCl(second, first);
}

//Функция объединения двух множеств
SetClass SetClass::comnineTwoSetsCl(SetClass first, SetClass second) {
	SetClass combine;
	if (first.isEmptyCl() && second.isEmptyCl())										//Если оба множества пустые, возвращаем указатель на пустое объединённое 
		return combine;
	for (int fir : first.sets)
		combine.addElemCl(fir);
	for (int sec : second.sets) 														//Пока не дошли до конца второго множества
		combine.addElemCl(sec);
	return combine;
}
//Функция пересечения двух множеств
SetClass SetClass::intersectionofSetsCl(SetClass first, SetClass second) {
	SetClass intersection;
	if (first.isEmptyCl() || second.isEmptyCl())											//Если 1 из множеств пустое, возвращаем указатель на пустое пересечение 
		return intersection;
	for (int fir : first.sets) {															//Пока не дошли до конца первого множества 
		if (second.inSetListCl(fir))													//Если элемент первого множества найден во втором множестве
			intersection.addElemCl(fir);																	//, то добавляем элемент в множество пересечения
	}
	return intersection;
}

//Функция разности двух множеств
SetClass SetClass::setDifferenceCl(SetClass first, SetClass second) {
	SetClass difference;
	if (first.isEmptyCl() && second.isEmptyCl())											//Если оба множества пустые, возвращаем указатель на пустую разность
		return difference;
	for (int fir : first.sets) {															//Пока не дошли до конца первого множества
		if (!second.inSetListCl(fir))														//Если элемент не найден первого множества отсутствует во втором множестве
			difference.addElemCl(fir);																	//, добавляем этот элемент в множество разности
	}	
	return difference;																				//Возвращаем указатель на первый элемент множества difference
}

//Функция симметричной разности двух множеств
SetClass SetClass::symmetricalDifferenceCl(SetClass combine, SetClass intersection) {
	return setDifferenceCl(combine, intersection);
}
