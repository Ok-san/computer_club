В корне проекта ввести команды

Windows:  
>*mkdir build  
cd build/  
cmake [-G "MinGW Makefiles"] ..  
cmake --build . [--config Release]*



Linux:  
>*mkdir build  
cd build/  
cmake ..  
make*


Запуск

>Windows: *Computer_Club.exe ../test_data/test_file.txt*    
Linux:  *./Computer_Club ../test_data/test_file.txt*
