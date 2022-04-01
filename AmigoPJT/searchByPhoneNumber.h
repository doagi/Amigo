#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<int> searchByPhoneNumber(int target, unordered_map<int, Employee2> data);
vector<int> searchByMiddlePhoneNumber(int target, unordered_map<int, Employee2> data);
vector<int> searchByLastPhoneNumber(int target, unordered_map<int, Employee2> data);