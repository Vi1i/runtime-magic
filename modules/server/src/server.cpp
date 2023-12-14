#include <rtfm/core.h>

#include <iostream>

auto main(void) -> int {
  auto lib_info = rtfm::core::GetLibraryInfo();

  std::cout << "Version: " << lib_info.version_string << std::endl;

  return 1;
}