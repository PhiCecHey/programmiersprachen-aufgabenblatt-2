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

# Build a_2_3
add_executable(a_2_3
  a_2_3.cpp
  )

# Build a_5
add_executable(a_5
  a_5.cpp  
  vec2.cpp
  mat2.cpp
  kreis.cpp
  rechteck.cpp
  )

# Build a_8
add_executable(a_8
  a_8.cpp
  )


