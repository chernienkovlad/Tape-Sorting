#include "Tape.hpp"

int Tape::read()
{
    return memory_[iterator_];
}

void Tape::write(int value)
{
    memory_[iterator_] = value;
}

void Tape::shift_forward()
{
    if (iterator_ != memory_.size() - 1)
    {
        ++iterator_;
    }
}

void Tape::shift_backward()
{
    if (iterator_ != 0)
    {
        --iterator_;
    }
}

void Tape::rewind(long long distance)
{
    if (distance < 0)
    {
        if (abs(distance) > (long long)iterator_)
        {
            iterator_ = 0;
            return;
        }
    }
    else
    {
        if (distance + iterator_ > memory_.size() - 1)
        {
            iterator_ = memory_.size() - 1;
            return;
        }
    }
    iterator_ += distance;
}

unsigned long Tape::capacity()
{
    return memory_.size();
}

unsigned long Tape::position()
{
    return (iterator_ + 1);
}