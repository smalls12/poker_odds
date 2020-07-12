#pragma once

#include "Logger.hpp"

class Logging
{
    public:

        inline static Logger get()
        {
            return logger;
        }
    
    private:
        static Logger logger;
};