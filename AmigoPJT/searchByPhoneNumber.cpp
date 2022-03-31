#include "searchByPhoneNumber.h"

int searchByMiddlePhoneNumber(int target, vector<Employee> data) {
	int result = 0;
	for (size_t i = 0; i < data.size(); i++) {
		string middle_number = data[i].phone_num.substr(4, 4);
		if (stoi(middle_number) != target) continue;
		result = i;
		break;
	}
	return result;
}

int searchByLastPhoneNumber(int target, vector<Employee> data) {
	int result = 0;
	for (size_t i = 0; i < data.size(); i++) {
		string last_number = data[i].phone_num.substr(9, 4);
		if (stoi(last_number) != target) continue;
		result = i;
		break;
	}

	return result;
}