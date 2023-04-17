#include "Init.hpp"

double ConfigParam::get_write_delay()
{
    return delays_.write_delay_;
}

double ConfigParam::get_read_delay()
{
    return delays_.read_delay_;
}

double ConfigParam::get_rewind_delay()
{
    return delays_.rewind_delay_;
}

double ConfigParam::get_shift_delay()
{
    return delays_.shift_delay_;
}

unsigned long ConfigParam::get_memory_size()
{
    return memory_size_;
}