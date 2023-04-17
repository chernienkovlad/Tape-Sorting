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
        if (out_of_bounds == true)
        {
            out_of_bounds = false;
        }
        return;
    }
    out_of_bounds = true;
}

void Tape::shift_backward()
{
    if (iterator_ != 0)
    {
        --iterator_;
        if (out_of_bounds == true)
        {
            out_of_bounds = false;
        }
        return;
    }
    out_of_bounds = true;
}

void Tape::rewind(long long distance)
{
    if (distance < 0)
    {
        if (abs(distance) > static_cast<long long>(iterator_))
        {
            iterator_ = 0;
            out_of_bounds = true;
            return;
        }
    }
    else
    {
        if (distance + iterator_ > memory_.size() - 1)
        {
            iterator_ = memory_.size() - 1;
            out_of_bounds = true;
            return;
        }
    }

    iterator_ += distance;

    if (out_of_bounds == true)
    {
        out_of_bounds = false;
    }
}

unsigned long Tape::capacity()
{
    return memory_.size();
}

unsigned long Tape::position()
{
    return (iterator_ + 1);
}

bool Tape::is_out_of_bounds()
{
    return out_of_bounds;
}

void Tape::tape_to_file(std::string output_file_path)
{
    std::ofstream output_file(output_file_path);
    if (output_file.is_open())
    {
        for (unsigned long i = 0; i < memory_.size(); i++) 
        {
            output_file << memory_[i] << std::endl;
        }
        output_file.close();
    }
}