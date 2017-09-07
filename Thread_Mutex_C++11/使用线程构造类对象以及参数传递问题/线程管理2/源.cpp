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
	//��s���ô���
	//Ĭ����ֵ����

	std::thread t1(Fctor(), std::move(s));
	t1.join();
	std::cout << "from main: " << s << std::endl;


	//CPU������
	std::cout << std::thread::hardware_concurrency << std::endl;

	//���̲߳��ȴ�t1�̵߳�ִ��
	//t1.detach();
	system("pause");
	return 0;
}