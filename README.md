# AuroraNotes

Проект представляет собой программу для создания текстовых заметок с цветовыми метками

## Условия использования и участия

Исходный код проекта предоставляется по [лицензии](LICENSE.BSD-3-CLAUSE.md),
которая позволяет использовать его в сторонних приложениях.

Информация об участниках указана в файле [AUTHORS](AUTHORS.md).

## Структура проекта

Проект имеет стандартную структуру приложения на базе C++ и QML для ОС Аврора.

* Файл **[ru.auroraos.AuroraNotes.pro](ru.auroraos.AuroraNotes.pro)**
        описывает структуру проекта для системы сборки qmake.
* Каталог **[icons](icons)** содержит иконки приложения для поддерживаемых разрешений экрана.
* Каталог **[qml](qml)** содержит исходный код на QML и ресурсы интерфейса пользователя.
    * Каталог **[cover](qml/cover)** содержит реализации обложек приложения.
    * Каталог **[icons](qml/icons)** содержит дополнительные иконки интерфейса пользователя.
    * Каталог **[pages](qml/pages)** содержит страницы приложения.
    * Файл **[AuroraNotes.qml](qml/ru.auroraos.TinyPdfViewer.qml)**
                предоставляет реализацию окна приложения.
* Каталог **[rpm](rpm)** содержит настройки сборки rpm-пакета.
    * Файл **[ru.auroraos.AuroraNotes.spec](rpm/ru.auroraos.AuroraNotes.spec)**
                используется инструментом rpmbuild.
* Каталог **[src](src)** содержит исходный код на C++.
    * Файл **[main.cpp](src/main.cpp)** является точкой входа в приложение.
* Каталог **[translations](translations)** содержит файлы перевода интерфейса пользователя.
* Файл **[ru.auroraos.AuroraNotes.desktop](ru.aurorao.AuroraNotes.desktop)**
        определяет отображение и параметры запуска приложения.
        
## Совместимость

Проект совместим с актуальными версиями ОС Аврора.

## В каталогах 
**[build-ru.auroraos aarch64](build-ru.auroraos.AuroraNotes-AuroraOS_5_0_1_27_base_aarch64_in_Aurora_Build_Engine-Release)**,
**[build-ru.auroraos armv7hl](build-ru.auroraos.AuroraNotes-AuroraOS_5_0_1_27_base_armv7hl_in_Aurora_Build_Engine-Release)**,
**[build-ru.auroraos x86_64](build-ru.auroraos.AuroraNotes-AuroraOS_5_0_1_27_base_x86_64_in_Aurora_Build_Engine-Release)**
в директориях RPMS содержатся rpm пакеты для установки приложения.
Установки на эмулятор следует использовать build-ru.auroraos x86_64

##Репозиторий для сервера заметок (пока не работает): **[aurora-notepad](https://gitlab.com/muxsin.shokirov/aurora-notepad)**
