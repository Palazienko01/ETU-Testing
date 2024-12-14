from gmpy2 import *

def chinese_remainder(n, a):
    """
    Решает систему линейных сравнений по модулю
    :param n: список модулей
    :param a: список остатков
    :return: наименьшее положительное решение
    """
    prod = 1
    for p in n:
        prod *= p

    sm = 0
    for p, a_i in zip(n, a):
        pp = prod // p
        _, x, _ = gcdext(pp, p)
        sm += a_i * x * pp
    return sm % prod

# Ввод данных
n = [26, 11, 37, 35]
a = [22, 2, 16, 11]

# Вычисление решения
result = chinese_remainder(n, a)

print("Наименьшее натуральное число x:", result)