#include "Store.h"


int main() {
	int select_num; //��� ���ÿ� ��ȣ

	Store yejin_store; //yejin_store ��ü ����

	while (true) {
		cout << endl << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
		cout << "        �١ڡ١� �Ǹ�/��� ���� �١ڡ١�        " << endl;
		cout << "          [ ������ ]          " << endl;
		cout << "�� ���α׷��� ������ �Ǹ�/��� ���� ���α׷��Դϴ�. " << endl;
		cout << "1. ��ǰ �԰� ����" << endl;
		cout << "2. ��ǰ��/���� Ȯ��" << endl;
		cout << "3. ��� ���� Ȯ��" << endl;
		cout << "4. ��ǰ �Ǹ� �� ����Ʈ ����" << endl;
		cout << "5. ��ǰ �� ������ �Ǹŷ� Ȯ��" << endl;
		cout << "6. ���� ����Ʈ ����" << endl;
		cout << "7. ���α׷� ���� " << endl;
		cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
		cout << "����� ����� ��ȣ�� �Է����ֽʽÿ�. " << endl;
		select_num = Base::return_int(1, 7);

		switch (select_num) {
		case 1: //��ǰ �԰� ���
			yejin_store.Receiving();
			break;

		case 2: //��ǰ���� ������ Ȯ���ϴ� ���
			yejin_store.CheckProduct();
			break;

		case 3: //������ Ȯ���ϴ� ��� ���� ���
			yejin_store.CheckAmount();
			break;

		case 4: //��ǰ �Ǹ� �� ����Ʈ ���� ���
			yejin_store.Sales();
			break;

		case 5: //��ǰ �� ������ �Ǹŷ��� �����ִ� ���
			yejin_store.Check_SaleProduct();
			break;

		case 6: //����ID�� ����Ʈ�� Ȯ���ϴ� ���
			yejin_store.CheckPoint();
			break;

		case 7: //���α׷� ����
			cout << "	�̿����ּż� �����մϴ�." << endl;
			cout << "	���� ���� ���α׷��� �����մϴ�." << endl;
			return 0;

		default:
			cout << "���� ����� ��ȣ�� �Է��ϼ̽��ϴ�. " << endl;
			cout << "�ʱ� ȭ������ �ǵ��ư��ϴ�.";
			break;
		} //swich ��ȣ
	} //while ��ȣ
	return 0;
} //main ��ȣ