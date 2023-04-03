#pragma once
#include <iostream>
#include <string>

using namespace std;


// ���һ��Skill�࣬�����������Ժͷ�����
// 	���ԣ����֡����͡��˺�ֵ���������������Ͱ���������������������
//  type�� attack��defense��support
// 	���������캯����������������ȡ���������Է�������ӡ�������Է���

class Skill	//������
{
	friend class Fireball;	//Fireball����Skill�����Ԫ��, ��ΪFireball������printSkill()������Ҫ����Skill���˽������
	friend class WaterShield;	//WaterShield����Skill�����Ԫ��, ��ΪWaterShield������printSkill()������Ҫ����Skill���˽������
	friend class Heal;	//Heal����Skill�����Ԫ��, ��ΪHeal������printSkill()������Ҫ����Skill���˽������

public:
	//���캯��������
	//���캯���Ĳ����� name type damage description�ֱ��ʾ���ܵ����֡����͡��˺�ֵ����������
	Skill(string name, string type, int damage, string description, int priority);
	//��������������
	~Skill();

	//��ȡ���������Է���������
	virtual	void setName(string name) = 0;
	virtual void setType(string type) = 0;
	virtual void setDamage(int damage) = 0;
	virtual void setDescription(string description) = 0;
	virtual void setPriority(int priority) = 0;

	//��ȡ���Է���������
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int getDamage() = 0;
	virtual string getDescription() = 0;
	virtual int getPriority() = 0;
	virtual void printSkill() = 0;
private:
	//���Ե�����
	string name;
	string type;
	int damage;
	string description;
	int priority;

};

// Pet ��
// ���һ��Pet�࣬�����������Ժͷ�����
// ���ԣ����֡����ࡢ����ֵ�������������������ٶ�
// ���������캯����������������ȡ���������Է�������ӡ�������Է���
class Pet
{
	friend class Battle; // Battle����Pet�����Ԫ��, ��ΪBattle������startBattle()������Ҫ����Pet���˽������

public:
	//���캯��������
	//���캯���Ĳ����� name type hp attack defense speed�ֱ��ʾ��������֡����ࡢ����ֵ�������������������ٶ�
	Pet(string name, string type, int hp, int attack, int defense, int speed);
	//��������������
	~Pet();

	//��ȡ���������Է���������
	virtual void setName(string name) = 0;
	virtual void setType(string type) = 0;
	virtual void setHp(int hp) = 0;
	virtual void setAttack(int attack) = 0;
	virtual void setDefense(int defense) = 0;
	virtual void setSpeed(int speed) = 0;

	//��ȡ���Է���������
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int getHp() = 0;
	virtual int getAttack() = 0;
	virtual int getDefense() = 0;
	virtual int getSpeed() = 0;
	virtual void printPet() = 0;
private:
	//���Ե�����
	string name;
	string type;
	int hp;
	int attack;
	int defense;
	int speed;
};

// ���һ��Battle�࣬ʵ�ֳ����ս�����ܣ������������Ժͷ�����
// 	���ԣ����ӵ�еĳ������顢��ǰ�����š�ս���غ���
// 	���������캯����������������ӳ��﷽����ɾ�����﷽����ѡ��ǰ���﷽������ȡ��ǰ���﷽��������ս������
class Battle
{
public:
	//���캯��������
	Battle();
	//��������������
	~Battle();

	//��ӳ��﷽��������
	void addPet(Pet* pet);
	//ɾ�����﷽��������
	void deletePet(int index);
	//ѡ��ǰ���﷽��������
	void selectPet(int index);
	//��ȡ��ǰ���﷽��������
	Pet* getCurrentPet();
	//����ս������������
	void startBattle();
private:
	//���Ե�����
	Pet* pets[10];	//���ӵ�еĳ�������
	int currentPetIndex;	//��ǰ������
	int round;	//ս���غ���
};

