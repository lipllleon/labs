from itertools import permutations

def generate_permutations(s):
    return [''.join(p) for p in permutations(s)]

def find_permutations(s1, s2):
    set_s1 = {...}
    set_s1.add(s1)
    permutations_of_s2 = set(generate_permutations(s2))
    intersection = set_s1 & permutations_of_s2
    return len(intersection)

def len_of_permutations(a, b):
    count = 0
    s1 = list(a)
    s2 = list(b)
    print(''.join(s2))
    for i in range(len(s2)):
        if s1[i] != s2[i]:
            for j in range(i, (len(s2))):
                if s2[j] == s1[i] and s1[j] != s2[j]:
                    count += 1
                    s2[i], s2[j] = s2[j], s2[i]
                    print(''.join(s2))
                    break
    return count

def main():
    a = input('Введите первую строку (0, 1, 2, 3): ')
    b = input('Введите вторую строку (0, 1, 2, 3): ')

    if find_permutations(a, b) >= 1:
        print(f'{a} может быть получено из {b} с помощью бинарных перестановок. ({len_of_permutations(a, b)})')
    else:
        print(f'{a} не может быть получено из {b}.')

if __name__ == '__main__':
    main()