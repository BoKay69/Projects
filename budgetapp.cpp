#include <iostream>
#include <fstream>

class BudgetApp {
private:
    double income;
    double expenses[10]; // Assuming a maximum of 10 expenses for simplicity
    int numExpenses;

public:
    BudgetApp() : income(0.0), numExpenses(0) {}

    double getIncome() const {
        return income;
    }

    void setIncome(double amount) {
        income = amount;
    }

    void addExpense(double amount) {
        if (numExpenses < 10) {
            expenses[numExpenses++] = amount;
        } else {
            std::cout << "Maximum number of expenses reached." << std::endl;
        }
    }

    void displaySummary() const {
        double totalExpenses = 0.0;
        for (int i = 0; i < numExpenses; ++i) {
            totalExpenses += expenses[i];
        }

        std::cout << "Income: $" << income << std::endl;
        std::cout << "Total Expenses: $" << totalExpenses << std::endl;
        std::cout << "Remaining Budget: $" << income - totalExpenses << std::endl;
    }

    void saveToDisk(const std::string& filename) const {
        std::ofstream file(filename);

        if (file.is_open()) {
            file << income << std::endl;
            file << numExpenses << std::endl;

            for (int i = 0; i < numExpenses; ++i) {
                file << expenses[i] << std::endl;
            }

            file.close();
            std::cout << "Data saved to " << filename << std::endl;
        } else {
            std::cout << "Unable to open file for writing." << std::endl;
        }
    }

    void loadFromDisk(const std::string& filename) {
        std::ifstream file(filename);

        if (file.is_open()) {
            file >> income;
            file >> numExpenses;

            if (numExpenses > 10) {
                std::cout << "Error: Number of expenses in file exceeds maximum allowed." << std::endl;
                numExpenses = 10; // Limit to maximum allowed
            }

            for (int i = 0; i < numExpenses; ++i) {
                file >> expenses[i];
            }

            file.close();
            std::cout << "Data loaded from " << filename << std::endl;
        } else {
            std::cout << "Unable to open file for reading." << std::endl;
        }
    }
};

int main() {
    BudgetApp budget;

    char choice;
    do {
        std::cout << "1. Set Income\n";
        std::cout << "2. Add Expense\n";
        std::cout << "3. Display Summary\n";
        std::cout << "4. Save to Disk\n";
        std::cout << "5. Load from Disk\n";
        std::cout << "6. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                double income;
                std::cout << "Enter income: $";
                std::cin >> income;
                budget.setIncome(income);
                break;
            }

            case '2': {
                double expense;
                std::cout << "Enter expense: $";
                std::cin >> expense;
                budget.addExpense(expense);
                break;
            }

            case '3':
                budget.displaySummary();
                break;

            case '4': {
                std::string saveFileName;
                std::cout << "Enter filename to save: ";
                std::cin >> saveFileName;
                budget.saveToDisk(saveFileName);
                break;
            }

            case '5': {
                std::string loadFileName;
                std::cout << "Enter filename to load: ";
                std::cin >> loadFileName;
                budget.loadFromDisk(loadFileName);
                break;
            }

            case '6':
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '6');

    return 0;
}
