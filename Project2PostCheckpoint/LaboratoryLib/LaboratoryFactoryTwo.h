/**
 * @file LaboratoryFactoryTwo.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LABORATORYFACTORYTWO_H
#define CANADIANEXPERIENCE_LABORATORYFACTORYTWO_H

class ActualLaboratory;

/**
 * Class that creates laboratory two, which is the lab that isn't used for challenge tasks
 */
class LaboratoryFactoryTwo {
private:

    /// Directory for resources | !!!!! NOT IN UML !!!!!
    std::wstring mResourcesDir;

public:

    /// Copy Constructor (Disabled)
    LaboratoryFactoryTwo(const LaboratoryFactoryTwo &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const LaboratoryFactoryTwo &) = delete;

    LaboratoryFactoryTwo(std::wstring resourcesDir);

    std::shared_ptr<ActualLaboratory> CreateLaboratory();

};

#endif //CANADIANEXPERIENCE_LABORATORYFACTORYTWO_H
