#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Util
{
public:
    static vector<string> split(const string& input, char delimiter)
    {
        vector<string> result;
        result.reserve(3);
        stringstream ss(input);
        string temp;
        while (getline(ss, temp, delimiter))
        {
            result.push_back(temp);
        }
        return result;
    }

    static vector<unsigned int> split_date(const string& input)
    {
        vector<unsigned int> result;
        if (input.size() == 8)
        {
            result.reserve(3);
            result.emplace_back(stoi(input.substr(0, 4)));
            result.emplace_back(stoi(input.substr(4, 2)));
            result.emplace_back(stoi(input.substr(6, 2)));
        }
        return result;
    }

#if _DEBUG
    static int Compare(string reference, string result)
    {
        cout << "\x1b[33m" << endl;
        string command = "fc.exe " + reference + " " + result;
        int error_level = system(command.c_str());
        cout << "\x1b[0m";

        if (error_level)
        {
            cout << "\x1b[31m[FAILED]\x1b[0m" << endl;
        }
        else
        {
            cout << "\x1b[32m[PASSED]\x1b[0m" << endl;
        }

        return error_level;
    }
#endif
};