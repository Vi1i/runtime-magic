#include <concepts>
#include <string_view>

namespace rtfm::core::rhyme {

template <typename T>
concept has_version_string = requires(T lib_info) {
  { lib_info.version_string } -> std::convertible_to<std::string_view>;
};

template <typename T>
concept has_version_major = requires(T lib_info) {
  { lib_info.version_major() } -> std::same_as<int>;
};

template <typename T>
concept has_version_minor = requires(T lib_info) {
  { lib_info.version_minor() } -> std::same_as<int>;
};

template <typename T>
concept has_version_patch = requires(T lib_info) {
  { lib_info.version_patch() } -> std::same_as<int>;
};

template <typename T>
concept VersionString = has_version_string<T>;

template <typename T>
concept VersionValues = has_version_major<T> && has_version_minor<T> && has_version_patch<T>;
}  // namespace rtfm::core::rhyme