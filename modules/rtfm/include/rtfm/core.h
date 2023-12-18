#pragma once

#include <string>

#include "rtfm/core/info/library_info.h"
#include "rtfm/meta/version.h"

namespace rtfm {
auto GetLibraryInfo() -> LibraryInfo;
}  // namespace rtfm