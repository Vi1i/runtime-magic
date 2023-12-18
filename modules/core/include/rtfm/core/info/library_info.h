#pragma once

#include <string>

#include "rtfm/core/meta/version.h"
#include "rtfm/core/rhymes.h"

namespace rtfm::core::info {

template <rtfm::core::rhymes::VersionBasic T>
struct LibraryInfo {
  T version;
};

template <typename T>
auto library_info_to_string(T) -> void {}

}  // namespace rtfm::core::info