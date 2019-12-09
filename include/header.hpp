// Copyright 2018 Your Name <your_email>
#pragma once
#include <boost/filesystem.hpp>
#include <string>

struct Broker
{
    std::string name;
    std::pair<unsigned int, std::pair<unsigned int, unsigned int>> account;
};
