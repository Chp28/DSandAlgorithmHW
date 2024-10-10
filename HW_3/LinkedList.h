#include <initializer_list>

template<typename T>
class SingleLinkedList{
private:
	class Node{
	private:
		T data;
		Node *next = nullptr;
		Node(T _val){data = _val;}
		
		friend class SingleLinkedList<T>;
	};
	Node* head = nullptr;
	int size = 0;
	Node* currentPos = nullptr;
	void _emptyList(){
		Node* p = head;
		while(p != nullptr){
			Node* t = p;
			p = p->next;
			delete t;
		}
	};
	void _copy(const SingleLinkedList<T> &_l);
public:
	T getCurrentVal() const;
	void setCurrentVal(const T &_val);
	bool isEmpty() const;
	int getsize() const;
	void emptyList();
	SingleLinkedList(){};
	~SingleLinkedList(){
		_emptyList();
	};
	SingleLinkedList(std::initializer_list<T> _l);
	void printList() const;
	SingleLinkedList(const SingleLinkedList<T> &_l);
	SingleLinkedList<T>& operator=(const SingleLinkedList<T> &_l);
///	SingleLinkedList(SingleLinkedList<T> &&_l);
	void insert(T _val);
	bool find(const T &val);
	void remove();
};

template<typename T>
bool SingleLinkedList<T>::find(const T &val)
{
	if(head == nullptr){
		return false;
	}else{
		Node* p = head;
		while(p!=nullptr){
			if(p->data==val){
				currentPos = p;
				return true;
			}else{
				p = p->next;
			}
		}
		return false;
	}
}

template<typename T>
T SingleLinkedList<T>::getCurrentVal() const
{
	if(currentPos == nullptr){
		std::cout << "Empty current position! Can't get value!" << std::endl;
		exit(-1);
	}
	else{
		return currentPos->data;
	}
}

template<typename T>
void SingleLinkedList<T>::setCurrentVal(const T &_val)
{
	if(currentPos == nullptr){
		std::cout << "Empty current position! Can't set value!" << std::endl;
		exit(-1);
	}else{
		currentPos->data = _val;
	}
}

template<typename T>
bool SingleLinkedList<T>::isEmpty() const
{
	if(size == 0)
		return true;
	else
		return false;
}

template<typename T>
int SingleLinkedList<T>::getsize() const
{
	return size;
}

template<typename T>
void SingleLinkedList<T>::insert(T _val)
{
	if(head == nullptr){
		head = new Node(_val);
		++size;
		currentPos = head;
	}else{
		Node* temp = currentPos->next;
		Node* newNode = new Node(_val);
		currentPos->next = newNode;
		newNode->next = temp;
		++size;
	}
}

template<typename T>
void SingleLinkedList<T>::remove()
{
	if(currentPos==nullptr){
		return;
	}else{
		if(size == 1){
			emptyList();
		}else{
			if(currentPos->next != nullptr){
				Node* temp = currentPos->next->next;
				delete currentPos->next;
				currentPos->next = temp;
				size -= 1;
			}
		}
	}
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> _l)
{
	for (auto i = _l.begin(); i != _l.end(); ++i)
	{
		Node* newNode = new Node(*i);
		if(head == nullptr){
			head = newNode;
			currentPos = head;
		}else{
			currentPos->next = newNode;
			currentPos = newNode;
		}
		++size;
	}
}

template <typename T>
void SingleLinkedList<T>::printList() const
{
	Node* p = head;
	while(p!=nullptr)
	{
		std::cout << p->data << "\t";
		p = p->next;
	}
	std::cout << std::endl;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &_l)
{
	_copy(_l);
}

template<typename T>
void SingleLinkedList<T>::_copy(const SingleLinkedList<T> &_l)
{
	Node *p = _l.head;
	while(p != nullptr)
	{
		Node* newNode = new Node(p->data);
		if(head == nullptr)
		{
			head = newNode;
			currentPos = head;
		}else{
			currentPos->next = newNode;
			currentPos = newNode;
		}
		++size;
		p = p->next;
	}
}

template<typename T>
void SingleLinkedList<T>::emptyList()
{
	_emptyList();
	head = nullptr;
	currentPos = nullptr;
	size = 0;
}

template <typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T> &_l)
{
	emptyList();
	_copy(_l);
	return *this;
}

