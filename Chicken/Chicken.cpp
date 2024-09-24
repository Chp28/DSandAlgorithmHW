#include <iostream>
#include <cstring>
using namespace std;

class Chicken
{
private:
	int age = 24;
	char *name = nullptr;
public:
	Chicken(){};
	Chicken(int _age) : age(_age) {};
	Chicken(int _age, const char *_name) : age(_age)
	{
		int len = strlen(_name) + 1;
		name = new char[len];
		for (int i=0; i<len ; i++)
			name[i] = _name[i];
	};
	~Chicken()
	{
		if(name != nullptr)
			delete[] name;
	}
	void setAge(int _age)
	{
		age = _age;
	}
	void setName(const char *_name)
	{
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
	Chicken c1(24, "Kunkun");
	cout<< "Hi, everyone! My name is " << c1.getName() << ", I am " << c1.getAge() << " years old." << endl;
	Chicken c2(c1); //use replication function
	cout<< "Hi, everyone! My name is " << c2.getName() << ", I am " << c2.getAge() << " years old." << endl;
	Chicken c3(c1); //use operator"="
	cout<< "Hi, everyone! My name is " << c3.getName() << ", I am " << c3.getAge() << " years old." << endl;
	return 0;
}



