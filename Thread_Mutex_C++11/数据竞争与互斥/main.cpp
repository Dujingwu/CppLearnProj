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
		lock_guard<mutex> locker(m_mutex);

		cout << "from" << id <<": "<< value << endl;
	}

protected:
private:
	mutex m_mutex;
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

	std::thread t1(function_1,ref(log));
	for (int i = 0; i < 100; i++)
	{
		log.shared_print("from main: ", i);
	}
	t1.join();
	return 0;
}


//����lock��unlockʱ,�����������쳣,����ᱻ��Զ��ס
//cout��ȫ�ֶ���,�����߳����ڲ�������������cout;�Ľ�ʹ��fstream