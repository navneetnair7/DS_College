
import java.util.*;

public class graph {
    static int[][] adjMatrix = new int[7][7];
    static graphNode[] adjList = new graphNode[7];
    public static void main(String[] args) {

        addEdges(5,6);
        addEdges(5,3);
        addEdges(4,2);
        addEdges(4,3);
        addEdges(0,2);
        addEdges(0,1);
        addEdges(6,5);
        addEdges(2,5);
        addEdges(2,0);
        addEdges(2,6);
        addEdges(1,3);
        addEdges(3,4);
        addEdges(3,1);

        System.out.println(Arrays.toString(adjMatrix[0]));
        for (int i = 0; i < 7  ; i++) {

            adjList[i] = new graphNode(i);

        }

        addToList(adjList, 5, 6);
        addToList(adjList, 5, 3);
        addToList(adjList, 4, 2);
        addToList(adjList, 4, 3);
        addToList(adjList, 0, 2);
        addToList(adjList, 0, 1);
        addToList(adjList, 6, 5);
        addToList(adjList, 2, 5);
        addToList(adjList, 2, 0);
        addToList(adjList, 2, 6);
        addToList(adjList, 1, 3);
        addToList(adjList, 3, 4);
        addToList(adjList, 3, 1);
        //System.out.println(adjList[5].next.next.value);

        DFS(1);
        System.out.println(" ");
        BFS(2);

    }

    public static void addEdges(int i, int j){
        adjMatrix[i][j] = 1;
    }

    public static void addToList(graphNode[] arr, int i, int j){
        graphNode temp = arr[i];
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = new graphNode(j);
    }

    //DEPTH FIRST SEARCH:
    public static void DFS(int v){
        boolean[] visited = new boolean[7];
        DFSUtil(v, visited);
    }

    public static void DFSUtil(int v, boolean[] visited){
        visited[v] = true;

        System.out.print(v + " ");

        graphNode temp = adjList[v];
        while (temp.next != null ){

            int n = temp.next.value;

            if (!visited[n]){

                DFSUtil(n, visited);

            }

            temp = temp.next;

        }
    }

    //BREADTH FIRST SEARCH:

    public static void BFS(int v){
        boolean[] visited = new boolean[7];
        Queues q = new Queues();
        visited[v] = true;
        q.enqueue(v);

        while (!q.isEmpty()){
            v = q.dequeue();
            System.out.print(v + " ");

            graphNode temp = adjList[v];

            while (temp.next != null){

                int n = temp.next.value;
                if (!visited[n]){

                    visited[n] = true;
                    q.enqueue(n);

                }
                temp = temp.next;

            }

        }
    }

}

class graphNode{
    int value;
    graphNode next;

    graphNode(int value){
        this.value = value;
        next = null;
    }
}

class Queues {
    int size = 7;
    int[] q = new int[size];
    int front = -1;
    int rear = -1;

    public boolean isFull() {
        if (front == 0 && rear == size - 1) {
            return true;
        }
        return false;
    }

    public boolean isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }

    public void enqueue(int x) {
        if (isFull()) {
            System.out.println("the queue is already full");
        }
        if (isEmpty()) {
            q[++front] = x;
            rear = 0;
        } else {
            q[++rear] = x;
        }
    }

    public int dequeue() {
        if (isEmpty()) {
            return 0;
        } else {
            int element = q[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }
            return element;
        }

    }
    public void display(){
        for (int i = front; i <= rear ; i++) {
            System.out.println(q[i]);
        }
    }
}
