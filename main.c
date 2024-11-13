//Ashley Grafner
// Orginal Date: 9/17/2024, Updated: 11/4/2024
//Question 1

//Updated the A4 ex1 question to now have command line arguments

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
double calculator(char operation, double numbers[], int count);
unsigned long long factorial(int num);
double power(double base, int exponent);
double simple_interest(double principal, double rate, double time);
double area_of_rectangle(double length, double breadth);
double area_of_circle(double radius);
double area_of_triangle(double base, double height);

// Main method with command line args
int main(int argc, char *argv[]) {
    // Check
    if (argc < 2) {
        printf("Usage: <task> <parameters>...\n");
        printf("Tasks Options: calc, si, area\n");
        return 1; // Exit if not enough args
    }

    // Calculator
    if (strcmp(argv[1], "calc") == 0) {
        // Ensure there are enough arguments for the calculator task
        if (argc < 5) {
            printf("Usage: calc <operation> <num1> <num2> ...\n");
            return 1;
        }

        char operation = argv[2][0];  // Get the first character of the operation
        int count = argc - 3;          // Calculate how many numbers were provided
        double numbers[count];          // Array to hold the numbers

        // Parse numbers from command-line arguments and convert them to double
        for (int i = 0; i < count; i++) {
            numbers[i] = atof(argv[i + 3]); // Convert string to double
        }

        // Handle factorial separately since it takes only one argument
        if (operation == '!') {
            if (count != 1) { // Check if exactly one number is provided
                printf("Factorial requires exactly one number.\n");
                return 1;
            }
            int num = (int)numbers[0]; // Cast to int for factorial calculation
            printf("Factorial of %d is %llu\n", num, factorial(num));
        }
        // Handle power operation separately since it takes two arguments
        else if (operation == '^') {
            if (count != 2) { // Check if exactly two numbers are provided
                printf("Power requires exactly two numbers.\n");
                return 1;
            }
            printf("%.2lf ^ %.0lf = %.2lf\n", numbers[0], numbers[1], power(numbers[0], (int)numbers[1]));
        }
        // Handle multiplication
        else if (operation == 'm' || operation == '*') {
            printf("Result: %.2lf\n", calculator('*', numbers, count)); // Use '*' for multiplication
        } else {
            printf("Invalid operation.\n");
            return 0; // Exit if the operation is invalid
        }

    // Task 2: Simple Interest
    } else if (strcmp(argv[1], "si") == 0) {
        // Ensure the correct number of arguments for simple interest calculation
        if (argc != 5) {
            printf("Usage: si <principal> <rate> <time>\n");
            return 1;
        }

        // Parse the command-line arguments for principal, rate, and time
        double principal = atof(argv[2]);
        double rate = atof(argv[3]);
        double time = atof(argv[4]);

        // Calculate and print the simple interest
        printf("Simple Interest: %.2lf\n", simple_interest(principal, rate, time));

    // Task 3: Area calculations (Rectangle, Circle, Triangle)
    } else if (strcmp(argv[1], "area") == 0) {
        // Ensure there are enough arguments for area calculation
        if (argc < 3) {
            printf("Usage: area <shape> <parameters>...\n");
            printf("Shapes: rectangle, circle, triangle\n");
            return 1;
        }

        // Check for rectangle area calculation
        if (strcmp(argv[2], "rectangle") == 0) {
            if (argc != 5) {
                printf("Usage: area rectangle <length> <breadth>\n");
                return 1; // Exit if the number of arguments is incorrect
            }
            double length = atof(argv[3]);
            double breadth = atof(argv[4]);
            printf("Area of Rectangle: %.2lf\n", area_of_rectangle(length, breadth));

        // Check for circle area calculation
        } else if (strcmp(argv[2], "circle") == 0) {
            if (argc != 4) {
                printf("Usage: area circle <radius>\n");
                return 1; // Exit if the number of arguments is incorrect
            }
            double radius = atof(argv[3]);
            printf("Area of Circle: %.2lf\n", area_of_circle(radius));

        // Check for triangle area calculation
        } else if (strcmp(argv[2], "triangle") == 0) {
            if (argc != 5) {
                printf("Usage: area triangle <base> <height>\n");
                return 1; // Exit if the number of arguments is incorrect
            }
            double base = atof(argv[3]);
            double height = atof(argv[4]);
            printf("Area of Triangle: %.2lf\n", area_of_triangle(base, height));
        } else {
            printf("Unknown shape: %s\n", argv[2]); // Handle unknown shapes
        }

    } else {
        printf("Unknown task: %s\n", argv[1]); // Handle unknown tasks
    }

    return 0; // Successful execution
}

// Function Definitions

// Calculator function that performs the specified operation on an array of numbers
double calculator(char operation, double numbers[], int count) {
    double result = numbers[0]; // Initialize result with the first number

    switch (operation) {
        case '+': // Addition
            for (int i = 1; i < count; i++)
                result += numbers[i]; // Accumulate sum
            break;
        case '-': // Subtraction
            for (int i = 1; i < count; i++)
                result -= numbers[i]; // Subtract each number
            break;
        case '*': // Multiplication
            for (int i = 1; i < count; i++)
                result *= numbers[i]; // Multiply each number
            break;
        case '/': // Division
            for (int i = 1; i < count; i++) {
                if (numbers[i] != 0) { // Check for division by zero
                    result /= numbers[i]; // Divide by each number
                } else {
                    printf("Error: Division by zero.\n");
                    return 0; // Exit on division by zero
                }
            }
            break;
        default: // Invalid operation
            printf("Invalid operation.\n");
            return 0; // Exit on invalid operation
    }

    return result; // Return the result of the operation
}

// Function to calculate the factorial of a number
unsigned long long factorial(int num) {
    unsigned long long result = 1; // Initialize result
    for (int i = 1; i <= num; i++) // Calculate factorial
        result *= i;
    return result; // Return the factorial result
}

// Function to calculate the power of a base raised to an exponent
double power(double base, int exponent) {
    return pow(base, exponent); // Use the pow function from math.h
}

// Function to calculate simple interest
double simple_interest(double principal, double rate, double time) {
    return (principal * rate * time) / 100; // Return simple interest calculation
}

// Function to calculate the area of a rectangle
double area_of_rectangle(double length, double breadth) {
    return length * breadth; // Return area calculation
}

// Function to calculate the area of a circle
double area_of_circle(double radius) {
    return M_PI * radius * radius; // Return area calculation
}

// Function to calculate the area of a triangle
double area_of_triangle(double base, double height) {
    return 0.5 * base * height; // Return area calculation
}