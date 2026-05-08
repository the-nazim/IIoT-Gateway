if(BUILD_DIR MATCHES "/master$")
    FILE(GLOB_RECURSE app_sources
        "${CMAKE_CURRENT_LIST_DIR}/master/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/master/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/master/*.S")
elseif(BUILD_DIR MATCHES "/slave$")
    FILE(GLOB_RECURSE app_sources
        "${CMAKE_CURRENT_LIST_DIR}/slave/*.c"
        "${CMAKE_CURRENT_LIST_DIR}/slave/*.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/slave/*.S")
else()
    message(FATAL_ERROR "Unknown PlatformIO build directory: ${BUILD_DIR}")
endif()

idf_component_register(SRCS ${app_sources})
