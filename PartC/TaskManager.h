#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <memory>
#include <string>
#include "Task.h"

class TaskManager {
private:
    std::unique_ptr<Task[]> tasks;
    int size;
    int capacity;
    int nextId;

    void resize(); // small helper (I added this so it feels more real)

public:
    TaskManager(int initialCapacity);

    void addTask(const std::string& desc);
    void removeTask(int id);
    void listTasks() const;
    void markCompleted(int id);
};

#endif
