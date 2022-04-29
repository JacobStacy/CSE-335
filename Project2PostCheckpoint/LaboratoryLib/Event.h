/**
 * @file Event.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_EVENT_H
#define CANADIANEXPERIENCE_EVENT_H

#include <wx/xml/xml.h>

/**
 * Class for our Event object
 */
class Event {
private:

    /// XML node for the Event
    wxXmlNode mNode;

public:

    /// Default constructor (disabled)
    Event() = delete;

    Event(wxXmlNode* node);

    /// Copy Constructor (Disabled)
    Event(const Event &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Event &) = delete;

    /**
     * Gets node
     * @return Node
     */
    wxXmlNode* GetNode() { return &mNode; }

};

#endif //CANADIANEXPERIENCE_EVENT_H
