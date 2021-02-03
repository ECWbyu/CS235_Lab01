#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "TodoListInterface.h"

using namespace std;

class TodoList {
public:
    TodoList() {
        // cout << "Starting constructor." << endl;
        ifstream inFile ("TODOList.txt");
        string line;
        if (inFile.is_open()) {
            while (getline(inFile, line)) {
                tasksVector.push_back(line);
            }
            inFile.close();
        }
    }
    virtual ~TodoList() {
        // cout << "Starting destructor." << endl;
        ofstream outFile;
        outFile.open("TODOList.txt", ofstream::out | ofstream::trunc);
        int i;
        for (i = 0; i < tasksVector.size(); i++) {
            outFile << tasksVector.at(i) << endl;
        }
        outFile.close();
    }

    /*
    *   Adds an item to the todo list with the data specified by the string "_duedate" and the task specified by "_task"
    */
    virtual void add(string _duedate, string _task) {
        cout << "Adding a task." << endl;
        cout << "Date: " << _duedate << ", description: " << _task << endl;
        tasksVector.push_back(_duedate);
        tasksVector.push_back(_task);
        cout << "The task has been added." << endl;
    }

    /*
    *   Removes an item from the todo list with the specified task name
    *
    *   Returns 1 if it removes an item, 0 otherwise
    */
    virtual int remove(string _task) {
        cout << "Removing a task." << endl;
        cout << "Task to remove: " << _task << endl;
        // We start at i=1 and iterate two at a time, because the list alternates dates and tasks
        int i;
        for (i = 1; i < tasksVector.size(); i += 2) {
            if (tasksVector.at(i).compare(_task) == 0) {
                tasksVector.erase(tasksVector.begin() + i);
                tasksVector.erase(tasksVector.begin() + (i - 1));
                cout << "Successfully removed task." << endl;
                return 1;
            }
        }
        cout << "Task was not found in list." << endl;
        return 0;
    }

    /*
    *   Prints out the full todo list to the console
    */
    virtual void printTodoList() {
        cout << "** Printing the list **" << endl;
        int i;
        for (i = 0; i < tasksVector.size(); i++) {
            cout << tasksVector.at(i) << endl;
        }
        cout << "** End of list **" << endl;
    }
    
    /*
    *   Prints out all items of a todo list with a particular due date (specified by _duedate)
    */
    virtual void printDaysTasks(string _date) {
        cout << "** Printing tasks by date **" << endl;
        //We iterate two at a time because we only check the date.
        int i;
        for (i = 0; i < tasksVector.size(); i+=2) {
            if (tasksVector.at(i).compare(_date) == 0) {
                cout << tasksVector.at(i) << endl;
                cout << tasksVector.at(i + 1) << endl;
            }
        }
        cout << "** End of list **" << endl;
    }
private:
    vector<string> tasksVector;
};

#endif