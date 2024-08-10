Компіляція проєкту:
```
g++ -o server Server.cpp Overload.cpp -lboost_system -I/usr/include -L/usr/lib
```
Якщо порт закритий:
```
sudo ss -tuln | grep 8080
```
та
```
sudo lsof -i :8080
```
Якщо бібліотеку не встановлено: 
```
sudo apt update
sudo apt install ufw
```

Дозвольте трафік на порт 8080:
```
sudo ufw allow 8080/tcp
```

Перевірте статус ufw:
```
sudo ufw status
```

Активуйте ufw, якщо він не активний:
```
sudo ufw enable
```

Перевірка фаєрволу:
```
sudo ufw status verbose
```

Перевірка публічної IP-адреси:
```
curl ifconfig.me
```

Перевірка з зовнішньої мережі:
```
curl http://your_public_ip:8080
```

типу: 
curl http://176.119.82.124:8080




