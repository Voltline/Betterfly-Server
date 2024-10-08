cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
project(Betterfly-Server)

add_compile_options(-lpthread -lsocket -lnsl -lssl -lcrypto)


add_executable(Betterfly-Server
        main.cpp
        utils/client.cpp
        utils/server.cpp
        utils/encrypto.cpp
        utils/dbhandler.cpp
)

find_package(OpenSSL REQUIRED)

include_directories(include)
include_directories(include/spdlog)
include_directories(include/nlohmann)
include_directories(${OPENSSL_INCLUDE_DIR})
target_link_libraries(Betterfly-Server PRIVATE ${OPENSSL_LIBRARIES})
