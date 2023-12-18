#pragma once

#include <string>
#include <string_view>

namespace rtfm::core::parser {
class SemVerParser {
 private:
  int major_;
  int minor_;
  int patch_;
  std::size_t position_;
  std::string prerelease_;
  std::string build_;
  const std::string input_;

 public:
  SemVerParser(std::string_view input);

  auto parse() -> void;
  auto getMajor() const noexcept(true) -> int;
  auto getMinor() const noexcept(true) -> int;
  auto getPatch() const noexcept(true) -> int;
  auto getPrerelease() const noexcept(true) -> std::string_view;
  auto getBuild() const noexcept(true) -> std::string_view;

 private:
  auto parseVersion() -> void;
  auto parsePreRelease() -> void;
  auto parseBuild() -> void;
  auto parseNumber() -> int;
  auto parseIdentifier() -> std::string;
  auto isIdentifierChar(char c) -> bool;
  auto expect(char expected) -> void;
  auto match(char expected) -> bool;
};
}  // namespace rtfm::core::parser