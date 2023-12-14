#include <concepts>
#include <functional>
#include <string>

namespace rtfm::core::rhyme {
template <typename T>
concept IPC =
    requires(T ipc, const typename T::message_type& msg, std::function<void(const typename T::message_type&)> handler) {
      // The IPC class must have a message_type type definition.
      typename T::message_type;

      // The IPC class must support connecting and disconnecting.
      { ipc.connect() } -> std::same_as<bool>;
      { ipc.disconnect() } -> std::same_as<bool>;

      // The IPC class must support sending messages.
      { ipc.send(msg) } -> std::same_as<bool>;

      // The IPC class must support setting a receive handler for incoming messages.
      { ipc.set_receive_handler(handler) } -> std::same_as<void>;

      // The IPC class must provide an error handling mechanism.
      { ipc.get_last_error() } -> std::convertible_to<std::string>;
    };
}