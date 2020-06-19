#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef struct { //��ǰ ���� ����ü
	string name; //��ǰ��
	int price; //����
	int amount; //��� ����
	int sales_rate; //���� �Ǹŷ�

} Product;

typedef struct { //�� ����Ʈ ����ü
	string name; //����
	int point; //����Ʈ
	int number; //��ȭ��ȣ
} Customer;

class Base {
public:
	int return_int(int min, int max); //int�� ���� ��ȯ�ϴ� �Լ�
};


class Store : public Base { //���� Ŭ���� (���,�Ǹ� ������) 
public:
	void Receiving(); //��ǰ �԰� ���
	void CheckProduct(); //��ǰ��,���� Ȯ�� ���
	void CheckAmount(); //��� ���� ���
	void Sales(); //��ǰ �Ǹ� ���
	void Check_SaleProduct(); //���� �Ǹŷ� Ȯ�� ���
	void CheckPoint(); //�� ����Ʈ Ȯ�� ���
};
