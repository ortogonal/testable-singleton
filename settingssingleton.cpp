#include "settingssingleton.h"

#include <fstream>
#include <iostream>

SettingsSingleton* SettingsSingleton::m_instance = nullptr;

constexpr const auto settingsFile = "settings.data";

SettingsSingleton *SettingsSingleton::instance()
{
    if (m_instance == nullptr) {
        m_instance = new SettingsSingleton();
    }

    return m_instance;
}

/**
 * @brief SettingsSingleton::hasValue
 * @param parameter Parameter to ask for
 * @return True if the parameter has a valid value, otherwise false
 */
bool SettingsSingleton::hasValue(const SettingsSingleton::Parameter &parameter) const
{
    return m_values.find(parameter) != m_values.end();
}

/**
 * @brief SettingsSingleton::value
 * @param parameter Parameter to ask for
 * @return value if parameter, -1 if invalid.
 *
 * Make sure to check that the parameter has a valid value
 * by calling SettingsSingleton::hasValue() before.
 */
int SettingsSingleton::value(const SettingsSingleton::Parameter &parameter) const
{
    if (hasValue(parameter)) {
        return m_values.at(parameter);
    }
    return -1;
}

SettingsSingleton::SettingsSingleton()
{
    std::ifstream inFile;

    int parameter = 0;
    int value = 0;

    inFile.open(settingsFile, std::ifstream::in);

    while(inFile >> parameter >> value)
    {
        auto p = static_cast<Parameter>(parameter);
        m_values[p] = value;
    }
}
