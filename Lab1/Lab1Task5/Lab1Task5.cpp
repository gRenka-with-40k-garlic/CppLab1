#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;
};

int main() {
    setlocale(LC_ALL, "rus");

    int N;
    std::cout << "Введите количество точек: ";
    std::cin >> N;

    Point* points = new Point[N];

    for (int i = 0; i < N; i++) {
        std::cout << "Введите координату х для точки " << i + 1 << ": ";
        std::cin >> points[i].x;
        std::cout << "Введите координату у для точки " << i + 1 << ": ";
        std::cin >> points[i].y;
    }

    double maxDistance = 0;
    int maxIndex = 0;

    for (int i = 0; i < N; i++) {
        double distance = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
        if (distance > maxDistance) {
            maxDistance = distance;
            maxIndex = i;
        }
    }

    std::cout << "Наиболее удаленная точка от начала координат: (" << points[maxIndex].x << ", " << points[maxIndex].y << ")" << std::endl;

    return 0;
}