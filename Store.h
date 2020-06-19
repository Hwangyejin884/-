#include <iostream>
#include <string>
#include <limits>
using namespace std;

typedef struct { //상품 정보 구조체
	string name; //제품명
	int price; //가격
	int amount; //재고 수량
	int sales_rate; //누적 판매량

} Product;

typedef struct { //고객 포인트 구조체
	string name; //고객명
	int point; //포인트
	int number; //전화번호
} Customer;

class Base {
public:
	int return_int(int min, int max); //int형 값을 반환하는 함수
};


class Store : public Base { //상점 클래스 (재고,판매 관리용) 
public:
	void Receiving(); //제품 입고 기능
	void CheckProduct(); //제품명,가격 확인 기능
	void CheckAmount(); //재고 관리 기능
	void Sales(); //제품 판매 기능
	void Check_SaleProduct(); //누적 판매량 확인 기능
	void CheckPoint(); //고객 포인트 확인 기능
};
