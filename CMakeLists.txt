cmake_minimum_required(VERSION 3.0)
project(theRoyalGameofUr
  VERSION 0.1.0
)
find_package(gf REQUIRED)
add_executable(theRoyalGameofUr
  theRoyalGameofUr.cc
  # and the rest of your sources
)
target_link_libraries(theRoyalGameofUr
  gf::gf0
)
