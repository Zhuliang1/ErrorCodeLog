/**
打印结果：
Success
Error code unknown
-6(Out of memory)
9(Timed out)
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_errorcode.h"
#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging
#include "spdlog/spdlog.h"
#include "spdlog/sinks/base_sink.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

using namespace spdlog;
using namespace std;


int foo()
{
    return -E_OUTOFMEM;
}

int bar()
{
    return E_TIMEOUT;
}

int main(void)
{

    // 基本输出
    spdlog::info("信息");
    spdlog::warn("警告");
    spdlog::error("错误");
    spdlog::critical("危险");
    std::cout << "\n" << std::endl;
/*
    // 带参输出
    spdlog::info("I am {} , {} years old !", "LYSM", 22);
    std::cout << "\n" << std::endl;

    // 类型转换
    spdlog::info("42 = int:{0:d}; hex:{0:x}; oct:{0:o}; bin:{0:b}", 42);
    std::cout << "\n" << std::endl;

    // 创建日志对象  
    auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");

    // 输出日志到文件
    my_logger->info("输出日志到文件");

    // 刷新，否则只有程序结束时才会把日志写入文件
    my_logger->flush();

    // 关闭日志对象
    spdlog::drop_all();*/
    //auto my_logger = spdlog::basic_logger_mt("Error Code Test", "logs/ErrorCode.txt");
    auto file_logger = spdlog::rotating_logger_mt("ErrorCodeTest", "logs/ErrorCode.txt", 1024 * 1024 * 5, 3);
    for (int i = 0; i < 28; i++)
    {
        //printf("%s\n", get_errorcode(i));
        spdlog::error("Error Code : {} , Error Info is {} !", i, get_errorcode(i));//输出到命令框
        file_logger->error("Error Code : {} , Error Info is {} !", i, get_errorcode(i));//输出到文件
        // 输出日志到文件
       // file_logger->error("输出日志到文件");
       
    }
    file_logger->flush();

    system("pause");






    //// Create a file rotating logger with 5mb size max and 3 rotated files.
    //auto rotating_logger_a = spdlog::rotating_logger_mt("log_file_a", "logs/ra.txt", 1024 * 1024 * 5, 100);

    //// testing 
    //for (int i = 0; i < 1024 ; i++)
    //{
    //    rotating_logger_a->info("index = {}", i);

    //    //cout << "index = " << i << endl;
    //}
    //spdlog::shutdown();



    //try {
    //    // create a file rotating logger with 5mb size max and 3 rotated files
    //    auto file_logger = spdlog::rotating_logger_mt("file_logger", "myfilename", 1024 * 1024 * 5, 3);
    //    for (int i = 0; i < 1024; i++)
    //        file_logger->info("This is a rotating logger: #{}", i);
    //}
    //catch (const spdlog::spdlog_ex& ex) {
    //    std::cout << "Log initialization failed: " << ex.what() << std::endl;
    //}











    return 0;
}