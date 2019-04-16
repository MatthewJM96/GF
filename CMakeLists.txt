cmake_minimum_required(VERSION 3.1)

# Make sure we aren't cluttering the source folder.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Don't run cmake inside the source folder!\nMake a 'build' folder and run from there.")
endif()

# Project name.
project(Gnome_Fortress)

# Set up compiler environment
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set up flags for g++ and clang compilers.
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # Specify options that can be modified on each build.
    option(TARGET_X64 "Should we target 64-bit architecture? If not we taget 32-bit." Off)
    option(USING_GDB "Are we using gdb to debug?" On)
    option(EXTRA_DEBUG "Should we add extra debug symbols?" On)
    option(OPTIMISE_ON_DEBUG "Should we optimise a debug target?" On)

    # Add a whole bunch of warnings and specify the standard to compile against.
    # Further, ensure that warnings are treated as errors.
    set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wshadow -Wformat=2 -std=c17")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wold-style-cast -Wshadow -Wformat=2 -std=c++17")
    # Add some warnings that are only supported by one of g++ or clang.
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wduplicated-cond")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wduplicated-cond -Wuseless-cast")
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wused-but-marked-unused")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wused-but-marked-unused")
    endif()

    # Set the appropriate optimisation and debug symbol flags depending on options chosen and if we are in release or debug mode.
    set(CMAKE_C_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    if (${USING_GDB})
        if (${EXTRA_DEBUG})
            set(CMAKE_C_FLAGS_DEBUG "-ggdb3")
            set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")
        else()
            set(CMAKE_C_FLAGS_DEBUG "-ggdb")
            set(CMAKE_CXX_FLAGS_DEBUG "-ggdb")
        endif()
    else()
        if (${EXTRA_DEBUG})
            set(CMAKE_C_FLAGS_DEBUG "-g3")
            set(CMAKE_CXX_FLAGS_DEBUG "-g3")
        else()
            set(CMAKE_C_FLAGS_DEBUG "-g")
            set(CMAKE_CXX_FLAGS_DEBUG "-g")
        endif()
    endif ()
    if (${OPTIMISE_ON_DEBUG})
        # This is supported by both Clang and GCC as long as we are up-to-date.
        # Should be fine going back as far as Ubuntu 17.10, and deffo fine on Arch.
        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Og")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og")
    endif()

#    if (${TARGET_X64})
#        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")
#    else()
#        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
#    endif()
# Set up flags for MSVC.
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # Warn on (nearly) everything, treat warnings as errors, use the most portable exception handling model.
    set(CMAKE_CXX_FLAGS "/W4 /WX /wd4201 /EHsc")

    # Set optimisation flags for release and debug modes.
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi")
endif()

# Add directories for compiler to search for included files.
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/deps/includes")

# List the headers and sources created for the project.
set(GF_headers
    include/common.hpp
    include/definitions.h
    include/stdafx.h
    include/types.h
)

set(GF_src
    src/main.cpp
)

set(GF_AGI_Character_headers
    include/agi/character/action_marshaller.h
    include/agi/character/desire_marshaller.h
    include/agi/character/registrar.h
    include/agi/character/risk.h
    include/agi/character/component/actions.hpp
    include/agi/character/component/capabilities.hpp
    include/agi/character/component/desires.hpp
    include/agi/character/component/duties.hpp
    include/agi/character/component/needs.hpp
    include/agi/character/component/org_memberships.hpp
    include/agi/character/component/personality.hpp
    include/agi/character/component/risks.hpp
    include/agi/character/component/schedule.hpp
)

set(GF_AGI_Character_src
    src/agi/character/desire_marshaller.cpp
    src/agi/character/registrar.cpp
    src/agi/character/risk_marshaller.cpp
)

set(GF_AGI_Org_headers
    include/agi/org/builder.h
    include/agi/org/registrar.h
    include/agi/org/component/members.hpp
    include/agi/org/component/org_data.hpp
)

set(GF_AGI_Org_src
    src/agi/org/builder.cpp
    src/agi/org/registrar.cpp
)

set(GF_World_headers
    include/world/inhabitants.h
)

set(GF_World_src
    src/world/inhabitants.cpp
)

set(GF_Physics_headers
    include/physics/component/position.hpp
)

set(GF_Utils
    include/utils/bounded_priority_queue.hpp
)

# Add an executable to be compiled and linked.
add_executable(Gnome_Fortress
    ${GF_headers}
    ${GF_src}
    ${GF_AGI_Character_headers}
    ${GF_AGI_Character_src}
    ${GF_AGI_Org_headers}
    ${GF_AGI_Org_src}
    ${GF_Physics_headers}
    ${GF_World_headers}
    ${GF_World_src}
    ${GF_Utils}
)

#target_link_libraries(
#    Gnome_Fortress
#    
#)