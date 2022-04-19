/**
 * @file LaboratoryFactoryOne.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LABORATORYFACTORYONE_H
#define CANADIANEXPERIENCE_LABORATORYFACTORYONE_H

class ActualLaboratory;

/**
 * Class that creates laboratory one, which is the lab that isn't used for challenge tasks
 */
class LaboratoryFactoryOne {
private:

    /// Directory for resources | !!!!! NOT IN UML !!!!!
    std::wstring mResourcesDir;

public:

    /// Copy Constructor (Disabled)
    LaboratoryFactoryOne(const LaboratoryFactoryOne &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const LaboratoryFactoryOne &) = delete;

    LaboratoryFactoryOne(std::wstring resourcesDir);

    std::shared_ptr<ActualLaboratory> CreateLaboratory();

};

#endif //CANADIANEXPERIENCE_LABORATORYFACTORYONE_H
