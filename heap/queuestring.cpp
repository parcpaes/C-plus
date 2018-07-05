#include <bits/stdc++.h>

using namespace std;

class Person {
public:
	Person(int age) : age(age){}

	int age;
};

bool operator<(const Person& a, const Person&b){
	return a.age < b.age;
}

int main(){
	priority_queue<Person> Q;
	priority_queue<int> test;
	set<int> call;
	for(int i: {1,1,10,2,9,3,8,4,7,5,6}){		
		Q.push(Person(i));
		test.push(i);
		call.insert(i);
	}

	while(!test.empty()){
		cout << test.top() << " ";
		test.pop();
		
	}
	cout << "\n";
	while(!Q.empty()){
		Person p = Q.top();
		Q.pop();
		cout << p.age << " ";
	}
	cout << "\n";
	for(auto it= call.begin(); it!=call.end(); it++){
		cout<< *it << " ";
	}
	return 0;
}