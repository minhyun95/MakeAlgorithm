#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	unordered_map<int, string> idNames;
	// unordered_multimap = ���� Ű���̿��� �ߺ��� ����Ѵ�.

	idNames.emplace(1, "�̸�1");
	idNames.emplace(2, "�̸�2");
	idNames.emplace(3, "�̸�3");

	// �ߺ��� ����ȉ�
	idNames.emplace(1, "4");


	// [] �����ڸ� ����ϸ� replace ����
	// ���� Ű�� ����ϸ� �����Ǳ⶧���� �����ؼ� ����ؾ� �Ѵ�.
	idNames[1] = "����";



	for (const auto& idname : idNames)
	{
		cout << idname.first << " " << idname.second << endl;
	}

	return 0;
}