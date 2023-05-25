#pragma once
class Monster
{
	// c++������ �Լ����� �װ� ���� ���α׷����� �ǵ��� �ο��Ҽ��� �ֽ��ϴ�.

	public:

		void StatusRender();
		void DamagePrint(const char* const _AttName, int _Att);
		void Damage(int _Att);
		const char* GetName();
		int GetAtt();
		bool IsDeath();

	private:
		// ĸ��ȭ
		char Name[40] = "Monster";
		int Att = 10;
		int Hp = 100;
};
