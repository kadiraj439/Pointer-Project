# Self-Reflection (Pointers Project)

## 1) Differences between pointer types


### Memory pointer stack (Part A)
In Part A, I created `Task t1` and `Task t2` on the stack using pointers like `Task* p1 = &t1`.
At the end of `main()`, the pointer will automatically clean up the standard variable that it points to.
I shouldn't have used `new` or `delete` in this case because the stack objects are not mine to manually release.

### Heap memory pointer (Part B)
In Part B, I used `new Task[capacity]` to allocate an array on the heap.
This memory is not cleaned up automatically, so I had to use `delete[] tasks;` at the end.
If I don't use `delete[]`, it leaks memory. Furthermore, I learned the hard way that using `delete tasks;` is wrong for arrays.
### Part C: Smart pointer (unique_ptr)
The array memory in Part C is owned by `std::unique_ptr`.
The unique_ptr automatically releases the memory when the `TaskManager` object leaves scope.

It's safer and more difficult to make a mistake because I don't call `delete` at all.

## 2) Where and why delete was applied
Because I used `new` in Part B, I only used delete there.
I specifically used `delete[] tasks;` since the array was allocated using `new[]`.

## 3) Ownership in each design Part A: The pointer does not give me ownership of the memory. Stack variables are self-contained.
Part B: Since I created the heap memory using `new[]`, I am the owner of it and must release it using `delete[]`.
Part C: The memory is owned by the `unique_ptr`, which releases it automatically when it leaves its scope.

## 4) The safest approach and why
Because it keeps you from forgetting to remove memory, `unique_ptr` is the safest method.
Additionally, it clarifies ownership: the memory is only owned by one entity at a time.
It is simpler to abuse raw pointers, particularly when dealing with arrays and manual cleanup.


