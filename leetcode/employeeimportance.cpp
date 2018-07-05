//690
#include <bits/stdc++.h>
using namespace std;

bool visited[2001];
int important;
class Employee{
public:
	int id;
	int importance;
	vector<int> subordinates;
};
map<int,Employee*> mapemployee;
int dfs(int id){
	visited[id] = true;
	Employee *stuff = mapemployee[id];
	important += stuff->importance;
	for(int id: stuff->subordinates){
		if(!visited[id]){
			dfs(id);
		}
	}
	return important;
}

int getImportance(vector<Employee*> employee, int id){
	if(employee.size() == 1){ return employee[0]->importance; }

	for(Employee *stuff: employee){
		mapemployee[stuff->id] = stuff;
	}
	important = 0;
	return dfs(id);	
}

int main(){
	vector<Employee*> list;
	Employee *emp1 = new Employee();
	emp1->id=1;
	emp1->importance=15;
	emp1->subordinates.push_back(2);	
	list.push_back(emp1);

	Employee *emp2 = new Employee();
	emp2->id=2;
	emp2->importance=10;	
	emp2->subordinates.push_back(3);
	list.push_back(emp2);

	Employee *emp3 = new Employee();
	emp3->id=3;
	emp3->importance=5;	
	list.push_back(emp3);

	cout<< getImportance(list,3);

	return 0;
}