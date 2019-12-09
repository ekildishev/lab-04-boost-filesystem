// Copyright 2018 Your Name <your_email>

#pragma once
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <vector>

struct Broker {
  std::string name;
  std::vector<std::pair<unsigned int, std::pair<unsigned int, unsigned int>>>
      account;  // номер счета-количество файлов-дата последнего
};
std::vector<Broker> brokerVector;

void findFile(std::string path, size_t fileLenght) {
  Broker broker;
  for (const boost::filesystem::directory_entry &x :
       boost::filesystem::directory_iterator(path)) {
    if (boost::filesystem::is_directory(x.path())) {
      findFile(x.path().string(), fileLenght);
    } else {
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
      if (file.substr(25, 4) != ".txt") {
        continue;
      }
      std::cout << path.substr(fileLenght) << ' ' << file << std::endl;
      std::string str = path.substr(fileLenght);
      broker.name = str;
      bool existBroker = false, existAccount;
      for (auto &a : brokerVector) {
        if (broker.name == a.name) {
          existAccount = false;
          existBroker = true;
          for (auto acc : a.account) {
            if (bill == acc.first) {
              existAccount = true;
              acc.second.first++;
              acc.second.second = std::max(acc.second.second, date);
            }
          }
          if (!existAccount) {
            a.account.push_back(std::make_pair(bill, std::make_pair(1, date)));
          }
          existAccount = false;
        }
      }
      if (!existBroker) {
        broker.account.push_back(std::make_pair(bill, std::make_pair(1, date)));
        brokerVector.push_back(broker);
      }
    }
  }
}

void print() {
  for (const auto &x : brokerVector) {
    for (const auto &y : x.account) {
      std::cout << "broker:" << x.name << " account:" << y.first
                << " files:" << y.second.first
                << " lastdate:" << y.second.second << std::endl;
    }
  }
}
