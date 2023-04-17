#ifndef TAPE_H_
#define TAPE_H_

#include <vector>
#include <string>
#include <fstream>
#include <cmath>

class TapeInterface
{
    public:
        virtual int read() = 0;
        virtual void write(int value) = 0;
        virtual void shift_forward() = 0;
        virtual void shift_backward() = 0;
        virtual void rewind(long long distance) = 0;
        virtual unsigned long capacity() = 0;
        virtual unsigned long position() = 0;
};

class Tape: public TapeInterface
{
    public:
        Tape(std::string input_file_path)
        {
            std::ifstream input_file(input_file_path);
            if (input_file.is_open())
            {
                int tmp = 0;
                while (input_file >> tmp)
                {
                    memory_.push_back(tmp);
                }
                memory_.shrink_to_fit();
                input_file.close();
            }
        }

        ~Tape() {}

        int read();
        void write(int value);
        void shift_forward();
        void shift_backward();
        void rewind(long long distance);
        unsigned long capacity();
        unsigned long position();
        
        private:
            std::vector<int> memory_;
            unsigned long iterator_ = 0;
};

#endif // TAPE_H_