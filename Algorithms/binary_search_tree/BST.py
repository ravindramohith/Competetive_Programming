class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
        self.adjList = {}
        self.queue = []
        self.visited = False

    def insert(self, data):
        if self.data is None:
            self.data = data
        else:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)

            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)

    def printTree(self, prefix="", is_left=None):
        if self is not None:
            print(prefix, end="")
            print("├── " if is_left else "└── ", end="")
            print(self.data)

            if self.left is not None or self.right is not None:
                new_prefix = prefix + ("│   " if is_left else "    ")
                if self.left is not None:
                    self.left.printTree(new_prefix, True)
                if self.right is not None:
                    self.right.printTree(new_prefix, False)

    def makeAdjlist(self):
        def traverse(node):
            if node:
                if node.data not in self.adjList:
                    self.adjList[node.data] = []
                if node.left:
                    self.adjList[node.data].append(node.left.data)
                if node.right:
                    self.adjList[node.data].append(node.right.data)
                traverse(node.left)
                traverse(node.right)

        traverse(self)

    def BFS(self):
        queue = [self.data]
        visited = []

        while queue:
            node = queue.pop(0)
            visited.append(node)
            [queue.append(x) for x in self.adjList[node]]

        print(visited)


def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)


def preorder(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)


def postorder(root):
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")


# def BFS(root):
#     if root is None:
#         return
#     else:


tree = Node(10)
insert_values = [4, 15, 7, 12, 2, 20, 9, 17, 5, 1, 8, 19, 11, 3, 14, 16, 6, 13, 18, 25]
for value in insert_values:
    tree.insert(value)

print("PreOrder Traversal: ")
preorder(tree)
print("\n", "-" * 20)
print("Inorder Traversal: ")
inorder(tree)
print("\n", "-" * 20)
print("PostOrder Traversal: ")
postorder(tree)
print("\n", "-" * 20)
tree.printTree()


tree.makeAdjlist()
print(tree.adjList)
tree.BFS()

a = [10, 4, 2, 1, 3, 7, 5, 6, 9, 8, 15, 12, 11, 14, 13, 20, 17, 16, 19, 18, 25]
b = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25]


def construct(a, b):
    root_index = -1
    for i in range(len(a)):
        if b.count(a[i]):
            root_index = i
            break

    new_ = Node(a[root_index])
    right, left = b[b.index(a[root_index]) + 1 :], b[: b.index(a[root_index])]


def construct(a, b):
    if not a or not b:
        return None

    root_data = a[0]
    root = Node(root_data)

    root_index_inorder = b.index(root_data)

    left_inorder = b[:root_index_inorder]
    right_inorder = b[root_index_inorder + 1 :]

    left_preorder = a[1 : len(left_inorder) + 1]
    right_preorder = a[len(left_inorder) + 1 :]

    root.left = construct(left_preorder, left_inorder)
    root.right = construct(right_preorder, right_inorder)

    return root


root = construct(a, b)


postorder_list = []


def make_postorder_list(root):
    if root is None:
        return
    make_postorder_list(root.left)
    make_postorder_list(root.right)
    postorder_list.append(root.data)


make_postorder_list(root)

print("Postorder Traversal List:")
print(postorder_list)

print("Constructed Tree:")
postorder(root)
