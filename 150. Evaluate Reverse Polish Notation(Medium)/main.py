class Solution:
    def evalRPN(self, tokens: list) -> int:
        my_stack = []
        for token in tokens:
            if token in ["+","-","*","/"]:
                no1 = my_stack.pop()
                no2 = my_stack.pop()
                if token == "+":
                    my_stack.append(no2+no1)
                elif token == "-":
                    my_stack.append(no2-no1)
                elif token == "*":
                    my_stack.append(no2*no1)
                elif token == "/":
                    my_stack.append(int(no2/no1))
            else:
                my_stack.append(int(token))
        return int(my_stack.pop())