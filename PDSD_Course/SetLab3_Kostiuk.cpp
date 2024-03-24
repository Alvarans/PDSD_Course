#include "SetLab3_Kostiuk.h"

using namespace std;

bool SetList::isEmptyCl(SetCl* set) {
	return set == nullptr;
}

bool SetList::inSetListCl(SetCl* set, int value) {
	//Проверка на пустоту множества
	if (isEmptyCl(set))
		return false;
	//Поиск элемента в множестве 
	while (set->next && set->value != value) {
		set = set->next;
	}
	return set->value == value;
}

SetCl* SetList::addElemCl(SetCl*& first, int value) {
	//Добавление элемента в множество
	if (!inSetListCl(first, value)) {	//Если элемент отсутствует в списке, добавляем его. Иначе выводим сообщение
		SetCl* new_set = new SetCl;		//Создаём новое множество
		new_set->value = value;			//Записываем значение добавляемого элемента в первый элемент
		new_set->next = first;			//Устанавливаем указатель на следующий элемент на первый элемент старого множества
		first = new_set;
	}
	return root = first;
}

SetCl* SetList::createSetCl(int num, int min, int max, int k) {
	SetCl* first = nullptr;
	if (num * k > max - min + 1) {
		return first;
	}
	for (int i = 0; i < num; i++) {
		int candidate = 0;
		candidate = rand() % (max - min + 1);
		while ((candidate % k != 0) || (inSetListCl(first, candidate))) {
			candidate = rand() % (max - min + 1);
		}
		addElemCl(first, candidate);
	}
	return root = first;
}

int SetList::setPowerCl(SetCl* first) {
	if (isEmptyCl(first)) {
		return 0;
	}
	int counter = 0;
	while (first != nullptr) {
		counter++;
		first = first->next;
	}
	return counter;
}

void SetList::showSetCl(SetCl* first, char splitter) {
	if (isEmptyCl(first)) {
		return;
	}
	cout << "\nShow set" << endl;
	while (first != nullptr) {
		cout << first->value;
		cout << splitter;
		first = first->next;
	}
}

bool SetList::isSubSetCl(SetCl* first, SetCl* second) {
	if (isEmptyCl(first))																//Если первое множество является пустым, то возвращаем true
		return true;
	if (isEmptyCl(second))
		return false;
	while (first != nullptr) {															//Пока не дошли до конца множества 
		if (!inSetListCl(second, first->value))											//Проверяем на наличие элемента first множества в second
			return false;																//Если элемент не найден - возвращаем false
		first = first->next;															//Переход на следующий элемент множества first
	}
	return true;																		//Возвращаем true, т.к. все элементы first найдены в second
}

bool SetList::setsIsEqualCl(SetCl* first, SetCl* second) {
	if (isSubSetCl(first, second) && isSubSetCl(second, first))							//Проверяем, является ли первое множество подмножество второго и наоборот
		return true;																	//Если являются, то возвращаем true. Иначе - false
	return false;
}

SetCl* SetList::combineTwoSetsCl(SetCl* first, SetCl* second) {
	SetCl* combined = nullptr;													//Создаём пустое множество для объединения
	if (isEmptyCl(first) && isEmptyCl(second))												//Если оба множества пустые, возвращаем указатель на пустое объединённое 
		return combined;																//множество
	while (first != nullptr) {															//Пока не дошли до конца первого множества 
		addElemCl(combined, first->value);
		first = first->next;															//Переходим к следующему элементу множества first
	}
	while (second != nullptr) {															//Пока не дошли до конца второго множества
		if (!inSetListCl(combined, second->value))										//Если элемент второго множества отсутствует в множестве combined, то добавляем
			addElemCl(combined, second->value);
		second = second->next;															//Переходим к следующему элементу множества second
	}
	return root = combined;																	//Возвращаем указатель на первый элемент множества combined
}

SetCl* SetList::intersectionofSetsCl(SetCl* first, SetCl* second) {
	SetCl* intersectioned = nullptr;												//Создаём пустое множество для пересечения
	if (isEmptyCl(first) || isEmptyCl(second))												//Если 1 из множеств пустое, возвращаем указатель на пустое пересечение 
		return intersectioned;
	while (first != nullptr) {															//Пока не дошли до конца первого множества 
		if (inSetListCl(second, first->value))											//Если элемент первого множества найден во втором множестве
			addElemCl(intersectioned, first->value);										//, то добавляем элемент в множество пересечения
		first = first->next;															//Переходим к следующему элементу множества first
	}
	return root = intersectioned;																//Возвращаем указатель на первый элемент множества intersectioned
}

SetCl* SetList::setDifferenceCl(SetCl* first, SetCl* second) {
	SetCl* difference = nullptr;													//Создаём пустое множество для разности 
	if (isEmptyCl(first) && isEmptyCl(second))											//Если оба множества пустые, возвращаем указатель на пустую разность
		return difference;
	while (first != nullptr) {														//Пока не дошли до конца первого множества
		if (!inSetListCl(second, first->value))										//Если элемент не найден первого множества отсутствует во втором множестве
			addElemCl(difference, first->value);										//, добавляем этот элемент в множество разности
		first = first->next;														//Переходим к следующему элементу множества first
	}
	return root = difference;																	//Возвращаем указатель на первый элемент множества difference
}

SetCl* SetList::symmetricalDifferenceCl(SetCl* first, SetCl* second) {
	return root = setDifferenceCl(combineTwoSetsCl(first, second),
		intersectionofSetsCl(first, second));							//Возвращаем указатель на первый элемент множества разности множества сортировки
}																						//и множества пересечения множеств first и second
