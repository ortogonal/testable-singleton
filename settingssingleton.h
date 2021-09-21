#pragma once

#include <map>

/**
 * @brief The SettingsSingleton class
 *
 * This is a really simplyfied class just to
 * illustrate a singleton.
 *
 * Yes I know this implementation is not thread safe,
 * but this code is written to illustrate an example.
 */
class SettingsSingleton
{
public:
    enum class Parameter {
        PinCode,
        AlarmTemperature,
        PortNumber,
        InstallationId
    };

    static SettingsSingleton *instance();

    bool hasValue(const Parameter &parameter) const;
    int value(const Parameter &parameter) const;


private:
    SettingsSingleton();

    static SettingsSingleton *m_instance;

    std::map<Parameter, int> m_values;
};

