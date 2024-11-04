#include <iostream> // For user input and output
#include <cmath> // For pow and sqrt functions

int main () {

    float num1, num2; // Declare two float variables to store user inputs for numbers.
    char op;          // Declare a char variable to store the operator.

    //Prompt the user for the first number and read it.
    std::cout << "Enter a Number: " << std::endl;
    std::cin >> num1;

    //Prompt the user for the operator and read it.
    std::cout << "Enter an Operator: " << std::endl;
    std::cin >> op;

    // If the operator is not 'r' (for square root), ask for a second number.
    if (op != 'r') {
        std::cout << "Enter a Number: " << std::endl;
        std::cin >> num2;
    }

    // Use a switch statement to perform the operation based on the operator input.
    switch(op) {
        case '+': // If the operator is '+', add num1 and num2.
            std::cout << num1 + num2 << std::endl;
            break;
        case '-': // If the operator is '-', subtract num2 from num1.
            std::cout << num1 - num2 << std::endl;
            break;
        case '*': // If the operator is '*', multiply num1 and num2.
            std::cout << num1 * num2 << std::endl;
            break;
        case '/': // If the operator is '/', divide num1 by num2.
            if (num1 != 0) { // Check if num2 is not zero to avoid division by zero error.
                std::cout << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by Zero" << std::endl;
            }
            break;
        case '^': // If the operator is '^', raise num1 to the power of num2.
            std::cout << pow(num1, num2) << std::endl; // pow function is used for exponentiation.
            break;
        case 'r': // If the operator is 'r', calculator the square root of num1
            if (num1 >= 0) { // Check if num1 is non-negative to avoid complex results.
                std::cout << sqrt(num1) << std::endl; // sqrt function is used for square root.
            } else {
                std::cout << "Error: Square Root of Negative Number" << std::endl;
            }
            break;
        default: // If the operator doesn't match any case, show an error message.
            std::cout << "Error: Ivalid Operator" << std::endl;
            break;
    }

    return 0; // End of program

}
