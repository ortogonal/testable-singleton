#pragma once

class ISettings {
public:
    virtual ~ISettings() = default;

    enum class Parameter {
        PinCode,
        AlarmTemperature,
        PortNumber,
        InstallationId
    };

    virtual bool hasValue(const Parameter &parameter) const = 0;
    virtual int value(const Parameter &parameter) const = 0;
};
