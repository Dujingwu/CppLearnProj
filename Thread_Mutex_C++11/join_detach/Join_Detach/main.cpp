#include <iostream>
#include <thread>

void f()
{
	std::cout << "www.google.com\n";
}

int main()
{
	std::thread t1(f);

	//���߳���ȴ����߳�ִ��
	t1.join();
	system("pause");

	//���̲߳��ȴ�t1�̵߳�ִ��
	//t1.detach();
	return 0;
}