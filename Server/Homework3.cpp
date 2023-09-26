#include "Common.h"
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


    //hostent* a = gethostbyname(domainname);
    hostent* a = gethostbyname((argv[1]));
    if (a != NULL) {
        cout << "도메인 이름 : " << a->h_name << endl;

        for (int i{}; a->h_addr_list[i] != NULL; ++i) {
            cout << "도메인 ip주소 ; " << inet_ntoa(*(struct in_addr*)a->h_addr_list[i]) << endl;
        }
        for (char** alias = a->h_aliases; *alias != NULL; alias++) {
            cout << "도메인 별명 : " << *alias << endl;
        }
    }
    else {
        cout << "정보 없" << endl;
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