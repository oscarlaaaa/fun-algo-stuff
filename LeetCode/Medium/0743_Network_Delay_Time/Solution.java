import java.util.*;

class QueueItem implements Comparable<Object> {
    public int node;
    public int dist;

    public QueueItem(int node, int dist) {
        this.node = node;
        this.dist = dist;
    }

    public int compareTo(Object y) {
        return this.dist - ((QueueItem) y).dist;
    }
    
    public String toString() {
        return "[" + node + ": " + dist + "]";
    }
}

// 2022-05-13
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        int[][] adjGraph = new int[n+1][n+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adjGraph[i][j] = -1;
            }
        }
        for (int[] time : times) {
            adjGraph[time[0]][time[1]] = time[2];
        }
        
        int[] dist = new int[n+1];
        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }
                
        PriorityQueue<QueueItem> pq = new PriorityQueue<>();
        pq.add(new QueueItem(k, 0));
    
        while (pq.size() > 0) {
            QueueItem item = pq.poll();
            if (dist[item.node] != -1 && item.dist >= dist[item.node]) continue;
            
            dist[item.node] = item.dist;
            for (int i = 1; i < adjGraph.length; i++) {
                if (adjGraph[item.node][i] != -1) {
                    pq.add(new QueueItem(i, item.dist + adjGraph[item.node][i]));
                }
            }
        }
        
        int max = Arrays.stream(dist).max().getAsInt();
        int min = Arrays.stream(dist).min().getAsInt();
        return min != -1 ? max : -1;
    }
}