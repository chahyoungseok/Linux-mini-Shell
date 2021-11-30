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

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#프로젝트-소개">프로젝트 소개</a>
      <ul>
        <li><a href="#환경-설정">환경 설정</a></li>
      </ul>
    </li>
    <li>
      <a href="#1.-구현한-명령어-목록">구현한 명령어 목록</a>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
     <li><a href="https://www.youtube.com/watch?v=eYo_AbOF7cA">Youtube Link</a></li>
  </ol>
</details>

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
 ![image](https://user-images.githubusercontent.com/29851990/143996770-00a7660e-3672-4d2b-9a92-d9dfc894f17b.png)<br>
 - ls (현재 디렉토리에 있는 파일 이름을 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143996946-2242edbc-5e34-49ab-ba31-686abfefdb36.png)<br>
 - cat (다수의 파일을 화면에 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997016-b23cac7f-b9cd-41ab-9be7-74621408b15d.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997226-69dda4fc-0447-4db5-9119-0c951c5745a4.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997258-db491e73-ee50-44f7-bb2b-aa0b24d8a2d1.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997278-69e21b10-090c-4d0d-a353-e7977127094d.png)<br>
 - pwd (현재 working 디렉토리 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997343-338889ff-5f59-4416-b3bb-4b5f8da9e13e.png)<br>
 - mkdir (디렉토리 생성)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997386-fa0f4881-d74d-4da6-9278-df1452c49bed.png)<br>
 - cd (working 디렉토리 변경)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997415-d6e0df29-c6fc-4455-b4a4-03c42b9b114e.png)<br>
 - ps (실행중인 process를 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997447-8ee75015-2fc2-47eb-b6ac-6978cd35f34b.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997473-fe5b5f10-196a-4fd1-b8fb-2dbb8bcd7915.png)<br>
 - cp (파일 복사)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997504-b5fb1c8c-bcd4-43a1-bda7-47ca7e4f8fd5.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997514-85306f63-cfc8-46d2-9f83-28b0de9c8873.png)<br>
 - history 및 ![number] (과거 사용된 명령어를 출력 및 재실행)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997532-17469e8f-67b8-4c2b-8848-85ce26caf593.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997538-68357167-0f58-43df-bdb9-f43946de311a.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997544-b4dd391f-d14b-4620-8893-f86d5c8d4233.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997551-94f7c257-a7eb-41e8-ab7d-7992aa2b8564.png)<br>
 - stat (파일의 status 출력)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997588-c19715ed-2fac-4bb6-9bb8-d1353b043dc6.png)<br>
 - chmod (파일의 permission을 변경)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997627-4efdb49d-cba6-4a41-8921-8e06ea944dac.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997636-8344656a-1175-402b-85e0-55f35a25dfb0.png)<br>
 - exit / C^ (Shell 종료)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997658-fdcc4c11-805c-496c-be7d-82a401e56f14.png)<br>
 - rm (파일 및 폴더 삭제 / 폴더안에 무언가 들어가있다면 삭제안됨)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997693-6fa5009c-448b-477c-ab60-0976f8aa9ffe.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997725-ae896fdd-f9c5-4210-846f-4bc651724189.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997733-aa0ea423-ba12-4707-995e-97e3ed104a57.png)<br>
 - alias (명령어를 alias)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997756-e6aead4c-7cc0-42c2-b25b-773e00749dfe.png)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997761-831fe3f9-c17d-492a-acd9-c4e5f6469990.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997772-56f00339-55b0-4652-881b-ef379242354d.png)<br>
 - lns (심볼릭링크)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997808-5222ad37-42b7-4b10-a84c-9814e881f30a.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997821-e5f19f7d-75fc-49ec-b38e-3a6eb185c7c9.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997828-3ebb4e57-fda9-443a-861a-2174d8348571.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997835-6a20f12e-1d6e-44de-a0e8-4d440ff363ac.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997842-7fc270eb-56ab-4c0d-95e5-d566f4da7a59.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997844-55d4199b-b1ee-4103-a5e2-74f994178b12.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997847-b7ca6eb1-c1e3-4245-9f1a-950bc4cbe8d4.png)
 ![image](https://user-images.githubusercontent.com/29851990/143997854-3f274688-a37e-417f-b2e6-aefaf93fa31c.png)<br>
 - ln (하드링크)<br>
 ![image](https://user-images.githubusercontent.com/29851990/143997888-5f9fa114-aea4-45ea-bff2-d48ce3922a79.png)

 
