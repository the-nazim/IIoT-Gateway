# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/nazim/new_volume/esp/esp-idf/components/bootloader/subproject"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/tmp"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/src/bootloader-stamp"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/src"
  "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/nazim/new_volume/Projects/IIoT-Gateway/master-node/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
