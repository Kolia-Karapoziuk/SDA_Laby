#include <iostream>
#include <string>
using namespace std;

int counter = 0;

int recursiveMethod(char* str, int count)
{
	if (isdigit(*str))
	{
		count++;
	}

	if (*str == '\0')
	{
		return count;
	}

	recursiveMethod(++str, count);
}

void iterativeMethod(string str)
{
	for (size_t i = 0; i != str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			counter++;
		}
	}
	
}

int main() {
	char S[100] = "BmW 476dc55625255 London";
	cout << "Number of digits(Recursive method): " << recursiveMethod(S, 0) << endl;

	string str("BmW 476dc55625255 London");
	iterativeMethod(str);
	cout << "Number of digits(Iterative method): " << counter << endl;

	return 0;
}