cmake_minimum_required(VERSION 3.20.0)

project(hellomain                      # 项目名称
VERSION      1.0.0.0                    # cmake工程的版本号
DESCRIPTION  "cmake的实例的exe项目"       # 简短的描述
LANGUAGES    "CXX"                      # 编译工程使用的语言
)
message(STATUS "${PROJECT_NAME}")

set(source_code_list
main.cpp
)
add_executable(${PROJECT_NAME}  ${source_code_list})

# 增加依赖库,必须放在add_library, add_executable语句的后面
target_link_libraries(${PROJECT_NAME} hellodll)
target_link_libraries(${PROJECT_NAME} cexportdemodll)
