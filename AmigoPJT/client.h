#pragma once

#include "amigoDatabase.h"
#include "inputStream.h"
#include "outputStream.h"
#include <string>

class Client
{
public:
    Client();

    Client(const string& input_path, const string& output_path);

    ~Client() = default;

    void Run(const bool& debug_print = false);

    void Run(const string& input_path, const string& output_path, const bool& debug_print = false);

private:
    IDatabase* amigo_db;
    string input_path;
    string output_path;
};