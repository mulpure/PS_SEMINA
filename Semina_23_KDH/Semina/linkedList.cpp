#include "struct_H.h"

/*
* 
* 함수 목록
* void insertStation()
* void deleteStation()
* void freeList()
* 
* */

/*
* 함수명 : insertStation
* 설  명 : 새로운 정류장을 링크드리스트 끝에 삽입
* 매개변수 : 없음
* 반환값 : 없음
*/
void insertStation() {

    Node* newNode = (Node*)malloc(sizeof(Node));

    printf("추가할 정류장 이름 : ");
    scanf("%s", newNode->station);

    printf("탑승객 수 입력 : ");
    scanf("%d", &newNode->passengerCount);

    newNode->next = NULL;

    // 첫 노드일 경우====
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("정류장이 추가되었습니다.\n");
}



/*
* 함수명 : deleteStation
* 설  명 : 입력받은 정류장 이름에 해당하는 노드 삭제
* 매개변수 : 없음
* 반환값 : 없음
*/
void deleteStation() {

    char target[30];

    printf("삭제할 정류장 이름 : ");
    scanf("%s", target);

    Node* temp = head;
    Node* prev = NULL;

    //등록된 것 중에 없을 경우(NULL이 나오면) 없다고 출력
    if (head == NULL) {
        printf("등록된 정류장이 없습니다.\n");
        return;
    }

    // 첫 노드 삭제
    if (strcmp(head->station, target) == 0) {

        head = head->next;
        free(temp);

        printf("정류장이 삭제되었습니다.\n");
        return;
    }

    // 삭제할 노드 탐색
    while (temp != NULL && strcmp(temp->station, target) != 0) {
        prev = temp;
        temp = temp->next;
    }
    // 노드를 찾지 못한 경우
    if (temp == NULL) {
        printf("정류장을 찾을 수 없습니다.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);

    printf("정류장이 삭제되었습니다.\n");
}


/*
* 함수명 : freeList
* 설  명 : 링크드리스트 전체 메모리 해제
* 매개변수 : 없음
* 반환값 : 없음
*/
void freeList() {

    Node* temp;

    while (head != NULL) {

        temp = head;
        head = head->next;

        free(temp);
    }
}