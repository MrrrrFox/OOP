#pragma once

// klasa do rysowania
class Drawable
{
public:
    virtual ~Drawable() = default;
    virtual double length() = 0;
    virtual void draw() = 0;
};

// klasa zamknietych powierzchni
class ClosedShape
{
public:
    virtual ~ClosedShape() = default;
    virtual double area() const = 0;
};

// klasa do przesuwania
class Transformable
{
public:
    virtual ~Transformable() = default;
    virtual void shift(double, double) = 0;
};

//funckja rysujaca
void draw(Drawable * myDraw)
{
    myDraw->draw();
}