/**
 * @file Shape.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Shape.h"

/**
 * Constructor
 * @param name name of the shape
 */
Shape::Shape(const std::wstring& name) : Component(name)
{
    mOrigin.x = 0;
    mOrigin.y = 0;
}

/**
 * Draws the Shape
 * @param graphics
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, mOrigin.x, mOrigin.y);
}



