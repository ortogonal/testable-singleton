#include "settingssingleton.h"

#include <iostream>

SettingsSingleton* SettingsSingleton::m_instance = nullptr;


void SettingsSingleton::initialize(std::unique_ptr<ISettings> implementation)
{
    assert(m_instance == nullptr);
    m_instance = new SettingsSingleton();
    m_instance->m_implementation = std::move(implementation);
}

SettingsSingleton *SettingsSingleton::instance()
{
    assert(m_instance != nullptr);
    return m_instance;
}

/**
 * @brief SettingsSingleton::hasValue
 * @param parameter Parameter to ask for
 * @return True if the parameter has a valid value, otherwise false
 */
bool SettingsSingleton::hasValue(const ISettings::Parameter &parameter) const
{
    if (m_implementation) {
        return m_implementation->hasValue(parameter);
    }
    return false;
}

/**
 * @brief SettingsSingleton::value
 * @param parameter Parameter to ask for
 * @return value if parameter, -1 if invalid.
 *
 * Make sure to check that the parameter has a valid value
 * by calling SettingsSingleton::hasValue() before.
 */
int SettingsSingleton::value(const ISettings::Parameter &parameter) const
{
    if (m_implementation) {
        return m_implementation->value(parameter);
    }
    return -1;
}
