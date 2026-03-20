#include "Ring.h"
#include <cmath>
#include <stdexcept>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ring::Ring(const Point& center, double outRad, double inRad)
: center_(center), outR_(outRad), inR_(inRad) {

if (outR_ <= 0 || inR_ <= 0) {
throw std::invalid_argument("Ошибка: Радиусы кольца должны быть положительными.");
}

if (outR_ <= inR_) {
throw std::invalid_argument("Ошибка: Внешний радиус должен быть больше внутреннего.");
}
}

double Ring::getArea() const {
return M_PI * (outR_ * outR_ - inR_ * inR_);
}

Point Ring::getCenter() const {
return center_;
}

void Ring::move(double dx, double dy) {
center_.x += dx;
center_.y += dy;
}

void Ring::scale(double factor) {
if (factor <= 0) {
throw std::invalid_argument("Ошибка: Коэффициент масштабирования должен быть положительным.");
}

double newOutR = outR_ * factor;
double newInR = inR_ * factor;

if (newOutR <= newInR) {
throw std::invalid_argument("Ошибка: Масштабирование нарушает соотношение радиусов.");
}

outR_ = newOutR;
inR_ = newInR;
}

std::string Ring::getName() const {
return "RING";
}
