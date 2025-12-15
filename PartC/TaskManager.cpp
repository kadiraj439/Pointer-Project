#include "TaskManager.h"
#include <iostream>
using namespace std;

TaskManager::TaskManager(int initialCapacity)
    : size(0), capacity(initialCapacity), nextId(1) {
    // required by assignment
    tasks = std::make_unique<Task[]>(initialCapacity);
}

void TaskManager::resize() {
    // side note: I originally forgot to copy tasks over and everything "vanished"
    int newCapacity = capacity * 2;
    auto newTasks = std::make_unique<Task[]>(newCapacity);

    for (int i = 0; i < size; i++) {
        newTasks[i] = tasks[i];
    }

    tasks = std::move(newTasks);
    capacity = newCapacity;
}

void TaskManager::addTask(const std::string& desc) {
    if (size >= capacity) {
        resize();
    }

    tasks[size] = Task(nextId, desc);
    nextId++;
    size++;
}

void TaskManager::removeTask(int id) {
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

    for (int i = index; i < size - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    size--;
}

void TaskManager::listTasks() const {
    cout << "\n--- Task List (unique_ptr version) ---\n";
    if (size == 0) {
        cout << "(no tasks)\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "ID " << tasks[i].getId() << ": " << tasks[i].getDescription()
             << " | completed=" << (tasks[i].isCompleted() ? "true" : "false") << "\n";
    }
}

void TaskManager::markCompleted(int id) {
    for (int i = 0; i < size; i++) {
        if (tasks[i].getId() == id) {
            tasks[i].markCompleted();
            return;
        }
    }
    cout << "No task found with ID " << id << ".\n";
}
