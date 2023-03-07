#pragma once
#include <string>
using namespace std;

enum typeClass {
	TH,
	LT
};

class School {
public:
	class Class;
private:
	Class* head;
	Class* tail;
	int numsClass;
public:
	School(int numsClass) : head(NULL), tail(NULL), numsClass(numsClass) {}
	int getNumsClass();
	bool is_Empty();
	void viewClass();
	bool addClass(string, typeClass, bool, int);
	bool addClass(string, typeClass, bool);
	int findIndex(string);
	Class* findClass(string);
	bool deleteClass(string);
	void setClass(string,typeClass,bool);

public:
	class Class {
	private:
		string id;
		typeClass type;
		bool is_Set;
		Class* next;
		friend class School;
	public:
		Class(string id, typeClass type, bool is_Set) : id(id), type(type), is_Set(is_Set), next(NULL) {}
		void setClassSet(bool is_Set) {
			this->is_Set = is_Set;
		}
		void setTypeClass(typeClass type) {
			this->type = type;
		}
		void setIDClass(string id) {
			this->id = id;
		}
	};
};