SET(MSRC
    ${SRC_DIR}/main.cpp	
    ${SRC_DIR}/mainwindow.cpp
    ${SRC_DIR}/mainwid.cpp
    ${SRC_DIR}/customCounter.cpp
    ${SRC_DIR}/countdown_setting.cpp
    ${SRC_DIR}/count_time_data.cpp
    ${SRC_DIR}/countup_box.cpp
    ${SRC_DIR}/config_dialog.cpp
	)

SET(MHED
    ${SRC_DIR}/mainwindow.hpp
    ${SRC_DIR}/mainwid.hpp
    ${SRC_DIR}/customCounter.hpp
    ${SRC_DIR}/countdown_setting.hpp
    ${SRC_DIR}/count_time_data.hpp
    ${SRC_DIR}/countup_box.hpp
    ${SRC_DIR}/config_dialog.hpp
    )

QT4_WRAP_CPP(HMOD ${MHED})

QT4_ADD_RESOURCES(QRC ${PROJECT_SOURCE_DIR}/src/main.qrc)
ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_PHONON_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

IF(WIN32)
    ADD_EXECUTABLE(gat WIN32 ${MSRC} ${HMOD} ${QRC})
ELSEIF(APPLE)
    ADD_EXECUTABLE(gat MACOSX_BUNDLE ${MSRC} ${HMOD} ${QRC})
ELSEIF(UNIX AND NOT APPLE)
    ADD_EXECUTABLE(gat ${MSRC} ${HMOD} ${QRC})
    INSTALL(TARGETS gat RUNTIME DESTINATION bin)
ENDIF()
TARGET_LINK_LIBRARIES(gat ${QT_LIBRARIES} ${QT_PHONON_LIBRARY} ${QT_QTXML_LIBRARY})
