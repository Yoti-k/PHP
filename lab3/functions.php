<?php
declare(strict_types=1);

$extensions = get_loaded_extensions();
$totalFunctions = 0; // Переменная для подсчета общего количества функций

foreach ($extensions as $ext) {
    $functions = get_extension_funcs($ext);
    
    echo "<h2>Модуль: {$ext}</h2>";
    if ($functions) {
        echo '<ul>';
        
        foreach ($functions as $func) {
            echo "<li>{$func}";
        }
        
        echo '</ul>';
        
        // Добавляем количество функций текущего модуля к общему счетчику
        $totalFunctions += count($functions);
    } else {
        echo '<p>Нет доступных функций для модуля';
    }
}

// Выводим общее количество всех функций в конце
echo "<h3>Общее количество всех функций: {$totalFunctions}</h3>";
?>