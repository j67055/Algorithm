# 단절점과 단절선

## 개요
  #### 단절점
    연결된 무방향 그래프에서 어떤 정점을 제거했을 때 그 그래프가 더 이상 연결되지 않도록 만드는 정점.
  #### 단절선
    연결된 무방향 그래프에서 어떤 간선을 제거했을 때 그 그래프가 더 이상 연결되지 않도록 만드는 간선.

## 복잡도
O(V + E)  

## 특징
* num 배열과 low배열을 사용한다.  
  #### num 배열
      DFS의 방문 순서를 저장하는 배열.  
  #### low 배열
      임의의 정점에서부터 DFS 스패닝 서브 트리상 도달 가능한 정점들의 num 값의 최소값을 저장하는 배열.
* u -> v 순으로 DFS를 방문할 때 num[u] <= low[v]를 만족하면 단절점이다.
* u -> v 순으로 DFS를 방문할 때 num[u] < low[v]를 만족하면 단절선이다.
* 그래프의 시작 정점의 단절점 판별은 자식의 개수를 세어 예외 처리 한다.
