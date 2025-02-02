#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct student
{
    int id;
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
        cout << "1-Add students\n2-Add Info about student\n3-Edit a student Info\n4-Delete a student info\n5-Show students list\n6-Show academic record\n7-exit\nChoose your option : ";
        cin >> task;
        switch (task)
        {
        case 1:{

            if(haveStudent == 0){
                for(int i=0; i < listSize; i++){
                    bool isMajor = false;
                    cout << "Enter student full name : \n";
                    cin >> list[i].firstName >> list[i].lastName;
                    cout << "Enter student id : \n";
                    cin >> list[i].id;
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
        }break;
        case 2:{
            if(haveStudent == 0){
                cout << "You don`t have a student yet\n";
                continue;
            }
            missIdAdd:
            int tempIdadd;
            cout << "Enter id of student you want to add info about\n";
            cin >> tempIdadd;
            int addIndex= -1;
            for(int i = 0; i < listSize; i++){
                if(list[i].id == tempIdadd)
                    addIndex = i;
            }
            if (addIndex == -1){
                cout << "There is no student with this id, Try again!\n";
                goto missIdAdd;
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
                    list[addIndex].subjects.push_back(sub);
                    list[addIndex].scores.push_back(point);
                    list[addIndex].avgScore += point;
                }while (1);
                list[addIndex].avgScore /= list[addIndex].scores.size();
            }
        }break;
        case 3:{
            if(haveStudent == 0){
                cout << "You don`t have a student yet\n";
                continue;
            }
            missIdEdit:
            int tempIdEdit;
            cout << "Enter id of student you want to edit his/her info\n";
            cin >> tempIdEdit;
            int editIndex= -1;
            for(int i = 0; i < listSize; i++){
                if(list[i].id == tempIdEdit)
                    editIndex = i;
            }
            if (editIndex == -1){
                cout << "There is no student with this id, Try again!\n";
                goto missIdEdit;
            }
            else{
                string editTask;
                missEditTask:
                cout << "Enter the part you wnat to edit (\'name\' , \'id\' , \'major\' , \'subject\'): ";
                cin >> editTask;
                if(editTask == "name"){
                    cout << "Enter student new full name: \n";
                    cin >> list[editIndex].firstName >> list[editIndex].lastName;
                }
                else if(editTask == "id"){
                    cout << "Enter student new id : \n";
                    cin >> list[editIndex].id;
                }
                else if(editTask =="major"){
                    cout << "Enter student new major : \n";
                    cin >> list[editIndex].major;
                }
                else if(editTask == "subject"){
                    string editSub,newSub;
                    float newScore = 0;
                    missEditSub:
                    bool isEditSub = 0;
                    for(int i = 0; i < list[editIndex].subjects.size(); i++){
                        cout << i+1 << "-" << list[editIndex].subjects[i] << " " << list[editIndex].scores[i] << "\n";
                    }
                    cout << "Enter the subject you want to edit : ";
                    cin >> editSub;
                    for(int i = 0; i < list[editIndex].subjects.size(); i++){
                        if(editSub == list[editIndex].subjects[i] && isEditSub == 0){
                            cout << "Enter your student new subject and new score : ";
                            cin >> newSub >> newScore;
                            list[editIndex].subjects[i] = newSub;
                            list[editIndex].scores[i] = newScore;
                            isEditSub = 1;
                        }
                    }
                    if(isEditSub == 0){
                        cout << "Please enter a valid subject\n";
                        goto missEditSub;
                    }
                }
                else{
                    cout << "Please enter a valid part\n";
                    goto missEditTask;
                }
            }
        }break;
        case 4:{
            if(haveStudent == 0){
                cout << "You don`t have a student yet\n";
                continue;
            }
            missIdDelete:
            int tempIdDelete;
            cout << "Enter id of student you want to delete his/her info\n";
            cin >> tempIdDelete;
            int deleteIndex = -1;
            for(int i = 0; i < listSize; i++){
                if(list[i].id == tempIdDelete)
                    deleteIndex = i;
            }
            if (deleteIndex == -1){
                cout << "There is no student with this id, Try again!\n";
                goto missIdDelete;
            }
            else{
                string DeleteTask;
                missDeleteTask:
                cout << "Which one do you wnat to delete (\'student\' , \'subject\'): ";
                cin >> DeleteTask;
                if(DeleteTask == "student"){
                    cout << "Student " << tempIdDelete << " has been deleted\n";
                    list[deleteIndex].id = -1;
                }
                else if(DeleteTask == "subject"){
                    string deleteSub;
                    missDeleteSub:
                    for(int i = 0; i < list[deleteIndex].subjects.size(); i++){
                        cout << i+1 << "-" << list[deleteIndex].subjects[i] << " " << list[deleteIndex].scores[i] << "\n";
                    }
                    cout << "Enter the subject you want to delete : ";
                    cin >> deleteSub;
                    bool isDeleteSub;
                    for(int i = 0; i < list[deleteIndex].subjects.size(); i++){
                        if(deleteSub == list[deleteIndex].subjects[i]){
                            list[deleteIndex].subjects.erase(list[deleteIndex].subjects.begin() + i);
                            list[deleteIndex].scores.erase(list[deleteIndex].scores.begin() + i);
                            isDeleteSub = true;
                            cout << "Subject " << deleteSub << " has been deleted\n";
                        }
                    }
                    if(isDeleteSub == false){
                        cout << "Please enter a valid subject\n";
                        goto missDeleteSub;
                    }
                }
                else{
                    cout << "Please enter a valid option\n";
                    goto missDeleteTask;
                }
            }
        }break;
        // case 5:{
        // }break;
        // case 6:{
        // }break;
        // case 7:{
        // }break;
        }
    } while (task <= 7);
    return 0;
}
