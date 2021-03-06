#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>


using namespace std;

class LofFile {
public:
	LofFile() {
		of.open("log.txt");
	}
	void shared_print(string id, int value) {
		lock(m_mutex, m_mutex2);
		lock_guard<mutex> locker(m_mutex, adopt_lock);
		lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		cout << "from" << id << ": " << value << endl;
	}
	void shared_print2(string id, int value) {
		lock(m_mutex, m_mutex2);
		lock_guard<mutex> locker2(m_mutex2, adopt_lock);
		lock_guard<mutex> locker(m_mutex, adopt_lock);


		cout << "from" << id << ": " << value << endl;
	}
protected:
private:
	mutex m_mutex;
	mutex m_mutex2;
	ofstream of;
};

void function_1(LofFile& log) {
	for (int i = 0; i > -100; i--)
	{
		log.shared_print2("from function_1: ", i);
	}
}

int main() {
	LofFile log;

	std::thread t1(function_1, ref(log));
	for (int i = 0; i < 100; i++)
	{
		log.shared_print("from main: ", i);
	}
	t1.join();
	return 0;
}


//采用lock和unlock时,如果处理出现异常,程序会被永远锁住
//如果有两把锁,锁的顺序需要一致,可避免循环等待,可使用lock();
//adopt_lock:锁住mutex,让locker获取mutex所有权,在析构时解锁mutex