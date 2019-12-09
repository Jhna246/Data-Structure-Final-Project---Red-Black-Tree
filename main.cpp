#include "main.h"

int main()
{
	RBT root;

	std::string value;

	std::ifstream input1;
	std::ifstream input2;

	input1.open("ex04.txt");

	std::string line;

	if (input1.is_open())
	{
		while (getline(input1, line))
		{
			root.insert(line);
		}
	}

	input1.close();
	root.display();
	cout << endl;

	input2.open("words.txt");

	if (input2.is_open())
	{
		while (getline(input2, line))
		{
				value = line;
				root.print(value);
		}
	}

	input2.close();

	system("PAUSE");
}