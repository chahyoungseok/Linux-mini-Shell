# Linux-mini-Shell
### Unbuntu Linux 안에서의 mini Shell 구현

<p align="center">
<img src="https://img.shields.io/badge/license-mit-green">
<img src="https://img.shields.io/github/issues/hongjin4790/SYE-project">
<img src="https://img.shields.io/badge/tag-v1.0.0-blue">
<img src="https://img.shields.io/badge/C Launage-007396?style=flat-square&logo=C&logoColor=white"/>
<img src="https://img.shields.io/badge/Linux-4479A1?style=flat-square&logo=Linux&logoColor=white"/>
<br>
</p>

## 1. 구현한 명령어 목록
> Unbuntu Linux안에서 지원하는 실제 기능들을 구현
 - cat
 - pwd
 - cd
 - mkdir
 - ls
 - history
 - ![number] - history 기능
 - ps
 - cp
 - rm
 - ln (hardlink)
 - lns (symlink)
 - stat
 - chmod
 - alias
 - exit

## 2. 구현한 명령어에 대한 설명 및 사용예제
 - cat - ./cat [파일명] (한줄이 255가 넘는다면 에러를 띄웁니다.)
 - pwd - ./pwd
 - cd - ./cd [폴더명]
 - mkdir - ./mkdir [폴더명]
 - ls - ./ls
 - history - history
 - ![number] - ![number]
 - ps - ./ps
 - cp - ./cp [파일명]
 - rm - ./rm [파일명] (폴더 안에 뭐가 있으면 삭제가 안되게 구현하였습니다.)
 - ln - ./ln [파일 및 폴더명]
 - lns - ./lns [파일 및 폴더명]
 - stat - ./stat [파일 및 폴더명]
 - chmod - ./chmod[파일 및 폴더명]
 - alias - alias / alias 단축=“내용” / 단축 -> 내용 (Shell이 실행될 때 초기화)
 - exit - exit / C^ 

## 3. 주요 코드에 대한 코드 분석
![image](https://user-images.githubusercontent.com/29851990/143995893-37421e93-0a65-42d2-bc14-96b1bd715c91.png)<br>
문자열의 첫 번째 문자를 없애는 함수입니다.<br><br>
![image](https://user-images.githubusercontent.com/29851990/143996448-ae838604-5960-48cc-95a0-54f6a134a64f.png)<br>
명령어 하나당 프로세스 생성 및 wait를 하는 코드입니다.<br>
exec 계열의 execv를 사용하였고, argv는 strtok를 활용하였습니다.<br><br>
![image](https://user-images.githubusercontent.com/29851990/143996481-b7f2c87c-60a4-4290-aa63-98acac4d65c9.png)<br>
아스키코드를 활용하여 “1000    ” 형태에서 빈공간을 때어냅니다.<br>
특수상황에만 활용되게 제작되었습니다.<br><br>
![image](https://user-images.githubusercontent.com/29851990/143996511-62eb6e2a-7d28-4444-a38c-0e5610858edf.png)<br>
문자열과 숫자 n을 인자로 전달하면 문자열의 n번째까지 삭제시킵니다.<br><br>

## 4. 테스트 결과 내용 표시
 - start (mini shell 시작 명령어)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143996770-00a7660e-3672-4d2b-9a92-d9dfc894f17b.png)
 - ls (현재 디렉토리에 있는 파일 이름을 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143996946-2242edbc-5e34-49ab-ba31-686abfefdb36.png)

