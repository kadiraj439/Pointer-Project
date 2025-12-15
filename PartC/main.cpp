#include <iostream>
#include <string>
#include "TaskManager.h"
using namespace std;

int main() {
    cout << "Part C: Task Manager using std::unique_ptr\n";

    TaskManager tm(5);

    bool running = true;
    while (running) {
        cout << "\nMenu:\n";
        cout << "1) Add Task\n";
        cout << "2) Remove Task\n";
        cout << "3) List Tasks\n";
        cout << "4) Mark Completed\n";
        cout << "5) Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cin.ignore();
            string desc;
            cout << "Enter description: ";
            getline(cin, desc);
            tm.addTask(desc);

        } else if (choice == 2) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            tm.removeTask(id);

        } else if (choice == 3) {
            tm.listTasks();

        } else if (choice == 4) {
            int id;
            cout << "Enter ID to mark completed: ";
            cin >> id;
            tm.markCompleted(id);

        } else if (choice == 5) {
            running = false;

        } else {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Exited. (No manual delete needed in this version.)\n";
    return 0;
}
