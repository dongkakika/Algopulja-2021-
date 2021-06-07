import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    static int n;
    static int[][] map;
    static boolean[][] visited;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        n = Integer.parseInt(br.readLine());
        map = new int[n+1][n+1];
        visited = new boolean[n+1][n+1];

        // 단지 안의 집 수 저장
        List<Integer> list = new ArrayList<>();

        // 집 정보 입력
        for(int i=1; i<=n; i++){
            String input = br.readLine();
            for(int j=1; j<=n; j++){
                map[i][j] = input.charAt(j-1) - '0';
            }
        }

        // dfs
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(checkThis(i, j)){
                    // 단지 안의 모든 집 수
                    int cnt = dfs(i, j);
                    list.add(cnt);
                }
            }
        }

        Collections.sort(list);
        sb.append(list.size() + "\n");
        for(int i: list) sb.append(i + "\n");
        System.out.println(sb);
    }

    public static int dfs(int x, int y){
        // 체크해보고 해당 장소가 '알맞은' 집인 경우, 합
        int cnt = 1; // 최초 call --> 한 번 checkThis 실행
        visited[x][y] = true;

        if(checkThis(x-1, y)) cnt += dfs(x-1, y);
        if(checkThis(x+1, y)) cnt += dfs(x+1, y);
        if(checkThis(x, y-1)) cnt += dfs(x, y-1);
        if(checkThis(x, y+1)) cnt += dfs(x, y+1);

        return cnt;
    }

    public static boolean checkThis(int x, int y){
        // 맵을 벗어나는 경우
        if(x<1 || x>n || y<1 || y>n) return false;
        // 지나간 경로 or 집이 아닌(0) 경우
        if(visited[x][y] == true || map[x][y] == 0) return false;

        return true;
    }
}