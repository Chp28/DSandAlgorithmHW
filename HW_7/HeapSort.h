#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;

template<typename T>
class HeapSort{
protected:
	vector<T> heap;
	chrono::duration<double> elapsed;
	int size;
public:
	HeapSort(vector<T> arr) : heap{arr} {
		size = arr.size();
	}

	void check_heap(){
		for(int i=0; i<size; i++){
			if(2*i+1<=size){
				if(heap[2*i+1]>heap[i]){cout<< "no" <<endl; cout << i << endl;break;}
			}
			if(2*i+2<=size){
				if(heap[2*i+2]>heap[i]){cout<< "no" <<endl; cout << i << endl;break;}
			}
		}
	}
	
	void swap(T& a,T& b){
		T temp = a;
		a = b;
		b = temp;
	}
	
	void make_heap(int i){
		int max = i;
		if(2*i+1<size && heap[2*i+1]>heap[max]){
			max = 2*i+1; 
		}
		if(2*i+2<size && heap[2*i+2]>heap[max]){
			max = 2*i+2;
		}
		if(max!=i){
			swap(heap[i],heap[max]);
			make_heap(max);
		}
	}
	
	void Generate(){
		for(int i=size/2-1; i>=0; i--){
			make_heap(i);
		}
	}
	
	void sort(){
		auto start = chrono::high_resolution_clock::now();
		Generate();
		for(int i=size-1; i>0; i--){
			swap(heap[0],heap[i]);
			int cur = 0;
			while(2*cur+1<i){
				int max = cur;
				if(heap[2*cur+1]>heap[max]){
					max = 2*cur+1; 
				}
				if(2*cur+2<i && heap[2*cur+2]>heap[max]){
					max = 2*cur+2;
				}
				if(max!=cur){
					swap(heap[cur],heap[max]);
					cur = max;
					continue;
				}
				break;
			}
		}
		auto end = chrono::high_resolution_clock::now();
		elapsed = end-start;
	}
	
	void print_time(){
		cout << "running time: " << elapsed.count() << " s\n";
	}

	void print_heap(){
		for(int i=0; i<100; i++){
			cout << heap[i] << " ";
		}
		cout << endl;
	}
	
	void check(){
		int flag = 1;
		for(int i=0; i<size-1; i++){
			if(heap[i]<=heap[i+1]){
				continue;
			}else{
				flag = 0;
				//cout << i << " " << heap[i] << " " << heap[i+1] << endl;
			}
		}
		if(flag==1){
			cout << "success" << endl;
		}else{cout << "fail" << endl;}
		return;
	}
};
