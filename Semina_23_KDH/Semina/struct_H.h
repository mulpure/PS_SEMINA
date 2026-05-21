#pragma once
/*
헤더명 : struct_H.h

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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* 구조체명 : Node
* 설  명 : 셔틀 정류장 정보를 저장하는 링크드리스트 노드
* 멤버변수 :
*   - station : 정류장 이름
*   - passengerCount : 탑승객 수
*   - next : 다음 노드를 가리키는 포인터
*/

typedef struct Node {
    char station[30];
    int passengerCount;
    struct Node* next;
} Node;

extern Node* head;

void insertStation();
void deleteStation();
void freeList();


void searchStation();
void updatePassengerCount();
void sortByPassengerCount();

