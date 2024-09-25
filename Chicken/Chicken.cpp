#include <iostream>
#include <cstring>
using namespace std;

class Chicken
{
private:
	int age = 24;
	char *name = nullptr;
public:
	Chicken() : age(0), name(nullptr){};
	Chicken(int _age) : age(_age), name(nullptr) {};
	Chicken(int _age, const char *_name) : age(_age)
	{
		int len = strlen(_name) + 1;
		name = new char[len];
		for (int i=0; i<len ; i++)
			name[i] = _name[i];
	};
	~Chicken()
	{
		if(name != nullptr){
			delete[] name;
		}
	}
	void setAge(int _age)
	{
		age = _age;
	}
	void setName(const char *_name)
	{
		delete[] name;
		int len = strlen(_name) + 1;
		name = new char[len];
		for(int i=0; i<len ; i++)
			name[i] = _name[i];
	}
	const char *getName() const
	{
		return name;
	}
	const int &getAge() const
	{
		return age;
	}
	//create a replication function
	Chicken(const Chicken &object) : age(object.age), name(nullptr)
	{
		if(object.name){
			int len = strlen(object.name)+1;
			name = new char[len];
			for (int i = 0; i<len ;i++)
				name[i] = object.name[i];
		}
	}
	//overload assignment operator
	Chicken& operator=(const Chicken &object)
	{
		if(this != &object){
			if(name != nullptr){
				delete[] name;
			}
			age = object.age;
			if(object.name){
				int len = strlen(object.name)+1;
				name = new char[len];
				for(int i=0; i<len; i++)
					name[i] = object.name[i];
			}else{
				name = nullptr;
			}
		}
		return *this;
	}
};

int main()
{
	auto print = [](const Chicken &c){
		cout<< "Hi, everyone! My name is "<< c.getName() << ", I am " << c.getAge() << "years old." << endl;
	};
	Chicken c(24, "Kunkun");
	print(c);
	
	Chicken d;
	d = c;
	print(d);
	
	Chicken a = c;
	print(a);
	
	c.setName("XuKun Cai");
	print(c);
	print(a);
	print(d);
	
	Chicken b;
	b = d = c;
	print(b);
	print(d);
	return 0;
}



