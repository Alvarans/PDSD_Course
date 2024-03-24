#include "SetLab1_10.h"

using namespace std;

Set* createEmptySet() {
	Set* emptyset = nullptr;										//Создаём пустое множество emptyset = nullptr;										
	return emptyset;												//Возвращаем указатель на первый элемент
}

bool isEmpty(Set* set) {
	return set == nullptr;
}

bool inSetList(Set* first, int value) {
	//Проверка на пустоту множества
	if (isEmpty(first))
		return false;
	//Поиск элемента в множестве 
	while (first->next && first->value != value) {										
		first = first->next;
	}																
	return first->value == value;													
}

Set* addElem(Set*& first, int value) {
	//Добавление элемента в множество
	if (!inSetList(first, value)) {									//Если элемент отсутствует в списке, добавляем его. Иначе выводим сообщение
		Set* new_set = new Set;										//Создаём новое множество
		new_set->value = value;										//Записываем значение добавляемого элемента в первый элемент
		new_set->next = first;										//Устанавливаем указатель на следующий элемент на первый элемент старого множества
		first = new_set;
	}
	return first;
}

Set* createSet(int num, int min, int max, int k) {
	Set* first = createEmptySet();
	if (num * k > max - min + 1) {
		return first;
	}
	for (int i = 0; i < num; i++) {
		int candidate = 0;
		candidate = rand() % (max - min + 1);
		while ((candidate % k != 0) || (inSetList(first, candidate))) {
			candidate = rand() % (max - min + 1);
		}
		addElem(first, candidate);
	}
	return first;
}

int setPower(Set* first) {
	if (isEmpty(first)) {
		return 0;
	}
	int counter = 0;
	while (first != nullptr) {
		counter++;
		first = first->next;
	}
	return counter;
}

void showSet(Set* first, char splitter) {
	if (isEmpty(first)) {
		return;
	}
	cout << "\nShow set" << endl;
	while (first != nullptr) {
		cout << first->value;
		cout << splitter;
		first = first->next;
	}
}

Set* deleteSet(Set*& first) {
	Set* current = first;
	while (current != nullptr) {
		Set* temp = current;
		current = current->next;
		delete temp;
	}
	first = nullptr;
	return first;
}
