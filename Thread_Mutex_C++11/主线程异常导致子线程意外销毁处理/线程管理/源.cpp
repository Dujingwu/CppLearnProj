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
		//����������쳣,ִ��for�������쳣�ᵼ��t1�߳�join֮ǰ������
		t1.join();
		throw;
	}

	//���̲߳��ȴ�t1�̵߳�ִ��
	//t1.detach();
	system("pause");
	return 0;
}