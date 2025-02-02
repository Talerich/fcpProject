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
    vector<float> scores;
    float avgScore = 0;
};
int main()
{
    int listSize=0;
    cout << "Enter the number of student you have : ";
    cin >> listSize;
    student list[listSize];
    string majorList[listSize];
    int task;
    bool haveStudent = 0;
    int counter = 0;
    do
    {
        cout << "1-Add students\n2-Add Info about student\n3-Edit a student Info\n4-Show students list\n5-Show academic record\n6-exit\nChoose your option : ";
        cin >> task;
        switch (task)
        {
        case 1:
            
            if(haveStudent == 0){
                for(int i=0; i < listSize; i++){
                    bool isMajor = false;
                    cout << "Enter student full name : \n";
                    cin >> list[i].firstName >> list[i].lastName;
                    cout << "Enter student id : \n";
                    cin >> list[i].code;
                    cout << "Enter student major : \n";
                    cin >> list[i].major;
                    for(int j = 0; majorList[j] != "\0"; j++){
                        if (list[i].major == majorList[j])
                            isMajor = true;
                    }
                    if(!isMajor){
                        majorList[counter] = list[i].major;
                        counter++;
                    }
                }
                haveStudent = 1;
            }
            else{
                cout << "You have already entered all students\n";
            }
            break;
        case 2:
            missId:
            int tempId;
            cout << "Enter id of student you want to add info about\n";
            cin >> tempId;
            int index= -1;
            for(int i = 0; i < listSize; i++){
                if(list[i].code == tempId)
                    index = i;
            }
            if (index == -1){
                cout << "There is no student with this id, Try again!\n";
                goto missId;
            }
            else{
                int point;
                string sub;
                do{
                    cout << "Enter your student subject and score : (Enter \'quit\' to return to menu)\n";
                    cin >> sub;
                    if(sub == "quit")
                        break;
                    cin >> point;
                    list[index].subjects.push_back(sub);
                    list[index].scores.push_back(point);
                    list[index].avgScore += point;
                }while (1);
                list[index].avgScore /= list[index].scores.size();
            }
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
