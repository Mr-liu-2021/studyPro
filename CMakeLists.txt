cmake_minimum_required(VERSION 3.17)
project(studyPro)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-static-libstdc++ -static-libgcc -static")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_WIN32_WINNT=0x0601 -DBOOST_UUID_FORCE_AUTO_LINK")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -D_WIN32_WINNT=0x0601 -DBOOST_UUID_FORCE_AUTO_LINK")
#设置大范围的目录路径
set(ROOT_DIR "D:/Soft/msys2/mingw64/")
set(TEST_INC_LIST "./test/")
#设置库的头文件路径
set(INCLUDE_DIR ${ROOT_DIR}include)
#设置自定义头文件路径
set(TEST ${TEST_INC_LIST}algorithmTest
        ${TEST_INC_LIST}jsonTest
        ${TEST_INC_LIST}streamTest
        ${TEST_INC_LIST}stringstreamTest
        ${TEST_INC_LIST}cpp11
        ${TEST_INC_LIST}testPro)

#设置自定义类文件路径
set(GET_LOG "./getLog/")
set(TIME_TOOL "./TimeTool/")


#将当前路径设为源文件路径
aux_source_directory(./ MainFile)
aux_source_directory(${TIME_TOOL} TIME)

#将此路径加入可执行源文件中
add_executable(studyPro
        ${MainFile}
        ${TIME})

#引入项目所需头文件
target_include_directories(studyPro PUBLIC
        ${INCLUDE_DIR}
        ${TEST}
        ${GET_LOG}
        ${TIME_TOOL})
#查找库文件位置
find_library(JSON_CPP jsoncpp ${ROOT_DIR}lib)

#变量打印
#MESSAGE(CRYPT "this var key = ${GET_UUID}.")
#将库文件链入项目中
target_link_libraries(studyPro ${JSON_CPP})


