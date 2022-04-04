#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<unsigned int> searchByPhoneNumber(string op2, string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByFullPhoneNumber(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByMiddlePhoneNumber(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByLastPhoneNumber(string target, unordered_map<unsigned int, Employee> data);