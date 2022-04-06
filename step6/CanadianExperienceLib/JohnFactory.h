/**
 * @file JohnFactory.h
 * @author Jacob R. Stacy
 *
 * Header File for JohnFactory class
 *
 */

#ifndef CANADIANEXPERIENCE_JOHNFACTORY_H
#define CANADIANEXPERIENCE_JOHNFACTORY_H

class Actor;

/**
 * Factory class that builds the John character
 */
class JohnFactory {
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_JOHNFACTORY_H
