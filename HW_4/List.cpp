#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	//test init() and size() and empty()
	List<int> lst;
	cout << lst.size() << endl; // 0
	cout << lst.empty() << endl; // 1
	
	//test push_back()
	for(int i=0; i<9 ; ++i)
	{
		lst.push_back(i);
	}
	int a = 9;
	lst.push_back(move(a));
	for(auto it: lst)
	{
		std::cout << it << " "; // 0 1 2 3 4 5 6 7 8 9
	}
	cout<<endl;
	
	//test front() and back()
	cout << lst.front() << " " << lst.back() << endl; // 0 9

	//test pop_front()
	lst.pop_front();
	for(auto it: lst)
	{
		std::cout << it << " "; // 1 2 3 4 5 6 7 8 9
	}
	cout<<endl;
	
	//test pop_back()
	lst.pop_back();
	for(auto it: lst)
	{
		std::cout << it << " "; // 1 2 3 4 5 6 7 8
	}
	cout<<endl;
	
	//test push_front()
	a = 0;
	int &b = a;
	lst.push_front(b);
	for(auto it: lst)
	{
		std::cout << it << " "; // 0 1 2 3 4 5 6 7 8
	}
	cout<<endl;
	lst.pop_front();
	lst.push_front(move(a));
	for(auto it: lst)
	{
		std::cout << it << " "; // 0 1 2 3 4 5 6 7 8
	}
	cout<<endl;
	
	//test insert() and end()
	int c = 9;
	int& d = c;
	lst.insert(lst.end(),d); 
	for(auto it: lst)
	{
		std::cout << it << " "; // 0 1 2 3 4 5 6 7 8 9
	}
	cout<<endl;
	lst.pop_back();
	lst.insert(lst.end(),move(c));
	for(auto it: lst)
	{
		std::cout << it << " "; // 0 1 2 3 4 5 6 7 8 9
	}
	cout<<endl;
	
	//test erase() and begin()
	lst.erase(lst.begin());
	for(auto it: lst)
	{
		std::cout << it << " "; // 1 2 3 4 5 6 7 8 9
	}
	cout<<endl;
	lst.erase(lst.begin(),lst.end());
	cout << lst.empty() << endl; // 1
	
	//test List(std::initializer_list<Object> il)
	List<int> _lst({1,2,3,4});
	for(auto it: _lst)
	{
		std::cout << it << " "; // 1 2 3 4
	}
	cout<<endl;
	
	//test operator =
	lst = _lst;
	for(auto it: lst)
	{
		std::cout << it << " "; // 1 2 3 4
	}
	cout<<endl;
	
	//test List(const List &rhs)
	List<int> l(lst);
	for(auto it: l)
	{
		std::cout << it << " "; // 1 2 3 4
	}
	cout<<endl;
	
	//test List(List &&rhs)
	List<int> _l(move(lst));
	for(auto it: l)
	{
		std::cout << it << " "; // 1 2 3 4
	}
	cout<<endl;
	
	//test clear()
	lst.clear();
	cout << lst.empty() << endl; // 1
	
	return 0;
}
