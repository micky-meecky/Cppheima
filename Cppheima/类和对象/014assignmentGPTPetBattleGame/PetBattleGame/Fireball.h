#pragma once
#include "BaseClass.h"
#include <iostream>
#include <string>


using namespace std;

class Fireball :
    public Skill
{
public:
    // ��д����Ĺ��캯��
    Fireball(string name, string type, int damage, string description);
    ~Fireball();

    // ��д������麯��printSkill����ӡ���ܵ���Ϣ
    void printSkill();

    // ��д������麯��setName�����ü��ܵ�����
    void setName(string name);

    // ��д������麯��setType�����ü��ܵ�����
    void setType(string type);


    // ��д������麯��setDamage�����ü��ܵ��˺�ֵ
    void setDamage(int damage);

    // ��д������麯��setDescription�����ü��ܵ�����
    void setDescription(string description);


    // ��д������麯��getName����ȡ���ܵ�����
    string getName();


    // ��д������麯��getType����ȡ���ܵ�����
    string getType();


    // ��д������麯��getDamage����ȡ���ܵ��˺�ֵ
    int getDamage();


    // ��д������麯��getDescription����ȡ���ܵ�����
    string getDescription();


    // ��д������麯��printSkill����ӡ���ܵ���Ϣ
    void printSkill();

private:

};

