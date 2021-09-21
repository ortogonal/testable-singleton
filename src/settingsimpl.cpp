#include "settingsimpl.h"
#include <fstream>

constexpr const auto settingsFile = "settings.data";

SettingsImpl::SettingsImpl()
{
    std::ifstream inFile;

    int parameter = 0;
    int value = 0;

    inFile.open(settingsFile, std::ifstream::in);

    while(inFile >> parameter >> value)
    {
        auto p = static_cast<ISettings::Parameter>(parameter);
        m_values[p] = value;
    }
}

/**
 * @brief SettingsImpl::hasValue
 * @param parameter Parameter to ask for
 * @return True if the parameter has a valid value, otherwise false
 */
bool SettingsImpl::hasValue(const ISettings::Parameter &parameter) const
{
    return m_values.find(parameter) != m_values.end();
}

/**
 * @brief SettingsImpl::value
 * @param parameter Parameter to ask for
 * @return value if parameter, -1 if invalid.
 *
 * Make sure to check that the parameter has a valid value
 * by calling SettingsSingleton::hasValue() before.
 */
int SettingsImpl::value(const ISettings::Parameter &parameter) const
{
    if (hasValue(parameter)) {
        return m_values.at(parameter);
    }
    return -1;
}
