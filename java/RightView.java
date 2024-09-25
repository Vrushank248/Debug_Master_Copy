
import java.util.*;

class Node
{
    int data;
    Node left, right;

public Node(int data)
    {
        this.data = data;
        left = right = null;
    }
}

class RightView
{
    // Function to return list containing elements of the right view of a binary tree.
public List<Integer> rightView(Node root)
    {
        List<Integer> result = new ArrayList<>();
        if (root == null)
            return result;

        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                Node curr = q.poll();

                // If it's the last node of the current level, add it to result
                if (i == n - 1)
                {
                    result.add(curr.data);
                }

                // First push left, then right child to ensure right view
                if (curr.left != null)
                    q.add(curr.left);
                if (curr.right != null)
                    q.add(curr.right);
            }
        }

        return result;
    }

public static void main(String[] args)
    {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.right = new Node(5);
        root.right.right = new Node(4);

        RightView sol = new RightView();
        List<Integer> rightView = sol.rightView(root);

        System.out.println("Right view of the binary tree: " + rightView);
    }
}

