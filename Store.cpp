#include "Store.h"
#define PSIZE 30 //상품 갯수
#define CSIZE 10 //고객 명수
#define PRICE 100000 //상품 1개의 최고 가격
#define AMOUNT 100 //상품 종류당 최고 수량

Product product[PSIZE]; //30개의 상품 정보
Customer customer[CSIZE];
int pro_index = 0; //초기 상품 정보 인덱스 0으로 초기화
int customer_index = 0; //초기 고객 정보 인덱스 0으로 초기화


int Base::return_int(int min, int max) { //int형 반환해주는 함수
	int select_num;
	while (1) { //MIN, MAX 사이의 수를 입력할때까지 반복
		cout << "	☞ 입력: ";
		cin >> select_num;
		if (select_num <= max && select_num >= min) { //min과 max 사이의 수라면
			return select_num; //입력받은 select_num 값 반환
			break;
		}
		else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "※※ 잘못된 입력입니다. 다시 입력하세요. ※※ " << endl << endl;
		}
	}
}


void Store::Receiving() { //case 1의 제품 입고 관리함수
	string name;
	int i = 0;
	cin.ignore(); //getline() buffer clear 문제 예방
	cout << "● 제품 입고 기능을 선택하셨습니다. ● " << endl;
	cout << "[  입고할 제품명을 입력하세요. ]" << endl;
	cout << "제품명 : ";
	getline(cin, name);
	for (i = 0; i < PSIZE; i++) {
		if (name == product[i].name) { // i 인덱스에서 값을 찾았을 시
			cout << "※※ 이미 등록돼 있는 제품입니다. ※※" << endl;
			cout << "┗ 수량을 변경은 판매 시에만 가능합니다. " << endl 
				<< endl << endl;
			return;
		}
	}
	cout << "■ 등록 가능한 제품명입니다. ■" << endl;
	product[pro_index].name = name;
	cout << "가격을 입력하세요.		";
	product[pro_index].price = Base::return_int(0, PRICE);
	cout << "수량을 입력하세요.		";
	product[pro_index].amount = Base::return_int(1,AMOUNT);;

	cout << product[pro_index].name << "가 가격 " << product[pro_index].price <<
		"로 책정되었습니다. 수량은 " << product[pro_index].amount << "입니다" << endl;
	cout << endl << endl;
	pro_index++; //기능 수행 후 인덱스 위치 +1
	return;
}


void Store::CheckProduct() { //case 2의 제품명/가격 확인 기능
	int select_num;
	string select_name;
	cout << "● 제품명 / 가격 확인 기능을 선택하셨습니다. ●" << endl;
	cout << "[  원하시는 기능의 번호를 입력해주세요.  ]" << endl;
	cout << "1. 전체 명단 확인 " << endl;
	cout << "2. 개별 명단 확인 " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {
	case 1: //전체 명단 확인
		cout << "【     이름		  가격    】" << endl;
		for (int i = 0; i < PSIZE; i++)
			cout << "    " << product[i].name << "		" << product[i].price << endl;
		break;
	case 2: //개별 명단 확인
		cin.ignore();
		cout << "[  확인할 제품명을 입력하세요.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "【     이름		 가격    】" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << "    " << product[i].name << "		" 
					<< product[i].price << endl << endl;
				break;
			}
		}
		break;
	default:
		cout << "※※ number는 1, 2 만 입력하실 수 있습니다. ※※" << endl;
	}
}


void Store::CheckAmount() { //case3의 재고 관리 기능
	int select_num;
	string select_name;
	cout << "● 재고 관리 기능을 선택하셨습니다. ●" << endl;
	cout << "[  원하시는 기능의 번호를 입력해주세요.  ]" << endl;
	cout << "1. 전체 명단 확인 " << endl;
	cout << "2. 개별 명단 확인 " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {
	case 1: //전체 명단 확인
		cout << "【     이름		 재고    】" << endl;
		for (int i = 0; i < PSIZE; i++) {
			cout << "  " << product[i].name << "		" << product[i].amount;
			if (product[i].amount <= 5 && product[i].amount != 0) //이부분도 수정
				cout << "		★품절임박★" << endl;
			else
				cout << endl;
		}
		break;
	case 2: //개별 명단 확인
		cin.ignore();
		cout << "[  확인할 제품명을 입력하세요.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "【     이름		 재고    】" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << "  " << product[i].name << "		" << product[i].amount;
				if (product[i].amount <= 5)
					cout << "		★품절임박★" << endl;
				else
					cout << endl;
				break;
			}
		}
		break;
	default:
		cout << "※※ 1, 2 만 입력하실 수 있습니다. ※※" << endl;
	}
}


void Store::Sales() { //case4의 판매 기록 관리
	int howMany, save_price = 0, how_amount, use_point;
	string what_Pname, what_Cname, what_number;
	char yes_no;

	cout << "● 판매 기록 관리 기능을 선택하셨습니다. ●" << endl;
	cout << "[  현재 고객님께서 몇 종류의 상품을 구매하셨나요?  ]";
	cout << "종류: ";
	howMany = Base::return_int(1, PSIZE);
	for (int i = 0; i < howMany; i++) { //구매한 종류의 갯수만큼 반복	
		cout << "[  구매하신 상품명을 입력하세요.  ]" << endl;
		cout << "Product Name : "; cin >> what_Pname;

		while (1) { //제대로 된 상품명을 입력할 때까지 반복
			for (int j = 0; j < PSIZE; j++) { //상품명 찾기
				if (what_Pname == product[j].name) { //상품명 찾기 성공
					cout << "[  " << product[j].name << "의 수량을 입력하세요.  ]" 
						<< endl;
					how_amount = Base::return_int(1, AMOUNT);
					product[j].amount -= how_amount; //재고 수량 빼기
					product[j].sales_rate += how_amount; //판매 기록 저장
					save_price += product[j].price * how_amount; //가격*수량 저장
					break;
				}
			}
			break;
		}
	}
	cout << "■ 총 금액은 " << save_price << "원입니다. ■" << endl;
	cout << "■ 저희 매장은 총 구매 금액의 5%를 포인트로 적립합니다. ■" << endl;
	cout << " ┗ 포인트가 1000점 이상이면 현금처럼 사용하실 수 있습니다. " << endl;
	cout << "● 저희 매장의 회원이십니까? ( Y / N ) : "; cin >> yes_no;
	if (yes_no == 'Y') { //매장 회원일 때
		cout << "[  이름을 입력해주세요  ]" << endl << "	이름: "; cin >> what_Cname;
		for (int i = 0; i < CSIZE; i++) {
			if (what_Cname == customer[i].name) {
				if (customer[i].point >= 1000) {
					cout << "● 포인트를 사용하시겠습니까? ( Y / N ) : " << endl;
					cin >> yes_no;
					if (yes_no == 'Y') {
						cout << customer[i].name << "님의 포인트는 " << customer[i].point
							<< "점 입니다.  얼마나 사용하시겠습니까? : ";
						use_point = Base::return_int(1, customer[i].point);
						cout << "■ 결제하실 금액은 " << save_price - use_point
							<< "원입니다. ■" << endl;
						customer[i].point -= use_point;
					}
					else if (yes_no == 'N')
						cout << "■ 결제하실 금액은 " << save_price << "원입니다. ■" << endl;
				}
				else 
					cout << "■ 결제하실 금액은 " << save_price << "원입니다. ■" << endl;
				customer[i].point += (save_price * 0.05);
				cout << save_price * 0.05 << " 적립되어 " << customer[i].name
					<< "님의 포인트가 " << customer[i].point << "점이 되었습니다."
					<< endl << "★☆★☆ 구매해주셔서 감사합니다. ☆★☆★" << endl << endl;
				return;
			}
		}
	}

	else if (yes_no == 'N') {//매장 회원이 아닐 때
		cout << "● 회원가입을 원하십니까?( Y / N ) : "; cin >> yes_no;
		if (yes_no == 'Y') {
			cout << "[  고객님의 이름과 전화번호를 입력하세요.  ]" << endl;
			cout << "Name : "; cin >> customer[customer_index].name;
			cout << "Number : "; cin >> customer[customer_index].number;
			customer[customer_index].point += save_price * 0.05;
			cout << save_price * 0.05 << "포인트가 적립되어 " 
				<< customer[customer_index].name
				<< "님의 포인트가 " << customer[customer_index].point 
				<< "점이 되었습니다."<< endl;
			customer_index++;
			cout << "■ 결제하실 금액은 " << save_price << "원입니다. ■" << endl;
			cout << "★☆★☆ 구매해주셔서 감사합니다. ☆★☆★" << endl << endl;
			return;
		}
		else {
			cout << "■ 결제하실 금액은 " << save_price << "원입니다. ■" << endl;
			cout << "★☆★☆ 구매해주셔서 감사합니다. ☆★☆★" << endl << endl;
			return;
		}
	}
}


void Store::Check_SaleProduct() { //case5의 누적 판매량 확인 기능
	int select_num;
	string select_name;
	cout << "● 누적 판매량 확인 기능을 선택하셨습니다. ●" << endl;
	cout << "[  원하시는 기능의 번호를 입력해주세요.  ]" << endl;
	cout << "1. 전체 명단 확인 " << endl;
	cout << "2. 개별 명단 확인 " << endl;
	select_num = Base::return_int(1, 2);

	switch (select_num) {

	case 1: //전체 명단 확인
		cout << "【     이름		 재고    】" << endl;
		for (int i = 0; i < PSIZE; i++)
			cout << product[i].name << "		" << product[i].sales_rate << endl;
		return;

	case 2: //개별 명단 확인
		cin.ignore();
		cout << "[  확인할 제품명을 입력하세요.  ]" << endl;
		cout << "name : ";
		getline(cin, select_name);
		cout << "【     이름		 재고    】" << endl;
		for (int i = 0; i < PSIZE; i++) {
			if (select_name == product[i].name) {
				cout << product[i].name << "		" << product[i].sales_rate 
					<< endl << endl;
				return;
			}
		}
		cout << "※※ 일치하는 제품명이 없습니다. 초기화면으로 돌아갑니다. ※※" 
			<< endl << endl;
	default:
		cout << endl;
	}
}


void Store::CheckPoint() { //고객 포인트 확인 기능
	string what_name;
	cout << "● 고객 포인트 확인 기능을 선택하셨습니다. ●" << endl;
	cout << "※ 고객의 포인트는 개별 확인 기능만 지원합니다. ※" << endl;
	cout << "[  조회하실 고객의 이름을 입력해주세요.  ]" << endl;
	cout << "Name : "; cin >> what_name;
	for (int i = 0; i < CSIZE; i++) {
		if (what_name == customer[i].name)
			cout << "Name : " << customer[i].name << "	Number: " << customer[i].number
			<< "	Point : " << customer[i].point << endl;
		return;
	}
	cout << "일치하는 고객이 없습니다. "<< endl << endl;
}
