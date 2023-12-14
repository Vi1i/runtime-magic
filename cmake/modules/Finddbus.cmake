# Finddbus.cmake
# Attempts to find D-Bus on Linux and macOS.

# Define a function to report not found message
function(report_not_found)
    message(WARNING "DBus could not be found. Ensure that it is installed and that dbus_ROOT_DIR is set if it is installed in a non-standard location.")
endfunction()

if(UNIX AND NOT APPLE)
    # Look for D-Bus on Linux
    find_package(PkgConfig)
    pkg_check_modules(dbus QUIET dbus-1)

    if(dbus_FOUND)
        add_library(dbus::dbus SHARED IMPORTED)
        set_target_properties(dbus::dbus PROPERTIES
                              INTERFACE_INCLUDE_DIRECTORIES "${dbus_INCLUDE_DIRS}"
                              INTERFACE_LINK_DIRECTORIES "${dbus_LIBRARY_DIRS}"
                              IMPORTED_LOCATION "${dbus_LIBRARIES}")
    else()
        report_not_found()
    endif()
elseif(APPLE)
    # Look for D-Bus on macOS, assuming it is installed via Homebrew in /usr/local
    find_path(dbus_INCLUDE_DIR
      NAMES
        dbus/dbus.h
      HINTS
        /usr/local/include/dbus-1.0
        /usr/local/include
        /opt/homebrew/include
        /opt/homebrew/include
        /opt/homebrew/include/dbus-1.0
    )

    find_path(dbus_ARCH_DEPS_INCLUDE_DIR
      NAMES
        dbus/dbus-arch-deps.h
      HINTS
        "${HOMEBREW_PREFIX}/lib/dbus-1.0/include"
        "/usr/local/lib/dbus-1.0/include"
        "/opt/homebrew/lib/dbus-1.0/include"
        NO_DEFAULT_PATH
    )

    set(dbus_INCLUDE_DIRS ${dbus_INCLUDE_DIR} ${dbus_ARCH_DEPS_INCLUDE_DIR})


    find_library(dbus_LIBRARY
      NAMES
        dbus-1
      HINTS
        /usr/local/lib
        /opt/homebrew/lib
    )

    if(dbus_INCLUDE_DIR AND dbus_LIBRARY)
      add_library(dbus::dbus SHARED IMPORTED)
      set_target_properties(dbus::dbus PROPERTIES
                            INTERFACE_INCLUDE_DIRECTORIES "${dbus_INCLUDE_DIRS}"
                            IMPORTED_LOCATION "${dbus_LIBRARY}"
      )

    else()
      report_not_found()
    endif()
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(dbus DEFAULT_MSG dbus_LIBRARIES dbus_INCLUDE_DIRS)

mark_as_advanced(dbus_INCLUDE_DIRS dbus_LIBRARY_DIRS dbus_LIBRARIES)