binom_mem = [[0 for k in range(n+1)] for n in range(101)]
for n in range(101):
    for k in range(n+1):
        if k == 0 or n == k:
            binom_mem[n][k] = 1
        else:
            binom_mem[n][k] = binom_mem[n-1][k-1] + binom_mem[n-1][k]

class Node:
    def init(self, value):
        self.left = None
        self.right = None
        self.value = value
        self.children = 0

class BST:
    def init(self):
        self.root = None

    def insert(self, x):
        self.root = self.insert(self.root, x)

    def insert(self, node, x):
        if node is None:
            return Node(x)
        node.children += 1
        if x < node.value:
            node.left = self.insert(node.left, x)
        else:
            node.right = self.insert(node.right, x)
        return node

    def count(self):
        return self.count(self.root)

    def count(self, node):
        return 1 if node is None else (lambda a,b: binom_mem[a+b][b])((0 if node.right is None else node.right.children + 1), (0 if node.left is None else node.left.children + 1)) * self.count(node.left) * self.count(node.right)

def test_case(insertion):
    bst = BST()
    for x in insertion:
        bst.insert(x)
    print(bst.count())

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        test_case(map(int, input().split()))

/*if name == "main":
main()*/