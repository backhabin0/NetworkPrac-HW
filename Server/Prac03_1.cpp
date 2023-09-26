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
      cout << "==============================================Ch3 Prac2=============================================="<<endl;
      u_short x1 = 0x1234;
      u_long y1 = 0x12345678;
      u_short x2;
      u_long y2;
      

      //ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ 
      printf("[ȣ��Ʈ ����Ʈ -> ��Ʈ��ũ ����Ʈ]\n");
      printf("%#x->%#x\n", x1, x2 = htons(x1));
      printf("%#x->%#x\n", y1, y2 = htons(y1));

      //��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ 
      printf("[��Ʈ��ũ ����Ʈ -> ȣ��Ʈ ����Ʈ]\n");

      printf("%#x-> %#x\n", x2, ntohs(x2));
      printf("%#x-> %#x\n", y2, ntohs(y2));
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