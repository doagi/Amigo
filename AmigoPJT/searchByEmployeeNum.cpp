#include "searchEtc.h"

vector<unsigned int> searchByEmployeeNumber(string target, unordered_map<unsigned int, Employee2> data)
{
    int entry_year = stoi(target.substr(0, 2));
    if (target.length() != 8)
    {
        throw std::length_error("Invalid Employee Number length.\n");
    }
    if (entry_year > 21 && entry_year < 69)
    {
        throw std::out_of_range("Invalid Employee Number. Entry year should be between 1969 and 2021.\n");
    }
    vector<unsigned int> result;
    unsigned int find_key = entry_year > 68 ? stoi("19" + target) : stoi("20" + target);
    auto aData = data.find(find_key);
    if (aData != data.end())
    {
        result.emplace_back(find_key);
    }
    return result;
}