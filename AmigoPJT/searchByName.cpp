#include "searchByName.h"

int searchByFirstName(string target, vector<Employee> data) {
	int result = 0;
	for (size_t i = 0; i < data.size(); i++) {
		size_t position = data[i].name.find(" ");
		string first_name = data[i].name.substr(0, position);
		if (first_name != target) continue;
		result = i;
		break;
	}
	return result;
}

int searchByLastName(string target, vector<Employee> data) {
	int result = 0;
	for (size_t i = 0; i < data.size(); i++) {
		size_t position = data[i].name.find(" ");
		string last_name = data[i].name.substr(position+1, string::npos);
		if (last_name != target) continue;
		result = i;
		break;
	}
	return result;
}