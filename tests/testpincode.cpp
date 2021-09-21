#include "gtest/gtest.h"

#include <isettings.h>
#include <pincode.h>
#include <settingssingleton.h>

class SettingsMock : public ISettings
{
public:
    bool hasValue(const Parameter &parameter) const override;
    int value(const Parameter &parameter) const override;
};

bool SettingsMock::hasValue(const Parameter &parameter) const
{
    return parameter == ISettings::Parameter::PinCode;
}

int SettingsMock::value(const Parameter &parameter) const
{
    if (parameter == ISettings::Parameter::PinCode) {
        return 1234;
    }
    return -1;
}

TEST(testPinCode, sample_test)
{
    SettingsSingleton::initialize(std::make_unique<SettingsMock>());

    PinCode pinCode;
    EXPECT_EQ(pinCode.validPinCode(1234), true);
    EXPECT_EQ(pinCode.validPinCode(0), false);
    EXPECT_EQ(pinCode.validPinCode(1), false);
    EXPECT_EQ(pinCode.validPinCode(2), false);
}
