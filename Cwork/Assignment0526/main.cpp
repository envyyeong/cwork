#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "int4.h"
#include "ConsoleScreen.h"
#include "Player.h"
#include "Wall.h"

int main()
{
    ConsoleScreen Screen;  // ConsoleScreen�� ��ü Screen ����
    Screen.Init('*');  // ���� ���ڸ� �⺻ ��ȣ �������� ����

    Player MainPlayer;  // Player�� ��ü MainPlayer ����
    MainPlayer.SetPos({ 10, 5 });  // MainPlayer�� ��ġ ���

    Wall dwall[5];  //  Wall�� ��ü dwall 5�� ����
    dwall[0].SetPos({ 1,2 });  // dwall 1������ 1,2 ��ġ ����
    dwall[1].SetPos({ 4,9 });  // dwall 2������ 4,9 ��ġ ����
    dwall[2].SetPos({ 5,7 });  // dwall 3������ 1,2 ��ġ ����
    dwall[3].SetPos({ 8,1 });  // dwall 4������ 1,2 ��ġ ����
    dwall[4].SetPos({ 9,3 });  // dwall 5������ 1,2 ��ġ ����

    while (true)
    {
        Screen.Clear();  // ��ũ���� �ʱ�ȭ �� ����
        Screen.SetPixel(MainPlayer.GetPos(), 'a');  // ��ü Mainplayer�� a�������� ����

        for (int i = 0; i < 5; ++i)  // ��ü dwall c�������� 5�� ����
        {
            if (dwall[i].Getalive() == true)
            {
                Screen.SetPixel(dwall[i].GetPos(), 'c');  // ��ü dwall i�������� c�������� ����
            }
        }
        
        if(MainPlayer.Fire == true)  // ��ü MainPlayer�� Fire�� true�̸�
        { 
            MainPlayer.SetBulletPos();  // Mainplayer��ü�� ����
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