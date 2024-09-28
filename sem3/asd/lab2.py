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
    
    number = ''
    isLastOperator = False
    for symbol in expr:
        if symbol in "0123456789.":
            number += symbol
            continue
        elif number:
            output.append(float(number))
            number = ''
            isLastOperator = False
        if symbol in ('+', '-', '*', '/'):
            if isLastOperator:
                print("Ошибка: проверьте запись выражения!")
                return
            while (stack and stack[-1] != '(' and priority(stack[-1]) >= priority(symbol)):
                output.append(stack.pop())
            stack.append(symbol)
            isLastOperator = True
        elif symbol == '(':
            stack.append(symbol)
        elif symbol == ')':
            while stack and stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()
        else:
            print("Ошибка: проверьте запись выражения!")
            return
    if number:
        output.append(float(number))
    while stack:
        output.append(stack.pop())
    
    return output

def evaluate_RPN(expr):
    stack = []
    
    for element in expr:
        if isinstance(element, float):
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
    
    RPN = get_RPN(expr)
    if RPN == None:
        return
    return evaluate_RPN(RPN)
    

def main():
    expression = input("Введите математическое выражение (заканчивается на '='):\n")
    result = eval_expr(expression)
    if result != None:
        print("Результат:", result)

if __name__ == "__main__":
    main()