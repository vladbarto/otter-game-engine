# Install script for directory: /Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/libs/glm-master/test

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/cmake-build-debug/libs/glm-master/test/bug/cmake_install.cmake")
  include("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/cmake-build-debug/libs/glm-master/test/core/cmake_install.cmake")
  include("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/cmake-build-debug/libs/glm-master/test/ext/cmake_install.cmake")
  include("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/cmake-build-debug/libs/glm-master/test/gtc/cmake_install.cmake")
  include("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/cmake-build-debug/libs/glm-master/test/gtx/cmake_install.cmake")

endif()

