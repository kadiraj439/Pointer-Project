#include <iostream>
#include "Task.h"
using namespace std;

void completeTask(Task* t) {
    // side note: I first wrote t.markCompleted(); and it didn't compile (forgot it's a pointer)
    if (t != nullptr) {
        t->markCompleted();
    }
}

int main() {
    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    Task* p1 = &t1;
    Task* p2 = &t2;

    cout << "Part A: Raw pointers to STACK objects\n\n";

    cout << "Before:\n";
    cout << "Task " << p1->getId() << ": " << p1->getDescription()
         << " | completed=" << (p1->isCompleted() ? "true" : "false") << "\n";
    cout << "Task " << p2->getId() << ": " << p2->getDescription()
         << " | completed=" << (p2->isCompleted() ? "true" : "false") << "\n";

    // dereference style demo (both work)
    completeTask(p1);
    (*p2).markCompleted(); // side note: I used this to prove deref works too

    cout << "\nAfter:\n";
    cout << "Task " << p1->getId() << ": " << p1->getDescription()
         << " | completed=" << (p1->isCompleted() ? "true" : "false") << "\n";
    cout << "Task " << p2->getId() << ": " << p2->getDescription()
         << " | completed=" << (p2->isCompleted() ? "true" : "false") << "\n";

    return 0;
}
