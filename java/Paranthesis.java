import java.util.Stack;

public class Paranthesis
{

    // Function to check if the expression is balanced
public static boolean isBalanced(String exp)
    {
        Stack<Character> stack = new Stack<>();
        for (char ch : exp.toCharArray())
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (stack.isEmpty())
                    return false;
                char top = stack.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    // Driver code
public static void main(String[] args)
    {
        String exp = "[()]{}{[()()]()}";
        if (isBalanced(exp))
            System.out.println("balanced");
        else
            System.out.println("not balanced");
    }
}

