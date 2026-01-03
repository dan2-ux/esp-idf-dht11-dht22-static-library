#pragma once

#include "driver/gpio.h"

namespace dht11
{
    void init(gpio_num_t pin);
    bool getData(gpio_num_t pin);
    float getHUM();
    float getTEMP();
}

namespace dht22
{
    void init(gpio_num_t pin);
    bool getData(gpio_num_t pin);
    float getHUM();
    float getTEMP();
}
