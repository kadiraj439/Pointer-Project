#include <iostream>
#include <string>
#include "Task.h"
using namespace std;

void listTasks(Task* tasks, int size) {
    cout << "\n--- Task List ---\n";
    if (size == 0) {
        cout << "(no tasks)\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "ID " << tasks[i].getId() << ": " << tasks[i].getDescription()
             << " | completed=" << (tasks[i].isCompleted() ? "true" : "false") << "\n";
    }
}

void addTask(Task* tasks, int& size, int capacity, const std::string& desc) {
    if (size >= capacity) {
        cout << "Task list is full (capacity " << capacity << ").\n";
        cout << "Side note: I didn't implement resize here, so I just block adding.\n";
        return;
    }

    int newId = (size == 0) ? 1 : (tasks[size - 1].getId() + 1);
    tasks[size] = Task(newId, desc);
    size++;
}

void removeTask(Task* tasks, int& size, int id) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (tasks[i].getId() == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No task found with ID " << id << ".\n";
        return;
    }

    // shift left to overwrite the removed task
    for (int i = index; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    size--;
}

int main() {
    cout << "Part B: Raw pointers to HEAP memory (new/delete)\n";

    int capacity = 5;
    int size = 0;

    // side note: I first did delete tasks; which is wrong for arrays.
    Task* tasks = new Task[capacity];

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
            cin.ignore(); // consume leftover newline
            string desc;
            cout << "Enter description: ";
            getline(cin, desc);
            addTask(tasks, size, capacity, desc);

        } else if (choice == 2) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            removeTask(tasks, size, id);

        } else if (choice == 3) {
            listTasks(tasks, size);

        } else if (choice == 4) {
            int id;
            cout << "Enter ID to mark completed: ";
            cin >> id;

            bool found = false;

            // pointer arithmetic demo
            for (int i = 0; i < size; i++) {
                Task* ptr = tasks + i; // pointer indexing style
                if (ptr->getId() == id) {
                    ptr->markCompleted();
                    found = true;
                    break;
                }
            }

            if (!found) cout << "No task found with that ID.\n";

        } else if (choice == 5) {
            running = false;

        } else {
            cout << "Invalid choice.\n";
        }
    }

    // Correct deallocation for array
    delete[] tasks;

    cout << "Exited. Memory cleaned up.\n";
    return 0;
}
