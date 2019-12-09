// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include <algorithm>
#include <iostream>

Broker findFile(std::string path, size_t fileNameLenght)
{
    Broker broker;
    for(const boost::filesystem::directory_entry &x : boost::filesystem::directory_iterator(path))
    {
        if(boost::filesystem::is_directory(x.path()))
        {
            findFile(x.path().string(), fileNameLenght);
        }
        else {
          std::string file = x.path().filename().string();
          unsigned int bill, date;
          if (file.find("balance_")) {
            continue;
          }
          if (file[16] != '_') {
            continue;
          }
          bill = std::stoi(file.substr(8, 8));
          date = std::stoi(file.substr(17, 8));
          if (file.substr(25, 4) != ".txt")
          {
            continue;
          }
          broker.account.first++;
        }
    }
}
