# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appRegistration_Application_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appRegistration_Application_autogen.dir/ParseCache.txt"
  "appRegistration_Application_autogen"
  )
endif()
