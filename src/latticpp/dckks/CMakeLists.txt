# SPDX-License-Identifier: Apache-2.0

target_sources(latticpp_obj
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/keygen.cpp
)

install(
    FILES
        ${CMAKE_CURRENT_LIST_DIR}/keygen.h
    DESTINATION
        ${LATTICPP_INCLUDES_INSTALL_DIR}/dckks
)
