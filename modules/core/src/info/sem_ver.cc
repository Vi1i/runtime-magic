#include "rtfm/core/info/sem_ver.h"

#include <iostream>

#include "rtfm/core/parser/sem_ver_parser.h"

namespace rtfm::core::info {
SemVer::SemVer() noexcept(true)
    : major_(0)
    , minor_(0)
    , patch_(0) {}

SemVer::SemVer(int major, int minor, int patch, const std::string_view prerelease,
               const std::string_view build) noexcept(true)
    : major_(major)
    , minor_(minor)
    , patch_(patch)
    , prerelease_(prerelease)
    , build_(build) {
  // Lazy-load SemVer string
  generate_semver_string();
}

SemVer::SemVer(const std::string_view version) noexcept(false) {
  rtfm::core::parser::SemVerParser parser(version);
  parser.parse();

  major_ = parser.getMajor();
  minor_ = parser.getMinor();
  patch_ = parser.getPatch();
  prerelease_ = parser.getPrerelease();
  build_ = parser.getBuild();

  generate_semver_string();
}

auto SemVer::get_major() const noexcept(true) -> int { return major_; }
auto SemVer::get_minor() const noexcept(true) -> int { return minor_; }
auto SemVer::get_patch() const noexcept(true) -> int { return patch_; }
auto SemVer::get_prerelease() const noexcept(true) -> const std::string_view { return prerelease_; }
auto SemVer::get_build() const noexcept(true) -> const std::string_view { return build_; }
auto SemVer::get_metadata() const noexcept(true) -> const std::string_view { return prerelease_ + "+" + build_; }

auto SemVer::to_string() const noexcept(true) -> std::string_view {
  if (semver_string_.empty()) {
    generate_semver_string();
  }

  return semver_string_;
}

auto SemVer::is_valid() const noexcept(true) -> bool { return major_ >= 0 && minor_ >= 0 && patch_ >= 0; }

auto SemVer::generate_semver_string() const noexcept(true) -> void {
  try {
    semver_string_ = std::to_string(major_) + "." + std::to_string(minor_) + "." + std::to_string(patch_);
    if (!prerelease_.empty()) {
      semver_string_ += "-" + prerelease_;
    }
    if (!build_.empty()) {
      semver_string_ += "+" + build_;
    }
  } catch (const std::exception& e) {
    std::cerr << "An unexpected exception occurred: " << e.what() << std::endl;
    semver_string_ = "error";
  }
}
}  // namespace rtfm::core::info