// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) { EXPECT_TRUE(true); }

TEST(test, simple) {
  std::string path_to_ftp = "../";
  findFile(path_to_ftp, path_to_ftp.length() + 1);
  print();
  EXPECT_EQ(brokerVector.size(), 3);
}
