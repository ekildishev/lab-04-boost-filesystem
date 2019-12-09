// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  std::string path_to_ftp;
  if (argc == 2) {
    path_to_ftp = std::string(argv[1]);
  } else {
    path_to_ftp = "../";
  }
  findFile(path_to_ftp, path_to_ftp.length() + 1);
  for (const auto &x : brokerVector) {
    for (const auto &y : x.account) {
      std::cout << "broker:" << x.name << " account:" << y.first
                << " files:" << y.second.first
                << " lastdate:" << y.second.second << std::endl;
    }
  }
}