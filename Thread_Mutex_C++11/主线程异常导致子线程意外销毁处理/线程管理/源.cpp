#include <iostream>
#include <thread>

void f()
{
	std::cout << "www.google.com\n";
}

int main()
{
	std::thread t1(f);

	try {
		for (int i = 0; i < 100; i++)
		{
			std::cout << "from main: " << i << std::endl;
		}
	}
	catch (...)
	{
		//如果不捕获异常,执行for语句出现异常会导致t1线程join之前被销毁
		t1.join();
		throw;
	}

	//主线程不等待t1线程的执行
	//t1.detach();
	system("pause");
	return 0;
}