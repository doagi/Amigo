# Amigo_CRA9th

## 0. Coding rule
- https://github.com/doagi/Amigo/wiki/Amigo%ED%8C%80-%EA%B7%9C%EC%B9%99

## 1. Request
### 1.1. 사원 정보를 관리하는 프로그램을 구현한다
- 사원 정보는 사원 번호, 성명, 직급, 전화번호, 생년월일, certi 등급을 포함한다

    |정보명|설명|Column명|
    |:---:|---|:---:|
    |사원번호|8자리 숫자로 구성<br>맨 앞 두 자리는 입사 년도를 의미<br>⁠69XXXXXX(1969년)~21XXXXXX(2021년)|employeeNum
    |성명|최대 15자리로 구성 (이름과 성이 띄어쓰기로 구분)<br>⁠영어 대문자로만 구성|name
    |경력개발단계|CL1, CL2, CL3, CL4 로 구성|cl
    |전화번호|010-xxxx-xxxx 형식으로 구성 (앞자리는 010 으로 고정)|phoneNum
    |생년월일|YYYYMMDD 형식으로 구성|birthday
    |CERTI|ADV, PRO, EX 로 구성|certi

### 1.2. 명령어의 형식
- 명령어는 지정된 형식으로 작성이 되며 작성된 명령어에 따라 정상적인 명령을 수행해야 한다.
- 명령어는 적용되는 옵션에 따라 기능이 변경된다.

    |||설명|
    |:---:|:---:|---|
    |명령어|ADD|새로운 사원 정보를 추가한다|
    ||DEL|조건에 부합하는 사원 정보를 삭제한다|
    ||SCH|조건에 부합하는 사원 정보를 검색한다|
    ||MOD|조건에 부합하는 사원 정보를 수정한다|
    |옵션1|-p|출력 옵션이 적용되면 조건에 부합하는 record가 줄 단위로 출력한다|
    |옵션2|-f / -l|-f : 성명의 이름으로 검색 / -l : 성명의 성으로 검색|
    ||-m / -l|-m : 전화 번호 중간 자리로 검색 / -l : 전화 번호 뒷자리로 검색|
    ||-y / -m / -d|-y : 생년월일의 연도로 검색 / -m : 생년월일의 월로 검색 / -d : 생년월일의 일로 검색|
    |옵션3|없음|실습에 집중하기 위하여 요구사항 삭제|

## 2. 실행 및 입출력
- Input / output 형태는 txt 파일이며, input file을 read하여, output file을 생성한다.
- main 함수의 argument(parameter) 로 input 파일과 output file을 받는다.
  ```bash
  Amigo.exe input.txt output.txt
  ```
  |Input|Output|
  |---|---|
  |ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO<br>ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV<br>ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO<br>...||
  |SCH,-p,-d, ,birthday,04<br>MOD,-p, , ,name,FB NTAWR,birthday,20050520<br>SCH, , , ,employeeNum,79110836<br>DEL, , , ,employeeNum,18115040<br>...|SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV<br>MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO<br>SCH,NONE<br>DEL,1<br>...|

## 3. 구조 설계
- (ToDo)