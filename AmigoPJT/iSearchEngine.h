#pragma once


class ISearchEngine
{
public:
    virtual vector<unsigned int> Search(string option2, string column, string target) = 0;
};