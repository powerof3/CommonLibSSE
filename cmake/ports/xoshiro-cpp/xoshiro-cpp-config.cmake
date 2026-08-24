if(NOT TARGET xoshiro-cpp::xoshiro-cpp)
    add_library(xoshiro-cpp::xoshiro-cpp INTERFACE IMPORTED)
    set_target_properties(xoshiro-cpp::xoshiro-cpp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/../../include")
endif()
