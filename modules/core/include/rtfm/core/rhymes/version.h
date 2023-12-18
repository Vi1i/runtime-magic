#pragma once

#include <concepts>
#include <string_view>

namespace rtfm::core::rhymes {
namespace version {
template <typename T>
concept has_version_digits = requires(T version) {
  { version.get_major() } -> std::convertible_to<int>;
  { version.get_minor() } -> std::convertible_to<int>;
  { version.get_patch() } -> std::convertible_to<int>;
};

template <typename T>
concept has_version_meta = requires(T version) {
  { version.get_meta() } -> std::convertible_to<std::vector<std::string_view>>;
};

template <typename T>
concept has_version_to_string = requires(T version) {
  { version.to_string() } -> std::same_as<std::string_view>;
};

template <typename T>
concept has_version_is_valid = requires(T version) {
  { version.is_valid() } -> std::same_as<bool>;
};

template <typename T>
concept has_version_semantic_meta = requires(T version) {
  { version.get_prerelease() } -> std::convertible_to<std::string_view>;
  { version.get_build() } -> std::convertible_to<std::string_view>;
};
}  // namespace version

template <typename T>
concept VersionBasic = version::has_version_digits<T> && version::has_version_to_string<T>;

template <typename T>
concept VersionValidation = version::has_version_is_valid<T>;

template <typename T>
concept Version = VersionBasic<T> && VersionValidation<T> && version::has_version_meta<T>;

template <typename T>
concept SemanticVersion = VersionBasic<T> && VersionValidation<T> && version::has_version_semantic_meta<T>;
}  // namespace rtfm::core::rhymes