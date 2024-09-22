#include <iostream>
#include <cmath>
#include <limits>

struct Point {
    int x;
    int y;
};

double distanceToOrigin(Point p) {
    return sqrt(p.x * p.x + p.y * p.y); //sqrt - возвращает квадратный корень числа
}

double distanceBetweenPoints(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //pow - возводит число в заданную степень
}

int main() {
    setlocale(LC_ALL, "Russian");

    Point A, B;

    std::cout << "Введите координаты точки А (x y): ";
    while (!(std::cin >> A.x >> A.y)) {
        std::cout << "Ошибка. Введите целые числа для координат точки А (x y): ";
        std::cin.clear();                                                   //clear - используется для очистки состояния ошибки входного потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore - константа стандартной библиотеки, используется для очистки буфера ввода
        //numeric_limits -  шаблонный класс, предоставляет информацию о числовых типах данных
        //max - максимальное значение типа streamsize
        //streamsize - тип данных, используемый для представления размеров потоков
    }

    std::cout << "Введите координаты точки B (x y): ";
    while (!(std::cin >> B.x >> B.y)) {
        std::cout << "Ошибка. Введите целые числа для координат точки B (x y): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    double distanceA = distanceToOrigin(A);
    double distanceB = distanceToOrigin(B);

    if (distanceA > distanceB) {
        std::cout << "Точка А самая удаленная от начала координатной оси. \n"
            "Расстояние OA = (" << distanceA << ") \n"
            "Расстояние OB = (" << distanceB << ")" << std::endl;
    }
    else if (distanceB > distanceA) {
        std::cout << "Точка B самая удаленная от начала координатной оси. \n"
            "Расстояние OB = (" << distanceB << ") \n"
            "Расстояние OA = (" << distanceA << ")" << std::endl;
    }
    else {
        std::cout << "Обе точки одинаково удалены от начала координатной оси.\n"
            "Расстояние OB = (" << distanceB << ") \n"
            "Расстояние OA = (" << distanceA << ")" << std::endl;
    }

    std::cout << "Расстояние между точками A и B = " << distanceBetweenPoints(A, B) << std::endl;

    return 0;
}