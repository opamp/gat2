
SET(MSRC
	${SRC_DIR}/main.cpp	
	${SRC_DIR}/mainwindow.cpp
	${SRC_DIR}/mainwid.cpp
	${SRC_DIR}/timer.cpp
	)

SET(MHED
	${SRC_DIR}/mainwindow.hpp
	${SRC_DIR}/mainwid.hpp
	${SRC_DIR}/timer.hpp
	)

QT4_WRAP_CPP(HMOD ${MHED})

ADD_DEFINITIONS(${QT_DEFINITIONS})
INCLUDE(${QT_USE_FILE})

ADD_EXECUTABLE(gat ${MSRC} ${HMOD})
TARGET_LINK_LIBRARIES(gat ${QT_LIBRARIES})

