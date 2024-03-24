#include "SetLab4_Kostiuk.h"

using namespace std;

//Функция проверки множества на пустоту
bool ListClass::isEmptyCl() {
	return sets.empty();
}

//Функция проверки на наличие элемента в множестве
bool ListClass::inSetListCl(int value) {
	for (auto i : sets)
		if (i == value)
			return true;
	return false;
}

//Функция добавления элемента в множество
void ListClass::addEleminStartCl(int value) {
	//Добавление элемента в множество
	if (!inSetListCl(value)) {															//Если элемент отсутствует в списке, добавляем его. Иначе выводим сообщение
		sets.push_front(value);
	}
}

//Функция добавления элемента в множество
void ListClass::addEleminEndCl(int value) {
	//Добавление элемента в множество
	if (!inSetListCl(value)) {															//Если элемент отсутствует в списке, добавляем его. Иначе выводим сообщение
		sets.push_back(value);
	}
}

//Функция создания множества 
void ListClass::createSetCl(int num, int min, int max, int k) {														//Создание пустого множества
	if (num * k > max - min + 1) {		
		cout << "Данные неверны" << endl;
	}
	for (int i = 0; i < num; i++) {														//Для каждого i до числа элементов в множестве
		int candidate = 0;																//СОздаём кандидата на добавление
		//srand(time(NULL));
		candidate = rand() % (max - min + 1);											//Присваиваем кандидату рандомное значение от min до max включительно
		while (candidate == 0 || candidate % k != 0 || inSetListCl(candidate)) {				//Проверяяем кандидата на кратность и наличие в создаваемом множестве
			candidate = rand() % (max - min + 1);										//Если какое то из условий не выполнено, то повторяем рандомизацию
		}
		addEleminEndCl(candidate);													//Если элемент соответствует всем требованиям, то он добавляется
	}

}

//Функция определения мощности множества
int ListClass::setPowerCl() {
	return sets.size();																	//Возвращаем мощность множества
}

//Функция отображения множества на экране
void ListClass::showSetCl(char splitter) {
	if (sets.empty()) {																//Если множество пустое, то отображать нечего
		return;
	}
	cout << "\nShow set" << endl;
	for (int n : sets) {
		cout << n;
		cout << splitter;
	}
	cout << endl;
}


void ListClass::deleteSetCl() {
	sets.clear();
	cout << "Delete is complete " << endl;
}
//Функция проверки на подмножество множества
bool ListClass::isSubSetCl(ListClass first, ListClass second) {
	if (first.isEmptyCl())																//Если первое множество является пустым, то возвращаем true
		return true;
	if (second.isEmptyCl())
		return false;
	for (int n : first.sets) {															//Пока не дошли до конца множества 
		if (!second.inSetListCl(n))											//Проверяем на наличие элемента first множества в second
			return false;																//Если элемент не найден - возвращаем false
	}
	return true;																		//Возвращаем true, т.к. все элементы first найдены в second
}

//Функция проверки равенства множеств
bool ListClass::setsIsEqualCl(ListClass first, ListClass second) {
	if (isSubSetCl(first, second) && isSubSetCl(second, first))							//Проверяем, является ли первое множество подмножество второго и наоборот
		return true;																	//Если являются, то возвращаем true. Иначе - false
	return false;
}

//Функция объединения двух множеств
void ListClass::combineTwoSetsCl(ListClass first, ListClass second) {																	
	if (first.isEmptyCl() && second.isEmptyCl())										//Если оба множества пустые, возвращаем указатель на пустое объединённое 
		return;																//множество
	for (int fir: first.sets) {															//Пока не дошли до конца первого множества 
		addEleminStartCl(fir);
	}
	for (int sec: second.sets) {														//Пока не дошли до конца второго множества
		if (!inSetListCl(sec))													//Если элемент второго множества отсутствует в множестве combined, то добавляем
			addEleminStartCl(sec);
	}
}

//Функция пересечения двух множеств
void ListClass::intersectionofSetsCl(ListClass first, ListClass second) {
	if (first.isEmptyCl() || second.isEmptyCl())											//Если 1 из множеств пустое, возвращаем указатель на пустое пересечение 
		return;
	for (int fir : first.sets) {															//Пока не дошли до конца первого множества 
		if (second.inSetListCl(fir))											//Если элемент первого множества найден во втором множестве
			addEleminStartCl(fir);									//, то добавляем элемент в множество пересечения
	}
}

//Функция разности двух множеств
void ListClass::setDifferenceCl(ListClass first, ListClass second) {
	if (first.isEmptyCl() && second.isEmptyCl())											//Если оба множества пустые, возвращаем указатель на пустую разность
		return;
	for (int fir : first.sets) {															//Пока не дошли до конца первого множества
		if (!second.inSetListCl(fir))											//Если элемент не найден первого множества отсутствует во втором множестве
			addEleminStartCl(fir);										//, добавляем этот элемент в множество разности
	}															//Возвращаем указатель на первый элемент множества difference
}

//Функция симметричной разности двух множеств
void ListClass::symmetricalDifferenceCl(ListClass first, ListClass second) {
	setDifferenceCl(first, second);

}