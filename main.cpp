#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
struct student
{
    int id = -1;
    string firstName;
    string lastName;
    string major;
    vector<string> subjects;
    vector<float> units;
    vector<float> scores;
    float avgScore = 0;
    float unitSum = 0;
};
void sortList(student a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            student b;
            if (a[j].avgScore >= a[i].avgScore)
            {
                b = a[j];
                a[j] = a[i];
                a[i] = b;
            }
        }
    }
}
int main()
{
    int listSize = 0;
unvalidSize:
    cout << "Enter the number of student you have : ";
    cin >> listSize;
    if (listSize < 1)
    {
        cout << "Please enter a number greater than 0\n";
        goto unvalidSize;
    }
    student list[listSize];
    vector<string> majorList;
    int task;
    bool haveStudent = 0;
    do
    {
        cout << "1-Add students\n2-Add Info about student\n3-Edit a student Info\n4-Delete a student info\n5-Show students list\n6-Show academic record\n7-exit\nChoose your option : ";
        cin >> task;
        switch (task)
        {
        case 1:
        {
            if (haveStudent == 0)
            {
                for (int i = 0; i < listSize; i++)
                {
                    cout << "Enter student full name : \n";
                    cin >> list[i].firstName >> list[i].lastName;
                notUniqeId:
                    cout << "Enter student id : \n";
                    int tempId;
                    cin >> tempId;
                    if (tempId > 0)
                    {
                        for (int j = 0; j <= i; j++)
                        {
                            if (list[j].id == tempId)
                            {
                                cout << "This Id has been used before, Please enter a different id\n";
                                goto notUniqeId;
                            }
                        }
                        list[i].id = tempId;
                    }
                    else
                    {
                        cout << "This is a invalid Id, Try again";
                        goto notUniqeId;
                    }
                    cout << "Enter student major : \n";
                    cin >> list[i].major;
                }
                haveStudent = 1;
            }
            else
            {
                cout << "You have already entered all students\n";
            }
        }
        break;
        case 2:
        {
            if (haveStudent == 0)
            {
                cout << "You don`t have a student yet\n";
                continue;
            }
        missIdAdd:
            for (int i = 0; i < listSize; i++)
                {
                    if (list[i].id != -1)
                    {
                        cout << i + 1 << "-" << list[i].firstName << " " << list[i].lastName << " -Id: " << list[i].id << " -Major: " << list[i].major << "\n";
                    }
                }
            int tempIdadd = -1;
            cout << "Enter id of student you want to add info about\n";
            cin >> tempIdadd;
            int addIndex = -1;
            for (int i = 0; i < listSize; i++)
            {
                if (list[i].id == tempIdadd)
                {
                    addIndex = i;
                }
            }
            if (addIndex == -1)
            {
                cout << "There is no student with this id, Try again!\n";
                goto missIdAdd;
            }
            else
            {
                float point, uni;
                string sub;
                do
                {
                    cout << "Enter your student subject : (Enter \'quit\' to return to menu)\n";
                    cin >> sub;
                    if (sub == "quit")
                    {
                        break;
                    }
                unvalidUnit:
                    cout << "Enter the subject`s unit : \n"; 
                    cin >> uni;
                    if (uni < 1)
                    {
                        cout << "This is a unvalid amount of unit, Try again\n";
                        goto unvalidUnit;
                    }
                unvalidPoint:
                    cout << "Enter the subject`s score : \n"; 
                    cin >> point;
                    if ((point < 0) || (point > 20))
                    {
                        cout << "Please enter a value between 0 and 20\n";
                        goto unvalidPoint;
                    }
                    list[addIndex].subjects.push_back(sub);
                    list[addIndex].units.push_back(uni);
                    list[addIndex].scores.push_back(point);
                    list[addIndex].avgScore += float(point * uni);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while (1);
                for (int i = 0; i < list[addIndex].units.size(); i++)
                {
                    list[addIndex].unitSum += list[addIndex].units[i];
                }
                list[addIndex].avgScore /= list[addIndex].unitSum;
            }
        }
        break;
        case 3:
        {
            if (haveStudent == 0)
            {
                cout << "You don`t have a student yet\n";
                continue;
            }
        missIdEdit:
            for (int i = 0; i < listSize; i++)
                {
                    if (list[i].id != -1)
                    {
                        cout << "\t" << list[i].firstName << " " << list[i].lastName << " -Id: " << list[i].id << " -Major: " << list[i].major << "\n";
                    }
                }
            int tempIdEdit;
            cout << "Enter id of student you want to edit his/her info\n";
            cin >> tempIdEdit;
            int editIndex = -1;
            for (int i = 0; i < listSize; i++)
            {
                if (list[i].id == tempIdEdit)
                    editIndex = i;
            }
            if (editIndex == -1)
            {
                cout << "There is no student with this id, Try again!\n";
                goto missIdEdit;
            }
            else
            {
                string editTask;
            missEditTask:
                cout << "Enter the part you wnat to edit (\'name\' , \'id\' , \'major\' , \'subject\'): ";
                cin >> editTask;
                if (editTask == "name")
                {
                    cout << "Enter student new full name: \n";
                    cin >> list[editIndex].firstName >> list[editIndex].lastName;
                }
                else if (editTask == "id")
                {
                notUniqeEditId:
                    cout << "Enter student new id : \n";
                    cin >> list[editIndex].id;
                    if (list[editIndex].id > 0)
                    {
                        for (int j = 0; j <= listSize; j++)
                        {
                            if (list[j].id == list[editIndex].id)
                            {
                                cout << "This Id has been used before, Please enter a different id\n";
                                goto notUniqeEditId;
                            }
                        }
                    }
                    else
                    {
                        cout << "This is a invalid Id, Try again";
                        goto notUniqeEditId;
                    }
                }
                else if (editTask == "major")
                {
                    bool uniqeMajor = true;
                    for (int i = 0; i < listSize; i++)
                    {
                        if (i == editIndex)
                        {
                            continue;
                        }
                        if (list[i].major == list[editIndex].major)
                        {
                            uniqeMajor = false;
                            break;
                        }
                    }
                    cout << "Enter student new major : \n";
                    cin >> list[editIndex].major;
                }
                else if (editTask == "subject")
                {
                    string editSub, newSub;
                    float newScore = 0;
                    int newUnit;
                missEditSub:
                    bool isEditSub = 0;
                    for (int i = 0; i < list[editIndex].subjects.size(); i++)
                    {
                        cout << i + 1 << "-" << list[editIndex].subjects[i] << " - unit : " << list[editIndex].units[i] << " - score : " << list[editIndex].scores[i] << "\n";
                    }
                    cout << "Enter the subject you want to edit : ";
                    cin >> editSub;
                    for (int i = 0; i < list[editIndex].subjects.size(); i++)
                    {
                        if (editSub == list[editIndex].subjects[i] && isEditSub == 0)
                        {
                            cout << "Enter your student new subject : ";
                            cin >> newSub;
                        unvalidEditUnit:
                            cout << "Enter the subject new unit : ";
                            cin >> newUnit;
                            if (newUnit < 1)
                            {
                                cout << "This is a unvalid amount of unit, Try again\n";
                                goto unvalidEditUnit;
                            }
                        unvalidEditPoint:
                            cout << "Enter the subject new score : ";
                            cin >> newScore;
                            if ((newScore < 0) || (newScore > 20))
                            {
                                cout << "Please enter a value between 0 and 20\n";
                                goto unvalidEditPoint;
                            }
                            list[editIndex].avgScore *= list[editIndex].unitSum;
                            list[editIndex].avgScore -= (list[editIndex].scores[i] * list[editIndex].units[i]);
                            list[editIndex].unitSum = list[editIndex].unitSum - list[editIndex].units[i] + newUnit;
                            list[editIndex].subjects[i] = newSub;
                            list[editIndex].units[i] = newUnit;
                            list[editIndex].scores[i] = newScore;
                            list[editIndex].avgScore += (list[editIndex].scores[i] * list[editIndex].units[i]);
                            list[editIndex].avgScore /= list[editIndex].unitSum;
                            isEditSub = 1;
                        }
                    }
                    if (isEditSub == 0)
                    {
                        cout << "Please enter a valid subject\n";
                        goto missEditSub;
                    }
                }
                else
                {
                    cout << "Please enter a valid part\n";
                    goto missEditTask;
                }
            }
        }
        break;
        case 4:
        {
            if (haveStudent == 0)
            {
                cout << "You don`t have a student yet\n";
                continue;
            }
        missIdDelete:
            for (int i = 0; i < listSize; i++)
                {
                    if (list[i].id != -1)
                    {
                        cout << "\t" << list[i].firstName << " " << list[i].lastName << " -Id: " << list[i].id << " -Major: " << list[i].major << "\n";
                    }
                }
            int tempIdDelete;
            cout << "Enter id of student you want to delete his/her info\n";
            cin >> tempIdDelete;
            int deleteIndex = -1;
            for (int i = 0; i < listSize; i++)
            {
                if (list[i].id == tempIdDelete)
                    deleteIndex = i;
            }
            if (deleteIndex == -1)
            {
                cout << "There is no student with this id, Try again!\n";
                goto missIdDelete;
            }
            else
            {
                string DeleteTask;
            missDeleteTask:
                cout << "Which one do you wnat to delete (\'student\' , \'subject\'): ";
                cin >> DeleteTask;
                if (DeleteTask == "student")
                {
                    cout << "Student " << list[deleteIndex].firstName << " " << list[deleteIndex].lastName << " has been deleted\n";
                    list[deleteIndex].id = -1;
                }
                else if (DeleteTask == "subject")
                {
                    string deleteSub;
                missDeleteSub:
                    for (int i = 0; i < list[deleteIndex].subjects.size(); i++)
                    {
                        cout << i + 1 << "-" << list[deleteIndex].subjects[i] << " - unit : " << list[deleteIndex].units[i] << " - score : " << list[deleteIndex].scores[i] << "\n";
                    }
                    cout << "Enter the subject you want to delete : ";
                    cin >> deleteSub;
                    bool isDeleteSub;
                    for (int i = 0; i < list[deleteIndex].subjects.size(); i++)
                    {
                        if (deleteSub == list[deleteIndex].subjects[i])
                        {
                            list[deleteIndex].avgScore *= list[deleteIndex].unitSum;
                            list[deleteIndex].avgScore -= (list[deleteIndex].scores[i] * list[deleteIndex].units[i]);
                            list[deleteIndex].subjects.erase(list[deleteIndex].subjects.begin() + i);
                            list[deleteIndex].scores.erase(list[deleteIndex].scores.begin() + i);
                            list[deleteIndex].unitSum -= list[deleteIndex].units[i];
                            list[deleteIndex].avgScore /= list[deleteIndex].unitSum;
                            isDeleteSub = true;
                            cout << "Subject " << deleteSub << " has been deleted\n";
                        }
                    }
                    if (isDeleteSub == false)
                    {
                        cout << "Please enter a valid subject\n";
                        goto missDeleteSub;
                    }
                }
                else
                {
                    cout << "Please enter a valid option\n";
                    goto missDeleteTask;
                }
            }
        }
        break;
        case 5:
        {
        missShowList:
            string showList;
            majorList.clear();
            bool isMajor = false;
            for(int i = 0; i < listSize; i++){
                if(list[i].id == -1){
                    continue;
                }
                for (int j = 0; j < majorList.size(); j++)
                    {
                        if (list[i].major == majorList[j])
                            isMajor = true;
                    }
                    if (!isMajor)
                    {
                        majorList.push_back(list[i].major);
                    }
            }
            sortList(list, listSize);
            cout << "1-All students\n";
            for (int i = 0; i < majorList.size(); i++)
            {
                cout << i + 2 << "-" << majorList[i] << "\n";
            }
            cout << "Enter the major you wnat to see its student or enter all : ";
            cin >> showList;
            if (showList == "all")
            {
                for (int i = 0; i < listSize; i++)
                {
                    if (list[i].id != -1)
                    {
                        cout << "\t" << list[i].firstName << " " << list[i].lastName << " -Id: " << list[i].id << " -Major: " << list[i].major << " -Average score: " << list[i].avgScore << "\n";
                    }
                }
            }
            else
            {
                bool epmtyList = true;
                for (int i = 0; i < listSize; i++)
                {
                    if (list[i].major == showList && list[i].id != -1)
                    {
                        epmtyList = false;
                        cout << "\t" << list[i].firstName << " " << list[i].lastName << " -Id: " << list[i].id << " -Major: " << list[i].major << " -Average score: " << list[i].avgScore << "\n";
                    }
                }
                if (epmtyList == true)
                {
                    cout << "There is no student in this major\n";
                    goto missShowList;
                }
            }
        }
        break;

        case 6:
        {
        missRecordId:
            for (int i = 0; i < listSize; i++)
            {
                cout << i + 1 << "-" << list[i].firstName << " " << list[i].lastName << " -Id:" << list[i].id << "\n";
            }
            cout << "Enter the Id of studnet you want their academic record :";
            int recordId;
            cin >> recordId;
            bool isRecord = 0;
            for (int i = 0; i < listSize; i++)
            {
                if (list[i].id == recordId)
                {
                    cout << "Name : " << list[i].firstName << " " << list[i].lastName << "\tId : " << list[i].id << "\n";
                    cout << "Major : " << list[i].major << "\n";
                    cout << "Subjects :\n";
                    for (int j = 0; j < list[i].subjects.size(); j++)
                    {
                        cout << j + 1 << "-" << list[i].subjects[j] << "\tUnit : " << list[i].units[j] << "\tScore : " << list[i].scores[j] << "\n";
                    }
                    cout << "Sum of all units : " << list[i].unitSum << "\tAvg score : " << list[i].avgScore << "\n";
                    isRecord = 1;
                    break;
                }
            }
            if (isRecord == 0)
            {
                cout << "Please enter a valid id\n";
                goto missRecordId;
            }
        }
        break;
        case 7:
        {
        missCloser:
            string closeCheck;
            cout << "Are you sure you want to close the program?(yes/no) : ";
            cin >> closeCheck;
            if (closeCheck == "yes")
            {
                cout << "Thank you for using our program!!";
                return 0;
            }
            else if (closeCheck == "no")
            {
                continue;
            }
            else
            {
                cout << "Please enter a valid answer\n";
                goto missCloser;
            }
        }
        break;
        default:
        {
            cout << "Please enter a valid option\n";
        }
        break;
        }
    } while (true);
    return 0;
}