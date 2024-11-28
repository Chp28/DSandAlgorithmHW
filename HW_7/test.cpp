#include <iostream>
#include <vector>
#include "HeapSort.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void test(vector<int> arr){
	vector<int> sequence = arr;
	auto start = chrono::high_resolution_clock::now();
	make_heap(sequence.begin(),sequence.end());
	sort_heap(sequence.begin(),sequence.end());
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end-start;
	cout << "running time: " << elapsed.count() << " s\n";
}

int main(){
	const int length = 1000000;
	vector<int> sequence(length);
	srand(static_cast<unsigned int>(time(nullptr)));
	for(int i=0; i<length; ++i){
		sequence[i] = rand()%1000000;
	}
	HeapSort<int> h1(sequence);
	h1.sort();
	h1.check();
	h1.print_time();
	test(sequence);
	
	for(int i=0; i<1000000; i++){
		sequence[i] = i;
	}
	HeapSort<int> h2(sequence);
	h2.sort();
	h2.check();
	h2.print_time();
	test(sequence);
	
	for(int i=0; i<1000000; i++){
		sequence[i] = 999999-i;
	}
	HeapSort<int> h3(sequence);
	h3.sort();
	h3.check();
	h3.print_time();
	test(sequence);
	
	for(int i=0; i<length; ++i){
		sequence[i] = rand()%100000;
	}
	HeapSort<int> h4(sequence);
	h4.sort();
	h4.check();
	h4.print_time();
	test(sequence);
	
	return 0;
}
