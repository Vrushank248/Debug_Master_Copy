def InfixtoPostfix(exp):
        
        stack = []
        operators = {'^':1, '*':2, '/':2, '-':3, '+':3}  
        postfix = "" 
        
        for i in exp:
            if i.isalnum():
                postfix += i
            elif i == '(':
                stack.append(i)
            elif i == ')':
                pop = stack.pop()
                while len(stack)!=0 and pop != '(':
                    postfix += pop
                    pop = stack.pop()
            else:
                while len(stack)!=0 and stack[-1] != '(' and operators[stack[-1]] <= operators[i]:
                    postfix += stack.pop()
                stack.append(i)
        while len(stack)!=0:
            postfix += stack.pop()
        return postfix

exp = input()
print(InfixtoPostfix(exp))