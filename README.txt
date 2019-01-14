Proiect -Lampa RGBW comanadata prin Bluethoot


PWM-  modul conceput pentru a controla duty cycle de pe cele 4 porturi PWM care comanda intensitatile fiecareia dintre cele 4 culori(rosu , verde,albastru,alb)

Serial - modulul cnfigureaza si utilizeaza USART pentru transmisie de date si receptionare de comenzi

Controller - combina celelalte 2 module si utilizeaza comenzile primite pe USART pentru a seta duty cycle pe porturile PWM

OS-ruleaza o bucla infinita in care verifica daca s-a primit o comanda , iar daca s-a primit comanda notifica modulul de controler

