## C-Calender 프로젝트
[![디미고](https://img.shields.io/badge/한국디지털미디어고등학교-002060?logo=data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiPz4KPHN2ZyBpZD0iX+ugiOydtOyWtF8xIiBkYXRhLW5hbWU9IuugiOydtOyWtF8xIiB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZlcnNpb249IjEuMSIgdmlld0JveD0iMCAwIDM5Ni44NSAzOTYuODUiPgogIDwhLS0gR2VuZXJhdG9yOiBBZG9iZSBJbGx1c3RyYXRvciAzMC4yLjEsIFNWRyBFeHBvcnQgUGx1Zy1JbiAuIFNWRyBWZXJzaW9uOiAyLjEuMSBCdWlsZCAxKSAgLS0+CiAgPGRlZnM+CiAgICA8c3R5bGU+CiAgICAgIC5zdDAgewogICAgICAgIGZpbGw6ICNjZDIzNzA7CiAgICAgIH0KICAgIDwvc3R5bGU+CiAgPC9kZWZzPgogIDxwYXRoIGNsYXNzPSJzdDAiIGQ9Ik0zNDcuOCwyMjguN2MtMTYuMjYsODEuNjQtOTUuNjEsMTM0LjY0LTE3Ny4yNSwxMTguMzktODEuNjQtMTYuMjYtMTM0LjY0LTk1LjYxLTExOC4zOS0xNzcuMjUsMTYuMjYtODEuNjQsOTUuNjEtMTM0LjY0LDE3Ny4yNS0xMTguMzksMzUuNTQsNy4wOCw2Ny4zNCwyNi43Miw4OS41OSw1NS4zM2wtMjYuNzMsNDkuMzFjLTIzLjk0LTUxLjA0LTg0Ljc1LTczLjAyLTEzNS44LTQ5LjA3LTUxLjA0LDIzLjk0LTczLjAyLDg0Ljc1LTQ5LjA3LDEzNS44LDIzLjk0LDUxLjA0LDg0Ljc1LDczLjAyLDEzNS44LDQ5LjA3LDE5LjY4LTkuMjMsMzUuOTEtMjQuNTEsNDYuMzEtNDMuNjFsNTMuMDEtOTguNjQsMjMuMDUtNDEuMDJjLTcuNC0xMy4zOS0xNi4zOC0yNS44NS0yNi43My0zNy4xMUMyNjguNzEtNS4xMywxNDkuNzctMTAuNDUsNzMuMTEsNTkuNjQtMy41NCwxMjkuNzItOC44NywyNDguNjcsNjEuMjIsMzI1LjMzYzcwLjA5LDc2LjY1LDE4OS4wNCw4MS45OCwyNjUuNjksMTEuODksMzAuMTUtMjcuNTcsNTAuNS02NC4yMSw1Ny45OS0xMDQuMzZsLTM3LjExLTQuMTVoMFpNMTk5LjYxLDI1Ny43NGMtMzIuMzMsMC01OC41My0yNi4yLTU4LjUzLTU4LjUzczI2LjItNTguNTMsNTguNTMtNTguNTMsNTguNTMsMjYuMiw1OC41Myw1OC41My0yNi4yLDU4LjUzLTU4LjUzLDU4LjUzIi8+Cjwvc3ZnPg==)](http://dimigo.hs.kr) [![C](https://img.shields.io/badge/c-%2300599C.svg?logo=c&logoColor=white)](https://www.c-language.org/) [![수행](https://img.shields.io/badge/프로그래밍-4E5E3E)](http://github.com/expo94718-dimigo/C-Calender)

### 개요
본 프로젝트는 C언어를 사용하여 간단한 2026년 6월 캘린더를 구현하는것을 목적으로 제작되었습니다.
함수 위에 함수의 내용을 설명하는 주석을 달아 코드를 이해하기 쉽게 하기 위하여 노력하였습니다.

### 프로젝트 소개
본 프로젝트는 2026년 6월 달력을 화면에 출력하여 화살표 키를 사용하여 커서를 움직이는 방식으로
일정을 수정, 조회, 삭제 할 수 있도록 만들었습니다.

### 사용된 문법
본 프로젝트에는 다음의 문법이 사용되었습니다.
* 변수
* 연산자
* 함수
* 조건문
* 반복문
* 배열
* 다차원 배열
* 구조체
* 포인터

### 사용 방법
본 프로젝트는 CLI 환경에서 구동되도록 작성되었습니다.
프로젝트를 CLI 환경에서 구동 시 아래와 같은 화면이 출력됩니다.
```text
=====================================================
    Sun    Mon    Tue    Wed    Thu    Fri    Sat

             1      2      3      4      5      6
      7      8      9     10     11     12     13
     14     15     16     17     18     19     20
     21     22     23     24     25     26     27
     28     29     30

[Enter] 를 눌러 일정을 조회 및 관리
```

이 화면에서 화살표 키를 사용해 날짜를 이동할 수 있습니다.
원하는 날짜에 커서를 올린 후 [Enter] 를 누르면 일정이 표시됩니다.

```text
=====================================================
    Sun    Mon    Tue    Wed    Thu    Fri    Sat

             1      2      3      4      5      6
      7      8      9     10     11     12     13
     14     15     16     17     18     19     20
     21     22     23     24     25     26     27
     28     29     30
=====================================================
2026년 6월 24일
[1] 추가/수정 [2] 제거 [Enter] 달력으로 이동

1. 이 칸에 일정이 없습니다.
2. 이 칸에 일정이 없습니다.
3. 이 칸에 일정이 없습니다.
4. 이 칸에 일정이 없습니다.
5. 이 칸에 일정이 없습니다.
```

여기서, [1][2][Enter] 키를 눌러 일정을 수정 제거 및 달력 이동이 가능해집니다.

### 사용된 헤더
* stdio.h
* stdlib.h
* string.h
* time.h
* conio.h

**stdio.h**
> 표준입출력 함수를 포함하고 있는 헤더입니다.

**stdlib.h**
> 포인터 관련 함수 및 기타 표준 함수 다량을 포함하고 있는 헤더입니다.

**string.h**
> memset 을 포함한 문자열 및 배열 관련 함수를 포함하고 있는 헤더입니다.

**time.h**
> 시간과 날짜를 다루는 time_h 구조체를 포함하고 있는 헤더입니다.

**conio.h**
> 달력 조종을 위한 화살표키 입력을 받기 위한 헤더입니다.

### 저작권
ⓒ No rights reserved.
