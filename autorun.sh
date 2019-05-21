#!/bin/bash --posix

PERFIX=$(pwd)
pro_dir=$(dirname $0)
echo -en "工作目录:${PERFIX}\n"
echo -en "项目目录:${PERFIX}${pro_dir#.}\n"
echo -en "切换工作目录到项目根目录\n"
cd $(dirname $0)
echo -en "检查build目录存在性\n"
if [ -d build ]; then
	echo -en "构建目录build已存在\n正在清楚构建残余...\n"
	rm -r build/*
else
	echo -en "构建目录build不存在\n正在创建目录..."\n
	mkdir build
fi
echo -en "\t*****-----> 开始生成Makefile <-----*****\n"
cd build
cmake ../

echo -en "\t*****-----> 开始编译 <-----*****\n"
make -j9
