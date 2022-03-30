#pragma once
/**
 * @file   my_errorcode.h
 * @author Late Lee
 * @date   2018.9.1
 *
 * @brief
 *         ͨ�ô����붨�弰ʵ��
 *
 * @note
 *         1���������0��ʼ���㣬˳����ӡ�
 *         2��ʵ��ʹ��ʱ����E_OK�⣬����������Ǹ���(��Ҫ�ֹ����'-')��Ҳ������������
 *         3��������������κ����֣�������ö��֮������ʾδ֪�����롣
 *
 * @log
 *
 */
#ifndef _MY_ERRORCODE_H
#define _MY_ERRORCODE_H

enum errorcode {
    E_OK = 0,         ///< �ɹ�
    E_FAIL,           ///< һ���Դ���
    E_INNER,          ///< �ڲ�����һ����ͬһ��ģ����ʹ�ã������⹫��
    E_POINTER,        ///< �Ƿ�ָ��
    E_INVALARG,       ///< �Ƿ�����
    E_NOTIMPL = 5,    ///< ����δʵ��
    E_OUTOFMEM,       ///< �ڴ�����ʧ��/�ڴ治��
    E_BUFERROR,       ///< ���������󣨲��㣬���ң�
    E_PERM,           ///< Ȩ�޲��㣬����δ��Ȩ�Ķ���
    E_TIMEOUT,        ///< ��ʱ
    E_NOTINIT = 10,        ///< δ��ʼ��
    E_INITFAIL,       ///< ��ʼ��ʧ��
    E_ALREADY,        ///< �ѳ�ʼ�����Ѿ�������
    E_INPROGRESS,     ///< �������С�����״̬
    E_EXIST,          ///< ������Դ����(���ļ���Ŀ¼)�Ѵ���
    E_NOTEXIST,       ///< ��Դ����(���ļ���Ŀ¼)������豸�Ȳ�����
    E_BUSY,           ///< �豸����Դæ����Դ�����ã�
    E_FULL,           ///< �豸/��Դ����
    E_EMPTY,          ///< ����/�ڴ�/����Ϊ��
    E_OPENFAIL,       ///< ��Դ����(���ļ���Ŀ¼��socket)��ʧ��
    E_READFAIL,       ///< ��Դ����(���ļ���Ŀ¼��socket)��ȡ������ʧ��
    E_WRITEFAIL,      ///< ��Դ����(���ļ���Ŀ¼��socket)д�롢����ʧ��
    E_DELFAIL,        ///< ��Դ����(���ļ���Ŀ¼��socket)ɾ�����ر�ʧ��
    E_CODECFAIL,      ///< �ӽ��ܡ��������ʧ��
    E_CRC_FAIL,       ///< crcУ�����
    E_TOOMANY,        ///< ��Ϣ��������������̫��
    E_TOOSMALL,       ///< ��Ϣ��������������̫��
    E_NETNOTREACH,    ///< ���粻�ɴ��·�ɣ����ش���
    E_NETDOWN,        ///< ���粻���ã�������

    // more...

    E_END,            ///< ռλ����ʵ������
};

const char* get_errorcode(int ec);
#endif