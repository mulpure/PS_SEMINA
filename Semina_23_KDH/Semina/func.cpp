
#include "struct_H.h"
/*


함수목록

* 함수명 : sortByPassengerCount
* 설  명 : 탑승객 수 기준 내림차순 선택 정렬 수행

* 함수명 : searchStation
* 설  명 : 정류장 이름을 검색하여 정보 출력


* 함수명 : updatePassengerCount
* 설  명 : 특정 정류장의 탑승객 수 수정



*/



/*
* 함수명 : searchStation
* 설  명 : 정류장 이름을 검색하여 정보 출력
* 매개변수 : 없음
* 반환값 : 없음
*/
void searchStation() {

    char target[30];

    printf("검색할 정류장 이름 : ");
    scanf("%s", target);

    Node* temp = head;

    while (temp != NULL) {

        if (strcmp(temp->station, target) == 0) {
            printf("정류장 이름 : %s\n", temp->station);
            printf("탑승객 수 : %d명\n", temp->passengerCount);

            return;
        }

        temp = temp->next;
    }

    printf("정류장을 찾을 수 없습니다.\n");
}

/*
* 함수명 : updatePassengerCount
* 설  명 : 특정 정류장의 탑승객 수 수정
* 매개변수 : 없음
* 반환값 : 없음
*/
void updatePassengerCount() {

    char target[30];
    int newCount;

    printf("탑승객 수를 수정할 정류장 이름 : ");
    scanf("%s", target);

    Node* temp = head;

    while (temp != NULL) {

        if (strcmp(temp->station, target) == 0) {

            printf("새로운 탑승객 수 입력 : ");
            scanf("%d", &newCount);

            temp->passengerCount = newCount;

            printf("탑승객 수가 수정되었습니다.\n");
            return;
        }

        temp = temp->next;
    }

    printf("정류장을 찾을 수 없습니다.\n");
}

/*
* 함수명 : sortByPassengerCount
* 설  명 : 탑승객 수 기준 내림차순 선택 정렬 수행
* 매개변수 : 없음
* 반환값 : 없음
*/
void sortByPassengerCount() {

    if (head == NULL || head->next == NULL) {
        printf("정렬할 데이터가 부족합니다.\n");
        return;
    }

    Node* i;
    Node* j;
    Node* maxNode;

    char tempName[30];
    int tempCount;

    for (i = head; i->next != NULL; i = i->next) {

        // 현재 노드를 최대값으로 가정
        maxNode = i;

        // 최대 탑승객 수 탐색
        for (j = i->next; j != NULL; j = j->next) {

            if (j->passengerCount > maxNode->passengerCount) {
                maxNode = j;
            }
        }

        // 데이터 swap
        if (maxNode != i) {

            strcpy(tempName, i->station);
            strcpy(i->station, maxNode->station);
            strcpy(maxNode->station, tempName);

            tempCount = i->passengerCount;
            i->passengerCount = maxNode->passengerCount;
            maxNode->passengerCount = tempCount;
        }
    }

    printf("탑승객 수 기준 선택 정렬 완료.\n");
}

