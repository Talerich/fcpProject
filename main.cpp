#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct student
{
    int code;
    string name;
    string major;
    vector<string> subjects;
    vector<int> scores;
};
int main()
{
    vector<student> list;
    int task;
    do {
        cout << "1-Add a student\n2-Add Info about student\n3-Edit a student Info\n4-Show students list\n5-Show academic record\n6-exit\nChoose your option : ";
        cin >> task;
        switch(task){
            
        }
    } while (task <=6);
    return 0;
}
