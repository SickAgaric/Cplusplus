#include<iostream>


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

	template<class T,class Ref,class Ptr>

	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;

		node* _node;

		__list_iteator(node* node)
			:_node(node)
		{}

		Ref operator*()//但会T&，内置类型，传引用
		{
			return _node->_data;
		}

		Ptr operator->()//返回T*类型，用于方便自定义类型
		{
			return &_node->_data;
		}
		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			__list_node<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		
		bool operator==(const Self& it)
		{
			return _node == it._node;
		}

		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}
	};

	template <class T>
	class list
	{
		typedef __list_node<T> node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

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
			return iterator(_head->next);
		}


		iterator end()
		{
			return iterator(_head);
		}

		/*list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			auto it = l.beginl

			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}*/

		/*list<T>& operator=(list<T> l)
		{

		}*/

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		/*~list()
		{

		}

		void clear()
		{

		}*/

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);

			tail->_next = newnode;
			newnode->_prev = tail;
			_head->_prev = newnode;
			newnode->_next = _head;
		}

		/*void push_front(const T& x)
		{

		}*/

		/*void pop_back()
		{

		}*/

		/*void insert(iterator pos, const T& x)
		{

		}

		iterator erase(iterator pos)
		{

		}*/

	private:
		node* _head;
	};

	/*void print_list(const list<int>& l)
	{

	}*/

	void test()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		list<int>::iterator it = l.begin;

		while (it != l.end());
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}