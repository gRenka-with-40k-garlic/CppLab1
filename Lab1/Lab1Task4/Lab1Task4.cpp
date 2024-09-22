#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

struct Ellipse {
    Point center;
    double radius1;
    double radius2;
};

double calculateEllipseCircumference(Ellipse e) {
    return 3.14159 * (e.radius1 + e.radius2);  // снова не смогла импортировать пи 
}

double calculateEllipseArea(Ellipse e) {
    return 3.14159 * e.radius1 * e.radius2;
}

int main() {
    setlocale(LC_ALL, "rus");
    Ellipse ellipse1, ellipse2;

    std::cout << "Введите координаты (x,y) центра второго эллипса и его радиусы (r1,r2):\n";
    std::cin >> ellipse1.center.x >> ellipse1.center.y >> ellipse1.radius1 >> ellipse1.radius2;

    std::cout << "Введите координаты (x,y) центра второго эллипса и его радиусы (r1,r2):\n";
    std::cin >> ellipse2.center.x >> ellipse2.center.y >> ellipse2.radius1 >> ellipse2.radius2;

    double circumference1 = calculateEllipseCircumference(ellipse1);
    double area1 = calculateEllipseArea(ellipse1);

    double circumference2 = calculateEllipseCircumference(ellipse2);
    double area2 = calculateEllipseArea(ellipse2);

    if (area1 > area2) {
        std::cout << "Площадь первого эллипса больше.\n";
    }
    else if (area2 > area1) {
        std::cout << "Площадь второго эллипса больше.\n";
    }
    else {
        std::cout << "Площади элипсов равны.\n";
    }

    return 0;
}