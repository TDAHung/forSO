#include <iostream>
#include "main.h"

using namespace std;

int School::getNumsClass() {
	return this->numsClass;
}

void School::viewClass() {
	Class* phead = head;
	while(phead){
		cout << "ID: " << phead->id << "     ,type: " << phead->type << "      ,status: " << phead->is_Set << "\n";
		phead = phead->next;
	}
}

bool School::is_Empty() {
	return this->numsClass;
}

bool School::addClass(string id, typeClass type, bool is_Set, int index) {
	if (index < 0 || index > this->getNumsClass()) {
		return 0; // bao loi cho user
	}
	else {
		Class* newClass = new Class(id, type, is_Set);
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

bool School::addClass(string id, typeClass type, bool is_Set) {
	Class* newClass = new Class(id, type, is_Set);
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
			delete(deleteClass);
		}
		//else if (index == this->numsClass - 1) {
		//	for (int i = 0; i < this->numsClass - 2; i++) deleteClass = deleteClass->next;
		//	tail = deleteClass;
		//	delete(deleteClass->next);
		//}
		//else {
		//	for (int i = 0; i < index - 2; i++) deleteClass = deleteClass->next;
		//	deleteClass->next = deleteClass->next->next;
		//	delete(deleteClass->next);
		//}
		this->numsClass--;
		return 1;
	}
}


void School::setClass(string id, typeClass type, bool is_Set) {
	Class *classFound = findClass(id);
	classFound->setClassSet(is_Set);
	classFound->setTypeClass(type);
}

int main() {
	School* mySchool = new School(0);
	int nums;
	cout << "input nums: ";
	cin >> nums;
	string id;
	int typeInput;
	bool is_Set;
	for (int i = 0; i < nums; i++) {
		cout << "input id: ";
		cin >> id;
		cout << "input type (TH: 0,LT: 1): ";
		cin >> typeInput;
		typeClass type = static_cast<typeClass>(typeInput);
		mySchool->addClass(id,type,0);
	}
	mySchool->viewClass();
	string test = mySchool->deleteClass("0") ? "xoa roi" : "chua xoa";
	cout << test << endl;
	mySchool->viewClass();
	return 0;
}


