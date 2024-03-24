#include "SetLab1_10.h"

using namespace std;

//Функция определения подмножества множества
bool isSubSet(Set* first, Set* second) {
	if (isEmpty(first))																	//Если первое множество является пустым, то возвращаем true
		return true;
	if (isEmpty(second))
		return false;
	while (first != nullptr) {															//Пока не дошли до конца множества 
		if (!inSetList(second, first->value))											//Проверяем на наличие элемента first множества в second
			return false;																//Если элемент не найден - возвращаем false
		first = first->next;															//Переход на следующий элемент множества first
	}
	return true;																		//Возвращаем true, т.к. все элементы first найдены в second
}

//функция определения равенства множеств
bool setsIsEqual(Set* first, Set* second) {												
	if (isSubSet(first, second) && isSubSet(second, first))								//Проверяем, является ли первое множество подмножество второго и наоборот
		return true;																	//Если являются, то возвращаем true. Иначе - false
	return false;
}

//функция объединения двух множеств
Set* combineTwoSets(Set* first, Set* second) {
	Set* combined = createEmptySet();													//Создаём пустое множество для объединения
	if (isEmpty(first) && isEmpty(second))												//Если оба множества пустые, возвращаем указатель на пустое объединённое 
		return combined;																//множество
	while (first != nullptr) {															//Пока не дошли до конца первого множества 
		addElem(combined, first->value);
		first = first->next;															//Переходим к следующему элементу множества first
	}
	while (second != nullptr) {															//Пока не дошли до конца второго множества
		if (!inSetList(combined, second->value))										//Если элемент второго множества отсутствует в множестве combined, то добавляем
			addElem(combined, second->value);											
		second = second->next;															//Переходим к следующему элементу множества second
	}
	return combined;																	//Возвращаем указатель на первый элемент множества combined
}

//Функция пересечения двух множеств
Set* intersectionofSets(Set* first, Set* second) {										
	Set* intersectioned = createEmptySet();												//Создаём пустое множество для пересечения
	if (isEmpty(first) || isEmpty(second))												//Если 1 из множеств пустое, возвращаем указатель на пустое пересечение 
		return intersectioned;
	while (first != nullptr) {															//Пока не дошли до конца первого множества 
		if (inSetList(second, first->value))											//Если элемент первого множества найден во втором множестве
			addElem(intersectioned, first->value);										//, то добавляем элемент в множество пересечения
		first = first->next;															//Переходим к следующему элементу множества first
	}
	return intersectioned;																//Возвращаем указатель на первый элемент множества intersectioned
}

//Функция разности двух множеств
Set* setDifference(Set* first, Set* second) {
	Set* difference = createEmptySet();													//Создаём пустое множество для разности 
		if (isEmpty(first) && isEmpty(second))											//Если оба множества пустые, возвращаем указатель на пустую разность
			return difference;	
		while (first != nullptr) {														//Пока не дошли до конца первого множества
			if (!inSetList(second, first->value))										//Если элемент не найден первого множества отсутствует во втором множестве
				addElem(difference, first->value);										//, добавляем этот элемент в множество разности
			first = first->next;														//Переходим к следующему элементу множества first
		}
	return difference;																	//Возвращаем указатель на первый элемент множества difference
}

//Функция симметричной разности двух множеств
Set* symmetricalDifference(Set* first, Set* second) {						
	return setDifference(combineTwoSets(first, second), 
						 intersectionofSets(first, second));							//Возвращаем указатель на первый элемент множества разности множества сортировки
}																						//и множества пересечения множеств first и second
