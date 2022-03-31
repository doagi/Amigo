#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "common.h"

using namespace std;

vector<Command> ParserFromTxt(string src_txt_path);
