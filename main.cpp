#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct student
{
    int code;
    string firstName;
    string lastName;
    string major;
    vector<string> subjects;
    vector<int> scores;
};
int main()
{
    int listSize=0;
    cout << "Enter the number of student you have : ";
    cin >> listSize;
    student list[listSize];
    int task;
    do
    {
        cout << "1-Add students\n2-Add Info about student\n3-Edit a student Info\n4-Show students list\n5-Show academic record\n6-exit\nChoose your option : ";
        cin >> task;
        switch (task)
        {
        case 1:
            for(int i=0; i < listSize; i++){
                cout << "Enter student full name : \n";
                cin >> list[i].firstName >> list[i].lastName;
                cout << "Enter student id : \n";
                cin >> list[i].code;
                cout << "Enter student major : \n";
                cin >> list[i].major;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    } while (task <= 6);
    return 0;
}
