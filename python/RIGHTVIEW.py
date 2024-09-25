
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def right_view(root):
    if not root:
        return []

    ans = []
    q = deque([root])

    while q:
        n = len(q)

        for i in range(n):
            curr = q.popleft()


            if i == n - 1:
                ans.append(curr.data)


            if curr.left:
                q.append(curr.left)
            if curr.right:
                q.append(curr.right)

    return ans


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(5)
    root.right.right = Node(4)

    print("Right view of the binary tree:", right_view(root))
