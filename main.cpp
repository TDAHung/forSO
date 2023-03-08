#include <iostream>
#include <iomanip>
#include "main.h"
#define WIDTH_ID 10
#define WIDTH_NAME 30
#define WIDTH_TYPE 15
#define WIDTH 10

using namespace std;

int School::getNumsClass() {
	return this->numsClass;
}

void School::viewClass() {
	Class* phead = head;
	while(phead){
		cout << "ID: " << phead->id << "name: " <<phead->name<<", type: " << phead->type << ", status : " << phead->is_Set << "\n";
		phead = phead->next;
	}
}

bool School::is_Empty() {
	return this->numsClass;
}

bool School::addClass(string id,string name, typeClass type, bool is_Set, int index) {
	if (index < 0 || index > this->getNumsClass()) {
		return 0; // bao loi cho user
	}
	else {
		Class* newClass = new Class(id,name , type, is_Set);
		if (this->numsClass == 0) {
			head = newClass;
			tail = head;
		}
		else {
			if (index == 0) {
				newClass->next = head;
				head = newClass;
			}
			else if (index == this->numsClass) {
				tail->next = newClass;
				tail = newClass;
			}
			else {
				Class* phead = head;
				for (int i = 0; i < index - 1 ; i++) {
					phead = phead->next;
				}
				newClass->next = phead->next;
				phead->next = newClass;
			}
		}
		this->numsClass++;
	}
	return 1;
}

bool School::addClass(string id, string name, typeClass type, bool is_Set) {
	Class* newClass = new Class(id,name, type, is_Set);
	if (this->numsClass == 0) {
		head = newClass;
		tail = head;
	}
	else {
		tail->next = newClass;
		tail = newClass;
	}
	this->numsClass++;
	return 1;
}

int School::findIndex(string id) {
	Class* phead = head;
	for (int i = 0; i < this->numsClass; i++) {
		if (phead->id == id) return i;
		phead = phead->next;
	}
	return -1;
}

School::Class *School::findClass(string id) {
	Class* phead = head;
	while (phead) if (phead->id == id) return phead;
	return NULL;
}

bool School::deleteClass(string id) {
	int index = this->findIndex(id);
	if (index < 0) return 0;
	else {
		Class* deleteClass = head;
		if (index == 0) {
			head = deleteClass->next;
			deleteClass = NULL;
		}
		else if (index == this->numsClass - 1) {
			while (deleteClass->next->next) deleteClass = deleteClass->next;
			tail = deleteClass;
			deleteClass->next = NULL;
		}
		else {
			for (int i = 0; i < index - 2; i++) deleteClass = deleteClass->next;
			Class* tempClass = deleteClass->next;
			deleteClass->next = deleteClass->next->next;
			tempClass = NULL;
		}
		this->numsClass--;
		return 1;
	}
}


void School::setClass(string id, typeClass type, bool is_Set) {
	Class *classFound = findClass(id);
	classFound->setClassSet(is_Set);
	classFound->setTypeClass(type);
}

void School::clearAll() {
	Class* phead = head;
	while (phead) {
		phead = phead->next;
		phead = NULL;
	}
	this->head = NULL;
	this->tail = NULL;
	this->numsClass = 0;
}

void School::inputClass(int size) {
	string id;
	string name;
	int typeInput;
	bool is_Set;
	for (int i = 0; i < size; i++) {
		cout << "input id: ";
		do {
			cin >> id;
			if (this->findIndex(id) != -1) cout << "Duplicate id. Please input again: ";
		} while (this->findIndex(id) != -1);

		cout << "Input Name: ";
		cin >> name;

		cout << "input type (TH: 0,LT: 1): ";
		do {
			cin >> typeInput;
			if (typeInput != LT && typeInput != TH) cout << "Invalid type of class. Please input again (TH: 0,LT: 1): ";
		} while (typeInput != LT && typeInput != TH);
		typeClass type = static_cast<typeClass>(typeInput);
		this->addClass(id,name, type, 0);
	}
}

void School::main() {
	cout << "*****************************************************************\n";
	cout << setw(WIDTH_ID) << left << "* ID";
	cout << setw(WIDTH_NAME) << left << "Name";
	cout << setw(WIDTH_TYPE) << left << "Type";
	cout << setw(WIDTH) << right << "Status *" << endl;
	cout << "*****************************************************************\n";

}

int main() {
	School* mySchool = new School(0);
	//int size = 0;
	//cout << "input nums: ";
	//cin >> size;
	//mySchool->inputClass(size);
	mySchool->main();
	return 0;
}


