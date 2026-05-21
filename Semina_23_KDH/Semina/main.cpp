/*
솔루션명 : Semina_23_KDH
소스코드 : main.c

프로그램의 목적 및 기능
    - 링크드리스트 기반 캠퍼스 셔틀 관리 시스템 구현
    - 정류장 삽입, 삭제, 검색 및 출력 기능 제공
    - 탑승객 수 수정 및 선택 정렬 기능 수행
    - 동적 메모리 할당을 이용한 노드 관리 수행

함수 목록
    - insertStation
    - deleteStation
    - printStations
    - searchStation
    - updatePassengerCount
    - sortByPassengerCount
    - freeList
    - main

최초 프로그램 작성 정보
   - 작성자 : 김동하
   - 학 번 : 22312076
   - 소 속 : 디지털융합대학 컴퓨터학부 정보통신공학전공
   - 작성일 : 2026/05/18
*/

#include "struct_H.h"
Node* head = NULL;

void printStations();



/*
* 함수명 : main
* 설  명 : 캠퍼스 셔틀 관리 시스템 메뉴 실행
* 매개변수 : 없음
* 반환값 : 프로그램 종료 상태값
*/
int main() {

    int menu;

    while (1) {

        printf("\n===== 캠퍼스 셔틀 관리 시스템 =====\n");
        printf("1. 정류장 삽입\n");
        printf("2. 정류장 삭제\n");
        printf("3. 정류장 출력\n");
        printf("4. 정류장 검색\n");
        printf("5. 탑승객 수 수정\n");
        printf("6. 탑승객 수 기준 정렬\n");
        printf("7. 종료\n");

        printf("메뉴 선택 : ");
        scanf("%d", &menu);

        switch (menu) {

        case 1:
            insertStation();
            break;

        case 2:
            deleteStation();
            break;

        case 3:
            printStations();
            break;

        case 4:
            searchStation();
            break;

        case 5:
            updatePassengerCount();
            break;

        case 6:
            sortByPassengerCount();
            break;

        case 7:
            freeList();
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}

/*
* 함수명 : printStations
* 설  명 : 현재 등록된 모든 정류장 출력
* 매개변수 : 없음
* 반환값 : 없음
*/
void printStations() {

    Node* temp = head;

    if (head == NULL) {
        printf("등록된 정류장이 없습니다.\n");
        return;
    }

    printf("\n===== 현재 셔틀 노선 =====\n");

    while (temp != NULL) {

        printf("[%s | 탑승객 수 : %d명]",
            temp->station,
            temp->passengerCount);

        if (temp->next != NULL) {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}
