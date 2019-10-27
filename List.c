//#include<iostream>
//
//
//using namespace std;
//
//
//namespace cx
//{
//	template<class T>
//
//	struct __list_node
//	{
//		__list_node<T>* _next;
//		__list_node<T>* _prev;
//		T _data;
//
//		__list_node(const T& x = T())
//			:_data(x)
//			, _next(nullptr)
//			, _prev(nullptr)
//		{}
//	};
//
//	template<class T, class Ref, class Ptr>
//
//	struct __list_iterator
//	{
//		typedef __list_node<T> node;
//		typedef __list_iterator<T, Ref, Ptr> Self;
//
//		node* _node;
//
//		__list_iteator(node* node)
//			:_node(node)
//		{}
//
//		Ref operator*()//但会T&，内置类型，传引用
//		{
//			return _node->_data;
//		}
//
//		Ptr operator->()//返回T*类型，用于方便自定义类型
//		{
//			return &_node->_data;
//		}
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		Self operator++(int)
//		{
//			__list_node<T> tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		Self operator--(int)
//		{
//			__list_iterator<T> tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//		bool operator==(const Self& it)
//		{
//			return _node == it._node;
//		}
//
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//	};
//
//	template <class T>
//	class list
//	{
//		typedef __list_node<T> node;
//
//	public:
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*> const_iterator;
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//
//		iterator begin()
//		{
//			return iterator(_head->next);
//		}
//
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		/*list(const list<T>& l)
//		{
//		_head = new node;
//		_head->_next = _head;
//		_head->_prev = _head;
//
//		auto it = l.beginl
//
//		while (it != l.end())
//		{
//		push_back(*it);
//		++it;
//		}
//		}*/
//
//		/*list<T>& operator=(list<T> l)
//		{
//
//		}*/
//
//		list()
//		{
//			_head = new node(T());
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		/*~list()
//		{
//
//		}
//
//		void clear()
//		{
//
//		}*/
//
//		void push_back(const T& x)
//		{
//			node* tail = _head->_prev;
//			node* newnode = new node(x);
//
//			tail->_next = newnode;
//			newnode->_prev = tail;
//			_head->_prev = newnode;
//			newnode->_next = _head;
//		}
//
//		/*void push_front(const T& x)
//		{
//
//		}*/
//
//		/*void pop_back()
//		{
//
//		}*/
//
//		/*void insert(iterator pos, const T& x)
//		{
//
//		}
//
//		iterator erase(iterator pos)
//		{
//
//		}*/
//
//	private:
//		node* _head;
//	};
//
//	/*void print_list(const list<int>& l)
//	{
//
//	}*/
//
//	void test()
//	{
//		list<int> l;
//		l.push_back(1);
//		l.push_back(2);
//		l.push_back(3);
//		l.push_back(4);
//
//		list<int>::iterator it = l.begin;
//
//		while (it != l.end());
//		{
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//}
#include<iostream>
#include<assert.h>
using namespace std;


namespace cx
{
	template<class T>

	struct __list_node
	{
		__list_node<T>* _next;
		__list_node<T>* _prev;
		T _data;

		__list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>

	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;

		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}

		

		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()//此处使用引用是因为这是前置++，出了作用域，不销毁
		{
			_node = _node->_next;
			return *this;
		}
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
		bool operator==(const Self& it)
		{
			return _node != it._node;
		}
	};

	template<class T>
	class list
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> const_iterator;
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);//调用__list_iterator构造函数
		}
		iterator end()
		{
			return iterator(_head);
		}

		list()
		{
			_head = new node(T());//调用__list_node结构体，初始化
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.begin();

			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
			/*if (*this == &l)
				return *this;
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
			return *this;*/
		}

		~list()
		{
			clear();

			delete[] _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);

			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return iterator(next);
		}

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);//调用__list_iterator(node* node)构造函数

			_head->_prev = newnode;
			newnode->_next = _head;

			tail->_next = newnode;
			newnode->_prev = tail;
			
		}
	private:
		node* _head;
	};
	void print_list(const list<int>& l)
	{
		auto it = l.begin();

		while (it != l.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test()
	{
		list<int> _l;
		list<int> l;//调用list构造函数初始化head
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		_l.push_back(6);
		_l.push_back(7);
		_l.push_back(8);
		print_list(_l);

		_l = l;
		print_list(_l);

		auto it = l.begin();

		while (it != l.end())
		{
			if (*it % 3 == 0)
			{
				it = l.erase(it);
			}
			++it;
		}

		print_list(l);
	}
}