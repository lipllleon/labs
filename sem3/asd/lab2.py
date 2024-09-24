from lab1 import check_brackets

def priority(operator):
    if operator in ('+', '-'):
        return 1
    elif operator in ('*', '/'):
        return 2
    return 0

def get_RPN(expr):  #Reverse Polish Notation
    output = []
    stack = []
    
    isDigit = False
    for symbol in expr:
        if symbol.isdigit():
            if isDigit:
                output.append(output.pop()*10 + int(symbol))
            else:
                output.append(int(symbol))
            isDigit = True
        elif symbol in ('+', '-', '*', '/'):
            while (stack and stack[-1] != '(' and priority(stack[-1]) >= priority(symbol)):
                output.append(stack.pop())
            stack.append(symbol)
            isDigit = False
        elif symbol == '(':
            stack.append(symbol)
            isDigit = False
        elif symbol == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()
            isDigit = False
    
    while stack:
        output.append(stack.pop())
    
    print(output)
    return output

def evaluate_math_expression(expr):
    stack = []
    
    for element in expr:
        if isinstance(element, int):
            stack.append(element)
        else:
            b = stack.pop()
            a = stack.pop()
            if element == '+':
                stack.append(a + b)
                print(f'{a} + {b} = {a + b}')
            elif element == '-':
                stack.append(a - b)
                print(f'{a} - {b} = {a - b}')
            elif element == '*':
                stack.append(a * b)
                print(f'{a} * {b} = {a * b}')
            elif element == '/':
                if b == 0:
                    print(f"Ошибка: деление на ноль ({a} / {b})")
                    return
                stack.append(a / b)
                print(f'{a} / {b} = {a / b}')
    
    return stack.pop()

def eval_expr(expression):
    expr = expression.strip()
    
    if not check_brackets(expr):
        print("Ошибка: скобки расставлены неверно")
        return
    if not expr.endswith('='):
        print("Ошибка: выражение должно заканчиваться на '='")
        return
    expr = expr[:-1].strip()
    
    expr = get_RPN(expr)
    return evaluate_math_expression(expr)
    

def main():
    expression = input("Введите математическое выражение (заканчивается на '='):\n")
    result = eval_expr(expression)
    if result != None:
        print("Результат:", result)

if __name__ == "__main__":
    main()