# KMP

## 개요
* 긴 문자열 안에서 특정 부분 문자열을 찾는 문자열 매칭 알고리즘

## 복잡도
O(N + M)
###### N: 전체 문자열의 길이, M: 찾고자 하는 문자열의 길이

## 특징
* 이미 매치된 글자는 다시 비교하지 않는다.
* 매칭이 이루어지지 않았을때 되돌아갈 위치를 저장하는 사전작업을 수행한다.

## 기억에 남는 문제
백준 4354 (https://www.acmicpc.net/problem/4354) : Failure Function을 이용하는 문제  
백준 1701(https://www.acmicpc.net/problem/1701) : Failure Function을 이용하여 LRS(Longest Repeated Substring)를 구하는 문제
백준 10266 (https://www.acmicpc.net/problem/10266)
