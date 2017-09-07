#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <fstream>
#include <future>


using namespace std;

int factorial(future<int> &f) {
	int res = 1;
	
	for (int i = f.get();  i>1; i--)
	{
		res *= i;
	}
	
	return res;
}

int main()
{
	int x;
	promise<int> p;
	future<int> f = p.get_future();
	future<int> fu = async(launch::async,factorial, ref(f));
	
	p.set_value(4);//未设置就会在factorial中运行到f.get()时抛出异常
	x =fu.get();

	cout << "Get from child: " << x << endl;
	return 0;
}
//async函数避免子线程冗余的编程,用future,从主线程获取子线程变量
//用promise从子线程获取主线程变量
//launch::defer(延期启动,直到get()被调用,在同一线程调用factorial) | launch::async(创建另一个进程执行factorial)
//shared_future可以被拷贝,future可以从promise中的get_future得到但不能被拷贝
