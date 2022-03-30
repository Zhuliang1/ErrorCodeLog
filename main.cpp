/**
��ӡ�����
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

    // �������
    spdlog::info("��Ϣ");
    spdlog::warn("����");
    spdlog::error("����");
    spdlog::critical("Σ��");
    std::cout << "\n" << std::endl;
/*
    // �������
    spdlog::info("I am {} , {} years old !", "LYSM", 22);
    std::cout << "\n" << std::endl;

    // ����ת��
    spdlog::info("42 = int:{0:d}; hex:{0:x}; oct:{0:o}; bin:{0:b}", 42);
    std::cout << "\n" << std::endl;

    // ������־����  
    auto my_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");

    // �����־���ļ�
    my_logger->info("�����־���ļ�");

    // ˢ�£�����ֻ�г������ʱ�Ż����־д���ļ�
    my_logger->flush();

    // �ر���־����
    spdlog::drop_all();*/
    //auto my_logger = spdlog::basic_logger_mt("Error Code Test", "logs/ErrorCode.txt");
    auto file_logger = spdlog::rotating_logger_mt("ErrorCodeTest", "logs/ErrorCode.txt", 1024 * 1024 * 5, 3);
    for (int i = 0; i < 28; i++)
    {
        //printf("%s\n", get_errorcode(i));
        spdlog::error("Error Code : {} , Error Info is {} !", i, get_errorcode(i));//����������
        file_logger->error("Error Code : {} , Error Info is {} !", i, get_errorcode(i));//������ļ�
        // �����־���ļ�
       // file_logger->error("�����־���ļ�");
       
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