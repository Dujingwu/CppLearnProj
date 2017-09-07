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
	
	p.set_value(4);//δ���þͻ���factorial�����е�f.get()ʱ�׳��쳣
	x =fu.get();

	cout << "Get from child: " << x << endl;
	return 0;
}
//async�����������߳�����ı��,��future,�����̻߳�ȡ���̱߳���
//��promise�����̻߳�ȡ���̱߳���
//launch::defer(��������,ֱ��get()������,��ͬһ�̵߳���factorial) | launch::async(������һ������ִ��factorial)
//shared_future���Ա�����,future���Դ�promise�е�get_future�õ������ܱ�����
