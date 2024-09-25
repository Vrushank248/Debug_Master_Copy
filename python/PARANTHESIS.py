
def isBalanced(x):
    stack = []

    brackets = {')': '(', '}': '{', ']': '['}
    
    for char in x:

        if char in brackets.values():
            stack.append(char)

        elif char in brackets.keys():

            if stack == [] or stack.pop() != brackets[char]:
                return False

    return stack == []


expression = "[()]{}{[()()]()}"
if isBalanced(expression):
    print("balanced")
else:
    print("not balanced")
