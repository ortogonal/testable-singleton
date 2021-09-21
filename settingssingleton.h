#pragma once

#include "isettings.h"

#include <cassert>
#include <memory>

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
    static void initialize(std::unique_ptr<ISettings> implementation);
    static SettingsSingleton *instance();

    bool hasValue(const ISettings::Parameter &parameter) const;
    int value(const ISettings::Parameter &parameter) const;


private:
    SettingsSingleton() = default;

    static SettingsSingleton *m_instance;

    std::unique_ptr<ISettings> m_implementation;
};

