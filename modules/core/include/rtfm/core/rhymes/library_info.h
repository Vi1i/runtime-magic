#include <concepts>
#include <string_view>

#include "rtfm/core/rhymes/version.h"

namespace rtfm::core::rhymes {
namespace library_info {
template <typename T>
concept has_version = requires(T library_info) {
  {library_info.version};
  requires VersionBasic<decltype(library_info.version)>;
};
}  // namespace library_info

template <typename T>
concept LibraryInfo = library_info::has_version<T>;

}  // namespace rtfm::core::rhymes