# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  kreis.cpp
  rechteck.cpp
  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  kreis.cpp
  rechteck.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

# Build a_2_3_9
add_executable(a_2_3_9
  a_2_3_9.cpp
  )

# Build a_5_6_7
add_executable(a_5_6_7
  a_5_6_7.cpp  
  vec2.cpp
  mat2.cpp
  kreis.cpp
  rechteck.cpp
  )

# Build a_8
add_executable(a_8
  a_8.cpp
  )

# Build a_10
add_executable(a_10
  a_10.cpp
  )

