# Таблица

В последовательности из n чисел за один просмотр необходимо каждый элемент заменить на ближайший следующий за ним элемент, который больше его, если такой существует, или на ноль в противном случае. Можно использовать дополнительную память.

## Формат входных данных

На входе задано n  (1<=n<=10^7) целых чисел, каждое из которых лежит на интервале от 1 до 10^9 включительно.

## Формат выходных данных

Выведите элементы новой последовательности.

## Пример

| Ввод                    | Вывод                           |
| :---------------------- | :------------------------------ |
| 1 3 2 5 3 4             | 3 5 5 0 4 0                     |
| 2 6 5 5 7 3 4           | 6 7 7 7 0 4 0                   |
