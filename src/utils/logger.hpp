#ifndef INCLUDE_UTILS_LOGGER_HPP_
#define INCLUDE_UTILS_LOGGER_HPP_

#include <iostream>
#include <string_view>

namespace Logger {
  inline void info(std::string_view message) {
    std::cout << "\033[34mINFO  |\033[0m " << message << std::endl;
  }

  inline void err(std::string_view message) {
    std::cerr << "\033[0;31mERROR |\033[0m " << message << std::endl;
  }

  inline void debug(std::string_view message) {
#ifndef NDEBUG
    std::cout << "\033[38;2;255;165;0mDEBUG |\033[0m " << message << std::endl;
#endif
  }
}

#endif
