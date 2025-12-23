<?php
// ЗАДАНИЕ 1: Анонимная функция swap
$swap = function(&$a, &$b) {
    $temp = $a;
    $a = $b;
    $b = $temp;
};

echo "<h3>Задание 1: Обмен значений</h3>";

$a = 5;
$b = 8;
echo "До обмена: a = $a, b = $b<br>";
$swap($a, $b);
echo "После обмена: a = $a, b = $b<br>";

var_dump(5 === $b); // true
var_dump(8 === $a); // true

echo "<br><h3>Задание 2: Функция map</h3>";

// ЗАДАНИЕ 2: Функция map
function map(array $array, callable $callback): array {
    $result = [];
    foreach ($array as $value) {
        $result[] = $callback($value);
    }
    return $result;
}

// Вызов как в задании
$numbers = [1, 2, 3, 4, 5];
$squaredNumbers = map($numbers, fn($n) => $n ** 2);

echo "Исходный массив: " . implode(', ', $numbers) . "<br>";
echo "Массив квадратов: " . implode(', ', $squaredNumbers) . "<br>";
?>
