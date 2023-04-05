#pragma once
#include "BaseClass.h"
class pt_Dragon :
    public Pet
{
public:
    pt_Dragon(string name, string type, int HP, int MP, int ATK, int DEF, int SPD);
    ~pt_Dragon();

    // ��д������麯��printPet����ӡ�������Ϣ
    void printPet();

    // ��д������麯��setName�����ó��������
    void setName(string name);

    // ��д������麯��setType�����ó��������
    void setType(string type);

    // ��д������麯��setHP�����ó��������ֵ
    void setHP(int HP);

    // ��д������麯��setMP�����ó����ħ��ֵ
    void setMP(int MP);

    // ��д������麯��setATK�����ó���Ĺ�����
    void setATK(int ATK);

    // ��д������麯��setDEF�����ó���ķ�����
    void setDEF(int DEF);

    // ��д������麯��setSPD�����ó�����ٶ�
    void setSPD(int SPD);

    // // ��д������麯��setCRI�����ó���ı�����
    // void setCRI(int CRI);

    // // ��д������麯��setLV�����ó���ĵȼ�
    // void setLV(int LV);

    // // ��д������麯��setEXP�����ó���ľ���ֵ
    // void setEXP(int EXP);

    // // ��д������麯��setEXP_Need�����ó�����������辭��ֵ
    // void setEXP_Need(int EXP_Need);

    // ��д������麯��getName����ȡ���������
    string getName();

    // ��д������麯��getType����ȡ���������
    string getType();

    // ��д������麯��getHP����ȡ���������ֵ
    int getHP();

    // ��д������麯��getMP����ȡ�����ħ��ֵ
    int getMP();

    // ��д������麯��getATK����ȡ����Ĺ�����
    int getATK();

    // ��д������麯��getDEF����ȡ����ķ�����
    int getDEF();

    // ��д������麯��getSPD����ȡ������ٶ�
    int getSPD();

    // // ��д������麯��getCRI����ȡ����ı�����
    // int getCRI();

    // // ��д������麯��getLV����ȡ����ĵȼ�
    // int getLV();


    // // ��д������麯��getEXP����ȡ����ľ���ֵ
    // int getEXP();

    // // ��д������麯��getEXP_Need����ȡ������������辭��ֵ
    // int getEXP_Need();
    


};

