#include <iostream>
#include "main.h"

using namespace std;

int School::getNumsClass() {
	return this->numsClass;
}

void School::viewClass() {

}

bool School::is_Empty() {
	return this->numsClass;
}

bool School::addClass(string id, typeClass type, bool is_Set, int index) {
	if (index < 0 || index >= this->getNumsClass()) {
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
			else if (index == this->numsClass - 1) {
				tail->next = newClass;
				tail = newClass;
			}
			else {
				Class* phead = head;
				for (int i = 0; i < index - 1; i++) {
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
	tail->next = newClass;
	tail = newClass;
	return 1;
}

int main() {
	School* mySchool = new School(0);
	return 0;
}


