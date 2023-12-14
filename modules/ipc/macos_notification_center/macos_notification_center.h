#pragma once

#include <functional>
#include <string>

namespace rtfm::core::ipc {
class MacOSNotificationCenter {
 public:
  using message_type = std::string;  // Simplified for the example.

  auto connect() -> bool;
  auto disconnect() -> bool;
  auto send(const message_type &) -> bool;
  auto set_receive_handler(std::function<void(const message_type &)> handler) -> void;
  auto get_last_error() -> std::string;
};
}  // namespace rtfm::core::ipc
