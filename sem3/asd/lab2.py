from lab1 import check_brackets

def priority(operator):
    if operator in ('+', '-'):
        return 1
    elif operator in ('*', '/'):
        return 2
    return 0

def transformation(expr):
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
    
    for c in expr:
        if isinstance(c, int):
            stack.append(c)
        else:
            b = stack.pop()
            a = stack.pop()
            if c == '+':
                stack.append(a + b)
                print(f'{a} + {b} = {a + b}')
            elif c == '-':
                stack.append(a - b)
                print(f'{a} - {b} = {a - b}')
            elif c == '*':
                stack.append(a * b)
                print(f'{a} * {b} = {a * b}')
            elif c == '/':
                if b == 0:
                    print(f"Ошибка: деление на ноль ({a} / {b})")
                    return
                stack.append(a / b)
                print(f'{a} / {b} = {a / b}')

    return stack.pop()

def eval_expr():
    expr = input("Введите математическое выражение (заканчивается на '='):\n").strip()
    
    if not check_brackets(expr):
        print("Ошибка: скобки расставлены неверно")
        return
    if not expr.endswith('='):
        print("Ошибка: expr должно заканчиваться на '='.")
        return
    
    expr = expr[:-1].strip()
    expr = transformation(expr)
    result = evaluate_math_expression(expr)
    if result != None:
        print("Результат:", result)

# Запуск функции
eval_expr()