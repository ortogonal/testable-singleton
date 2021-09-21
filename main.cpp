#include <iostream>
#include "pincode.h"

int main()
{
    PinCode pinCode;

    std::cout << "Pin code 1234 ";
    if (pinCode.validPinCode(1234)) {
        std::cout << "is valid" << std::endl;
    } else {
        std::cout << "is not valid" << std::endl;
    }

    return 0;
}
