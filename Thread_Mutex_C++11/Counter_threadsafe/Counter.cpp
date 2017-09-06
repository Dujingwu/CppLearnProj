#include <boost\noncopyable.hpp>
#include <stdint.h>
#include <stdlib.h>
#include <mutex>
#include <iostream>

using namespace std;
class Counter :boost::noncopyable
{
public:
	Counter(){}
	int64_t value() const;
	int64_t getAndIncrease();

private:
	int64_t value_;
	//mutable MutexLock mutex_;
};


int main()
{
	int x = 9 & 7;
	cout << x;
	return 0;
}