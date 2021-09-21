#pragma once

/**
 * @brief The PinCode class
 *
 * This class is just a very simple example
 * of a class that use the SettingsSingleton.
 *
 * Yes, the singleton is not really needed here,
 * but this is just a example to illustrate the problem.
 */
class PinCode
{
public:
    PinCode() = default;

    bool validPinCode(const int enteredPinCode) const;
};

