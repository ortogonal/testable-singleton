#pragma once

#include "isettings.h"

#include <map>

class SettingsImpl : public ISettings
{
public:
    SettingsImpl();

    bool hasValue(const Parameter &parameter) const override;
    int value(const Parameter &parameter) const override;

private:
    std::map<ISettings::Parameter, int> m_values;
};

