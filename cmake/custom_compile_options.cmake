macro(custom_compile_options)
  add_compile_options(
    "-Wall"
    "-Wextra"
    # "-Wl,-ld_classic"
    # $<$<CONFIG:DEBUG>:-Wl,-ld_classic>
    # $<$<CONFIG:RELEASE>:-Wl,-ld_classic>
    $<$<CONFIG:RELEASE>:-O2>
    $<$<CONFIG:RELEASE>:-Werror>
  )
endmacro()