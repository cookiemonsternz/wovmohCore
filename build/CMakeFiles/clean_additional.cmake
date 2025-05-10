# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\wovmohCore_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\wovmohCore_autogen.dir\\ParseCache.txt"
  "wovmohCore_autogen"
  )
endif()
