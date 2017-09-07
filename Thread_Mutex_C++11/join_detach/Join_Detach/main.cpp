#include <iostream>
#include <thread>

void f()
{
	std::cout << "www.google.com\n";
}

int main()
{
	std::thread t1(f);

	//主线程需等待子线程执行
	t1.join();
	system("pause");

	//主线程不等待t1线程的执行
	//t1.detach();
	return 0;
}