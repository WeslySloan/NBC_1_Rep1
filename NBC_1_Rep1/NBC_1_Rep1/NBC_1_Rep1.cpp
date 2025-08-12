#include <iostream>
using namespace std;

// 포션 개수를 포인터로 설정
void setPotion(int count, int* hpPotion, int* mpPotion) {
    *hpPotion = count;
    *mpPotion = count;
}

int main() {
    int status[4] = { 0 }; // 0: HP, 1: MP, 2: 공격력, 3: 방어력
    int hpPotion, mpPotion;
    int choice;

    // HP, MP 입력 (둘 다 50 초과)
    while (true) {
        cout << "\nHP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) 
            break;
        cout << "HP와 MP는 모두 50 초과여야 합니다.\n";
    }

    // 공격력, 방어력 입력 (둘 다 0 초과)
    while (true) {
        cout << "\n공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) 
            break;
        cout << "공격력과 방어력은 모두 0 초과여야 합니다.\n";
    }

    // 포션 지급
    setPotion(5, &hpPotion, &mpPotion);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";

    // 스탯 관리 시스템
    while (true) {
        cout << "\n<스탯 관리 시스템>\n";
        cout << "1. HP 회복\n";
        cout << "2. MP 회복\n";
        cout << "3. HP 강화\n";
        cout << "4. MP 강화\n";
        cout << "5. 공격 스킬 사용\n";
        cout << "번호를 선택해주세요: ";
        cin >> choice;

        if (choice == 1) {
            if (hpPotion > 0) {
                status[0] += 20;
                hpPotion--;
                cout << "* HP가 20 회복되었습니다. 남은 HP 포션: " << hpPotion << "\n";
            }
            else {
                cout << "HP 포션이 없습니다.\n";
            }
        }
        else if (choice == 2) {
            if (mpPotion > 0) {
                status[1] += 20;
                mpPotion--;
                cout << "* MP가 20 회복되었습니다. 남은 MP 포션: " << mpPotion << "\n";
            }
            else {
                cout << "MP 포션이 없습니다.\n";
            }
        }
        else if (choice == 3) {
            status[0] *= 2;
            cout << "* HP가 2배로 증가되었습니다. 현재 HP: " << status[0] << "\n";
        }
        else if (choice == 4) {
            status[1] *= 2;
            cout << "* MP가 2배로 증가되었습니다. 현재 MP: " << status[1] << "\n";
        }
        else if (choice == 5) {
            if (status[1] >= 50) {
                status[1] -= 50;
                cout << "* 스킬 사용! MP가 50 소모되었습니다. 현재 MP: " << status[1] << "\n";
            }
            else {
                cout << "MP가 부족합니다.\n";
            }
        }
        else {
            cout << "잘못된 입력입니다.\n";
        }
    }

    return 0;
}
