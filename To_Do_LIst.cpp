#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(const string &desc) : description(desc), isCompleted(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string &description) {
        tasks.emplace_back(description);
        cout << "Task added successfully.\n";
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number.\n";
            return;
        }
        if (tasks[index - 1].isCompleted) {
            cout << "Task is already marked as completed.\n";
        } else {
            tasks[index - 1].isCompleted = true;
            cout << "Task marked as completed.\n";
        }
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in your to-do list.\n";
            return;
        }

        cout << "Your To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << (tasks[i].isCompleted ? " [Completed]" : " [Pending]") << "\n";
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add a task\n";
    cout << "2. Mark task as completed\n";
    cout << "3. View tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    TodoList todoList;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer

        if (choice == 1) {
            cout << "Enter the task description: ";
            string description;
            getline(cin, description);
            todoList.addTask(description);

        } else if (choice == 2) {
            cout << "Enter the task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;
            todoList.markTaskCompleted(taskNumber);

        } else if (choice == 3) {
            todoList.viewTasks();

        } else if (choice == 4) {
            cout << "Exiting the application. Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
