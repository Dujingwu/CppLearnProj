#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <fstream>
#include <future>

using namespace std;

class A
{
public:
	void f(int x, char c) {};
	int operator()(int N) { return 0; }

};

int main()
{
	A a;
	thread(a, 6);//
	async(launch::async, a, 6);
	return 0;
}