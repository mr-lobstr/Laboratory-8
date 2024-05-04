#include <string>
#include <iostream>
using namespace std;

size_t end_expr (const string& str, size_t ind)
{
	int brackets = 0;

	for (; ind < str.size(); ++ind)
	{
		if (brackets == 0)
		{
			if (str[ind] == ',' or str[ind] == ')')
				return ind;
		}

		if (str[ind] == ')')
			--brackets;

		if (str[ind] == '(')
			++brackets;	
	}

	return str.size();
}

bool logic_func (const string& str, size_t ind)
{
	if (str[ind] == 't' or str[ind] == 'f')
		return str[ind] == 't';

	if (str[ind] == '!')
		return not logic_func(str, ind + 2);

	bool is_AND = str[ind] == '&';
	ind += 2;

	while (str[ind] != ')')
	{
		bool res = logic_func(str, ind + 1);

		if (is_AND and not res)
		{
			return false;
		}

		if (not is_AND and res)
		{
			return true;
		}

		ind = end_expr(str, ind + 1);
	}

	return not is_AND;
}

int main()
{
	string st;
	cin >> st;
	cout << logic_func(st, 0) << endl;
}