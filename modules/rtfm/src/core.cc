#include "rtfm/core.h"

#include "rtfm/core/meta/version.h"
#include "rtfm/meta/version.h"

namespace rtfm {
auto GetLibraryInfo() -> LibraryInfo {
  auto info = LibraryInfo{meta::version::kString, meta::version::kMajor, meta::version::kMinor, meta::version::kPatch};

  return info;
}
}  // namespace rtfm