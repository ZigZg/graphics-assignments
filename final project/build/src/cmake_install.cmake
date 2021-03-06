# Install script for directory: /afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst" TYPE EXECUTABLE FILES "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src/final")
  IF(EXISTS "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/inst/final")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

