#pragma once

#include <string>

#include "rtfm/core/meta/version.h"
#include "rtfm/core/rhyme.h"

namespace rtfm::core {
struct LibraryInfo {
  std::string version_string;
  int version_major;
  int version_minor;
  int version_patch;
};

auto GetLibraryInfo() -> LibraryInfo;
}  // namespace rtfm::core