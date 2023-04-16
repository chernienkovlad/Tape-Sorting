#include "Tape.hpp"

inline int Tape::read()
{
    return memory_[iterator_];
}

inline void Tape::write(int value)
{
    memory_[iterator_] = value;
}

inline unsigned long Tape::capacity()
{
    return memory_.size();
}

inline unsigned long Tape::position()
{
    return (iterator_ + 1);
}

void Tape::move_forward()
{
    if (iterator_ != memory_.size() - 1)
    {
        ++iterator_;
    }
}

void Tape::move_backward()
{
    if (iterator_ != 0)
    {
        --iterator_;
    }
}