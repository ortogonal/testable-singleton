#include "pincode.h"
#include "settingssingleton.h"

/**
 * @brief PinCode::validPinCode
 * @param enteredPinCode
 * @return True if the enteredPinCode is correct.
 */
bool PinCode::validPinCode(const int enteredPinCode) const
{
    auto parameter = SettingsSingleton::Parameter::PinCode;

    if (SettingsSingleton::instance()->hasValue(parameter)) {
        return SettingsSingleton::instance()->value(parameter) == enteredPinCode;
    }

    return false;
}
