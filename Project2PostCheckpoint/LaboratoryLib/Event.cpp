/**
 * @file Event.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Event.h"

/**
 * Constructor
 * @param node Event Xml Node
 */
Event::Event(wxXmlNode* node)
{
    mNode = *node;

}
