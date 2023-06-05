macro(include_util)
    foreach(TARGET ${ARGN})
        target_include_directories(
            ${TARGET}
            PRIVATE ${INCLUDE_SOURCE}
        )
    endforeach()
endmacro()

macro(simple_executable)
    foreach(TARGET ${ARGN})
        add_executable(
            ${TARGET}
            ${TARGET}.c
        )
    endforeach()
endmacro()