#include "figures.h"

using namespace std;

bool Circle::operator<(const IPhysObject &ob) const {
    const auto *other = dynamic_cast<const Circle *>(&ob);
    return mass_of_object < other->mass_of_object;
}

double Circle::square() {
    return 3.14 * radius * radius;
}

double Circle::perimeter() {
    return 2 * 3.14 * radius;
}

double Circle::mass() {
    return mass_of_object;
}

Vector2D Circle::position() {
    return pos;
}

bool Circle::operator==(const IPhysObject &ob) const {
    const auto *other = dynamic_cast<const Circle *>(&ob);
    return mass_of_object == other->mass_of_object;
}

void Circle::draw() {
    cout << "Radius: " << radius << endl;
    cout << "The mass of object base: "  << mass_of_object << endl;
    cout << "The position: ("  << pos.x << ";"<<pos.y << ")" << endl;
}

void Circle::initFromDialog() {
    cout << "Enter the radius:";
    cin >> radius;
    cout << "Enter the mass:";
    cin >> mass_of_object;
    cout << "Enter the position:";
    cin >> pos.x >> pos.y;
}

const char *Circle::classname() {
    return "Circle";
}

unsigned int Circle::size() {
    return sizeof(*this);
}

Circle::Circle(double r, double m, double px, double py) {
    radius = r;
    mass_of_object = m;
    pos = {px, py};
}
Circle::Circle() {
    radius = 0;
    mass_of_object = 0;
    pos = {0, 0};
}


Trapezoid::Trapezoid(double a, double b, double h, double px, double py, double m) {
    lower_base = a;
    upper_base = b;
    height = h;
    mass_of_object = m;
    pos = {px, py};
}

Trapezoid::Trapezoid() {
    lower_base = 0;
    upper_base = 0;
    height = 0;
    mass_of_object = 0;
    pos = {0,0};
}

double Trapezoid::square() {
    return 0.5 * (lower_base + upper_base)*height;
}

double Trapezoid::perimeter() {
    return height/(height/((lower_base - upper_base)/2))*2 + lower_base + upper_base;
}

double Trapezoid::mass() {
    return mass_of_object;
}

Vector2D Trapezoid::position() {
    return pos;
}

bool Trapezoid::operator==(const IPhysObject &ob) const {
    const auto *other = dynamic_cast<const Trapezoid *>(&ob);
    return mass_of_object == other->mass_of_object;
}

bool Trapezoid::operator<(const IPhysObject &ob) const {
    const auto *other = dynamic_cast<const Trapezoid *>(&ob);
    return mass_of_object < other->mass_of_object;
}

void Trapezoid::draw() {
    cout << "The lower base: "  << lower_base << endl;
    cout << "The upper base: "  << upper_base << endl;
    cout << "The height base: "  << height << endl;
    cout << "The mass of object base: "  << mass_of_object << endl;
    cout << "The position: ("  << pos.x << ";"<<pos.y << ")" << endl;
}

void Trapezoid::initFromDialog() {
    cout << "Enter the lower base:";
    cin >> lower_base;
    cout << "Enter the upper base:";
    cin >> upper_base;
    cout << "Enter the height:";
    cin >> height;
    cout << "Enter the mass:";
    cin >> mass_of_object;
    cout << "Enter the position:";
    cin >> pos.x >> pos.y;
}

const char *Trapezoid::classname() {
    return "Trapezoid";
}

unsigned int Trapezoid::size() {
    return sizeof(*this);
}
