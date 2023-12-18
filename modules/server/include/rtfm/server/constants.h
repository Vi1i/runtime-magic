#pragma once

#include "rtfm/core/info.h"
#include "rtfm/server/meta/version.h"

namespace rtfm::server::constants {
using Version = core::info::SemVer;

static const core::info::LibraryInfo<Version> kLibraryInfo = {
    .version = Version{meta::version::kMajor, meta::version::kMinor, meta::version::kPatch, "alpha", "0"}};
}  // namespace rtfm::server::constants