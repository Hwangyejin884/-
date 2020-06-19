#include "Store.h"


int main() {
	int select_num; //기능 선택용 번호

	int one_count_name = 0, one_count_price = 0; //1번에서 배열의 위치를 넘기기 위한 수
	int product_price;
	string product_name;


	Store yejin_store; //yejin_store 객체 생성

	while (true) {
		cout << endl << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
		cout << "        ☆★☆★ 판매/재고 관리 ☆★☆★        " << endl;
		cout << "          [ 상점용 ]          " << endl;
		cout << "본 프로그램은 상점용 판매/재고 관리 프로그램입니다. " << endl;
		cout << "1. 제품 입고 관리" << endl;
		cout << "2. 제품명/가격 확인" << endl;
		cout << "3. 재고 수량 확인" << endl;
		cout << "4. 제품 판매 및 포인트 적립" << endl;
		cout << "5. 제품 당 누적된 판매량 확인" << endl;
		cout << "6. 고객 포인트 관리" << endl;
		cout << "7. 프로그램 종료 " << endl;
		cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
		cout << "사용할 기능의 번호를 입력해주십시오. " << endl;
		
		while (1) { //1~7 사이의 정수를 입력받을 때까지 반복 
			cout << "	Number: "; 
			cin >> select_num;
			if (select_num <= 7 && select_num >= 1)
				break;
			else {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "잘못된 입력입니다. 다시 입력하세요. " << endl << endl;
			}
		}

		switch (select_num) {
		case 1: //제품 입고 기능
			yejin_store.Receiving();
			break;

		case 2: //제품명과 가격을 확인하는 기능
			yejin_store.CheckProduct();
			break;

		case 3: //수량을 확인하는 재고 관리 기능
			yejin_store.CheckAmount();
			break;

		case 4: //제품 판매 및 포인트 적립 기능
			yejin_store.Sales();
			break;

		case 5: //제품 당 누적된 판매량을 보여주는 기능
			yejin_store.Check_SaleProduct();
			break;

		case 6: //고객ID의 포인트를 확인하는 기능
			yejin_store.CheckPoint();
			break;

		case 7: //프로그램 종료
			cout << "	이용해주셔서 감사합니다." << endl;
			cout << "	상점 관리 프로그램을 종료합니다." << endl;
			return 0;

		default:
			cout << "없는 기능의 번호를 입력하셨습니다. " << endl;
			cout << "초기 화면으로 되돌아갑니다.";
			break;
		} //swich 괄호
	} //while 괄호
	return 0;
} //main 괄호