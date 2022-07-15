cmake_minimum_required(VERSION 3.20.0)

project(cexportdemodll               # 项目名称
VERSION      1.0.0.0                 # cmake工程的版本号
DESCRIPTION  "用于展示c语言接口导出"   # 简短的描述
LANGUAGES    "C"                   # 编译工程使用的语言
)
message(STATUS "${PROJECT_NAME}")

# 源码加dll定义
add_definitions(-DCEXPORTDEMODLL_DLL)

# 设置源码列表
set(source_code_list
ctooldemo.cpp 
${CMAKE_DEMO_INCLUDE}/cexportdemodll/ctooldemo.h
${CMAKE_DEMO_INCLUDE}/cexportdemodll/cexportdemodll_exportdef.h
) 

# 已经 set(BUILD_SHARED_LIBS ON) 默认生成动态库了 
# add_library(${PROJECT_NAME} SHARED ${source_code_list}) 
add_library(${PROJECT_NAME}  ${source_code_list}) 
