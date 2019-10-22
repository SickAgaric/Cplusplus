#include<iostream>

using namespace std;

namespace cx
{
	template<class T>

	struct _list_node
	{

		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _date;

		_list_node(const T& x = T())
			:_date(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}

	};

	template<class T,class ref,class ptr>

	class _list_iterator
	{
		typedef _list_iterator<T> node;
		typedef _list_iterator<T, ref, ptr> self;

		node* _node;

		__list_iterator(node _node)
			:_node(node)
		{}

		ref operator*()
		{
			return _node->date;
		}

		ptr operator->()
		{
			return &_node->date;
		}

		self operator++()
		{
			_node = _node->next;
			return *this;
		}

		self operator++(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->next;
			return tmp;
		}

		self operator--()
		{
			_node = _node->prev;
			return *this;
		}

		self operator--(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->prev;
			return tmp;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}

	};

	template<class T>

	class List
	{
		typedef __list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin() const
		{
			return const_iterator (_head->next);
		}

		const_iterator end() const
		{
			return const_iterator (_head->prev);
		}

		iterator begin()
		{
			return iterator (_head->next);
		}

		iterator end()
		{
			return iterator (_head->prev);
		}

		List()
		{
			_head = new node(T());
			_head->next = _head;
			_head->prev = _head;
		}

		~List()
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



		List(const List<T>& l)
		{
			_head = new node;
			_head->next = _head;
			_head->prev = _head;

			auto it = l.begin();

			while (it != l.end)
			{
				push_back(*it);
				it++;
			}

		}

		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
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
	private:
		node* _head;
	};
	void print_list(const List<int>& l)
	{
		List<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10; // it.operator*() = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}



void Test()
{
	cx::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.pop_back();
	cx::print_list(l);

}