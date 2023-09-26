#include "Common.h"
bool IsLittleEndian(u_short n);
bool IsLittleEndian(u_short n)
{
    if (n != htons(n))
        return true;
    else
        return false;
}
bool isBigEndian(u_short n);
bool isBigEndian(u_short n)
{
    if (n == htons(n))
        return true;
    else
        return false;

}
int main(int argc, char* argv[])
{
    // ���� �ʱ�ȭ
    WSADATA wsa;                            //������ ����ü ����, WIndow �����ʱ�ȭ�� �ʿ��� ������ �����ϴµ� ���

    if (WSAStartup((2 << 8) | 2, &wsa) != 0)
        return 1;
    printf("[�˸�] ���� �ʱ�ȭ ����\n");

    //�ǽ�Ch3_2 
    cout << "==============================================Ch3 Prac2==============================================" << endl;
    /*  --------------------
         IPv4 ��ȯ����
      --------------------*/
    //������ IPv4�ּ� ���
    const char* ipv4test = "147.46.114.70";
    cout << "IPv4 �ּ�(��ȯ ��) = "<<ipv4test << endl;

    //inet_pton()�Լ� ����
    struct in_addr ipv4num;
    inet_pton(AF_INET, ipv4test, &ipv4num);
    printf("IPv4 �ּ�(��ȯ ��) = %#\n", ipv4num.s_addr);

    //inet_ntop()�Լ� ����
    char ipv4str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));
    printf("IPv4�ּ�(�ٽú�ȯ ��) = %s\n", ipv4str);
    printf("\n");

    /*-----------------------
        IPv6 ��ȯ����
    -----------------------*/

    //������ IPv6 �ּ� ���
    const char* ipv6test = "2001:0230:abcd:ffab:0023:eb00:ffff:1111";
    printf("IPv6 �ּ�(��ȯ��) = %s\n", ipv6test);

    //inet_pton()�Լ� ����
    struct in6_addr ipv6num;
    inet_pton(AF_INET6, ipv6test, &ipv6num);
    printf("IPv6 �ּ�(��ȯ ��) = 0x");
    for (int i = 0; i < 16; i++)
        printf("%02x", ipv6num.s6_addr[i]);
    cout << endl;

    //inet_ntop() �Լ�����
    char ipv6str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str));
    printf("IPv6 �ּ� (�ٽ� ��ȯ ��) =%s\n", ipv6str);




    cout << "===================================================================================================" << endl;




    // ���� ����
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) err_quit("socket()");
    printf("[�˸�] ���� ���� ����\n");
    // ���� �ݱ�
    closesocket(sock);

    // ���� ����
    WSACleanup();
    return 0;
}