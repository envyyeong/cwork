#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "int4.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"

int main()
{
    ConsoleScreen Screen;  // ConsoleScreen의 객체 Screen 생성
    Screen.Init('*');  // 받은 인자를 기본 부호 형식으로 지정

    Player MainPlayer;  // Player의 객체 MainPlayer 생성
    MainPlayer.SetPos({ 10, 5 });  // MainPlayer의 위치 등록

    Wall dwall[5];  //  Wall의 객체 dwall 5개 생성
    dwall[0].SetPos({ 1,2 });  // dwall 1번쨰의 1,2 위치 세팅
    dwall[1].SetPos({ 4,9 });  // dwall 2번쨰의 4,9 위치 세팅
    dwall[2].SetPos({ 5,7 });  // dwall 3번쨰의 1,2 위치 세팅
    dwall[3].SetPos({ 8,1 });  // dwall 4번쨰의 1,2 위치 세팅
    dwall[4].SetPos({ 9,3 });  // dwall 5번쨰의 1,2 위치 세팅

    while (true)
    {
        Screen.Clear();  // 스크린을 초기화 후 세팅
        Screen.SetPixel(MainPlayer.GetPos(), 'a');  // 객체 Mainplayer에 a문자형태 생성

        for (int i = 0; i < 5; ++i)  // 객체 dwall c문자형태 5개 생성
        {
            if (dwall[i].Getalive() == true)
            {
                Screen.SetPixel(dwall[i].GetPos(), 'c');  // 객체 dwall i번지마다 c문자형태 생성
            }
        }
        
        if(MainPlayer.Fire == true)  // 객체 MainPlayer의 Fire가 true이면
        { 
            MainPlayer.SetBulletPos();  // Mainplayer객체에 세팅
            int4 Pos = MainPlayer.getBulletPos();
            Screen.SetPixel(Pos, '-');
        }
        
        int4 Bpos = MainPlayer.getBulletPos();
        // x == -1, y == 5
        if (0 > Bpos.X)
        {
            MainPlayer.Fire = false;
        }

        if (0 > Bpos.Y)
        {
            MainPlayer.Fire = false;
        }

        if (int4::XLine <= Bpos.X) 
        {
            MainPlayer.Fire = false;
        }

        if (int4::YLine <= Bpos.Y)
        {
            MainPlayer.Fire = false;
        }
        for (int i = 0; i < 5; ++i) {
            int4 test1 = Bpos;
            int4 test2 = dwall[i].GetPos();
            if ((Bpos) == dwall[i].GetPos())
            {
                MainPlayer.Fire = false;
                //Screen.SetPixel(dwall->GetPos(), '*');
                dwall[i].Setalive(false);
            }
        }

        for (int i = 0; i < 5; ++i)
        {
            if (dwall[i].IsCrashed(MainPlayer.GetPos()))
            {
                MainPlayer.AddPos(MainPlayer.RevDirection());
            }
        }

        Screen.Print();

        if (0 != _kbhit())
        {
            MainPlayer.Input(&Screen);
        }

        Sleep(200);

    }

    Screen.Print();
}