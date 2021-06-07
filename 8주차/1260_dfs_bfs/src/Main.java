import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int map[][];
    static boolean[] visit;
    static int n, m, v;

    public static void dfs(int i){
        visit[i] = true;
        System.out.print(i+" ");
        // 정점의 번호는 1부터 시작
        for(int j=1; j<n+1; j++){
            if(map[i][j] == 1 && visit[j] == false){
                dfs(j);
            }
        }
    }

    public static void bfs(int i){
        Queue<Integer> q = new LinkedList<>();
        // 시작 정점부터 queue 넣고 진행
        q.offer(i);
        visit[i] = true;

        while(!q.isEmpty()){
            int front = q.poll(); // 첫번째 값 반환하고 제거, 비었다면 null
            System.out.print(front + " ");

            for(int j=1; j<=n; j++){
                if(map[front][j] == 1 &&  visit[j] == false){
                    q.offer(j);
                    visit[j] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        String s = br.readLine();
        // n, m, v 정보 입력
        StringTokenizer st = new StringTokenizer(s, " "); // 공백 하나만큼 건너뛰고 받음
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        // 동적으로 n보다 하나 더만큼 생성
        map = new int[n+1][n+1];
        visit = new boolean[n+1];

        // 초기화
        for(int j=0; j<n+1; j++){
            Arrays.fill(map[j], 0);
        }
        Arrays.fill(visit, false);

        // 간선 정보 입력
        for (int i=0; i<m; i++){
            String edge = br.readLine();
            StringTokenizer st1 = new StringTokenizer(edge, " ");
            int a = Integer.parseInt(st1.nextToken());
            int b = Integer.parseInt(st1.nextToken());
            map[a][b]=1;
            map[b][a]=1;
        }

        dfs(v);
        System.out.println();

        // 방문 정보 초기화
        Arrays.fill(visit, false);

        bfs(v);
    }

}
