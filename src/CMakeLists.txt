cmake_minimum_required( VERSION 3.0.0 )
project( toynn )

include_directories(${PROJECT_SOURCE_DIR}/../include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ops/ OPSRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/core/ CORESRC)

add_library( ${PROJECT_NAME} ${OPSRC} ${CORESRC})