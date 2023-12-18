#include <rtfm/core.h>
#include <rtfm/server.h>

#include <iostream>

auto main(void) -> int {
  std::cout << "Version: " << rtfm::core::constants::kLibraryInfo.version.to_string() << std::endl;
  std::cout << "Version: " << rtfm::server::constants::kLibraryInfo.version.to_string() << std::endl;
  return 1;
}