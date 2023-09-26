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

    if (WSAStartup((2<<8)|2, &wsa) != 0)    
        return 1;
    printf("[알림] 윈속 초기화 성공\n");

    ////실습Ch3_2 
    //cout << "==============================================Ch3 Prac2=============================================="<<endl;
    //u_short x1 = 0x1234;
    //u_long y1 = 0x12345678;
    //u_short x2;
    //u_long y2;
    //

    ////호스트 바이트 -> 네트워크 바이트 
    //printf("[호스트 바이트 -> 네트워크 바이트]\n");
    //printf("%#x->%#x\n", x1, x2 = htons(x1));
    //printf("%#x->%#x\n", y1, y2 = htons(y1));

    ////네트워크 바이트 -> 호스트 바이트 
    //printf("[네트워크 바이트 -> 호스트 바이트]\n");

    //printf("%#x-> %#x\n", x2, ntohs(x2));
    //printf("%#x-> %#x\n", y2, ntohs(y2));
    //cout << "===================================================================================================" << endl;
     
     
    
    ////과제1
    //cout << "==============================================과제 1==============================================" << endl;
    //cout << wsa.wVersion << endl;
    //cout << wsa.wHighVersion << endl;
   
    ////LOBYTE - Window API에서 제공하는 매크로
    //// 16비트 값을 조작하여 해당 값의 하위 바이트를 추출
    //cout << (int)LOBYTE(wsa.wVersion)<<"."<<(int)HIBYTE(wsa.wVersion) << endl;

    ////HIBYTE - Window API에서 제공하는 매크로
    //// 16비트 값을 조작하여 해당 값의 상위 바이트를 추출
    //cout << (int)LOBYTE(wsa.wHighVersion)<<"."<<(int)HIBYTE(wsa.wHighVersion) << endl;


    //cout << wsa.szDescription << endl;
    //cout << wsa.szSystemStatus << endl;  
    //
    //cout << "=================================================================================================" << endl;





    //과제2
    cout << "==============================================과제 2==============================================" << endl;
    u_short n = 0x1234;
    cout << "IsLittleEndian : " <<IsLittleEndian(n) << endl;
    cout << "IsBigEndian : " << isBigEndian(n) << endl;
    cout << "==================================================================================================" << endl;
   
   


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