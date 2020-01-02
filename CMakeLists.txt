AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/TeleNewPlayers.cpp")
AC_ADD_SCRIPT_LOADER("TeleNewPlayers" "${CMAKE_CURRENT_LIST_DIR}/src/TeleNewPlayersLoader.h")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/telenewplayers.conf.dist")