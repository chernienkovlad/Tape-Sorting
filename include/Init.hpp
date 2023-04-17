#ifndef INIT_H_
#define INIT_H_

#include "Tape.hpp"

#define DELAY_CONFIG_FILENAME "delay_values.conf"
#define MEMORY_CONFIG_FILENAME "memory_size.conf"

class ConfigParam
{
    public:
        ConfigParam(std::string config_files_dir)
        {
            std::ifstream delay_config_file(config_files_dir + "/" + DELAY_CONFIG_FILENAME);
            if (delay_config_file.is_open())
            {
                std::string tmp_s;
                while (delay_config_file >> tmp_s)
                {
                    if (tmp_s == "write_delay")
                    {
                        delay_config_file >> delays_.write_delay_;
                    }
                    else if (tmp_s == "read_delay")
                    {
                        delay_config_file >> delays_.read_delay_;
                    }
                    else if (tmp_s == "rewind_delay")
                    {
                        delay_config_file >> delays_.rewind_delay_;
                    }
                    else if (tmp_s == "shift_delay")
                    {
                        delay_config_file >> delays_.shift_delay_;
                    }
                }
                delay_config_file.close();
            }

            std::ifstream memory_config_file(config_files_dir + "/" + MEMORY_CONFIG_FILENAME);
            if (memory_config_file.is_open())
            {
                std::string tmp_s;
                memory_config_file >> tmp_s;
                if (tmp_s == "memory_size")
                {
                    memory_config_file >> memory_size_;
                }
                memory_config_file.close();
            }
        }

        ~ConfigParam() {}

        double get_write_delay();
        double get_read_delay();
        double get_rewind_delay();
        double get_shift_delay();
        unsigned long get_memory_size();

    private:
        struct DelayValues
        {
            double write_delay_ = 0;
            double read_delay_ = 0;
            double rewind_delay_ = 0;
            double shift_delay_ = 0;
        };
        DelayValues delays_;
        unsigned long memory_size_ = 0;
};

#endif // INIT_H_