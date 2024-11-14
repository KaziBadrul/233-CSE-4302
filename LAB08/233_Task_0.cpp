#include <iostream>
#include <math.h>
using namespace std;

class Shape
{
};

class TwoDimensionalShape : public Shape
{
protected:
    float area;
    float perimeter;

public:
    virtual void display()
    {
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
        cout << "------------------------------------" << endl;
    };

    virtual void whoAmI()
    {
        cout << "I am a two-dimensional shape" << endl;
    };
};

class ThreeDimensionalShape : public Shape
{
protected:
    float surArea;
    float volume;

public:
    virtual void whoAmI()
    {
        cout << "I am a three-dimensional shape" << endl;
    };

    virtual void display()
    {
        cout << "Surface Area: " << surArea << endl;
        cout << "Volume: " << volume << endl;
        cout << "------------------------------------" << endl;
    };
};

// My shapes
class Square : public TwoDimensionalShape
{
private:
    float side;

public:
    Square(float s) : side(s)
    {
        area = s * s;
        perimeter = s * 4;
    }

    void display()
    {
        cout << "Square: " << side << endl;
        TwoDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Square." << endl;
        TwoDimensionalShape::whoAmI();
    };
};

class Circle : public TwoDimensionalShape
{
private:
    float radius;

public:
    Circle(float r) : radius(r)
    {
        area = 3.14 * radius * radius;
        perimeter = 2 * 3.14 * radius;
    };
    void display()
    {
        cout << "Circle: " << radius << endl;
        TwoDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Circle." << endl;
        TwoDimensionalShape::whoAmI();
    };
};

class Triangle : public TwoDimensionalShape
{
private:
    float a;
    float b;
    float c;

public:
    Triangle(float a, float b, float c) : a(a), b(b), c(c)
    {
        float s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        perimeter = a + b + c;
    };
    void display()
    {
        float s = (a + b + c) / 2;
        cout << "Triangle: " << endl;
        TwoDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Triangle." << endl;
        TwoDimensionalShape::whoAmI();
    };
};

class Rectangle : public TwoDimensionalShape
{
private:
    float l;
    float w;

public:
    Rectangle(float l, float w) : l(l), w(w)
    {
        area = l * w;
        perimeter = 2 * (l + w);
    };
    void display()
    {
        cout << "Rectangle: " << endl;
        TwoDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Rectangle." << endl;
        TwoDimensionalShape::whoAmI();
    };
};

class Cube : public ThreeDimensionalShape
{
private:
    float s;

public:
    Cube(float s) : s(s)
    {
        surArea = 6 * s * s;
        volume = s * s * s;
    };
    void display()
    {
        cout << "Cube: " << endl;
        ThreeDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Cube." << endl;
        ThreeDimensionalShape::whoAmI();
    };
};

class Sphere : public ThreeDimensionalShape
{
private:
    float r;

public:
    Sphere(float r) : r(r)
    {
        surArea = 4 * 3.14 * r * r;
        volume = (4 / 3) * 3.14 * r * r * r;
    };
    void display()
    {
        cout << "Sphere: " << endl;
        ThreeDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Sphere." << endl;
        ThreeDimensionalShape::whoAmI();
    };
};

class Cylinder : public ThreeDimensionalShape
{
private:
    float r;
    float h;

public:
    Cylinder(float r, float h) : r(r), h(h)
    {
        surArea = 2 * 3.14 * r * (r + h);
        volume = 3.14 * r * r * h;
    };
    void display()
    {
        cout << "Cylinder: " << endl;
        ThreeDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Cylinder." << endl;
        ThreeDimensionalShape::whoAmI();
    };
};

class Cone : public ThreeDimensionalShape
{
private:
    float r;
    float h;

public:
    Cone(float r, float h) : r(r), h(h)
    {
        surArea = 3.14 * r * (r + sqrt(r * r + h * h));
        volume = (1 / 3) * 3.14 * r * r * h;
    };
    void display()
    {
        cout << "Cone: " << endl;
        ThreeDimensionalShape::display();
    };

    void whoAmI()
    {
        cout << "I am a Cone." << endl;
        ThreeDimensionalShape::whoAmI();
    };
};

int main()
{
    Square s(5);
    s.whoAmI();
    s.display();

    Circle c(5);
    c.whoAmI();
    c.display();

    Triangle t(3, 4, 5);
    t.whoAmI();
    t.display();

    Rectangle r(3, 4);
    r.whoAmI();
    r.display();

    Cube cu(5);
    cu.whoAmI();
    cu.display();

    Sphere sp(5);
    sp.whoAmI();
    sp.display();

    Cylinder cy(5, 3);
    cy.whoAmI();
    cy.display();

    Cone co(5, 3);
    co.whoAmI();
    co.display();
}