#include <cstdint>
#include <cstdio>

#include <functional>

#include <stm32f072xb.h>

#include <hal.hpp>
#include <stm32f0xx_hal_uart.hpp>
#include <uart_stm32.hpp>

#include <retarget.hpp>

#include <gpio_stm32.hpp>

#include <etl/vector.h>

int main()
{
    hal::init();

    hal::uart_stm32<hal::stm32::uart> uart(USART2);
    uart.init();

    retarget::set_stdio_uart(&uart);

    using gpio = hal::gpio_stm32<hal::port_a>;
    gpio seg_a(hal::pin::p4);   
    gpio seg_b(hal::pin::p5);     
    gpio seg_c(hal::pin::p6);  
    gpio seg_d(hal::pin::p7);  
    gpio seg_e(hal::pin::p8);  
    gpio seg_f(hal::pin::p9);  
    gpio seg_g(hal::pin::p10);  
    gpio dig_1(hal::pin::p11);  
    gpio dig_2(hal::pin::p12); 

    std::array<gpio, 7> all = {seg_a, seg_b, seg_c, seg_d, seg_e, seg_f, seg_g};
    std::array<gpio, 2> one = {seg_b, seg_c};
    std::array<gpio, 5> two = {seg_a, seg_b, seg_g, seg_e, seg_d};

    constexpr auto set_num = [](auto num, bool state) {
        for(auto& seg: num) {
            seg = state;
        }
    };

    while(true)
    {
        set_num(all, false);
        dig_1 = true;
        dig_2 = false;
        set_num(one, true);
        hal::time::delay_ms(500);

        set_num(all, false);
        dig_1 = false;
        dig_2 = true;
        set_num(two, true);
        hal::time::delay_ms(500);
    }
}
