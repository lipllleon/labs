def check_brackets(string):
    stack = []
    brackets = {'(': ')', 
                '[': ']', 
                '{': '}'}
    for char in string:
        if char in brackets.keys():
            stack.append(char)
        elif char in brackets.values():
            try:
                last_bracket = brackets[stack.pop()]
            except IndexError:
                return False
            if char != last_bracket:
                return False
    return not stack

def main():
        string = input("Введите строку: ")
        if not string:
            print("Строка пуста")
        if check_brackets(string):
            print("Строка существует.")
        else:
            print("Строка не существует.")

if __name__ == "__main__":
    main()