#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <fstream>
#include <future>
#include <vector>

using namespace std;

int factorial(int N) {
	int res = 1;

	for (int i = N; i>1; i--)
	{
		res *= i;
	}
	cout << "Result is: " << res << endl;
	return res;
}

int main()
{
	thread t1(factorial, 4);
	this_thread::sleep_for(chrono::seconds(2));
	chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::milliseconds(1000);
	this_thread::sleep_until(tp);
	t1.join();
	return 0;
}