// ============================================================
//  EXPENSE TRACKER
//  A console-based Data Structures project in C++
//  Concepts used: Structures, Arrays, Linear Search,
//                 Bubble Sort, Functions, Loops, Conditionals
// ============================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_EXPENSES = 100;   // maximum number of records the array can hold

// ---------- Structure to hold one expense record ----------
struct Expense {
    int id;
    string category;
    string date;
    double amount;
};

Expense expenses[MAX_EXPENSES];   // array of structures (our "database")
int count = 0;                    // number of expenses currently stored

// ---------- Function Prototypes ----------
void addExpense();
void viewExpenses();
double calculateTotal();
void searchByCategory();
void sortByAmount();
void deleteExpense();
void showMenu();

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: cout << "\nTotal Expense: Rs. " << calculateTotal() << "\n"; break;
            case 4: searchByCategory(); break;
            case 5: sortByAmount(); break;
            case 6: deleteExpense(); break;
            case 7: cout << "\nExiting... Thank you!\n"; break;
            default: cout << "\nInvalid choice, try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// ---------- Display Menu ----------
void showMenu() {
    cout << "\n===== EXPENSE TRACKER =====\n";
    cout << "1. Add Expense\n";
    cout << "2. View All Expenses\n";
    cout << "3. Calculate Total Expense\n";
    cout << "4. Search Expense by Category\n";
    cout << "5. Sort Expenses by Amount\n";
    cout << "6. Delete an Expense\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// ---------- Add a new expense (Array Insertion) ----------
void addExpense() {
    if (count >= MAX_EXPENSES) {
        cout << "\nExpense list is full!\n";
        return;
    }

    Expense e;
    e.id = count + 1;
    cout << "\nEnter category (e.g. Food, Travel, Books): ";
    cin >> e.category;
    cout << "Enter date (DD-MM-YYYY): ";
    cin >> e.date;
    cout << "Enter amount: ";
    cin >> e.amount;

    expenses[count] = e;   // insert at the next free index
    count++;

    cout << "Expense added successfully!\n";
}

// ---------- View all expenses (Array Traversal) ----------
void viewExpenses() {
    if (count == 0) {
        cout << "\nNo expenses recorded yet.\n";
        return;
    }

    cout << "\n---------------------------------------------------\n";
    cout << left << setw(5) << "ID" << setw(15) << "Category"
         << setw(15) << "Date" << setw(10) << "Amount" << "\n";
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < count; i++) {
        cout << left << setw(5) << expenses[i].id
             << setw(15) << expenses[i].category
             << setw(15) << expenses[i].date
             << setw(10) << expenses[i].amount << "\n";
    }
}

// ---------- Calculate total of all expenses ----------
double calculateTotal() {
    double total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// ---------- Linear Search by category ----------
void searchByCategory() {
    if (count == 0) {
        cout << "\nNo expenses to search.\n";
        return;
    }

    string target;
    cout << "\nEnter category to search: ";
    cin >> target;

    bool found = false;
    double subtotal = 0;

    cout << "\nMatching Expenses:\n";
    for (int i = 0; i < count; i++) {                 // linear search: check every element
        if (expenses[i].category == target) {
            cout << "ID: " << expenses[i].id
                 << " | Date: " << expenses[i].date
                 << " | Amount: " << expenses[i].amount << "\n";
            subtotal += expenses[i].amount;
            found = true;
        }
    }

    if (!found)
        cout << "No expenses found in category \"" << target << "\".\n";
    else
        cout << "Subtotal for \"" << target << "\": Rs. " << subtotal << "\n";
}

// ---------- Bubble Sort by amount (ascending) ----------
void sortByAmount() {
    if (count == 0) {
        cout << "\nNo expenses to sort.\n";
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (expenses[j].amount > expenses[j + 1].amount) {
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }

    cout << "\nExpenses sorted by amount (ascending):\n";
    viewExpenses();
}

// ---------- Delete an expense by ID (Array Deletion) ----------
void deleteExpense() {
    if (count == 0) {
        cout << "\nNo expenses to delete.\n";
        return;
    }

    int id;
    cout << "\nEnter ID of expense to delete: ";
    cin >> id;

    int pos = -1;
    for (int i = 0; i < count; i++) {          // linear search for the ID
        if (expenses[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Expense with ID " << id << " not found.\n";
        return;
    }

    for (int i = pos; i < count - 1; i++) {    // shift left to fill the gap
        expenses[i] = expenses[i + 1];
    }
    count--;

    cout << "Expense deleted successfully.\n";
}
