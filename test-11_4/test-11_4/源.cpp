#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// stack就是将双端队列重新封装
// 适配器：将一种数据结构进行封装，形成一种新的结构
// 容器适配器
#include <deque>
namespace bite
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack()
			: _con()
		{}

		void push(const T& data)
		{
			_con.push_back(data);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}

		const T& top()const
		{
			return _con.back();
		}

		size_t size()const
		{
			return _con.size();
		}

		bool empty()const
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}

#include <vector>

int main()
{
	bite::stack<int> s1;
	bite::stack<int, vector<int>> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	cout << s2.size() << endl;
	cout << s2.top() << endl;

	s2.pop();
	s2.pop();
	cout << s2.size() << endl;
	cout << s2.top() << endl;

	return 0;
}
#endif

#if 0
#include <deque>

namespace bite
{
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		queue()
			: c()
		{}

		void push(const T& data)
		{
			c.push_back(data);
		}

		void pop()
		{
			c.pop_front();
		}

		T& front()
		{
			return c.front();
		}

		const T& front()const
		{
			return c.front();
		}

		T& back()
		{
			return c.back();
		}

		const T& back()const
		{
			return c.back();
		}

		size_t size()const
		{
			return c.size();
		}

		bool empty()const
		{
			return c.empty();
		}
	private:
		Container c;
	};
}


#include <list>

int main()
{
	bite::queue<int> q1;
	bite::queue<int, list<int>> q2;

	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;

	q2.pop();
	q2.pop();
	cout << q2.size() << endl;
	cout << q2.front() << endl;
	cout << q2.back() << endl;
	return 0;
}
#endif


#if 0
// 默认按照小于less方式比较--->大堆
// 小堆：用户必须提供比较方式--->大于--->greater
//      注意：如果需要提供比较规则，模板参数列表的第二个参数必须显式提供
#include <queue>
#include <functional>

int main()
{
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(3);
	q.push(1);
	q.push(9);
	q.push(0);
	q.push(5);
	q.push(7);

	cout << q.top() << endl;

	return 0;
}
#endif

// 对于自定义类型，如果创建小堆--->必须重载 >
//              如果创建大堆--->必须重载 <
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		if (_year < d._year ||
			_year == d._year && _month < d._month ||
			_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}

		return false;
	}


private:
	int _year;
	int _month;
	int _day;
};


#include <queue>
#include <functional>

int main()
{
	Date d1(2019, 9, 15);
	Date d2(2019, 9, 16);
	Date d3(2019, 9, 14);

	priority_queue<Date> q;
	q.push(d1);
	q.push(d2);
	q.push(d3);
	return 0;
}

