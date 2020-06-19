#include "Store.h"


int main() {
	int select_num; //기능 선택용 번호

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
		select_num = Base::return_int(1, 7);

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