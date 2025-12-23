<?php
declare(strict_types=1);
namespace src\Classes;

require_once 'User.php';

/**
 * Класс SuperUser представляет пользователя с расширенными правами
 * 
 * Наследует функциональность класса User и добавляет свойство role (роль).
 * Переопределяет метод showInfo() для отображения дополнительной информации.
 * 
 * @package src\Classes
 * @extends User
 */
class SuperUser extends User
{
    /**
     * Конструктор класса SuperUser с продвижением параметров
     * 
     * Расширяет конструктор родительского класса, добавляя параметр role.
     * Вызывает конструктор родительского класса для инициализации базовых свойств.
     * Свойство role инициализируется через продвижение параметров.
     * 
     * @param string $name Имя пользователя
     * @param string $login Логин пользователя
     * @param string $password Пароль пользователя
     * @param string $role Роль пользователя в системе
     */
    public function __construct(
        string $name,
        string $login,
        string $password,
        public string $role
    ) {
        parent::__construct($name, $login, $password);
        // Свойство role уже инициализировано благодаря продвижению параметров
    }

    /**
     * Возвращает HTML-строку с полной информацией о супер-пользователе
     * 
     * Переопределяет метод родительского класса, добавляя отображение роли.
     * Формирует оформленный HTML-блок с именем, логином и ролью пользователя.
     * 
     * @return string HTML-строка с полной информацией о пользователе
     * @override
     */
    public function showInfo(): string
    {
        return "<div class=\"super-user-info\">
                    <h3>Super User Info</h3>
                    <p><strong>Name:</strong> {$this->name}</p>
                    <p><strong>Login:</strong> {$this->login}</p>
                    <p><strong>Role:</strong> {$this->role}</p>
                </div>";
    }
}
