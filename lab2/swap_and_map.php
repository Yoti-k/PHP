<?php


function swap(&$a, &$b): void {
    $a ^= $b;
    $b ^= $a;
    $a ^= $b;
}


$a = 5;
$b = 8;
swap($a, $b);

echo '5 === $b: ', (5 === $b) ? 'true' : 'false';
echo "<br>";
echo '8 === $a: ', (8 === $a) ? 'true' : 'false';
echo "<br>";

function map(array $array, callable $callback): array {
    $result = [];
    foreach ($array as $value) {
        $result[] = $callback($value);
    }
    return $result;
}

// Пример использования с массивом чисел
$numbers = [1, 2, 3, 4, 5];

// Используем стрелочную функцию для возведения в квадрат
$squaredNumbers = map($numbers, fn($x) => $x * $x);

// Вывод результата
echo "Исходный массив: " . implode(', ', $numbers) . "\n";
echo "Квадраты чисел: " . implode(', ', $squaredNumbers) . "\n";