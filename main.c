#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

char schedules[30][5][200];
/**
 * 달력 헤더를 출력.
 * 일 월 화 수 목 금 토
 * 이때, 일요일은 붉은색(\e[0;31m) / 토요일은 푸른색(\e[0;34m)
 */
void printHeader() {
    char days[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    char buffer[10000] = {};
    int offset = 0;

    for (int i = 0; i < 53; i++) {
        offset += sprintf(buffer + offset, "=");
    }

    offset += sprintf(buffer + offset, "\n");

    for (int i = 0; i < 7; i++) {
        offset += sprintf(buffer + offset, "%s%7s\e[0;37m", (i == 0 ? "\e[0;31m" : (i == 6) ? "\e[0;34m" : ""), days[i]);
    }
    offset += sprintf(buffer + offset, "\n");
    puts(buffer);
}

/**
 * 달력 내 일자를 출력.
 * 1일 ~ 30일까지 출력함.
 * 공휴일은 붉은색 처리 하지 않음.
 * 단, 일요일은 붉은색(\e[0;31m) / 토요일은 푸른색(\e[0;34m)
 */
void printBody(int selected) {
    int day = 1;

    char buffer[10000] = {};
    int offset = 0;

    offset += sprintf(buffer + offset, "%7s", "");
    for (int i = 1; i < 31; i++) {
        offset += sprintf(buffer + offset, "%s%7d\e[0;37m", (selected == i ? "\e[0;33m" : day == 0 ? "\e[0;31m" : (day == 6) ? "\e[0;34m" : ""), i);
        day++;
        if (day > 6) {
            offset += sprintf(buffer + offset, "\n");
            day = 0;
        }
    }
    puts(buffer);
}

/**
 * 일정 상세 목록을 출력함.
 * 선택된 날짜가 없을 경우, [Enter] 를 눌러.. 를 출력하여 일정 조회 방식을 출력함.
 */
void printDetailList(int selected, int detailSelected) {
    if (selected < 1) {
        printf("\n[Enter] 를 눌러 일정을 조회 및 관리\n");
        return;
    }

    char buffer[10000] = {};
    int offset = 0;

    for (int i = 0; i < 53; i++) {
        offset += sprintf(buffer + offset, "=");
    }

    offset += sprintf(buffer + offset, "\n");
    offset += sprintf(buffer + offset, "2026년 6월 %02d일\n", selected);
    offset += sprintf(buffer + offset, "[1] 추가/수정 [2] 제거 [Enter] 달력으로 이동\n");

    for (int i = 0; i < 5; i++) {
        char schedule[200];
        strcpy(schedule, schedules[selected - 1][i]);
        int isEmpty = (strlen(schedule) < 1);
        
        offset += sprintf(buffer + offset, "\n%s%d\e[0;37m. %s\e[0;37m", detailSelected == i ? "\e[0;33m" : "\e[0;37m", i+1, isEmpty ? "\e[30m이 칸에 일정이 없습니다." : schedule);
    }

    puts(buffer);
}

/**
 * 화면을 새로고침함.
 * \e[1;1H\e[2J 을 출력하여 터미널을 초기화 후,
 * 화면 출력 함수를 차례로 사용하여 화면을 재구성함.
 * 
 * 1. 화면 초기화
 * 2. `printHeader`로 헤더 출력
 * 3. `printBody`로 본문 출력
 * 4. `printDetailList`로 일정 출력
 */
void refresh(int current, int selected, int detail) {
    printf("\e[1;1H\e[2J");
    printHeader();
    printBody(current);

    printDetailList(selected, detail);
}

/**
 * 입력 처리, 날짜 선택, 화면 상태 관리 등 수행
 */
int main() {
    time_t timer;
    struct tm *t;

    timer = time(NULL);
    t = localtime(&timer);

    int current = t->tm_mday;
    int selected = 0;

    int detailSelected = 0;

    /**
     * boolean - 부울리아아아아아아ㅏ아아아ㅏㄴ
     * 0 - 날짜 선택 / 일정 조회 (기본값)
     * 1 - 날짜 추가 / 수정 (input)
     */
    int mode = 0;
    while (1) {
        refresh(current, selected, detailSelected);

        if (mode == 1) {
            char* str = schedules[selected - 1][detailSelected];
            fgets(str, sizeof(schedules[selected - 1][detailSelected]), stdin);
            str[strlen(str) - 1] = '\0';
            mode = 0;
            continue;
        }

        int ch = getch();
        if (ch == 3) {
            break;
        }

        if (ch == 13) {
            if (selected == current) {
                selected = -1;
                continue;
            }
            selected = current;
            continue;
        }

        if (ch == '1') {
            if (selected < 1) {
                continue;
            }

            mode = 1;
            continue;
        }

        if (ch == '2') {
            if (selected < 1) {
                continue;
            }

            memset(schedules[selected - 1][detailSelected], 0, sizeof(schedules[selected - 1][detailSelected]));
            continue;
        }

        if (ch != 224) {
            continue;
        }

        ch = getch();

        switch (ch) {
            case 72: {
                if (selected > 0) {
                    if ((detailSelected - 1) < 0) {
                        break;
                    }

                    detailSelected--;
                    continue;
                }

                if ((current - 7) < 1) {
                    break;
                }

                current -= 7;
                break;
            }
            case 77: {
                if ((current + 1) > 30) {
                    break;
                }

                current += 1;
                break;
            }

            case 80: {
                if (selected > 0) {
                    if ((detailSelected + 1) > 4) {
                        break;
                    }

                    detailSelected++;
                    continue;
                }

                if ((current + 7) > 30) {
                    break;
                }

                current += 7;
                break;
            }

            case 75: {
                if ((current - 1) < 1) {
                    break;
                }

                current -= 1;
                break;
            }
        }
    }
}