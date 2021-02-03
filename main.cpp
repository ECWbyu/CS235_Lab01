#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv []) {
    /*
    int i;
    for (i = 0; i < argc; i++) {
    cout << "argv["<<i<<"] = "<<argv[i]<<endl;
    }
    */
    TodoList mylist;
    string firstarg = argv[1];
    if(firstarg.compare("add") == 0) {
        string dateToAdd = argv[2];
        string taskToAdd = argv[3];
        mylist.add(dateToAdd, taskToAdd);
    } else if (firstarg.compare("remove") == 0) {
        string taskToRemove = argv[2];
        mylist.remove(taskToRemove);
    } else if (firstarg.compare("printList") == 0) {
        mylist.printTodoList();
    } else if (firstarg.compare("printDay") == 0) {
        string dateToPrint = argv[2];
        mylist.printDaysTasks(dateToPrint);
    } else {
        cout << "Invalid arguments. Exiting" << endl;
    }

    return 0;
}