cmake_minimum_required(VERSION 3.20.0)

project(cmake_demo                      # 项目名称
VERSION      1.0.0.0                    # cmake工程的版本号
# DESTINATION  "用于做cmake的实例的项目"   # 简短的描述
HOMEPAGE_URL ""                         # 主页URL
LANGUAGES    "CXX"                      # 编译工程使用的语言
)
message(STATUS "${PROJECT_NAME}")

# 设置编译模式 Debug/Release
set(CMAKE_BUILD_TYPE Debug)

# 平台位数
if(CMAKE_CL_64)
    message(STATUS "平台位数:X64")
else()
    message(STATUS "平台位数:X86")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
endif(CMAKE_CL_64)




# 对于平台的匹配
# linux平台
if(CMAKE_SYSTEM_NAME MATCHES "Linux")  # 注意区分大写
  message(STATUS "Linux platorm!")
  add_definitions(-DLINUX_PLATORM)
# windows平台
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_definitions(-DWINDOWS_PLATORM)    
    if(CMAKE_CL_64)
        add_definitions(-DWINDOWS64_PLATORM)  
        message(STATUS "Windows Win64 platform!")
    else()
        add_definitions(-DWINDOWS32_PLATORM)  
        message(STATUS "Windows Win32 platform!")
    endif(CMAKE_CL_64)
# FreeBSD平台 
elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
    add_definitions(-DFREEBSD_PLATORM)  
    message(STATUS "FreeBSD platform!")
# 其他平台
else()
    add_definitions(-DUNKNOWN_PLATORM) 
    message(STATUS "other platform!")
endif(CMAKE_SYSTEM_NAME MATCHES "Linux")


# 检查一系列变量
# 检查下 CMAKE_DEMO_HOME 用于组织bin lib include 存放目录
# 不再使用环境变量, 直接用 CMAKE_CURRENT_SOURCE_DIR 配合相对路径
# if(DEFINE ENV{CMAKE_DEMO_HOME})
#     SET(CMAKE_DEMO_BIN $ENV{CMAKE_DEMO_HOME}/bin)
#     SET(CMAKE_DEMO_LIB $ENV{CMAKE_DEMO_HOME}/lib)
# else()
#     message(FATAL_ERROR "未设置 CMAKE_DEMO_HOME")
# endif(DEFINE ENV{CMAKE_DEMO_HOME})

# 我不喜欢 bin,lib目录 与各个模块源代码目录同级,而是喜欢放在一个src下
# 当前目录作为根目录,设置bin lib include
SET(CMAKE_DEMO_HOME ${CMAKE_CURRENT_SOURCE_DIR}/..)
SET(CMAKE_DEMO_SRC ${CMAKE_DEMO_HOME}/src)
SET(CMAKE_DEMO_BIN ${CMAKE_DEMO_HOME}/bin)
SET(CMAKE_DEMO_LIB ${CMAKE_DEMO_HOME}/lib)
SET(CMAKE_DEMO_INCLUDE ${CMAKE_DEMO_SRC}/include)

add_compile_options(-std=c++11)
# debug模式后缀
set(CMAKE_DEBUG_POSTFIX "_d")

# release模式后缀,一般是不设置的
# set(CMAKE_RELEASE_POSTFIX "_r")

# 增加include目录,之后各个子目录不建议再设置,而是用全路径
include_directories(${CMAKE_DEMO_INCLUDE})


# 设置静态库文件目录
set(LIBRARY_OUTPUT_PATH                     ${CMAKE_DEMO_LIB})
# visual stdio 在debug/release模式下, bin/lib会多一层 Debug/Release文件夹, 下面用于消除这层文件夹
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG    ${CMAKE_DEMO_LIB})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE  ${CMAKE_DEMO_LIB})

# 可执行文件目录
set(EXECUTABLE_OUTPUT_PATH                   ${CMAKE_DEMO_BIN})
# visual stdio 在debug/release模式下, bin/lib会多一层 Debug/Release文件夹, 下面用于消除这层文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG     ${CMAKE_DEMO_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE   ${CMAKE_DEMO_BIN})

# 需要设置编译所用的中间文件输出路径 todo

# 给出链接库的路径, 后面各个模块就不需要再重复
link_directories( ${CMAKE_DEMO_BIN} ${CMAKE_DEMO_LIB} )
# 增加并编译子目录,放到对应目录
add_subdirectory(hellodll  )
add_subdirectory(hellomain )

