#include "trapezoid.h"
#include <algorithm>
#include <cmath>

Trapezoid::Trapezoid(const Point& bl, double bBase, double tBase, double h)
    : bottomLeft(bl), bottomBase(bBase), topBase(tBase), height(h) {}

double Trapezoid::getArea() const {
    return (bottomBase + topBase) / 2.0 * height;
}

Point Trapezoid::getCenter() const {
    double offset = (bottomBase - topBase) / 2.0;
    double cx = bottomLeft.x + bottomBase / 2.0 - offset / 2.0;
    double cy = bottomLeft.y + height / 2.0;
    return Point(cx, cy);
}

void Trapezoid::move(double dx, double dy) {
    bottomLeft.x += dx;
    bottomLeft.y += dy;
}

void Trapezoid::scale(double factor) {
    Point center = getCenter();
    double xBr = bottomLeft.x + bottomBase;
    double yBr = bottomLeft.y;
    double offset = (bottomBase - topBase) / 2.0;
    double xTl = bottomLeft.x + offset;
    double yTl = bottomLeft.y + height;
    double xTr = xTl + topBase;
    double yTr = yTl;
    bottomLeft.x = center.x + (bottomLeft.x - center.x) * factor;
    bottomLeft.y = center.y + (bottomLeft.y - center.y) * factor;
    xBr = center.x + (xBr - center.x) * factor;
    yBr = center.y + (yBr - center.y) * factor;
    xTl = center.x + (xTl - center.x) * factor;
    yTl = center.y + (yTl - center.y) * factor;
    xTr = center.x + (xTr - center.x) * factor;
    yTr = center.y + (yTr - center.y) * factor;
    bottomBase = std::abs(xBr - bottomLeft.x);
    topBase = std::abs(xTr - xTl);
    height = std::abs(yTl - bottomLeft.y);
}

std::string Trapezoid::getName() const {
    return "TRAPEZOID";
}
