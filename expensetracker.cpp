#include <iostream>
#include <fstream>
#include <iomanip>

class ExpenseTracker {
public:
    void addExpense(double amount, const std::string& category, const std::string& description) {
        std::ofstream outFile("expenses.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << std::fixed << std::setprecision(2);
            outFile << amount << "," << category << "," << description << std::endl;
            std::cout << "Expense added successfully.\n";
            outFile.close();
        } else {
            std::cerr << "Unable to open expenses file.\n";
        }
    }

    void viewExpenses() {
        std::ifstream inFile("expenses.txt");
        if (inFile.is_open()) {
            double amount;
            std::string category, description;
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Amount\tCategory\tDescription\n";
            while (inFile >> amount >> std::ws && std::getline(inFile, category, ',') && std::getline(inFile, description)) {
                std::cout << amount << "\t" << category << "\t\t" << description << "\n";
            }
            inFile.close();
        } else {
            std::cerr << "Unable to open expenses file.\n";
        }
    }
};

int main() {
    ExpenseTracker expenseTracker;

    int choice;
    double amount;
    std::string category, description;

    do {
        std::cout << "\nExpense Tracker Menu:\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View Expenses\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount: ";
                std::cin >> amount;
                std::cout << "Enter category: ";
                std::cin.ignore();
                std::getline(std::cin, category);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                expenseTracker.addExpense(amount, category, description);
                break;

            case 2:
                expenseTracker.viewExpenses();
                break;

            case 3:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

