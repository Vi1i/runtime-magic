#pragma once

#include <regex>
#include <stdexcept>
#include <string>
#include <string_view>

namespace rtfm::core::info {
class SemVer {
 public:
  SemVer() noexcept(true);
  SemVer(int major, int minor, int patch, const std::string_view prerelease = "",
         const std::string_view build = "") noexcept(true);
  SemVer(const std::string_view version) noexcept(false);

  auto get_major() const noexcept(true) -> int;
  auto get_minor() const noexcept(true) -> int;
  auto get_patch() const noexcept(true) -> int;
  auto get_prerelease() const noexcept(true) -> const std::string_view;
  auto get_build() const noexcept(true) -> const std::string_view;
  auto get_metadata() const noexcept(true) -> const std::string_view;

  auto to_string() const noexcept(true) -> std::string_view;
  auto is_valid() const noexcept(true) -> bool;

 private:
  int major_;
  int minor_;
  int patch_;
  std::string prerelease_;
  std::string build_;
  mutable std::string semver_string_;

  auto generate_semver_string() const noexcept(true) -> void;
};
}  // namespace rtfm::core::info