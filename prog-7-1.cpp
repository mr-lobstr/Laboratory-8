#include <iostream>
using namespace std;

int digit_add(long long num, int dig)
{
	while (num >= dig)
	{
		dig *= 10;
	}

	return dig + num;
}

bool func (long long N, long long sum, long long head, long long tail)
{
	if (head == 0)
	{
		if (sum + tail == N)
			cout << tail;

		return sum + tail == N;
	}

	if (func (N, sum + tail, head / 10, head % 10))
	{
		cout << "+" << tail;
	}
	else if (func (N, sum - tail, head / 10, head % 10))
	{
		cout << "-" << tail;
	}
	else if (func (N, sum, head / 10, digit_add(tail, head % 10)))
	{}
	else
	{
		return false;
	}

	return true;
}

int main()
{
	long long N, digits;
	cin >> N >> digits;
	func (N, 0, digits /10, digits % 10);
}