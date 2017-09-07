#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>

using namespace std;

deque<int> q;
mutex mu;
condition_variable cond;

void funciton_1()
{
	int count = 1;
	while (count>0)
	{
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();
		cout << "1 notify" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
	cout << "1 end" << endl;
}

void function_2()
{
	int data = 0;
	do
	{
		unique_lock<mutex> locker(mu);
		cout << "2 wait" << endl;
		//cond.wait(locker, []() {return !q.empty(); });//locker
		cond.wait(locker);//locker
		data = q.back();
		q.pop_back();
		locker.unlock();
		cout << "f2 got a value from f1: " << data << endl;
	} while (data>1);
	cout << "2 end" << endl;
}

int main()
{
	
	thread t1(funciton_1);
	thread t2(function_2);
	
	t1.join();
	t2.join();

	return 0;
}

//设置循环等待占用cpu,设置延时等待具体的等待时间难以界定,解决方案是:条件变量
//uniquelock可以重复加解锁lockguard不行,cond.wait必须传入uniquelock参数