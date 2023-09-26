#include "Common.h"
#define TESTNAME "www.google.com"
bool GetIPAddr(const char* name, struct in_addr* addr)
{
    struct hostent* ptr = gethostbyname(name);
    if (ptr == NULL) {
        err_display("gethostbyname()");
        return false;
    }
    if (ptr->h_addrtype != AF_INET)
        return false;
    memcpy(addr, ptr->h_addr, ptr->h_length);
    return true;
}
bool GetDomainName(struct in_addr addr, char* name, int namelen)
{
    struct hostent* ptr = gethostbyaddr((const char*)&addr,
        sizeof(addr), AF_INET);
    if (ptr == NULL) {
        err_display("gethostbyaddr()");
        return false;
    }
    if (ptr->h_addrtype != AF_INET)
        return false;
    strncpy(name, ptr->h_name, namelen);
    return true;

}
int main(int argc, char* argv[])
{
    // 윈속 초기화
    WSADATA wsa;                            //데이터 구조체 선언, WIndow 소켓초기화에 필요한 정보를 저장하는데 사용

    if (WSAStartup((2 << 8) | 2, &wsa) != 0)
        return 1;
    printf("[알림] 윈속 초기화 성공\n");

    //실습Ch3_3
    cout << "==============================================Ch3 Prac3==============================================" << endl;
    printf("도메인 이름(변환 전) = %s\n", TESTNAME);

    struct in_addr addr;
    if (GetIPAddr(TESTNAME, &addr)) {
        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr, str, sizeof(str));
        printf("IP주소(변환 후) = %s\n", str);

        char name[256];
        if (GetDomainName(addr, name, sizeof(name))) {
            printf("도메인 이름(다시변환 후 )=%s\n", name);
        }
    }
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