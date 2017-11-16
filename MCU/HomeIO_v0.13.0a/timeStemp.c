#include <time.h>
#include <stdint.h>

static uint32_t timestamp =0;

void time_isr(void)
{
    timestamp++;
}

uint32_t getTimeStemp(void)
{
    return timestamp;
}

void setTimeStemp(uint32_t time)
{
    timestamp=time;
}

void timeInit(void)
{
    timestamp=1502383929;
}
