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
    mOrgin.x = 0;
    mOrgin.y = 0;
}

/**
 * Draws the Shape
 * @param graphics
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    mPolygon.DrawPolygon(graphics, mOrgin.x, mOrgin.y);
}



