#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../common.h"

using namespace std;

vector<string> Mod(unordered_map<unsigned int, Employee2>& map_employees,
    vector<unsigned int>& found_data, const ModificationInfo& condition);

string GenerateRecord(const std::string& cmd, Employee2& data);

void ModifyColumnData(Employee2& employee, const ModificationInfo& mod_info);
