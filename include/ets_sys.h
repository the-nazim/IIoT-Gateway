#ifndef ETS_SYS_H
#define ETS_SYS_H

#include <esp_rom_sys.h>

#ifndef ets_delay_us
#define ets_delay_us esp_rom_delay_us
#endif

#endif // ETS_SYS_H
