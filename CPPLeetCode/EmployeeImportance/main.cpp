#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
    Employee(int id, int importance, vector<int> subordinates=vector<int>()): id(id), importance(importance), subordinates(subordinates){};
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> id_map;
        auto iend = employees.end();
        for(auto i=employees.begin(); i< iend; ++i){
            id_map[(*i)->id] = *i;
        }
        if(id_map.find(id) == id_map.end()){
            return 0;
        }
        auto employee = id_map[id];
        int result = employee->importance;
        queue<int> tmp_queue;
        {
            auto iend = employee->subordinates.end();
            for(auto i=employee->subordinates.begin(); i< iend; ++i){
                tmp_queue.push(*i);
            }
        }

        while(!tmp_queue.empty()){
            int inx = tmp_queue.front();
            if (id_map.find(inx)==id_map.end()){
                return 0;
            }
            auto sub = id_map[tmp_queue.front()];
            tmp_queue.pop();
            result += sub->importance;
            auto iend = sub->subordinates.end();
            for(auto i=sub->subordinates.begin(); i< iend; ++i){
                tmp_queue.push(*i);
            }
        }
        return result;
    }
};

int main(){
    vector<int> subordinates = {2};
    Employee* employee_1 = new Employee(1, 5, subordinates);
    Employee* employee_2 = new Employee(2, 4);
    vector<Employee*> employees = {employee_1, employee_2};
    cout << Solution().getImportance(employees, 1) << endl;
    delete employee_1;
    delete employee_2;
}
