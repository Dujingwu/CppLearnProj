#include <iostream>
#include <thread>
#include <string>
void f()
{
	std::cout << "www.google.com\n";
}

class Fctor {
public:
	void operator()(std::string msg) {
		std::cout << "from Fctor: " << msg << std::endl;
	}
};


int main()
{
	std::string s = "www.google.com";

	//std::thread t1(Fctor(), std::ref(s));
	//将s引用传递
	//默认是值传递

	std::thread t1(Fctor(), std::move(s));
	t1.join();
	std::cout << "from main: " << s << std::endl;


	//CPU核心数
	std::cout << std::thread::hardware_concurrency << std::endl;

	//主线程不等待t1线程的执行
	//t1.detach();
	system("pause");
	return 0;
}