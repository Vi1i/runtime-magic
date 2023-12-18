#include "rtfm/core/parser/sem_ver_parser.h"

#include <stdexcept>
#include <string>
#include <string_view>

namespace rtfm::core::parser {
SemVerParser::SemVerParser(const std::string_view input)
    : position_(0)
    , input_(input) {}

auto SemVerParser::parse() -> void {
  parseVersion();
  parsePreRelease();
  parseBuild();
}

auto SemVerParser::getMajor() const noexcept(true) -> int { return major_; }
auto SemVerParser::getMinor() const noexcept(true) -> int { return minor_; }
auto SemVerParser::getPatch() const noexcept(true) -> int { return patch_; }
auto SemVerParser::getPrerelease() const noexcept(true) -> std::string_view { return prerelease_; }
auto SemVerParser::getBuild() const noexcept(true) -> std::string_view { return build_; }

auto SemVerParser::parseVersion() -> void {
  major_ = parseNumber();
  expect('.');
  minor_ = parseNumber();
  expect('.');
  patch_ = parseNumber();
}

auto SemVerParser::parsePreRelease() -> void {
  if (match('-')) {
    prerelease_ = parseIdentifier();
    while (match('.')) {
      prerelease_ += "." + parseIdentifier();
    }
  }
}

auto SemVerParser::parseBuild() -> void {
  if (match('+')) {
    build_ = parseIdentifier();
    while (match('.')) {
      build_ += "." + parseIdentifier();
    }
  }
}

auto SemVerParser::parseNumber() -> int {
  std::size_t start = position_;
  while (position_ < input_.size() && std::isdigit(input_[position_])) {
    ++position_;
  }
  if (position_ == start) {
    throw std::invalid_argument("Invalid SemVer: Expected a number.");
  }
  return std::stoi(input_.substr(start, position_ - start));
}

auto SemVerParser::parseIdentifier() -> std::string {
  std::size_t start = position_;
  while (position_ < input_.size() && isIdentifierChar(input_[position_])) {
    ++position_;
  }
  if (position_ == start) {
    throw std::invalid_argument("Invalid SemVer: Expected an identifier.");
  }
  return input_.substr(start, position_ - start);
}

auto SemVerParser::isIdentifierChar(char c) -> bool { return std::isalnum(c) || c == '-' || c == '+'; }

auto SemVerParser::expect(char expected) -> void {
  if (position_ < input_.size() && input_[position_] == expected) {
    ++position_;
  } else {
    throw std::invalid_argument("Invalid SemVer: Expected '" + std::string(1, expected) + "'.");
  }
}

auto SemVerParser::match(char expected) -> bool {
  if (position_ < input_.size() && input_[position_] == expected) {
    ++position_;
    return true;
  }
  return false;
}
}  // namespace rtfm::core::parser
