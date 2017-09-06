#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>


using namespace std;

class LofFile {
public:
	LofFile() {

	}
	void shared_print(string id, int value) {
		
		/*unique_lock<mutex> locker2(m_mutex_open, defer_lock);
		if (!of.is_open()) {
			of.open("log.txt");
		}*/
		call_once(m_flag, [&]() {of.open("log.txt"); });//

		unique_lock<mutex> locker(m_mutex, defer_lock);
		locker.lock();
		of << "from" << id << ": " << value << endl;
		locker.unlock();
		//...
		locker.lock();
	}
protected:
private:
	mutex m_mutex;
	mutex m_mutex_open;
	once_flag m_flag;
	ofstream of;
};

void function_1(LofFile& log) {
	for (int i = 0; i > -100; i--)
	{
		log.shared_print("from function_1: ", i);
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