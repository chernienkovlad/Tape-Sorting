#ifndef TAPE_H_
#define TAPE_H_

#include <vector>
#include <string>
#include <fstream>

class TapeInterface
{
    public:
        virtual int read() = 0;
        virtual void write(int value) = 0;
        virtual void move_forward() = 0;
        virtual void move_backward() = 0;
        virtual unsigned long capacity() = 0;
        virtual unsigned long position() = 0;
};

class Tape: public TapeInterface
{
    public:
        Tape(std::string input_filename)
        {
            std::ifstream input_file{input_filename};
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
        void move_forward();
        void move_backward();
        unsigned long capacity();
        unsigned long position();
        
        private:
            std::vector<int> memory_;
            unsigned long iterator_ = 0;
};

#endif // TAPE_H_