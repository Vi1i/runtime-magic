#pragma once

#include "rtfm/core/info.h"
#include "rtfm/core/meta/version.h"

namespace rtfm::core ::constants {
using Version = info::SemVer;

static const info::LibraryInfo<Version> kLibraryInfo = {
    .version = Version{meta::version::kMajor, meta::version::kMinor, meta::version::kPatch, "alpha", "0"}};
}  // namespace rtfm::core::constants