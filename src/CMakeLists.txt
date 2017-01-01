# set(src_srcs )
# add_library(cpp_src ${src_srcs})
# install(TARGETS cpp_src DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/src)

add_subdirectory(test)
