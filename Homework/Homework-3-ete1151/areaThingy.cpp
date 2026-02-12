#include <iostream>

// Constant expression
constexpr double pi {3.14159};

constexpr double areaSquare(double side) {
    return side * side;
}

constexpr double areaRectangle(double length, double width)
{
    return length * width;
}

constexpr double areaCircle(double radius)
{
    return pi * radius * radius;
}

constexpr double areaCylinder(double radius, double height)
{
    return 2 * pi * radius * height + 2 * pi * radius * radius;
}

int main()
{ 
    int choice {};

    std::cout << "1. Calculate the area of a square. \n";
    std::cout << "2. Calculate the area of a rectangle. \n";
    std::cout << "3. Calculate the area of a circle. \n";
    std::cout << "4. Calculate the area of a cylinder. \n";
    std::cout << "which one you wanna calculate my brotha ?: \n";
    std::cin >> choice;

    switch (choice)
    {
        case 1: {
            double side {};
            std::cout << "Enter the length of the side of the square: \n";
            std::cin >> side;
            std::cout << "The area of the square is: " << areaSquare(side) << "\n";
            break;
        }
        case 2: {
            double length {}, width {};
            std::cout << "Enter the length and width of the rectangle: \n";
            std::cin >> length >> width;
            std::cout << "The area of the rectangle is: " << areaRectangle(length, width) << "\n";
            break;
        }
        case 3: {
            double radius {};
            std::cout << "Enter the radius of the circle: \n";
            std::cin >> radius;
            std::cout << "The area of the circle is: " << areaCircle(radius) << "\n";
            break;
        }
        case 4: {
            double cylRadius {}, height {};
            std::cout << "Enter the radius and height of the cylinder: \n";
            std::cin >> cylRadius >> height;
            std::cout << "The area of the cylinder is: " << areaCylinder(cylRadius, height) << "\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please select a number between 1 and 4.\n";
    }
}