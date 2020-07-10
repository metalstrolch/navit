if(BUILD_MAPTOOL2)

	find_package(Protobuf-c REQUIRED)
	include_directories(${PROTOBUF-C_INCLUDE_DIR})
	include_directories(${CMAKE_CURRENT_BINARY_DIR})
	SET(NAVIT_LIBS ${NAVIT_LIBS} m)

	add_definitions( -DMODULE=maptool2 ${NAVIT_COMPILE_FLAGS})

	add_executable (maptool2 maptool2.c)
	PROTOBUF_C_GENERATE_C (PROTO_SRCS PROTO_HDRS osmformat.proto)
	PROTOBUF_C_GENERATE_C (PROTO_SRCS PROTO_HDRS fileformat.proto)
	add_library (maptool2_core itemaccess.c osm_protobuf.c)
	target_link_libraries(maptool2_core ${PROTOBUF_C_LIBRARY})
   target_sources(maptool2_core PRIVATE fileformat.pb-c.c osmformat.pb-c.c)


	target_link_libraries(maptool2 maptool2_core ${NAVIT_LIBNAME} ${NAVIT_LIBS})

	install(TARGETS maptool2
		DESTINATION ${BIN_DIR}
		PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

endif()
