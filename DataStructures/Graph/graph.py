class Graph:
    def __init__(self, edges, nodes):
        self.edges = edges
        self.nodes = nodes
        self.adjacent = {}
        self.visited = {}
        for i in range(nodes):
            self.visited[i] = False

    def add_edge(self, u, v, direction):
        if u in self.adjacent:
            self.adjacent[u].append(v)
        else:
            self.adjacent[u] = [v]
        if not direction:
            if v in self.adjacent:
                self.adjacent[v].append(u)
            else:
                self.adjacent[v] = [u]

    def print_adj_list(self):
        for i, neighbors in self.adjacent.items():
            neighbor_str = " ".join(map(str, neighbors))
            print(f"{i} -> {neighbor_str}")

    def BFS(self):
        ans = []

        def bfs(node):
            queue = []
            queue.append(node)
            self.visited[node] = True

            while len(queue) > 0:
                front_node = queue.pop(0)
                ans.append(front_node)

                for i in self.adjacent[front_node]:
                    if not self.visited[i]:
                        queue.append(i)
                        self.visited[i] = True

        for i in range(self.nodes):
            if not self.visited[i]:
                bfs(i)

        print("BFS traversal:", ans)



if __name__ == "__main__":
    n = int(input("Enter number of nodes: "))
    m = int(input("Enter number of edges: "))

    print("Enter the edges:")
    undirected_graph = Graph(m, n)
    for _ in range(m):
        u, v = map(int, input().split())
        undirected_graph.add_edge(u, v, False)

    undirected_graph.print_adj_list()
    undirected_graph.BFS()
