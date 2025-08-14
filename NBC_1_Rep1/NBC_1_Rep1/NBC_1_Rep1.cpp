#include <iostream>
using namespace std;

void setPotion(int count, int* hpPotion, int* mpPotion) {
    *hpPotion = count;
    *mpPotion = count;
}

class Player
{
private:
    int status[4] = { 0 }; // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int hpPotion;
    int mpPotion;

public:
    Player() {
        for (int i = 0; i < 4; i++) status[i] = 0;
        hpPotion = mpPotion = 0;
    }

    void inputStatus() 
    {
        // HP & MP 입력 (50 이하 입력 불가)
        while (true) 
        {
            cout << "HP와 MP를 입력해주세요: ";
            cin >> status[0] >> status[1];
            if (status[0] > 50 && status[1] > 50) break;
            cout << "HP와 MP는 모두 50 초과여야 합니다. 다시 입력해주세요.\n";
        }

        // 공격력 & 방어력 입력 (0 이하 입력 불가)
        while (true) 
        {
            cout << "공격력과 방어력을 입력해주세요: ";
            cin >> status[2] >> status[3];
            if (status[2] > 0 && status[3] > 0) break;
            cout << "공격력과 방어력은 모두 0 초과여야 합니다. 다시 입력해주세요.\n";
        }
    }

    void givePotion(int count) 
    {
        setPotion(count, &hpPotion, &mpPotion);
        cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)\n";
    }

    void recoverHP() 
    {
        if (hpPotion > 0) 
        {
            status[0] += 20;
            hpPotion--;
            cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
            cout << "현재 HP: " << status[0] << "\n";
            cout << "남은 포션 수: " << hpPotion << "\n";
        }
        else 
        {
            cout << "HP 포션이 없습니다!\n";
        }
    }

    void recoverMP() 
    {
        if (mpPotion > 0) 
        {
            status[1] += 20;
            mpPotion--;
            cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
            cout << "현재 MP: " << status[1] << "\n";
            cout << "남은 포션 수: " << mpPotion << "\n";
        }
        else 
        {
            cout << "MP 포션이 없습니다!\n";
        }
    }

    void upgradeHP() 
    {
        status[0] *= 2; // 2배 증가
        cout << "* HP가 2배로 증가되었습니다.\n";
        cout << "현재 HP: " << status[0] << "\n";
    }

    void upgradeMP() 
    {
        status[1] *= 2; // 2배 증가
        cout << "* MP가 2배로 증가되었습니다.\n";
        cout << "현재 MP: " << status[1] << "\n";
    }

    void useSkill() 
    {
        if (status[1] >= 50) 
        {
            status[1] -= 50;
            cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n";
            cout << "현재 MP: " << status[1] << "\n";
        }
        else 
        {
            cout << "MP가 부족합니다!\n";
        }
    }

    void useUlt()
    {
        if (status[1] >= 0)
        {
            status[1] = status[1]/2;
            cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.\n";
            cout << "현재 MP: " << status[1] << "\n";
        }
        else
        {
            cout << "MP가 부족합니다!\n";
        }
    }

    void Exit()
    {
        exit(0);
    }

    // 메뉴 실행
    void startSystem() {
        int choice;
        cout << "=============================================\n";
        cout << "<스탯 관리 시스템>\n";
        cout << "1. HP 회복\n";
        cout << "2. MP 회복\n";
        cout << "3. HP 강화\n";
        cout << "4. MP 강화\n";
        cout << "5. 공격 스킬 사용\n";
        cout << "6. 필살기 사용\n";
        cout << "7. 나가기\n";

        while (true) {
            cout << "번호를 선택해주세요: ";
            cin >> choice;

            switch (choice) {
            case 1: recoverHP(); break;
            case 2: recoverMP(); break;
            case 3: upgradeHP(); break;
            case 4: upgradeMP(); break;
            case 5: useSkill(); break;
            case 6: useUlt(); break;
            case 7: Exit(); break;
            default:
                cout << "잘못된 입력입니다. 종료합니다.\n";
                return;
            }
        }
    }
};

int main() 
{
    Player player;
    player.inputStatus();  // 초기 스탯 입력
    player.givePotion(5); // 포션 지급
    player.startSystem(); // 스탯 관리 시스템 시작

}
