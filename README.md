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
cat - ./cat [파일명] (한줄이 255가 넘는다면 에러를 띄웁니다.)(1개 이상 띄웁니다.)
pwd - ./pwd
cd - ./cd [폴더명]
mkdir - ./mkdir [폴더명]
ls - ./ls
history - history
![number] - ![number]
ps - ./ps
cp - ./cp [파일명]
rm - ./rm [파일명] (폴더 안에 뭐가 있으면 삭제가 안되게 구현하였습니다.)
ln - ./ln [파일 및 폴더명]
lns - ./lns [파일 및 폴더명] (실수로 만들었습니다..)
stat - ./stat [파일 및 폴더명]
chmod - ./chmod[파일 및 폴더명]
alias - alias / alias 단축=“내용” / 단축 -> 내용 (Shell이 실행될 때 초기화)
exit - exit / C^ 
