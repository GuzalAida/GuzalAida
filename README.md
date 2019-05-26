# GuzalAida

daemon配置<br>
edit file: "/etc/rsyslog.conf" add 
```
#GuzalAida daemon log
user.GuzalAida  /var/log/GuzalAida
local0.* /var/log/GuzalAida0
```
重启rsyslog服务
```
sudo systemctl restart rsyslog.service
```
如果想要运行可以执行(默认为Release Version)
```
cd GuzalAida
chmod 0744 autorun.sh
./autorun.sh
```
