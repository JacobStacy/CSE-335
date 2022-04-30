/**
 * @file ActualLaboratory.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_ACTUALLABORATORY_H
#define CANADIANEXPERIENCE_ACTUALLABORATORY_H

class Component;
class Event;

/**
 * The ActualLaboratory class
 * This class handles the actual objects in the laboratory
 */
class ActualLaboratory {
private:

    /// Components that are part of the laboratory
    std::vector<std::shared_ptr<Component>> mComponents;

    /// Components that are part of the laboratory
    std::vector<std::shared_ptr<Event>> mEvents;

    /// The next event to happen
    int mNextEvent = 0;

public:

    ActualLaboratory();

    /// Copy Constructor (Disabled)
    ActualLaboratory(const ActualLaboratory &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const ActualLaboratory &) = delete;

    /**
     * Destructor
    */
    virtual ~ActualLaboratory() = default;


    void DrawLaboratory(std::shared_ptr<wxGraphicsContext> graphics);

    void Update(double elapsed);

    void AddComponent(std::shared_ptr<Component> component);

    void LoadScript(const std::wstring& script);

};

#endif //CANADIANEXPERIENCE_ACTUALLABORATORY_H
