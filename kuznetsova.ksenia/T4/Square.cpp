#include "Square.h"
#include <stdexcept>
#include <string>

Square::Square(const Point& bottomLeft, double sideLength)
: bottomLeft_(bottomLeft), side_(sideLength) {

if (sideLength <= 0) {
throw std::invalid_argument("Ошибка: Длина стороны квадрата должна быть положительной.");
}
}

double Square::getArea() const {
return side_ * side_;
}

Point Square::getCenter() const {
return Point(bottomLeft_.x + side_ / 2.0,
bottomLeft_.y + side_ / 2.0);
}

void Square::move(double dx, double dy) {
bottomLeft_.x += dx;
bottomLeft_.y += dy;
}

void Square::scale(double factor) {
if (factor <= 0) {
throw std::invalid_argument("Ошибка: Коэффициент масштабирования должен быть положительным.");
}

Point center = getCenter();
side_ *= factor;
bottomLeft_.x = center.x - side_ / 2.0;
bottomLeft_.y = center.y - side_ / 2.0;
}

std::string Square::getName() const {
return "SQUARE";
}