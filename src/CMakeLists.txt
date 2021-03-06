FIND_PACKAGE(Qt5Multimedia)
SET(MSRC
    ${SRC_DIR}/main.cpp	
    ${SRC_DIR}/MainWindow.cpp
    ${SRC_DIR}/CentralWidget.cpp
    ${SRC_DIR}/PreferenceDialog.cpp
	${SRC_DIR}/SetTimerDialog.cpp
	${SRC_DIR}/EnumeratedTimeView.cpp
    ${SRC_DIR}/TimeData.cpp
    ${SRC_DIR}/AboutWidget.cpp
	${SRC_DIR}/xml.cpp
	)

SET(MHED
    ${SRC_DIR}/MainWindow.hpp
    ${SRC_DIR}/CentralWidget.hpp
    ${SRC_DIR}/PreferenceDialog.hpp
    ${SRC_DIR}/SetTimerDialog.hpp
	${SRC_DIR}/EnumeratedTimeView.hpp
    ${SRC_DIR}/TimeData.hpp
    ${SRC_DIR}/AboutWidget.hpp
	${SRC_DIR}/xml.hpp
    )

QT5_ADD_RESOURCES(QRC ${PROJECT_SOURCE_DIR}/src/main.qrc)
SET(SRCS ${MSRC} ${HMOD} ${QRC})
IF(WIN32)
    SET(SRCS ${SRCS} ${PROJECT_SOURCE_DIR}/src/resource/win/WinPICON.rc)
    ADD_EXECUTABLE(gat WIN32 ${SRCS})
ELSEIF(APPLE)
    SET(SRCS ${SRCS} ${PROJECT_SOURCE_DIR}/src/resource/mac/p_icon.icns)
	SET(MACOSX_BUNDLE_ICON_FILE ${PROJECT_SOURCE_DIR}/src/resource/mac/p_icon.icns)
    SET_SOURCE_FILES_PROPERTIES(p_icon.icns PROPERTIES 
	    MACOSX_PACKAGE_LOCATION Resources)
   ADD_EXECUTABLE(gat MACOSX_BUNDLE ${SRCS})
ELSEIF(UNIX AND NOT APPLE)
    ADD_EXECUTABLE(gat ${SRCS})
ENDIF()
QT5_USE_MODULES(gat Widgets Xml Multimedia)

IF(UNIX AND NOT APPLE)
    INSTALL(TARGETS gat RUNTIME DESTINATION bin)
ENDIF(UNIX AND NOT APPLE)
