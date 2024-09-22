#include <iostream>
#include <cmath>


struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
};


double calculateCircleLength(double radius) {
    return 2 * 3.14159 * radius; // не смогла импортировать точное число пи
}

double calculateCircleArea(double radius) {
    return 3.14159 * radius * radius;
}

bool circlesСrossing(Circle c1, Circle c2) {
    double distance = sqrt(pow(c2.center.x - c1.center.x, 2) + pow(c2.center.y - c1.center.y, 2));
    return (abs(c1.radius - c2.radius) < distance) && (c1.radius + c2.radius > distance);
}

int main() {
    setlocale(LC_ALL, "Russian");

    double r1, x1, y1;
    std::cout << "Введите радиус и координаты (x, y) центра  1 окружности" << std::endl;
    std::cin >> r1 >> x1 >> y1;

    double r2, x2, y2;
    std::cout << "Введите радиус и координаты (x, y) центра 2 окружности" << std::endl;
    std::cin >> r2 >> x2 >> y2;

    Circle circle1 = { {x1, y1}, r1 };
    Circle circle2 = { {x2, y2}, r2 };

    double length1 = calculateCircleLength(circle1.radius);
    double area1 = calculateCircleArea(circle1.radius);
    double length2 = calculateCircleLength(circle2.radius);
    double area2 = calculateCircleArea(circle2.radius);

    bool intersect = circlesСrossing(circle1, circle2);


    std::cout << "Длина 1 окружности (2πR):" << length1 << "\nПлощадь 1 окружности: " << area1 << std::endl;
    std::cout << "Длина 2 окружности (2πR):" << length2 << "\nПлощадь 2 окружности: " << area2 << std::endl;
    if (intersect) {
        std::cout << "Да, окружности пересекаются" << std::endl;
    }
    else {
        std::cout << "Нет, окружности не пересекаются" << std::endl;
    }

    return 0;
}