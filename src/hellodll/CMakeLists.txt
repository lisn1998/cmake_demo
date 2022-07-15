cmake_minimum_required(VERSION 3.20.0)

project(hellodll                      # 项目名称
VERSION      1.0.0.0                    # cmake工程的版本号
DESCRIPTION  "cmake的实例的dll项目"   # 简短的描述
LANGUAGES    "CXX"                      # 编译工程使用的语言
)
message(STATUS "${PROJECT_NAME}")

# 源码加dll定义
add_definitions(-DHELLO_DLL)

# 设置源码列表
set(source_code_list
hellofun.cpp 
${CMAKE_DEMO_INCLUDE}/hellodll/hellofun.h
${CMAKE_DEMO_INCLUDE}/hellodll/hello_exportdef.h
) 

# 已经 set(BUILD_SHARED_LIBS ON) 默认生成动态库了 
# add_library(${PROJECT_NAME} SHARED ${source_code_list}) 
add_library(${PROJECT_NAME}  ${source_code_list}) 
