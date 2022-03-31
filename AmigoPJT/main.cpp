#include <iostream>
#include <fstream>

int main ()
{
	std::string Path = "input_20_20.txt";

	std::ifstream readFile (Path);
	if (readFile.is_open ())
	{
		char line[200];
		while (!readFile.eof ())
		{
			readFile.getline (line, sizeof (line));
			std::cout << line << std::endl;
		}
		readFile.close ();
	}
	return 0;
}