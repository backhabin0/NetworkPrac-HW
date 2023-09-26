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
    // 윈속 초기화
    WSADATA wsa;                            //데이터 구조체 선언, WIndow 소켓초기화에 필요한 정보를 저장하는데 사용

    if (WSAStartup((2 << 8) | 2, &wsa) != 0)
        return 1;
    printf("[알림] 윈속 초기화 성공\n");

    //실습Ch3_2 
    cout << "==============================================Ch3 Prac2==============================================" << endl;
    /*  --------------------
         IPv4 변환연습
      --------------------*/
    //원래의 IPv4주소 출력
    const char* ipv4test = "147.46.114.70";
    cout << "IPv4 주소(변환 전) = "<<ipv4test << endl;

    //inet_pton()함수 연습
    struct in_addr ipv4num;
    inet_pton(AF_INET, ipv4test, &ipv4num);
    printf("IPv4 주소(변환 후) = %#\n", ipv4num.s_addr);

    //inet_ntop()함수 연습
    char ipv4str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ipv4num, ipv4str, sizeof(ipv4str));
    printf("IPv4주소(다시변환 후) = %s\n", ipv4str);
    printf("\n");

    /*-----------------------
        IPv6 변환연습
    -----------------------*/

    //원래의 IPv6 주소 출력
    const char* ipv6test = "2001:0230:abcd:ffab:0023:eb00:ffff:1111";
    printf("IPv6 주소(변환전) = %s\n", ipv6test);

    //inet_pton()함수 연습
    struct in6_addr ipv6num;
    inet_pton(AF_INET6, ipv6test, &ipv6num);
    printf("IPv6 주소(변환 후) = 0x");
    for (int i = 0; i < 16; i++)
        printf("%02x", ipv6num.s6_addr[i]);
    cout << endl;

    //inet_ntop() 함수연습
    char ipv6str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &ipv6num, ipv6str, sizeof(ipv6str));
    printf("IPv6 주소 (다시 변환 후) =%s\n", ipv6str);




    cout << "===================================================================================================" << endl;




    // 소켓 생성
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) err_quit("socket()");
    printf("[알림] 소켓 생성 성공\n");
    // 소켓 닫기
    closesocket(sock);

    // 윈속 종료
    WSACleanup();
    return 0;
}