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
    // ���� �ʱ�ȭ
    WSADATA wsa;                            //������ ����ü ����, WIndow �����ʱ�ȭ�� �ʿ��� ������ �����ϴµ� ���

    if (WSAStartup((2 << 8) | 2, &wsa) != 0)
        return 1;
    printf("[�˸�] ���� �ʱ�ȭ ����\n");

    //�ǽ�Ch3_3
    cout << "==============================================Ch3 Prac3==============================================" << endl;


    //hostent* a = gethostbyname(domainname);
    hostent* a = gethostbyname((argv[1]));
    if (a != NULL) {
        cout << "������ �̸� : " << a->h_name << endl;

        for (int i{}; a->h_addr_list[i] != NULL; ++i) {
            cout << "������ ip�ּ� ; " << inet_ntoa(*(struct in_addr*)a->h_addr_list[i]) << endl;
        }
        for (char** alias = a->h_aliases; *alias != NULL; alias++) {
            cout << "������ ���� : " << *alias << endl;
        }
    }
    else {
        cout << "���� ��" << endl;
    }




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