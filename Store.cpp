#include "Store.h"
#define PSIZE 30 //��ǰ ����
#define CSIZE 10 //�� ���
#define PRICE 100000 //��ǰ 1���� �ְ� ����
#define AMOUNT 100 //��ǰ ������ �ְ� ����

Product product[PSIZE]; //30���� ��ǰ ����
Customer customer[CSIZE];
int pro_index = 0; //�ʱ� ��ǰ ���� �ε��� 0���� �ʱ�ȭ
int customer_index = 0; //�ʱ� �� ���� �ε��� 0���� �ʱ�ȭ


int Base::return_int(int min, int max) { //int�� ��ȯ���ִ� �Լ�
	int select_num;
	while (1) { //MIN, MAX ������ ���� �Է��Ҷ����� �ݺ�
		cout << "	�� �Է�: ";
		cin >> select_num;
		if (select_num <= max && select_num >= min) { //min�� max ������ �����
			return select_num; //�Է¹��� select_num �� ��ȯ
			break;
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�ء� �߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���. �ء� " << endl << endl;
		}
	}
}


void Store::Receiving() { //case 1�� ��ǰ �԰� �����Լ�
	string name;
	int i = 0;
	cin.ignore(); //getline() buffer clear ���� ����
	cout << "�� ��ǰ �԰� ����� �����ϼ̽��ϴ�. �� " << endl;
	cout << "[  �԰��� ��ǰ���� �Է��ϼ���. ]" << endl;
	cout << "��ǰ�� : ";
	getline(cin, name);
	for (i = 0; i < PSIZE; i++) {
		if (name == product[i].name) { // i �ε������� ���� ã���� ��
			cout << "�ء� �̹� ��ϵ� �ִ� ��ǰ�Դϴ�. �ء�" << endl;
			cout << "�� ������ ������ �Ǹ� �ÿ��� �����մϴ�. " << endl 
				<< endl << endl;
			return;
		}
	}
	cout << "�� ��� ������ ��ǰ���Դϴ�. ��" << endl;
	product[pro_index].name = name;
	cout << "������ �Է��ϼ���.		";
	product[pro_index].price = Base::return_int(0, PRICE);
	cout << "������ �Է��ϼ���.		";
	product[pro_index].amount = Base::return_int(1,AMOUNT);;

	cout << product[pro_index].name << "�� ���� " << product[pro_index].price <<
		"�� å���Ǿ����ϴ�. ������ " << product[pro_index].amount << "�Դϴ�" << endl;
	cout << endl << endl;
	pro_index++; //��� ���� �� �ε��� ��ġ +1
	return;
}


void Store::CheckProduct() { //case 2�� ��ǰ��/���� Ȯ�� ���
	int select_num;
	string select_name;
	cout << "�� ��ǰ�� / ���� Ȯ�� ����� �����ϼ̽��ϴ�. ��" << endl;
	cout << "[  ���Ͻô� ����� ��ȣ�� �Է����ּ���.  ]" << endl;
	cout << "1. ��ü ��� Ȯ�� " << endl;
	cout << "2. ���� ��� Ȯ�� " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {
	case 1: //��ü ��� Ȯ��
		cout << "��     �̸�		  ����    ��" << endl;
		for (int i = 0; i < PSIZE; i++)
			cout << "    " << product[i].name << "		" << product[i].price << endl;
		break;
	case 2: //���� ��� Ȯ��
		cin.ignore();
		cout << "[  Ȯ���� ��ǰ���� �Է��ϼ���.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "��     �̸�		 ����    ��" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << "    " << product[i].name << "		" 
					<< product[i].price << endl << endl;
				break;
			}
		}
		break;
	default:
		cout << "�ء� number�� 1, 2 �� �Է��Ͻ� �� �ֽ��ϴ�. �ء�" << endl;
	}
}


void Store::CheckAmount() { //case3�� ��� ���� ���
	int select_num;
	string select_name;
	cout << "�� ��� ���� ����� �����ϼ̽��ϴ�. ��" << endl;
	cout << "[  ���Ͻô� ����� ��ȣ�� �Է����ּ���.  ]" << endl;
	cout << "1. ��ü ��� Ȯ�� " << endl;
	cout << "2. ���� ��� Ȯ�� " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {
	case 1: //��ü ��� Ȯ��
		cout << "��     �̸�		 ���    ��" << endl;
		for (int i = 0; i < PSIZE; i++) {
			cout << "  " << product[i].name << "		" << product[i].amount;
			if (product[i].amount <= 5 && product[i].amount != 0) //�̺κе� ����
				cout << "		��ǰ���ӹڡ�" << endl;
			else
				cout << endl;
		}
		break;
	case 2: //���� ��� Ȯ��
		cin.ignore();
		cout << "[  Ȯ���� ��ǰ���� �Է��ϼ���.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "��     �̸�		 ���    ��" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << "  " << product[i].name << "	" << product[i].amount;
				if (product[i].amount <= 5)
					cout << "		��ǰ���ӹڡ�" << endl;
				else
					cout << endl;
				break;
			}
		}
		break;
	default:
		cout << "�ء� 1, 2 �� �Է��Ͻ� �� �ֽ��ϴ�. �ء�" << endl;
	}
}


void Store::Sales() { //case4�� �Ǹ� ��� ����
	int howMany, save_price = 0, how_amount, use_point;
	string what_Pname, what_Cname, what_number;
	char yes_no;

	cout << "�� �Ǹ� ��� ���� ����� �����ϼ̽��ϴ�. ��" << endl;
	cout << "[  ���� ���Բ��� �� ������ ��ǰ�� �����ϼ̳���?  ]";
	cout << "����: ";
	howMany = Base::return_int(1, PSIZE);
	for (int i = 0; i < howMany; i++) { //������ ������ ������ŭ �ݺ�	
		cout << "[  �����Ͻ� ��ǰ���� �Է��ϼ���.  ]" << endl;
		cout << "Product Name : "; cin >> what_Pname;

		while (1) { //����� �� ��ǰ���� �Է��� ������ �ݺ�
			for (int j = 0; j < PSIZE; j++) { //��ǰ�� ã��
				if (what_Pname == product[j].name) { //��ǰ�� ã�� ����
					cout << "[  " << product[j].name << "�� ������ �Է��ϼ���.  ]" << endl;
					how_amount = Base::return_int(1, AMOUNT);
					product[j].amount -= how_amount; //��� ���� ����
					product[j].sales_rate += how_amount; //�Ǹ� ��� ����
					save_price += product[j].price * how_amount; //����*���� ���ؼ� ����
					break;
				}
			}
			break;
		}
	}
	cout << "�� �� �ݾ��� " << save_price << "���Դϴ�. ��" << endl;
	cout << "�� ���� ������ �� ���� �ݾ��� 5%�� ����Ʈ�� �����մϴ�. ��" << endl;
	cout << " �� ����Ʈ�� 1000�� �̻��̸� ����ó�� ����Ͻ� �� �ֽ��ϴ�. " << endl;
	cout << "�� ���� ������ ȸ���̽ʴϱ�? ( Y / N ) : "; cin >> yes_no;
	if (yes_no == 'Y') { //���� ȸ���� ��
		cout << "[  �̸��� �Է����ּ���  ]" << endl << "	�̸�: "; cin >> what_Cname;
		for (int i = 0; i < CSIZE; i++) {
			if (what_Cname == customer[i].name) {
				if (customer[i].point >= 1000) {
					cout << "�� ����Ʈ�� ����Ͻðڽ��ϱ�? ( Y / N ) : " << endl;
					cin >> yes_no;
					if (yes_no == 'Y') {
						cout << customer[i].name << "���� ����Ʈ�� " << customer[i].point
							<< "�� �Դϴ�.  �󸶳� ����Ͻðڽ��ϱ�? : ";
						use_point = Base::return_int(1, customer[i].point);
						cout << "�� �����Ͻ� �ݾ��� " << save_price - use_point
							<< "���Դϴ�. ��" << endl;
						customer[i].point -= use_point;
					}
					else if (yes_no == 'N')
						cout << "�� �����Ͻ� �ݾ��� " << save_price << "���Դϴ�. ��" << endl;
				}
				else 
					cout << "�� �����Ͻ� �ݾ��� " << save_price << "���Դϴ�. ��" << endl;
				customer[i].point += (save_price * 0.05);
				cout << save_price * 0.05 << " �����Ǿ� " << customer[i].name
					<< "���� ����Ʈ�� " << customer[i].point << "���� �Ǿ����ϴ�."
					<< endl << "�ڡ١ڡ� �������ּż� �����մϴ�. �١ڡ١�" << endl << endl;
				return;
			}
		}
	}

	else if (yes_no == 'N') {//���� ȸ���� �ƴ� ��
		cout << "�� ȸ�������� ���Ͻʴϱ�?( Y / N ) : "; cin >> yes_no;
		if (yes_no == 'Y') {
			cout << "[  ������ �̸��� ��ȭ��ȣ�� �Է��ϼ���.  ]" << endl;
			cout << "Name : "; cin >> customer[customer_index].name;
			cout << "Number : "; cin >> customer[customer_index].number;
			customer[customer_index].point += save_price * 0.05;
			cout << save_price * 0.05 << "����Ʈ�� �����Ǿ� " << customer[customer_index].name
				<< "���� ����Ʈ�� " << customer[customer_index].point << "���� �Ǿ����ϴ�."<< endl;
			customer_index++;
			cout << "�� �����Ͻ� �ݾ��� " << save_price << "���Դϴ�. ��" << endl;
			cout << "�ڡ١ڡ� �������ּż� �����մϴ�. �١ڡ١�" << endl << endl;
			return;
		}
		else {
			cout << "�ڡ١ڡ� �������ּż� �����մϴ�. �١ڡ١�" << endl << endl;
			return;
		}
	}
}


void Store::Check_SaleProduct() { //case5�� ���� �Ǹŷ� Ȯ�� ���
	int select_num;
	string select_name;
	cout << "�� ���� �Ǹŷ� Ȯ�� ����� �����ϼ̽��ϴ�. ��" << endl;
	cout << "[  ���Ͻô� ����� ��ȣ�� �Է����ּ���.  ]" << endl;
	cout << "1. ��ü ��� Ȯ�� " << endl;
	cout << "2. ���� ��� Ȯ�� " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {

	case 1: //��ü ��� Ȯ��
		cout << "��     �̸�		 ���    ��" << endl;
		for (int i = 0; i < PSIZE; i++)
			cout << product[i].name << "		" << product[i].sales_rate << endl;
		return;

	case 2: //���� ��� Ȯ��
		cin.ignore();
		cout << "[  Ȯ���� ��ǰ���� �Է��ϼ���.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "��     �̸�		 ���    ��" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << product[i].name << "		" << product[i].sales_rate << endl << endl;
				return;
			}
		}
		cout << "�ء� ��ġ�ϴ� ��ǰ���� �����ϴ�. �ʱ�ȭ������ ���ư��ϴ�. �ء�" << endl << endl;
	default:
		cout << "�� number�� 1, 2 �� �Է��Ͻ� �� �ֽ��ϴ�. " << endl;
	}
}


void Store::CheckPoint() { //�� ����Ʈ Ȯ�� ���
	string what_name;
	cout << "�� �� ����Ʈ Ȯ�� ����� �����ϼ̽��ϴ�. ��" << endl;
	cout << "�� ���� ����Ʈ�� ���� Ȯ�� ��ɸ� �����մϴ�. ��" << endl;
	cout << "[  ��ȸ�Ͻ� ���� �̸��� �Է����ּ���.  ]" << endl;
	cout << "Name : "; cin >> what_name;
	for (int i = 0; i < CSIZE; i++) {
		if (what_name == customer[i].name)
			cout << "Name : " << customer[i].name << "	Number: " << customer[i].number
			<< "	Point : " << customer[i].point << endl;
	}
	cout << endl << endl;
}